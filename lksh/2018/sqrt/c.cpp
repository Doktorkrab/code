#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
 

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
	int t = (int)x;
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

#include <bits/stdc++.h>

using namespace std;

struct Decomposition{
    vector<vector<int64_t>> blocks;
    vector<int64_t> arr;
    vector<int64_t> add;
    int BLOCK_SIZE;
    Decomposition(int BLOCK_SIZE, const vector<int64_t>& arr) : arr(arr), BLOCK_SIZE(BLOCK_SIZE){
        int n = arr.size();
        blocks.resize((n + BLOCK_SIZE - 1) / BLOCK_SIZE);
        add.resize((n + BLOCK_SIZE - 1) / BLOCK_SIZE);
        int block = -1;
        for (int i = 0; i < n;i++){
            if (i % BLOCK_SIZE == 0) block++;
            blocks[block].push_back(arr[i]);
        }
        for (int i = 0;i < (int)blocks.size();i++){
            sort(blocks[i].begin(), blocks[i].end());
        }
    }
    void pull(int block){
        blocks[block].clear();
        int start = block * BLOCK_SIZE;
         for (int i = 0; i < BLOCK_SIZE && start + i < (int)arr.size();i++){
            blocks[block].push_back(arr[i + start]);
        }
        sort(blocks[block].begin(), blocks[block].end());
    }
    void push(int block){
        int start = block * BLOCK_SIZE;
        for (int i = 0; i < BLOCK_SIZE && start + i < (int)arr.size();i++){
            arr[i + start] += add[block];
        }
        add[block] = 0;
        pull(block);
    }
    int get(int l, int r, int64_t x){
        int bl_l = l / BLOCK_SIZE;
        int bl_r = r / BLOCK_SIZE;
        push(bl_l);
        push(bl_r);
        int j = l;
        for (; j <= min(r, BLOCK_SIZE * (bl_l + 1) - 1); j++){
            if (arr[j] == x) return 1;
        }
        if (j > r) return 0;
        for (int block = bl_l + 1; block < bl_r; block++){
            auto tmp = lower_bound(blocks[block].begin(), blocks[block].end(), x - add[block]);
            if (tmp == blocks[block].end()) continue;
            if (*(tmp) == x - add[block]) return 1;
        }
        j = max(j, bl_r * BLOCK_SIZE);
        for (; j <= r; j++){
            if (arr[j] == x) return 1;
        }
        return 0;
    }

    void add_sum(int l, int r, int64_t x){
        int bl_l = l / BLOCK_SIZE, bl_r = r / BLOCK_SIZE;
        push(bl_l);
        push(bl_r);
        int j = l;
        for (; j <= min(r, BLOCK_SIZE * (bl_l + 1) - 1); j++){
            arr[j] += x;
        }

        for (int block = bl_l + 1; block < bl_r; block++){
            add[block] += x;
        }
        j = max(j, bl_r * BLOCK_SIZE);
        for (; j <= r; j++){
            arr[j] += x;
        }
        pull(bl_l);
        pull(bl_r);
    }
};

signed main(){
    int n = readInt(), q = readInt();
    vector<int64_t> arr(n);
    for (auto& i : arr) i = readInt();
    Decomposition dec = Decomposition(123, arr);
    for (int i = 0;i < q;i++){
        char query = readChar();
        int l = readInt(), r = readInt(), x = readInt();
        --l, --r;
        if (query == '?'){
            writeWord((dec.get(l, r, x) ? "YES\n" : "NO\n"));
        }
        if (query == '+'){
            dec.add_sum(l, r, x);
        }
    }
}