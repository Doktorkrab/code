#include <bits/stdc++.h>

using namespace std;


mt19937 gen(123);
struct Choice {
    int direction, steps;
};
int n;

bool check(Choice ch, int pos) {
    return (ch.direction == -1 && pos >= ch.steps) || (ch.direction == 1 && pos <= n - ch.steps - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // clock_t tm = clock();
//    srand(time(NULL));
    cin >> n;
    uniform_int_distribution<> uid1(0, n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<Choice> choices;
    choices.push_back({-1, 3});
    choices.push_back({-1, 4});
    choices.push_back({1, 3});
    choices.push_back({1, 4});
    if (n == 3) {
        if (arr[0] >= arr[1] && arr[1] >= arr[2]) cout << "YES\n0\n";
        else cout << "NO\n";
        return 0;
    }
    if (n == 2) {
        if (arr[0] >= arr[1]) cout << "YES\n0\n";
        else cout << "NO\n";
        return 0;
    }
    if (n < 7) {
//        cout << "NO\n";
//        return 0;
        vector<pair<long long, long long>> ans;
        int kk = 0;
        while (kk < 23000) {
            bool f = 0;

            for (int i = 1; i < n; i++) {
                f |= arr[i] > arr[i - 1];
            }
            if (!f) {
                cout << "YES\n";
                cout << ans.size() << '\n';
                for (auto i : ans) {
                    cout << i.first + 1 << ' ' << i.second + 1 << '\n';
                }
                return 0;
            }
            int ind = gen() % n;
            int choice = gen() % 4;
            if (ind + choices[choice].direction * choices[choice].steps < 0 || ind + choices[choice].direction * choices[choice].steps >= n) continue;
            swap(arr[ind], arr[ind + choices[choice].direction * choices[choice].steps]);
            ++kk;
            ans.push_back({ind, ind + choices[choice].direction * choices[choice].steps});
        }
        cout << "NO\n";
        return 0;
    }
    vector<pair<int, int>> ans;
//    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        int mx = INT_MIN, ind = 0;
        for (int j = i; j < n; j++) {
            if (mx < arr[j]) {
                mx = arr[j];
                ind = j;
            }
        }
        while (ind != i){
            if (ind + 3 >= n){
                ans.push_back({ind, ind - 4});
                ans.push_back({ind - 4, ind - 1});
                ans.push_back({ind - 4, ind});
            }
            else {
                ans.push_back({ind, ind + 3});
                ans.push_back({ind + 3, ind - 1});
                ans.push_back({ind, ind + 3});
            }
            swap(arr[ind], arr[ind - 1]);
            ind -= 1;
        }
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
    return 0;
}
