#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vi = vector<int>;
using vb = vector<bool>;
using pll = pair<long, long>;
#define vin(v) for (int& i : v) cin >> i;
#define all(x) (x).begin, (x).end()
#define pbc push_back
int main(){
    int n;
    cin >> n;
    vector<int> cnt_need(1e5 + 1), cnt_now(1e5 + 1), arr(n);
    int need = 1e5 + 1;
    for (int i = 0;i < n;i++){
        cin >> arr[i];
        cnt_need[arr[i]]++;
    }
    int now = 0;
    for (int i = 0; i <= 1e5;i++){
        if (!cnt_need[i]) now++;
    }
    int m;
    cin >> m;
    vector<int> arr1(m);
    for (int i = 0;i < m;i++){
        cin >> arr1[i];
    }
    for (int i = 0;i < n;i++){
        if (cnt_now[arr1[i]] == cnt_need[arr1[i]]) now--;
        cnt_now[arr1[i]]++;
        if (cnt_now[arr1[i]] == cnt_need[arr1[i]]) now++;
    }
    if (now == need){
        cout << "YES\n";
        cout << 1 << '\n';
        return 0;
    }
    for (int i = n; i < m;i++){
        if (cnt_now[arr1[i - n]] == cnt_need[arr1[i - n]]) now--;
        cnt_now[arr1[i - n]]--;
        if (cnt_now[arr1[i - n]] == cnt_need[arr1[i - n]]) now++;
        if (cnt_now[arr1[i]] == cnt_need[arr1[i]]) now--;
        cnt_now[arr1[i]]++;
        if (cnt_now[arr1[i]] == cnt_need[arr1[i]]) now++;
        if (now == need){
            cout << "YES\n";
            cout << i - n + 2 << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}
