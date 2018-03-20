#include <bits/stdc++.h>
using namespace std;

vector<char> s;
vector<vector<char>> arr;
int n;
void rec(vector<char>& t, int pos){
    if (pos == n){
        arr.push_back(t);
        return;
    }
    for (int i = 0;i < 10;i++){
        t[pos] = i;
        rec(t, pos + 1);
     }
     t[pos] = 0;
}
bool cmp(vector<char> const & a, vector<char> const & b){
    int razn = 0, razn1 = 0;
    for (int i = 0;i < n;i++){
        razn += abs(a[i] - s[i]);
        razn1 += abs(b[i] - s[i]);
    }
    if (razn != razn1) return razn < razn1;
    return a < b;
}
int main(){
    int k;
    cin >> n >> k;
    s.resize(n);
    for (int i = 0;i < n;i++){
        cin >> s[i];
        s[i] -= '0';
    }
    vector<char> tmp(n, 0);
    rec(tmp, 0);
    sort(arr.begin(), arr.end(), cmp);
    for (auto i : arr[k - 1]) cout << (int)i;
    cout << '\n';
}