#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
#include <cassert>

/** Begin fast allocation */

/*const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
    return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { } // must have!*/
/** End fast allocation */
/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;

using namespace std;


int main(){
    int t = readInt();
    vector<int> hist(18);
    while(t--){
        int n = readInt(), m = readInt();
        vector<vector<int>> g(n);
        vector<vector<int>> dp((1 << n), vector<int>(n));
        vector<int> mx_color((1 << n), INT_MAX);
        mx_color[0] = 0;
        for (int i = 0;i < m;i++){
            int v = readInt(), u = readInt();
            g[--v].push_back(--u);
            g[u].push_back(v);
        }

        for (int mask = 1; mask < (1 << n); mask++){
            for (int i = 0; i < n;i++){
                if (((1 << i) & mask) == 0) continue;
                int new_mask = mask ^ (1 << i);
                int mex = 1;
                for (int u : g[i]){
                    if (((1 << u) & new_mask) == 0) continue;
                    hist[dp[new_mask][u]] = 1;
                }
                for (mex = 1; hist[mex] == 1; mex++);
                for (int u : g[i]){
                    if (((1 << u) & new_mask) == 0) continue;
                    hist[dp[new_mask][u]] = 0;
                }
                int c = max(mx_color[new_mask], mex);
                if (c < mx_color[mask]){
                    mx_color[mask] = c;
                    dp[mask] = dp[new_mask];
                    dp[mask][i] = mex;
                }
            }
        }
        writeInt(mx_color[(1 << n) - 1]);
        writeChar('\n');
        for (int i : dp[(1 << n) - 1]){
            writeInt(i);
            writeChar(' ');
        }
        writeChar('\n');
    }

}