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
struct Node{
	vector<int> go;
	bool is_terminal = 0;
	Node () : go(255, -1) {}
};

string s, t;
int pos = 0;
vector<Node> automaton;
pair<int, int> build1(const string& s){
	 if (isalpha(s[pos])){
	 	int startId = automaton.size();
	 	automaton.emplace_back();
	 	int endId = automaton.size();
	 	automaton.emplace_back();
	 	automaton[startId].go[s[pos]] = endId;
	 	return {startId, }
	 }	

}

inline void solve(){

}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> s >> t)
        solve();

}