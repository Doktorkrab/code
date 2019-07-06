#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;
#define int int64_t
struct Event{
    int x, type, ind;
    bool operator<(const Event& oth) const {
        return tie(x, type, ind) < tie(oth.x, oth.type, oth.ind);
    }
};
mt19937 rnd(239);
namespace Cartesian{
    struct Node{
        int x, y;
        int sum = 0, sum_here = 0;
        int ans_here = 0, ans;
        Node *left = nullptr;
        Node *right = nullptr;
        Node(int x, int sum) : x(x), y(rnd()), sum(sum), sum_here(sum), ans_here(sum * x), ans(sum * x) {}
    };
    using nd = Node *;
    int safe_sum(nd a){
        return a ? a->sum : 0;
    }
    int safe_ans(nd a){
        return a ? a->ans : 0;
    }
    nd pull(nd a){
        a->sum = a->sum_here + safe_sum(a->left) + safe_sum(a->right);
        a->ans = a->ans_here + safe_ans(a->left) + safe_ans(a->right);
        return a;
    }
    nd merge(nd a, nd b){
        if (!a)
            return b;
        if (!b)
            return a;
        if (a->y < b->y){
            a->right = merge(a->right, b);
            return pull(a);
        }
        b->left = merge(a, b->left);
        return pull(b);
    }
    pair<nd, nd> split(nd a, int x){
        if (!a)
            return {a, a};
        if (a->x <= x){
            auto tmp = split(a->right, x);
            a->right = tmp.first;
            return {pull(a), tmp.second};
        }
        auto tmp = split(a->left, x);
        a->left = tmp.second;
        return {tmp.first, pull(a)};
    }
    nd find(nd a, int x, int b){
        if (!a)
            return nullptr;
        if (a->x == x){
            a->sum_here += b;
            a->ans_here = (a->sum_here * x);
            return pull(a);
        }
        if (a->x > x){
            auto ret = find(a->left, x, b);
            pull(a);
            return ret;
        }
        auto ret = find(a->right, x, b);
        pull(a);
        return ret;
    }
    void insert(nd& a, int x, int b){
        if (a == nullptr){
            a = new Node(x, b);
            return;
        }
        auto ret = find(a, x, b);
        if (ret != nullptr)
            return;
        auto tmp = split(a, x);
        auto tmp1 = split(tmp.first, x);
        tmp1.second = new Node(x, b);
        a = merge(merge(tmp1.first, tmp1.second), tmp.second);
    }
    int get_ans(nd a, int x){
        if (!a)
            return 0;
        if (safe_sum(a->right) <= x)
            return safe_ans(a->right) + get_ans(a->left, x - safe_sum(a->right));
        return max(a->x * min(a->sum_here, x), get_ans(a->right, x));
    }
};
int n, m, p;
const int MAXN = 1e5 + 7;
int sum = 0;
int a[MAXN];
pair<int, int> b[MAXN];
Event events[MAXN];
Cartesian::nd root = nullptr;
inline void init(){
    sum = 0;
    root = nullptr;
}
int recalc(int now){
    return Cartesian::get_ans(root, now);
}
inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        int x, ai;
        cin >> x >> ai;
        a[i] = ai;
        events[i] = {x, 0, i};
    }
    for (int i = 0; i < m; i++){
        int y, bi, c;
        cin >> y >> bi >> c;
        b[i] = {c, bi};
        events[n + i] = {y, 1, i};
    }
    sort(events, events + n + m);
    int ans = 0;
    for (int ee = 0; ee < n + m; ee++){
        Event &e = events[ee];
        if (e.type == 0)
            sum += a[e.ind];
        else
            Cartesian::insert(root, b[e.ind].first, b[e.ind].second);
        int64_t tmp = recalc(sum);
        ans = max(ans, tmp - e.x * p);
    }
    cout << ans << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#else
                freopen("fisher.in", "r", stdin);
                freopen("fisher.out", "w", stdout);
    #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m >> p)
        solve();

}
