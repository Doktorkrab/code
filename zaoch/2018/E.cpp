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
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

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

const char ASK = -1, PLUS = 0, MINUS = 1;
struct Query{
	char type;
	int v, u;
	int pair;
};
struct Version{
	int v;
	pair<int, bool> parent;
	int sz;
	bool biparticle;
	bool same = 0;
};
int n, m;
const int MAXN = 1e6;
pair<int, bool> parent[MAXN];
int sz[MAXN];
bool biparticle[MAXN];
int biparticle_comps;
int comps;
// bool ans[MAXN];
int pnt = 0;
vector<int> g[MAXN];
Query events[6 * MAXN + 5];
vector<Version> versions;
int ans[MAXN], pnt1 = 0;

unordered_map<int, int> lst[MAXN];

inline void init(){
	for (int i = 0; i < n; i++){
		sz[i] = 1;
		parent[i] = {i, 0};
		biparticle[i] = 1;
		// g[i].clear();
	}
	pnt = 0;
	pnt1 = 0;
	biparticle_comps = comps = n;
}
pair<int, bool> get(int v){
	if (v == parent[v].first)
		return {v, 0};
	auto ret = get(parent[v].first);
	ret.second ^= parent[v].second;
	return ret;
}
// inline pair<int, bool> get(int v){
// 	bool xr = 0;
// 	while (v != parent[v].first){
// 		xr ^= parent[v].second;
// 		v = parent[v].first;
// 	}
// 	return {v, xr};
// }

inline void un(int a, int b){
	auto pa = get(a);
	auto pb = get(b);
	a = pa.first, b = pb.first;
	int x = pa.second, y = pb.second;

	if (sz[a] > sz[b])
		swap(a, b);
	versions.push_back({a, parent[a], sz[b], biparticle[b], a == b});
	if (a == b){
		if (x == y){
			if (biparticle[a])
				biparticle_comps--;
			biparticle[a] = 0;
		}
	}
	else {
		parent[a] = {b, x ^ y ^ 1};
		if ((biparticle[a] ^ biparticle[b]) == 1 || biparticle[a] == 1){
			biparticle_comps--;
		}
		biparticle[b] &= biparticle[a];
		sz[b] += sz[a];
		comps--;
	}
}

inline void get_prev(){
	Version top = versions.back();
	versions.pop_back();
	if (top.same){
		if (top.biparticle == 1 && biparticle[top.v] == 0){
			biparticle_comps++;
		}
		biparticle[top.v] = top.biparticle;
		return;
	}

	sz[parent[top.v].first] = top.sz;
	if ((biparticle[top.v] ^ top.biparticle) == 1 || top.biparticle == 1)
		biparticle_comps++;
	biparticle[parent[top.v].first] = top.biparticle;
	parent[top.v] = top.parent;
	comps++;


}
void split(int tl, int tr){
	if (tr == 0)
		return;
	if (tr - tl == 1){
		if (events[tl].type == ASK){
			if (biparticle_comps == comps){
				ans[pnt1++] = events[tl].v;
			}
		}
		return;
	}
	int tm = (tl + tr) / 2;
	int cnt = 0;
	for (int i = tl; i < tm; i++){
		if (events[i].type == PLUS && events[i].pair >= tr){
			cnt++;
			un(events[i].v, events[i].u);
		}
	}
	split(tm, tr);
	while(cnt > 0){
		get_prev();
		cnt--;
	}
	for (int i = tm; i < tr; i++){
		if (events[i].type == MINUS && events[i].pair < tl){
			un(events[i].v, events[i].u);
			cnt++;
		}
	}
	split(tl, tm);
	while (cnt > 0){
		get_prev();
		cnt--;
	}
}
inline void solve(){
	init();
	const int kek = 1e9;
	int v, u;
	for (int i = 0; i < m; i++){
		v = readInt(), u = readInt();
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
		lst[min(v, u)][max(v, u)] =pnt;
		events[pnt++] = {PLUS, v, u, kek};
	}
	int l, r;
	for (int i = 0; i < n; i++){
		for (int j : g[i]){
			l = min(i, j);
			r = i ^ j ^ l;
			events[lst[l][r]].pair = pnt;
			events[pnt++] = {MINUS, i, j, lst[l][r]};
		}
		events[pnt++] = {ASK, i, -1, -1};
		if (i != n - 1)
			for (int j : g[i]){
				l = min(i, j);
				r = i ^ j ^ l;
				lst[l][r] = pnt;
				events[pnt++] = {PLUS, i, j, kek};
			}
	}
	split(0, pnt);
	writeInt(pnt1, '\n');
	for (int i = pnt1 - 1; i >= 0; i--){
		writeInt(ans[i] + 1, (i ? ' ' : '\n'));
	}
}


int main(){
	#ifdef LOCAL
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif
	
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    // while ()
    n = readInt();
    m = readInt();
        solve();

}