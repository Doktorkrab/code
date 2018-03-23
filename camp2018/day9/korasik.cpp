
/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */
 
#define VERSION "0.1.4"

#include <cassert>
#include <cstdio>
#include <algorithm>

/** Fast allocation */

#ifdef FAST_ALLOCATOR_MEMORY
    int allocator_pos = 0;
    char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
    inline void * operator new ( size_t n ) {
        char *res = allocator_memory + allocator_pos;
        allocator_pos += n;
        assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
        return (void *)res;
    }
    inline void operator delete ( void * ) noexcept { }
    //inline void * operator new [] ( size_t ) { assert(0); }
    //inline void operator delete [] ( void * ) { assert(0); }
#endif

/** Fast input-output */

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

static const int buf_size = (1 << 24);

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


inline void readWord( char *s ) { 
    int c = readChar();
    while (c > 32)
        *s++ = c, c = getChar();
    *s = 0;
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
    if (write_buf_pos)
        fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
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


#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
// TEMPLATE HERE

#define ALLOC
#define forn(i, n) for (int i = 0;i < n;i++)
#define pb push_back
  
  
#ifdef ALLOC
const int MAX_MEM = 3e8;
int mpos = 0;
unsigned char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
    return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { }
#endif
  
// TEMPLATE END
  
// CODE HERE
struct Trie{
    Trie* edges[26];
    bool is_terminal = 0;
    Trie* parent = nullptr;
    unsigned char prev_letter;
    Trie* link = nullptr, *suplink = nullptr;
    vector<int> index;
    Trie(Trie* p, unsigned char c) : is_terminal(0), parent(p), prev_letter(c), link(nullptr), suplink(nullptr) {
        for (int i = 0;i < 26;i++) edges[i] = nullptr;
    }
};
using trie = Trie*;
void add(trie a, string& s, int i){
    for (unsigned char c : s){
        if (!a->edges[c - 'a']) a->edges[c - 'a'] = new Trie(a, c);
        a = a->edges[c - 'a'];
    }
    a->index.pb(i);
    a->is_terminal = 1;
}

inline void make_link(trie v){
    if (!v->parent){
        v->link = v->suplink = v;
        return;
    }
    if (!v->parent->parent){
        v->link = v->parent;
        if (!v->is_terminal){
            v->suplink = v->link;
        }
        else{
            v->suplink = v;
        }
        return;
    }
    trie u = v->parent->link;
    unsigned char c = v->prev_letter;
    while(u->parent && !u->edges[c - 'a']) u = u->link;
    if (u->edges[c - 'a']){
        v->link = u->edges[c - 'a'];
    }
    else{
        v->link = u;
    }
    if (v->is_terminal){
        v->suplink = v;
    }
    else{
        v->suplink = v->link->suplink;
    }
}

void bfs(trie root){
    deque<trie> q = {root};
    while (q.size()){
        trie v = q.front();
        q.pop_front();
        make_link(v);
        for (int i = 0;i < 26;i++){
            if (v->edges[i]){
                q.push_back(v->edges[i]);
            }
        }
    }
}


vector<string> strs;
vector<int> found_cnt;
void get_all(trie v){
    if (!v->suplink->is_terminal) return;
    for (int i : v->suplink->index){
        found_cnt[i]++;
    }
    get_all(v->suplink->link);
}
void process(trie root, string& s){
    trie v = root;
    for (unsigned char c : s){
        while(v->parent && !v->edges[c - 'a']) {
            v = v->link;
        }
        if (v->edges[c - 'a']) {
            v = v->edges[c - 'a'];
        }
        get_all(v);
    }
}
unordered_map<string, int> id;
struct Solver{
    int n;
    trie root = new Trie(nullptr, 'a');
    Solver(){
        n = readUInt();
        int id_now = 0;
        char t[(int)1e6];
        forn(i, n){
            readWord(t);
            string t_cpp(t);
            strs.pb(t_cpp);
            if (id.count(t_cpp)) continue;
            id[t] = id_now;
            add(root, t_cpp, id_now++);
        }
        found_cnt.resize(id_now);
        bfs(root);
        readWord(t);
        string s(t);
        process(root, s);
        for (string i : strs){
            writeInt(found_cnt[id[i]]);
            writeChar('\n');
        }
    }   
};
  
// CODE END
signed main(){
    int t  = 1;
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    freopen("output.txt", "w", stdout);
    cin >> t;
#else
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    string FN = "search5";
    freopen("search5.in", "r", stdin);
    freopen("search5.out", "w", stdout);
#endif
    while(t--){
#ifdef LOCAL
        clock_t t_elapsed = clock();
#endif
        Solver a;
#ifdef LOCAL
        cerr << setprecision(5) << fixed <<"Elapsed: " << fabs(clock() - t_elapsed) / CLOCKS_PER_SEC << " sec.\n";
#endif
    }
  
}