#include <bits/stdc++.h>

using namespace std;
struct Event{
    int start, end;
    bool operator<(const Event& o) const {
        return tie(start, end) < tie(o.start, o.end);
    }
};


int main(){
    freopen("cat.in", "r", stdin);
    freopen("cat.out", "w", stdout);
    int a, b;
    cin >> a >> b;
    a *= 60;
    b *= 60;
    int n;
    cin >> n;
    vector<Event> events(n);
    for (int i = 0; i < n; i++){
        int h, m, h1, m1;
        scanf("%d:%d-%d:%d", &h, &m, &h1, &m1);
        events[i].start = h * 60 + m;
        events[i].end = h1 * 60 + m1;
//        cout << events[i].start << ' ' << events[i].end << '\n';
    }
    sort(events.begin(), events.begin());
//    events.push_back(events[0]);
    int free = events.back().end + 1;
    int lst = abs(events.back().end - events.back().start) + 1;
//    cout << free << '\n';
    vector<Event> ans;
    int podryad = 1, sum = 0;
    for (int i = 0; i < n; i++){
        int diff = 0;
        if (free > events[i].start){
            diff = 24 * 60 - (free - events[i].start);
        }
        else{
            diff = abs(events[i].start - free);
        }
//        cout << diff << ' ' << sum << '\n';
//        cout << abs(events[i].end - events[i].start) + 1 << '\n';
        if (diff > a) ans.push_back({free, events[i].start - 1}), podryad = 0, sum = 0;
        else sum += diff + abs(events[i].end - events[i].start) + 1 + lst, podryad++;
        lst = abs(events[i].end - events[i].start) + 1;
//        cerr << sum << '\n';
        if (sum > b){
            cout << "No\n";
            return 0;
        }
        free = events[i].end + 1;
    }
    if (podryad == n || sum > 0){
        cout << "No\n";
        return 0;
    }
    if (ans.size() == 0){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
//    cout << podryad << '\n';
    cout << ans.size() << '\n';
    for (auto i : ans){
        assert(i.start / 60 <= 24);
        assert(i.end / 60 <= 24);
        printf("%.2d:%.2d-%.2d:%.2d\n", i.start / 60, i.start % 60, i.end / 60, i.end % 60);
    }
}