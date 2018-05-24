#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void prep(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
}


void run(){
}

int main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#endif
   // string FN = "z-function";
   // assert(freopen((FN + ".in").c_str(), "r", stdin));
   // freopen((FN + ".out").c_str(), "w", stdout);


    int t = 1;
    prep();

#ifdef LOCAL
    cin >> t;
#endif
    while (t--) run();
#ifdef LOCAL
    cerr << "Elapsed: " << (clock() * 1.) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}