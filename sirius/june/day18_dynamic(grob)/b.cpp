#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
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
struct Solver{
    vector<vector<int>> dp;
    vector<vector<int>> choice; // x - go to [l..x] and [x + 1..r], -x - compress x times
    const ll STAY =  INT_MIN;

    string s;
    int n;
    int get_period(int l, int r){
        int n = r - l + 1;
        vector<int> p(n);
        p[0] = 0;
        for (int i = 1; i < n;i++){
            int k = p[i - 1];
            while (k > 0 && s[i + l] != s[k + l]) k = p[k - 1];
            if (s[i + l] == s[k + l]) k++;
            p[i] = k;
            // cout << p[i] << ' ';
        }
        return (n % (n - p.back()) ? n : n - p.back());
    }
    void get_ans(int l, int r){
        // cerr << l << ' ' << r << ' ' << choice[l][r] << '\n';
        if (choice[l][r] == STAY) {
            cout << s.substr(l, r - l + 1);
            return;
        }
        if (choice[l][r] < 0){
            int period = -choice[l][r];
            cout << (r - l + 1) / period;
            cout << "(";
            get_ans(l, l + period - 1);
            cout << ")";
            return;
        }
        get_ans(l, choice[l][r]);
        get_ans(choice[l][r] + 1, r);
    }   
    Solver(){
        cin >> s;
        n = s.size();
        dp.assign(n, vector<int>(n, 1e9));
        choice.assign(n, vector<int>(n, STAY));
        for (int len = 1; len <= n; len++){
            for (int l = 0; l + len - 1 < n; l++){
                int r = l + len - 1;
                dp[l][r] = r - l + 1;
                for (int l1 = l; l1 < r; l1++){
                    if (dp[l][r] > dp[l][l1] + dp[l1 + 1][r]){
                        dp[l][r] = dp[l][l1] + dp[l1 + 1][r];
                        choice[l][r] = l1;
                    }
                }
                int period = get_period(l, r);
                if (period == len) continue;
                int tmp = to_string(len / period).size() + 2 + dp[l][l + period - 1];
                if (dp[l][r] > tmp){
                    dp[l][r] = tmp;
                    choice[l][r] = -period;
                }
            }
        }
        get_ans(0, n - 1);
        cout << '\n';
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
