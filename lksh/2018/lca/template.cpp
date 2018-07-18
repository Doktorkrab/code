#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif
struct Node{
    bool is_terminal;
    Node* suff, *suf_term;
    unordered_map<char, Node*> go;
};
using nd = Node*;
// -*-*-* All variables *-*-*-


// -*-*-* All functions *-*-*-
void insert(nd root, const string& s){
    nd now = root;
    
}
void init(){
}

void solve(){

}
int main(){
    #ifdef LOCAL
    string taskName = "";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}