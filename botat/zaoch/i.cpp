#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 gen(time(0));
uniform_int_distribution<int> ran(0, INT_MAX - 1);


struct TNode{
    ll x, y, size = 1;
    TNode* left = nullptr;
    TNode* right = nullptr;
    TNode(ll x) : x(x), y(ran(gen)) {}
};


using node = TNode*;
using ptt = pair<node, node>;
unordered_map<ll, int> cnt[2];


ll safe(node a){ return a ? a->size : 0;}
node recalc(node a, int ind){
    a->size = safe(a->left) + cnt[ind][a->x] + safe(a->right);
    return a;
}
//(-inf; x] (x, +inf)
ptt split(node a, ll k, int ind){
    if (!a) return {nullptr, nullptr};
    if (a->x <= k){
        ptt tmp = split(a->right, k, ind);
        a->right = tmp.first;
        tmp.first = recalc(a, ind);
        return tmp;
    }
    ptt tmp = split(a->left, k, ind);
    a->left = tmp.second;
    tmp.second = recalc(a, ind);
    return tmp;
}

node merge(node a, node b, int ind){
    if (!a) return b;
    if (!b) return a;
    if (a->y > b->y){
        a->right = merge(a->right, b, ind);
        return recalc(a, ind);
    }
    b->left = merge(a, b->left, ind);
    return recalc(b, ind);
}

node insert(node a, ll k, int ind){
    if (!a){
        cnt[ind][k]++;
        return new TNode(k);
    }
    if (a->x < k){
        a->right = insert(a->right, k, ind);
        return recalc(a, ind);
    }
    if (a->x == k){
        cnt[ind][k]++;
        return recalc(a, ind);
    }
    if (a->x > k){
        a->left = insert(a->left, k, ind);
        return recalc(a, ind);
    }
    assert(false);
    return nullptr;
}


node delete_(node a, ll k, int ind){
    if (!a) return nullptr;
    if (a->x == k){
        if (cnt[ind][k] > 1){
            cnt[ind][k]--;
            return recalc(a, ind);
        }
        cnt[ind][k]--;
        return merge(a->left, a->right, ind); 
    }
    if (a->x > k){
        a->left = delete_(a->left, k, ind);
        return recalc(a, ind);
    }
    if (a->x < k){
        a->right = delete_(a->right, k, ind);
        return recalc(a, ind);
    }
    assert(false);
    return nullptr;
}
void print(node a){
    if (!a) return;
    print(a->right);
    cout << a->x << ' ';
    print(a->left);
}

void update(node& a, ll old, ll new_, int ind){
    a = delete_(a, old, ind);
    a = insert(a, new_, ind);
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    node min_ = nullptr;
    node max_ = nullptr;
    int n, m, q, k;
    cin >> n >> m >> q >> k;
    vector<ll> balls(n, 0);
    vector<ll> max_balls(n, 0);
    vector<int> max_ball(m, 0);
    vector<vector<ll>> balls_each(n, vector<ll>(m));
    for (int i = 0; i < m; i++) cin >> max_ball[i];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ll ball;
            cin >> ball;
            balls[i] += ball;
            balls_each[i][j] = ball;
            if (ball == k - max_ball[j]){
                max_balls[i] += k;
            }
            else{
                max_balls[i] += ball;
            }
        }
    }
    for (int i = 0; i < n; i++){
        min_ = insert(min_, max_balls[i], 0);
        max_ = insert(max_, balls[i], 1);
    }
    for (int gg = 0; gg < q; gg++){
        int t;
        cin >> t;
        if (t == 1){
            int i;
            cin >> i;
            --i;
            update(min_, max_balls[i], balls[i], 0);
            update(max_, balls[i], max_balls[i], 1);
            ptt s1 = split(min_, balls[i], 0);
            ptt s2 = split(max_, max_balls[i], 1);
            int ans = (s1.second ? s1.second->size : 0) + 1, ans1 = (s2.second ? s2.second->size : 0) + 1;
            cout << ans1 << ' ' << ans << '\n';
            max_ = merge(s2.first, s2.second, 1);
            min_ = merge(s1.first, s1.second, 0);
            update(max_, max_balls[i], balls[i], 1);
            update(min_, balls[i], max_balls[i], 0);
        }
        else if (t == 2){
            int i, j, kek;
            cin >> i >> j >> kek;
            --i;--j;
            update(min_, max_balls[i], max_balls[i] - k + kek, 0);
            update(max_, balls[i], balls[i] + kek - balls_each[i][j], 1);
            max_balls[i] -= k;
            max_balls[i] += kek;
            balls[i] += kek - balls_each[i][j];
        }
    }
}