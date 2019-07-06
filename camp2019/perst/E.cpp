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

int n;
namespace CartesianTree{
    mt19937 rnd(239);
    struct Node{
        int x, cnt = 0, uniq = 0;
        int sz = 1;
        Node *left = nullptr;
        Node *right = nullptr;
        Node () {}
    };
    using nd = Node*;
    nd recalc(nd a){
        a->cnt = a->uniq = a->sz = 0;
        a->sz++;
        if (a->left){
            a->sz += a->left->sz;
            a->cnt += a->left->cnt;
            a->uniq += a->left->uniq;
        }
        if (a->right){
            a->sz += a->right->sz;
            a->cnt += a->right->cnt;
            a->uniq += a->right->uniq;
        }
        return a;
    }
    nd merge(nd a, nd b){
        if (!a) 
            return b;
        if (!b) 
            return a;
        if (rnd() % (a->sz + b->sz) <= a->sz){
           nd nxt = new Node();
           nxt->left = a->left;
           nxt->right = merge(a->right, b);
           return recalc(nxt);
        }
        nd nxt = new Node();
        nxt->right = b->right;
        nxt->left = merge(a, b->left);
        return recalc(nxt);
    }
    pair<nd, nd> split(nd a, int x){
        if (!a)
            return {nullptr, nullptr};
        if (a->x <= x){
            nd nxt = new Node();
            auto ret = split(a->right, x);
            nxt->left = a->left;
            nxt->right = ret.first;
            return {recalc(nxt), ret.second};
        }
        auto nxt = new Node();
        auto ret = split(a->left, x);
        nxt->right = a->right;
        nxt->left = ret.second;
        return {ret.first, recalc(nxt)};
    }
    bool find(nd a, int x){
        if (!a)
            return 0;
        if (a->x > x)
            return find(a->left, x);
        if (a->x < x)
            return find(a->right, x);
        return a->cnt > 0;
    }
    nd insert(nd a, int x){
        if (find(a, x)){
            auto kek = split(a, x);
            auto kek1 = split(kek.first, x - 1);
            nd nxt = new Node();
            *nxt = *kek1.second;
            nxt->cnt++;
            if (nxt->cnt >= 2)
                nxt->uniq = 0;
            else
                nxt->uniq = 1;
            return merge(merge(kek1.first, nxt), kek.second);
        }
        auto kek = split(a, x);
        auto kek1 = split(kek.first, x - 1);
        nd nxt = new Node();
        nxt->cnt = 1;
        nxt->uniq = 1;
        return merge(merge(kek1.first, nxt), kek.second);
    }

    nd remove(nd a, int x){
        if (!find(a, x))
            return a;
        
    }
};
inline void init(){

}

inline void solve(){

}


int main(){
	#ifdef LOCAL
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
