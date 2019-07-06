#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Man {
    ll a, b, c, d, index;

    bool operator<(const Man &oth) const {
        return a - b < oth.a - oth.b;
    }
};

struct Event {
    int type; // -1 - exit, 1 - enter
    int index;

    bool operator<(const Event &oth) const {
        return tie(type, index) < tie(oth.type, oth.index);
    }
};

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<Event>> events(p);
    vector<Man> men(n);
    set<Man> sit, stand;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --c, --d;
        men[i] = {a, b, c, d, i};
        events[c].push_back({1, i});
        events[d].push_back({-1, i});
    }

    ll b_sum = 0, a_b_sum = 0;
    ll ans = 0;
    sort(events.begin(), events.end());
    for (int stop = 0; stop < p; stop++) {
        for (Event &e : events[stop]) {
            if (e.type == -1) {
                b_sum -= men[e.index].b;
                if (sit.count(men[e.index])) a_b_sum -= men[e.index].a - men[e.index].b;
                sit.erase(men[e.index]);
                stand.erase(men[e.index]);
            } else {
                b_sum += men[e.index].b;
                a_b_sum += men[e.index].a - men[e.index].b;
                sit.insert(men[e.index]);
            }
        }
        while (!stand.empty() && sit.size() < m) {
            auto man = *(stand.rbegin());
            a_b_sum += man.a - man.b;
            sit.insert(man);
            stand.erase(--stand.end());
        }
        while (sit.size() > m) {
            auto man = *(sit.begin());
            a_b_sum -= man.a - man.b;
            if (man.a - man.b > 0) {
                stand.insert(man);
            }
            sit.erase(sit.begin());
        }
        if (!sit.empty()) {
            auto man = *(sit.begin());
            while (!sit.empty() && (man.a - man.b) < 0) {
                man = *(sit.begin());
                a_b_sum -= man.a - man.b;
                sit.erase(sit.begin());
            }
        }
        ans += b_sum + a_b_sum;
    }
    cout << ans << '\n';
}