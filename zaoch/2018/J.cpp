#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int ui;
typedef unsigned long long ull;

#define f first
#define s second
#define mp make_pair
#define pb push_back
//#define hash hash42

const int MAXN = 2e5 + 42;
const int MAX = 2e5 + 42;
const int MAXLOG = 25;

inline vector<int> build_lcp(const string& s, const vector<int>& sufarr) {
    int n = s.size();
    cerr << n << '\n';
    vector<int> p(n);
    // cerr << "here\n";
    for (int i = 0; i < n; ++i){
    	cerr << sufarr[i] << ' ';
        p[sufarr[i]] = i;
    }
    cerr << '\n';
    int k = 0;
    vector<int> lcp(n - 1, 0);
    for (int i = 0; i < n; ++i) {
        if (p[i] == n - 1) continue;
        int j = sufarr[p[i] + 1];
        k = max(k - 1, 0);
        while (max(i, j) + k < n && s[i + k] == s[j + k])
            ++k;
        lcp[p[i]] = k;
    }
    return lcp;
}

inline vector<int> build_sufarray(string s) {
    s.pb('$');
    int n = s.size();
    cerr << n << "!\n";
    vector<int> c(n, 0);
    vector<int> p(n, 0);
    for (int i = 0; i < n; ++i)
        p[i] = i;
    sort(p.begin(), p.end(), [&](int a, int b) {return s[a] < s[b];});
    int col = 0;
    for (int i = 0; i < n; ++i)
        c[p[i]] = ((i == 0 || s[p[i]] == s[p[i - 1]]) ? col : ++col);
    for (int k = 0; k < 19; ++k) {
        int pk = 1 << k;
        int tmpk = ((n - pk) % n + n) % n;
        vector<int> ctr(n + 1, 0);
        vector<int> np(n, 0);
        vector<int> nc(n, 0);
        for (int i = 0; i < n; ++i)
            ++ctr[c[i] + 1];
        for (int i = 1; i < n; ++i)
            ctr[i] += ctr[i - 1];
        for (int i = 0; i < n; ++i) {
            int j = (p[i] + tmpk) % n;
            np[ctr[c[j]]++] = j;
        }
        int col = 0;
        for (int i = 0; i < n; ++i) {
            nc[np[i]] = ((i == 0 || mp(c[np[i]], c[(np[i] + pk) % n]) == mp(c[np[i - 1]], c[(np[i - 1] + pk) % n])) ? col : ++col);
        }
        swap(p, np);
        swap(c, nc);
    }
    reverse(p.begin(), p.end());
    p.pop_back();
    reverse(p.begin(), p.end());
    return p;
}
vector<int> lcp_;
vector<int> sufarr;
#define log log42
int log[MAXN];
int sparse[MAXLOG][MAXN];
int n;

inline int min_on_seg(int L, int R) {
    if (R >= n) return -1;
    if (L == R) return n - sufarr[L];
    int k = log[R - L];
    return min(sparse[k][L], sparse[k][R - (1 << k)]);
}

inline void build_sparse(const vector<int>& lcp_) {
    for (int i = 0; i < n - 1; ++i) {
        sparse[0][i] = lcp_[i];
    }
    for (int k = 1; k < MAXLOG; ++k) {
        for (int i = 0; i + (1 << k) < n; ++i) {
            sparse[k][i] = min(sparse[k - 1][i], sparse[k - 1][i + (1 << k - 1)]);
        }
    }
}

int binSearch1(int pos, int len){
	int l = 0, r = pos;
	while (r - l > 1){
		int m = (l + r) / 2;
		cerr << m << ' ' << min_on_seg(m, pos + 1) << "!\n";
		if (min_on_seg(m, pos + 1) >= len)
			r = m;
		else
			l = m;
	}
	return r;
}
int main() {
	for (int i = 2; i < MAXN; ++i) {
        log[i] = log[i / 2] + 1;
    }
	string s, t;
	cin >> s >> t;
	string st = s + t;
	cerr << st.size() << '\n';
	s.pop_back();

	sufarr = build_sufarray(st);
	int n = st.size();
	for (int i = 0; i < n; i++)
		cerr << st.substr(sufarr[i]) << '\n';
	lcp_ = build_lcp(st, sufarr);
	for (int i = 0; i < n - 1; i++)
		cerr << lcp_[i] << " \n"[i == n - 2];
	vector<int> pos(n);
	build_sparse(lcp_);
	for (int i = 0; i < n; i++)
		pos[sufarr[i]] = i;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		l1--, r1--, l2--, r2--;
		cerr << pos[l1] << ' ';
		cerr << sufarr[binSearch1(pos[l1], r1 - l1 + 1)] << '\n';
	}
}