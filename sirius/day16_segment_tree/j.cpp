#include <bits/stdc++.h>
using namespace std;
// TEMPLATE HERE

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define ALLOC

#define MAX INT_MAX
#define MIN INT_MIN
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0;i < n;i++)
#define ft first
#define st second
#define pb push_back

void print(ostream& os){
    os << "\n";
}

template <typename Arg1, typename... Args>
void print(ostream& os, const Arg1& arg1, const Args&... args){
    os << arg1 << " ";
    print(os, args...);
}

// TEMPLATE END

// CODE HERE
struct Node{
    int max = 0, count = 0, first_pos = -1, add = 0;
    bool operator< ()
};
const int OPEN = -1, CLOSE = 1;
struct Event{
    int x, type, start, end;
    bool operator< (const Event& oth) const{
        return tie(x, type, start, end) < tie(oth.x, oth.type, oth.start, oth.end);

    }
};

const int MAXN = 2e6 + 5;
vector<Node> st(4 * MAXN);

void push(int x, int l, int r){
    st[x].max += st[x].add;
    if (r - l != 1){
        st[2 * x].add += st[x].add;
        st[2 * x + 1].add += st[x].add;
    }
    st[x].add = 0;
}

void pull(int x,int l, int r){
    if (r - l != 1){
        st[x] = max(st[2 * x], st[2 * x + 1]);
    }
}
pair<int, int> NEUTRAL = {MAX, -1};

void push_add(int x, int l, int r, int L, int R, int add){
    push(x, l, r);
    if (l >= R || L >= r) return;
    if (L <= l && r <= R){
        st[x].add += add;
        push(x, l, r);
        return;
    }
    int m = (l + r) / 2;
    push_add(2 * x, l, m, L, R, add);
    push_add(2 * x + 1, m, r, L, R, add);
    pull(x, l, r);
}

struct Solver{
    vector<Event> events;
    int n;
    Solver(){
        cin >> n;
        events.resize(2 * n);
        for (int i = 0;i < n;i++){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            y1 += 1e6;
            y2 += 1e6;
            events[i] = {x1, OPEN, min(y1, y2), max(y1, y2)};
            events[i] = {x2, CLOSE, min(y1, y2), max(y1, y2)};
        }
        n *= 2;
        int power = 0;
        while ((1 << power) < n) power++;
        int N = 1 << power;
        sort(all(events));
        int ans = 0;
        int ans_x = 0, ans_y = 0;
        for (const Event& e : events){
            if (e.type == OPEN){
                push_add(1, 0, N, e.start, e.end, 1);
            }
            push_add(1, 0, N, 0, N, 0);
            if (ans < st[1].max){
                ans = st[1].max;
                ans_x = e.x;
                ans_y = 
            }
            if (e.type == CLOSE){
                push_add(1, 0, N, )
            }
        }
    }   
};

// CODE END

int main(){
    int t = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
#endif
    while(t--){
#ifdef LOCAL
        clock_t t_elapsed = clock();
#endif
        Solver a;
#ifdef LOCAL
        cout << setprecision(5) << fixed <<"Elapsed: " << fabs(clock() - t_elapsed) / CLOCKS_PER_SEC << " sec.\n";
#endif
    }

}
