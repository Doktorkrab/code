#include <bits/stdc++.h>

using namespace std;
deque<int> q1, q2;

void balance() {
    while (((int) q1.size()) < q2.size() + ((q1.size() + q2.size()) % 2)) {
        q1.push_back(q2.front());
        q2.pop_front();
    }
    while (q1.size() > q2.size() + ((q1.size() + q2.size()) % 2)) {
        q2.push_front(q1.back());
        q1.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        balance();
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            q2.push_back(x);
        }
        if (c == '*') {
            int x;
            cin >> x;
            q1.push_back(x);
        }
        if (c == '-') {
            cout << q1.front() << '\n';
            q1.pop_front();
        }
    }
    return 0;
}