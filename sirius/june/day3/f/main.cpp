#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_set<int> st1;
    for (int i = 0;i < n;i++){
        int x;
        cin >> x;
        st1.insert(x);
    }
    cin >> n;
    unordered_set<int> st2;
    for (int i = 0;i < n;i++){
        int x;
        cin >> x;
        st2.insert(x);
    }
    set<int> ans;
    for (auto i : st1){
        if (!st2.count(i)) ans.insert(i);
    }
    for (auto i : st2){
        if (!st1.count(i)) ans.insert(i);
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
}