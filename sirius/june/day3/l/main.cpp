#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    sort(points.begin(), points.end());
    set<int> x_ans, y_ans;
    for (int i = 1; i < n; i++) {
        if (points[i].first == points[i - 1].first) {
            y_ans.insert((points[i - 1].second + points[i].second + 1) / 2);
        } else {
            x_ans.insert((points[i - 1].first + points[i].first + 1) / 2);
        }
    }//(points[i].x points[i-1].x+1)/2
    cout << x_ans.size() + y_ans.size() << '\n';
    for (int i : x_ans) {
        cout << "x " << i << '\n';
    }
    for (int i : y_ans) {
        cout << "y " << i << '\n';
    }
}