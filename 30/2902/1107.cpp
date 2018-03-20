#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sqr(x) 1LL * x * x

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Solver{
    int n, k, m;
    Solver() {
        cin >> n >> k >> m;
        cout << "YES\n";
        for (int i = 0; i < k; i++){
            int cnt, sum = 0;
            cin >> cnt;
            for (int j = 0; j < cnt; j++){
                int tmp;
                cin >> tmp;
                sum += tmp;
                sum %= m;
            }
            cout << sum + 1 << '\n';
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int t = 1;
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    cin >> t;
    #endif
    while(t--) Solver a;
}
