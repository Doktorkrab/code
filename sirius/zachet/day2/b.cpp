#include <bits/stdc++.h>

using namespace std;
using ld = long double;

ld EPS = 1e-12;

ld x1, x2;
bool cmp(pair<int, int> a, pair<int, int> b){
    return (a.first * (x1 + EPS) + a.second) < (b.first * (x1 + EPS) + b.second); 
}

bool cmp1(pair<int, int> a, pair<int, int> b){
    return (a.first * (x2 - EPS) + a.second) < (b.first * (x2 - EPS) + b.second); 
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> lines(n);
    vector<pair<int, int>> lines1(n);
    cin >> x1 >> x2;
    for (int i = 0;i < n;i++){
        int a, b;
        cin >> a >> b;
        lines[i] = {a, b};
        lines1[i] = {a, b};
    }
    sort(lines.begin(), lines.end(), cmp);
    sort(lines1.begin(), lines1.end(), cmp1);
    map<pair<int, int>, int> kek;
    for (int i = 0;i < n;i++){
        kek[lines[i]] = i;
    }
    for (int i = 0;i < n;i++){
        if (kek[lines1[i]] != i){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}