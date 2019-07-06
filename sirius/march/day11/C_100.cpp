#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#define FMA 8e7
#ifdef FMA
    int alloc = 0;
    char alloc_arr[(int) FMA];
    inline void* operator new (size_t n){
        char *res = alloc_arr + alloc;
        alloc += n;
        assert(alloc <= (int) FMA);
        return (void*) res;
    }
    inline void operator delete( void*) noexcept {}
#endif
using namespace std;
 template <class T = int> inline T readInt();                       
inline double readDouble();
inline int readUInt();                   
inline int readChar(); // first non-blank character
inline void readWord( char *s ); 
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int getChar(); 
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();

template <class T> inline void writeInt( T x, char end = 0, int len = -1 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
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

inline int peekChar() { 
    return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() { 
    int c;
    while ((c = peekChar()) != -1 && c <= 32)
        buf_pos++;
    return c == -1;
}

inline void skipBlanks() {
    while (!isEof() && buf[buf_pos] <= 32U)
        buf_pos++;
}

inline int readChar() {
    int c = getChar();
    while (c != -1 && c <= 32)
        c = getChar();
    return c;
}

inline int readUInt() {
    int c = readChar(), x = 0;
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return x;
}

template <class T>
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

inline double readDouble() {
    int s = 1, c = readChar();
    double x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    if (c == '.') {
        c = getChar();
        double coef = 1;
        while ('0' <= c && c <= '9')
            x += (c - '0') * (coef *= 1e-1), c = getChar();
    }
    return s == 1 ? x : -x;
}

inline void readWord( char *s ) { 
    int c = readChar();
    while (c > 32)
        *s++ = c, c = getChar();
    *s = 0;
}

inline bool readLine( char *s ) { 
    int c = getChar();
    while (c != '\n' && c != -1)
        *s++ = c, c = getChar();
    *s = 0;
    return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
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

template <class T> 
inline void writeInt( T x, char end, int output_len ) {
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

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
    if (x < 0)
        writeChar('-'), x = -x;
    assert(x <= (1LLU << 63) - 1);
    long long t = (long long)x;
    writeInt(t), x -= t;
    writeChar('.');
    for (int i = output_len - 1; i > 0; i--) {
        x *= 10;
        t = std::min(9, (int)x);
        writeChar('0' + t), x -= t;
    }
    x *= 10;
    t = std::min(9, (int)(x + 0.5));
    writeChar('0' + t);
}

const int MAXN = 1.5e5 + 7;
int a, b, n, q;
const int OPEN = -1, CLOSE = 1, POINT = 0;
struct Event{
    int time, type, id, y1, y2;
    bool operator< (const Event& oth) const {
        return tie(time, type, id, y1, y2) < tie(oth.time, oth.type, oth.id, oth.y1, oth.y2);
    }
};
 
vector<Event> events_all;
vector<Event> events_vertical;
vector<Event> events_horisontal;
 
int query_all[MAXN], query_horisontal[MAXN], query_vertical[MAXN];
int st[4 * MAXN];
 
int gt(int v, int l, int r, int L, int R){
    if (l >= R || L >= r)
        return 0;
    if (L <= l && r <= R)
        return st[v];
    int m = (l + r) / 2;
    return gt(v * 2, l, m, L, R) + gt(v * 2 + 1, m, r, L, R);
}
 
void ins(int v, int l, int r, int pos, int x){
    // cerr << l << ' ' << pos << ' ' << r << ' ' << v << '\n';
    if (pos < l || pos >= r)
        return;
    if (r - l == 1){
        st[v] += x;
        return;
    }
    int m = (l + r) / 2;
    ins(v * 2, l, m, pos, x);
    ins(v * 2 + 1, m, r, pos, x);
    // cerr << l << ' ' << r << ' ' << st[2 * v] + st[2 * v + 1] << '\n';
    st[v] = st[2 * v] + st[2 * v + 1]; 
}
 
inline void solve(){
    int N = 1;
    int gg = 1.5e5;
    while (N < gg) N <<= 1;
    for (int i = 1; i < n; i++){
        char c = getChar();
        int v, u;
        v = readInt();
        u = readInt();
        // --v, --u;
        events_all.push_back({v, POINT, -1, u, u});
        if (c == 'h'){
            events_horisontal.push_back({v, POINT, -1, u, u});
            events_all.push_back({v + 1, POINT, -1, u, u});
        }
        if (c == 'v'){
            events_vertical.push_back({v, POINT, -1, u, u});
            events_all.push_back({v, POINT, -1, u + 1, u + 1});
        }
    }
    // cerr << events_horisontal.size() << '\n';
    for (int i = 0; i < q; i++){
        int x, y, x1, y1;
        x = readInt();
        y = readInt();
        x1 = readInt();
        y1 = readInt();
        // --x, --y;
        y1++;
        events_all.push_back({x, OPEN, i, y, y1});
        events_all.push_back({x1, CLOSE, i, y, y1});
         
        events_vertical.push_back({x, OPEN, i, y, y1 - 1});
        events_vertical.push_back({x1, CLOSE, i, y, y1 - 1});
 
        events_horisontal.push_back({x, OPEN, i, y, y1});
        events_horisontal.push_back({x1 - 1, CLOSE, i, y, y1});
    }
    memset(st, 0, sizeof(int) * N * 2);
    while (!events_all.empty()){
        auto e = *(events_all.begin());
        events_all.erase(events_all.begin());
        // cerr << e.type << ' ' << e.time << ' ' << e.id << ' ' << e.y1 << ' ' << e.y2 << '\n';
        if (e.type == POINT)
            ins(1, 0, N, e.y1, 1);
        if (e.type == OPEN)
            query_all[e.id] -= gt(1, 0, N, e.y1, e.y2);
        if (e.type == CLOSE)
            query_all[e.id] += gt(1, 0, N, e.y1, e.y2);
    }
 
    memset(st, 0, sizeof(int) * N * 2);
    while (!events_horisontal.empty()){
        auto e = *(events_horisontal.begin());
        events_horisontal.erase(events_horisontal.begin());
        if (e.type == POINT)
            ins(1, 0, N, e.y1, 1);
        if (e.type == OPEN)
            query_horisontal[e.id] -= gt(1, 0, N, e.y1, e.y2);
        if (e.type == CLOSE)
            query_horisontal[e.id] += gt(1, 0, N, e.y1, e.y2);
    }
 
    memset(st, 0, sizeof(int) * N * 2);
    while (!events_vertical.empty()){
        auto e = *(events_vertical.begin());
        events_vertical.erase(events_vertical.begin());
        if (e.type == POINT)
            ins(1, 0, N, e.y1, 1);
        if (e.type == OPEN)
            query_vertical[e.id] -= gt(1, 0, N, e.y1, e.y2);
        if (e.type == CLOSE)
            query_vertical[e.id] += gt(1, 0, N, e.y1, e.y2);
    }
    for (int i = 0; i < q; i++){
        // cerr << query_all[i] << ' ' << query_vertical[i] << ' ' << query_horisontal[i] << '\n';
        writeInt(query_all[i] - query_vertical[i] - query_horisontal[i], '\n');
    }
}
 
 
int main(){
    #ifdef LOCAL
        freopen("C_100.in", "r", stdin);
        freopen("C_100.out", "w", stdout);
    // #else
    //     freopen("repair.in", "r", stdin);
    //     freopen("repair.out", "w", stdout);
    #endif
     
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    a = readInt();
    b = readInt();
    n = readInt();
    q = readInt();
    solve();
 
}