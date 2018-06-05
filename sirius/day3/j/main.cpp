#include <bits/stdc++.h>

using namespace std;
const double EPS = 1e-4;

bool eq(double a, double b) {
    return fabs(b - a) < EPS;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<double> stack;
        deque<double> arr;
        multiset<double> st;
        for (int i = 0; i < n; i++) {
            double tmp;
            cin >> tmp;
            arr.push_back(tmp);
            st.insert(tmp);
        }
        while (!arr.empty()) {
            while (stack.size() && eq(stack.back(), *(st.begin()))) {
                st.erase(st.begin());
                stack.pop_back();
            }
            stack.push_back(arr.front());
            arr.pop_front();

        }
        while (stack.size() && eq(stack.back(), *(st.begin()))) {
            stack.pop_back();
            st.erase(st.begin());
        }
        cout << (st.empty()) << '\n';

    }
}