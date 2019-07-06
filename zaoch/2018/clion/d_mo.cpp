//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <cassert>
#include <cstdio>
#include <algorithm>

#define FAST_ALLOCATOR_MEMORY 2e7
#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
char allocator_memory[(int) FAST_ALLOCATOR_MEMORY];

inline void *operator new(size_t n) {
    char *res = allocator_memory + allocator_pos;
    allocator_pos += n;
    assert(allocator_pos <= (int) FAST_ALLOCATOR_MEMORY);
    return (void *) res;
}

inline void operator delete(void *) noexcept {}
//inline void * operator new [] ( size_t ) { assert(0); }
//inline void operator delete [] ( void * ) { assert(0); }
#endif

template<class T = int>
inline T readInt();

inline int readChar(); // first non-blank character
inline bool isEof();

inline int getChar();

template<class T>
inline void writeInt(T x, char end = 0, int len = -1);

inline void writeChar(int x);

inline void flush();

static struct buffer_flusher_t {
    ~buffer_flusher_t() {
        flush();
    }
} buffer_flusher;

/** Read */

static const int buf_size = 4096;

static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
    if (buf_pos == buf_len) {
        buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
        if (buf_pos == buf_len)
            return 1;
    }
    return 0;
}

inline int getChar() {
    return isEof() ? -1 : buf[buf_pos++];
}


inline int readChar() {
    int c = getChar();
    while (c != -1 && c <= 32)
        c = getChar();
    return c;
}

template<class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    else if (c == '+')
        c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
    if (write_buf_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
    write_buf[write_buf_pos++] = x;
}

inline void flush() {
    if (write_buf_pos) {
        fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
        fflush(stdout);
    }
}

template<class T>
inline void writeInt(T x, char end, int output_len) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n < output_len)
        s[n++] = '0';
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <string>
#include <cassert>

using namespace std;

mt19937 rnd((uint64_t) new char);

int64_t rand(int64_t x, int64_t y) { return rnd() % (y - x + 1) + x; }

template<typename t>
t min(t a) {
    return a;
}

template<typename t, typename... ts>
t min(const t &a, const ts &... as) {
    t tmp = min(as...);
    return tmp < a ? tmp : a;
}

template<typename t>
t max(t a) {
    return a;
}

template<typename t, typename... ts>
t max(const t &a, const ts &... as) {
    t tmp = max(as...);
    return tmp > a ? tmp : a;
}

void prn(ostream &os) {
    os << '\n';
}

void prn() {
    cout << '\n';
}

template<typename t, typename... ts>
void prn(ostream &os, const t &a, const ts &... b) {
    os << a << ' ';
    prn(os, b...);
}

template<typename t, typename... ts>
void prn(const t &a, const ts &... b) {
    cout << a << ' ';
    prn(cout, b...);
}

#ifdef LOCAL

template<typename... ts>
void deb(const ts &... b) {
    prn(cerr, "DEBUG", b...);
}

#else
template<typename... ts>
void deb(const ts&... b){

}
#endif


#define vec_in(v) for (auto& i : v) cin >> i;
#define vec_out(v) for (const auto& i : v) cout << i << ' '; cout << '\n';
#define repab(i, a, b) for (int i = a; i < (int) b; i++)
#define rep(i, n) repab(i, 0, n)
#define repab_(i, a, b) for (int i = b - 1; i >= a; i--)
#define rep_(i, n) repab_(i, 0, n)
#define infc for(;;)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using vi = vector<int>;
using vll = vector<int64_t>;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ll = int64_t;
//------------------------------------------------------------------------------
const int MAXN = 5e5 + 5;
int arr[MAXN];
int blocks[(MAXN + 1023) / 1024];
int block_size = 1024;
void add(int x, int pos) {
    int block = pos >> 10;
    if (arr[pos] == 0 && x > 0) blocks[block]++;
    if (arr[pos] + x <= 0 && arr[pos] > 0) blocks[block]--;
    arr[pos] += x;
}

int get() {
    rep(block, (MAXN + 1023) / 1024) {
        if (blocks[block] < block_size) {
            repab(el, (block << 10), MAXN) {
                if (arr[el] == 0) return el;
            }
        }
    }
    assert(0);
}

struct GetQuery {
    int l, r, time, id;
};

struct InsQuery {
    int pos, x, prev;

};


void solve(int n, int q) {
    int arr[n];
    int arr1[n];
    for (int i = 0; i < n; i++) arr[i] = arr1[i] = readInt();
    InsQuery inserts[q];
    int ins_cnt = 0;
    GetQuery query[q];
    int q_cnt = 0;
    char type;
    int l, r;
    rep(i, q) {
        type = readChar();
        l = readInt();
        r = readInt();
        if (type == '!') {
            inserts[ins_cnt++] = {l - 1, r, arr1[l - 1]};
            arr1[l - 1] = r;
        }
        if (type == '?') {
            query[q_cnt] = {l - 1, r - 1, ins_cnt, q_cnt};
            q_cnt++;
        }
    }
    int block_size = (int) ceil(cbrt(2.L * n * n));
    int tmp[n];
    for (int i = 0; i < n; i++) tmp[i] = i / block_size;
    stable_sort(query, query + q_cnt, [&](const GetQuery &a, const GetQuery &b) {
        if (tmp[a.l] != tmp[b.l]) return tmp[a.l] < tmp[b.l];
        if (tmp[a.r] != tmp[b.r]) return tmp[a.r] < tmp[b.r];
        if (a.time != b.time) return a.time < b.time;
        return a.id < b.id;
    });
    l = 0, r = -1;
    int t = 0, pos;
    int ans[q_cnt];
    for (int i = 0; i < q_cnt; i++) {
        auto w = query[i];
        while (r < w.r) add(1, arr[++r]);
        while (r > w.r) add(-1, arr[r--]);
        while (l < w.l) add(-1, arr[l++]);
        while (l > w.l) add(1, arr[--l]);
        while (t < w.time) {
            pos = inserts[t].pos;
            if (l > pos || r < pos) {
                arr[pos] = inserts[t++].x;
                continue;
            }
            add(-1, arr[pos]);
            arr[pos] = inserts[t++].x;
            add(1, arr[pos]);
        }
        while (t > w.time) {
            --t;
            pos = inserts[t].pos;
            if (l > pos || r < pos) {
                arr[pos] = inserts[t].prev;
                continue;
            }
            add(-1, arr[pos]);
            arr[pos] = inserts[t].prev;
            add(1, arr[pos]);
        }
        ans[w.id] = get();
    }
    for (int i = 0; i < q_cnt; i++) {
//        cerr << ans[i] << '\n';
        writeInt(ans[i]);
        writeChar('\n');
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("array.in", "r", stdin);
#else
    //    ios::sync_with_stdio(0);
    //    cin.tie(0), cout.tie(0);
#endif
    int n, q;
    n = readInt();
    q = readInt();
    solve(n, q);
}
