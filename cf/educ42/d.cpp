#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    set<pair<long long, int>> s;
    cin >> n;
    for (int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        s.insert({tmp * 1LL, i});
    }
    vector<long long> ans(n);
    while(s.size()){
        auto fir = *s.begin();
        auto sec1 = s.begin();
        sec1++;
        auto sec = *sec1;
        if (fir.first != sec.first){
            ans[fir.second] = fir.first;
            s.erase(fir);
            continue;
        }
        s.erase(fir);
        s.erase(sec);
        s.insert({sec.first * 2, sec.second});
    }
    int ln = 0;
    for (long long i : ans){
        if (i != 0)ln++;
    }
    cout << ln << '\n';
    for (long long i : ans){
        if (i != 0) cout << i << ' ';
    }
    cout << '\n';
}