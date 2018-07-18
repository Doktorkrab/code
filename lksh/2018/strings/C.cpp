#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
#else
const int INF = 1e9; 
#endif

// -*-*-* All variables *-*-*-
string s, t;

// -*-*-* All functions *-*-*-
vector<int> calc_z(string s) {
    int n = s.size();
    vector<int> func(n);
    func[0] = n;
    int l = 0, r = 0;
    s += '#';
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            func[i] = min(r - i + 1, func[i - l]);
        }
        while (func[i] < n && s[func[i]] == s[func[i] + i]) {
            func[i]++;
        }
        if (r < func[i] + i - 1) {
            r = func[i] + i - 1;
            l = i;
        }
    }
    return func;
}
void init(){
    
}

void solve(){
    string s1 = s + '#' + t;

    auto z1_tmp = calc_z(s1);
    vector<int> z1(t.size());
    for (size_t i = s.size() + 1; i < s1.size(); i++) z1[i - s.size() - 1] = z1_tmp[i];
    
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    
    string s2 = s + '#' + t; 
    auto z2_tmp = calc_z(s2);
    vector<int> z2(t.size());

    for (size_t i = s.size() + 1; i < s2.size(); i++) z2[i - s.size() - 1] = z2_tmp[i];
    
    vector<int> ans;
    for (size_t i = 0; i + s.size() - 1 < t.size(); i++){
        if (z1[i] + z2[t.size() - i - s.size()] >= (int)s.size() - 1) ans.push_back(i + 1);
    }

    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n'; 
}
int main(){
    #ifdef LOCAL
    string taskName = "C";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "C";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> s >> t){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}