#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define ALLOC

#define MAX INT_MAX
#define MIN INT_MIN
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0;i < n;i++)
#define ft first
#define st second
#define pb push_back

void print(ostream& os){
    os << "\n";
}

template <typename Arg1, typename... Args>
void print(ostream& os, const Arg1& arg1, const Args&... args){
    os << arg1 << " ";
    print(os, args...);
}

// TEMPLATE END

// CODE HERE
struct TNode{
    int l, r;
    int min = 0, count = 0, add = 0;
    TNode* left = nullptr;
    TNode* right = nullptr;
    TNode(int L, int R) : l(L), r(R) {}
};
using node = TNode*;
pair<int, int> NEUTRAL = {MAX, 0};
pair<int, int> safe(node a){
    return (a ? make_pair(a->min, a->count) : NEUTRAL); 
}

void pull(node a){
    auto lft = safe(a->left), rht = safe(a->right);
    if (lft.first == rht.first && lft.first != NEUTRAL.first){
        a->min = lft.first;
        a->count = lft.second + rht.second;
    }
    else{
        a->min = min(lft, rht).first;
        a->count = min(lft, rht).second;
    }
}

void insert(node& now, int L, int R, int pos, int x){
    if (L > pos || R <= pos) return;
    if (!now){
        now = new TNode(L, R);
    }
    if (R - L == 1){
        now->min = x;
        now->count = 1;
        return;
    }
    int M = (L + R) / 2;
    insert(now->left, L, M, pos, x);
    insert(now->right, M, R, pos, x);
    pull(now);
}

struct Solver{
    TNode *root = 0;
    Solver(){

    }   
};

// CODE END

int main(){
    int t = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
#endif
    while(t--){
#ifdef LOCAL
        clock_t t_elapsed = clock();
#endif
        Solver a;
#ifdef LOCAL
        cout << setprecision(5) << fixed <<"Elapsed: " << fabs(clock() - t_elapsed) / CLOCKS_PER_SEC << " sec.\n";
#endif
    }

}
