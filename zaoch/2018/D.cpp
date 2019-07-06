#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

using namespace std;
struct InsQuery{
	int pos, x;
};
struct GetQuery{
	int l, r, time, id;
};
int n, m;
const int MAXN = 5e5 + 5;
// const int MAXN = 49;
const int SQRT_MAXN = 708;
// const int SQRT_MAXN = 7;
const int MAX_INSERTS = 5e4;
// const int MAX_INSERTS = 3;
int sqrtDec[MAXN];
int arr[MAXN];
int blocks[SQRT_MAXN + 1];
int tmp[MAXN];
int ans[MAXN];
vector<InsQuery> stack;
GetQuery query[MAXN];
InsQuery inserts[MAX_INSERTS];

int block_size, mo_block_size;
int ipos, gpos;

char type;
int l, r, t;
InsQuery now;
inline void init(){
	// block_size = sqrt(n + 0.5) + 1;
	block_size = 1024;
	mo_block_size = (int) ceil(cbrt(2.L * n * n));
	for (int i = mo_block_size; i <= n; i++)
		tmp[i] = tmp[i - mo_block_size] + 1;
	#ifdef LOCAL
		memset(sqrtDec, 0, sizeof(int) * MAXN);
		memset(blocks, 0, sizeof(int) * (SQRT_MAXN + 1));
		memset(arr, 0, sizeof(int) * MAXN);
	#endif
	ipos = gpos = 0;
}

inline void add(int pos){
	if (sqrtDec[pos]++ == 0)
		blocks[pos << 10]++;
}
inline void del(int pos){
	if (--sqrtDec[pos] == 0)
		blocks[pos << 10]--;
}
inline int get(){
	for (int i = 0;;i++)
		if (blocks[i] < block_size){
			for (i *= block_size;;i++)
				if (sqrtDec[i] == 0)
					return i;
		}
}
inline bool cmp(const GetQuery &a, const GetQuery &b){
    if (tmp[a.l] != tmp[b.l]) return tmp[a.l] < tmp[b.l];
    if (tmp[a.r] != tmp[b.r]) return tmp[a.r] < tmp[b.r];
    if (a.time != b.time) return a.time < b.time;
    return a.id < b.id;
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++)
		arr[i] = readInt();
	for (int i = 0; i < m; i++){
		type = readChar();
		l = readInt();
		r = readInt();
		if (type == '!')
			inserts[ipos++] = {l - 1, r};
		else {
			query[gpos] = {l - 1, r - 1, ipos, gpos};
			gpos++;
		}
	}
	stable_sort(query, query + gpos, cmp);
	l = 0, r = -1;
	t = 0;
	for (int i = 0; i < gpos; i++){
		auto w = query[i];
		while (r < w.r) add(arr[++r]);
		while (r > w.r) del(arr[r--]);
		while (l < w.l) del(arr[l++]);
		while (l > w.l) add(arr[--l]);
		while (stack.size() < w.time){
			now = inserts[stack.size()];
			stack.push_back({now.pos, arr[now.pos]});
			if (l > now.pos || r < now.pos){
				arr[now.pos] = now.x;
				continue;
			}
			del(arr[now.pos]);
			arr[now.pos] = now.x;
			add(arr[now.pos]);
		}
		while (stack.size() > w.time){
			now = stack.back();
			stack.pop_back();
			if (l > now.pos || r < now.pos){
				arr[now.pos] = now.x;
				continue;
			}
			del(arr[now.pos]);
			arr[now.pos] = now.x;
			add(arr[now.pos]);
		}
		ans[w.id] = get();
	}

	for (int i = 0; i < gpos; i++)
		writeInt(ans[i], '\n');
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    // while (cin >> n >> m)
    n = readInt();
    m = readInt();
        solve();

}