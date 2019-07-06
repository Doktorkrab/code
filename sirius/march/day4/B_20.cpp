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

using namespace std;

int n;
unordered_map<string, string> gg = {{"a", "0\na"}, 
								 {"b", "0\nb"},
								 {"aa", "0\naa"},
								 {"ab", "1\naba"},
								 {"ba", "1\naba"},
								 {"bb", "0\nbb"},
								 {"aaa", "0\naaa"},
								 {"aab", "1\nbaab"},
								 {"aba", "0\naba"},
								 {"abb", "1\nabba"},
								 {"baa", "1\nbaab"},
								 {"bab", "0\nbab"},
								 {"bba", "1\nabba"},
								 {"bbb", "0\nbbb"},
								 {"aaaa", "0\naaaa"},
								 {"aaab", "1\nbaaab"},
								 {"aaba", "1\nababa"},
								 {"aabb", "2\nbbaabb"},
								 {"abaa", "1\naabaa"},
								 {"abab", "1\nababa"},
								 {"abba", "0\nabba"},
								 {"abbb", "1\nabbba"},
								 {"baaa", "1\nbaaab"},
								 {"baab", "0\nbaab"},
								 {"baba", "1\nbabab"},
								 {"babb", "1\nbbabb"},
								 {"bbaa", "2\nbbaabb"},
								 {"bbab", "1\nbbabb"},
								 {"bbba", "1\nabbba"},
								 {"bbbb", "0\nbbbb"}};
string s;
inline void init(){
}

inline void solve(){
	cin >> s;
	// cerr << gg.size() << '\n';
	// for (auto i : gg){
	// 	cerr << i.first << " " << i.second << '\n';
	// }
	cout << gg[s] << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B_20.in", "r", stdin);
		freopen("B_20.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
        solve();

}