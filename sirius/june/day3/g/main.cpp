#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        string q;
        cin >> q;

        if (q == "ADD"s) {
            int x;
            cin >> x;
            st.insert(x);
        }
        if (q == "COUNT"s) {
            cout << st.size() << '\n';
        }
        if (q == "PRESENT"s) {
            int x;
            cin >> x;
            cout << (st.count(x) ? "YES" : "NO") << '\n';
        }
    }
}