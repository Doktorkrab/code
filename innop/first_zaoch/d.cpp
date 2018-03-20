#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define ch(arr) arr.begin(),arr.end()
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
vector<ull> hashes;
vector<ull> bases;
const int BASE = 11;
const ull MOD = 1e9 + 7;
void build(vector<int>& arr){
    hashes.push_back(arr[0]);
    bases.push_back(1);
    for (int i = 1;i < arr.size();i++){
        hashes.push_back((hashes[i - 1] * BASE + arr[i])%MOD);
        bases.push_back((bases[i - 1] * BASE)%MOD);
    }
}
ull get_hash(int l, int r){
    if (!l) return hashes[r];
    return ((hashes[r] - hashes[l] * bases[r - l])%MOD + MOD) % MOD;
}
ll bin_s(int l0, int l1, int s){
    int l = 0, r = s;
    while (r - l != 1){
        int m = (l + r) / 2;
        if (get_hash(l0, l0 + m) == get_hash(l1,l1 + m)) l = m;
        else r = m;
    }
    //cout << l << ' ' << r << '\n';
    return l;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        rep(tests, 5){
    #endif
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        ll s = 0; 
        for (int i = 0;i < n;i++){
            char gg;
            cin >> gg;
            arr[i] = gg - '0';
            s += arr[i];
        }
        build(arr);
        deque<int> sum;
        for (int i = k - 1;i < n;i++){
            sum.push_back(arr[i]);
        }
        deque<int> max_ = sum;
        int max_b = k - 1;
        for (int i = k - 2;i >= 0;i--){
            sum.pop_back();
            //cout << "!!!!" << arr[i] << '\n';
            sum.push_front(arr[i]);
            if (arr[i] == 0) continue;
            int d = bin_s(i, max_b, sum.size());
            if (d == sum.size()) continue;
            //cout <<sum[d]<< ' ' << max_[d] << '\n';
            if (max_[d] < sum[d]) {
                max_ = sum;
                max_b = i;
            }
        }
        //for (auto i : max_) cout << (int)i << ' ';
        //cout << "\n";
        ll s2 = 0;
        for (auto i : max_) s2 += (ll)i;
        s -= s2;
        //ll s = 100;
        //deque<int> max_ = {239};
        //cout << s << '\n';
        vector<int> gg;
        while(s){
            ll gg1 = max_.back() + (s % 10);
            //cout << gg1 << '\n';
            s /= 10;
            max_.pop_back();
            if (max_.empty()) max_.push_front(gg1 / 10);
            else max_[max_.size() - 1] += gg1 / 10;
            gg.push_back(gg1 % 10);
        }
        while (max_.size()){
                int tmp = max_.back();
                max_.pop_back();
                gg.push_back(tmp % 10);
                if (tmp < 10) continue;
                if (max_.empty()) max_.push_front(1);
                else max_[max_.size() - 1]++;
        }
        bool flag = 0;
        reverse(gg.begin(), gg.end());
        for (auto i : max_) {
            if (i == 0 && !flag) continue;
            flag = 1;
            cout << (int)i;
        }
        for (auto i : gg) {
            if (i == 0 && !flag) continue;
            flag = 1;
            cout << (int)i;
        }
        cout << '\n';

}
#ifdef LOCAL
}
#endif