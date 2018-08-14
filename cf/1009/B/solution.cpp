#include <bits/stdc++.h>

using namespace std;
void print(ostream& ot){
    ot << '\n';
}
template<typename Arg, typename... Args>
void print(ostream& ot, const Arg& arg, const Args&... arg1){
    ot << arg << ' ';
    print(ot, arg1...);
}


#define err(x) print(cerr, #x, x)

#ifdef LOCAL
const int INF = 100;
#else
#define err() ;

const int INF = 1e9; 
#endif

// -*-*-* All variables *-*-*-
string s;
// -*-*-* All functions *-*-*-
void init(){

}

void solve(){
    int ones = 0;
    string t;
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (s[i] != '1') t += s[i];
        else ones++;
    }
    for (int i = 0; i < (int)t.size(); i++){
        if ((!i || t[i - 1] == '0') && t[i] == '2'){
            while(ones--){
                cout << 1;
            }
        }
        cout << t[i];
    }
    while (ones-- > 0) cout << 1;
    cout << '\n';
}
int main(){
    #ifdef LOCAL
    clock_t start = clock();
    #endif
    cin >> s;
    solve();
    #ifdef LOCAL
    cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
    #endif
}