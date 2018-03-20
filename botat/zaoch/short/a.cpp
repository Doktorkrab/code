#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main(){
    ll n, m, t, k;
    cin >> n >> m >> t >> k;
    vector<ll> a(n);
    vector<ll> b(m);
    int left = 0;
    int right = 0;
    bool cur = 0;
    ll now = 0, ans = 0, ans1 = 0;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];
    while (1){
        // cerr << left << ' ' << right << '\n';
        if (now >= t) break;
        if (!cur){
            while (left < n && a[left] < now) left++;
            if (left && a[left - 1] + k > now) now = a[left - 1] + k;
            if (left >= n) {
                ans += max(t - now, 0LL);
                break;
            }
            while (left < n && a[left] <= now && a[left] + k > now) now = a[left++] + k; 
            if (now >= t) {
                // assert(now == t);
                break;
            }
            if (left >= n || a[left] >= t) {
                ans += t - now;
                break;
            }
            // cerr << "left" << now << '\n';
            ans += a[left] - now;
            now = a[left];
            cur = 1;
            // left++;
        }
        else{
            while (right < m && b[right] < now) right++;
            if (right && b[right - 1] + k > now && b[right - 1] < now) now = b[right - 1] + k;
            if (right >= m){
                // cerr << now << '\n';
                ans1 += max(t - now, 0LL);
                break;
            }
            while (right < m && b[right] <= now && b[right] + k > now) now = b[right++] + k;
            if (now >= t){
                // assert(now == t);
                break;
            }
            if (right >= m || b[right] >= t){
                ans1 += t - now;
                break;
            }
            // cerr << "right" << now << '\n';
            ans1 += b[right] - now;
            now = b[right];
            cur = 0;
            // right++;
        }
    }
    cout << ans << ' ' << ans1 << '\n';
}