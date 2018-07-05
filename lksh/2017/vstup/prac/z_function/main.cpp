#include <bits/stdc++.h>

using namespace std;

using ll = long long;


struct Event{
    int l, r;
    bool operator< (const Event& o) const{
        return tie(l, r) < tie(o.l, o.r);
    }
};
void prep(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
}

vector<int> z(string &s) {
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

void run(){
    string s;
    int n;
    cin >> s;
    n = s.size();
    vector<int> z_func = z(s);
    set<Event> events;
    vector<int> ans(n);
    for (int i = 0;i < n;i++){
        if (z_func[i] != 0) {
            events.insert({i, i + (z_func[i] + 1) / 2});
        }
        while(events.size() && (*events.begin()).r <= i) events.erase(events.begin());
        if (!events.size()) continue;
        ans[i] = 2 * (i - events.begin()->l) + 1;
    }
    for (int u : ans) cout << u << ' ';
    cout << '\n';
}

int main() {
    string FN = "z-function";
//    assert(freopen((FN + ".in").c_str(), "r", stdin));
//    freopen((FN + ".out").c_str(), "w", stdout);


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