#include <bits/stdc++.h>

using namespace std;
void print(ostream& ot){
    ot << '\n';
}
template<typename Arg, typename... Args>
void print(ostream& ot, const Arg& arg, const Args&... arg1){
    ot << arg << ' ';
    print(ot, arg1...);
}


#define err(x) print(cerr, #x, x)

#ifdef LOCAL
const int INF = 100;
#else
#define err() ;

const int INF = 1e9; 
#endif
struct Queue{
    int64_t sum = 0;
    Queue() {}
    deque<int64_t> deq;
    void push(int x){
        sum += x;
        // print(cerr, "push", x, sum);
        deq.push_back(x);
    }

    int pop(){
        int64_t top = deq.front();

        sum -= top;
        // print(cerr, "pop", top, sum);
        deq.pop_front();
        return top;
    }
};
// -*-*-* All variables *-*-*-
Queue q;
int64_t sum = 0;
int n;
int64_t ans = 1e18;
int64_t ans1 = -1e18;
vector<int64_t> arr;
// -*-*-* All functions *-*-*-
void init(){
    arr.resize(2 * n);
    sum = 0;
    ans = 1e18;
    ans1 = -1e18;
    q = Queue();
}

void solve(){
    init();
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        arr[n + i] = arr[i];
    }
    // print(cerr, sum);
    for (int i = 0; i < n / 2 + (n % 2); i++){
        q.push(arr[i]);
    }
    auto relax = [&](){
        int64_t t_ans = q.sum;
        int64_t t_ans1 = sum - q.sum;
        if (t_ans >= t_ans1 && t_ans - t_ans1 < ans - ans1){
                ans = t_ans;
                ans1 = t_ans1;
        }
    };
    relax();
    for (int i = n / 2 + (n % 2); i < 2 * n; i++){
        q.pop();
        q.push(arr[i]);
        relax();
    }
    print(cout, ans, ans1);
}
int main(){
    #ifdef LOCAL
    string taskName = "B";
    freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}