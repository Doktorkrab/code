#include <bits/stdc++.h>


using namespace std;
string s;
int m, k, r;
vector<string> ans;

void rec(int i, int gg){
    // cerr << i << ' ' << s << ' ' << gg << ' ' << k << '\n';
    if (gg > k)
        return;
    string kek = "ACGT";
    if (i == m){
        ans.push_back(s);
        return;
    }
    if (s[i] != 'N'){
        if (i != 0 && s[i] < s[i - 1])
            rec(i + 1, gg + 1);
        else
            rec(i + 1, gg);
        return;
    }
    for (int j = 0; j < 4; j++){
        s[i] = kek[j];
        if (i != 0 && s[i - 1] > s[i])
            rec(i + 1, gg + 1);
        else
            rec(i + 1, gg);
    }
    s[i] = 'N';
}
int main(){
    cin >> m >> k >> r;
    cin >> s;
    rec(0, 1);
    // for (auto c : ans)
    //     cerr << c << '\n';
    assert(r <= ans.size());
    cout << ans[r - 1] << '\n';
}