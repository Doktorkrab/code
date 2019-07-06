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
#include <climits>
#include <complex>
#include "message.h"
#include "rps.h"

using namespace std;

int n, nodeId, numberNodes;

inline void init(){
	nodeId = MyNodeId();
	numberNodes = NumberOfNodes();
}
bool started = 1;
int iter = 0;

void slave(){
	Receive(0);
	int l = GetInt(0);
	int r = GetInt(0);
	// fprintf(stderr, "Slave %d: [%d;%d)\n", nodeId, l, r);
	vector<int> ans(r - l);
   	for (int i = l; i < r; i++)
		ans[i - l] = i;
	while (ans.size() > 1){
		// cerr << "here\n";
		vector<int> tmp;
		for (int i =0; i < ans.size(); i += 2){
			// cerr << i << '\n';
			int a = ans[i];
			int b = ans[i + 1];
			// cerr << i + 1 <<'\n';
			char cA = GetFavoriteMove(a);
			char cB = GetFavoriteMove(b);
			if (cA == 'R' && (cB == 'R' || cB == 'S')){
				tmp.push_back(a);
				continue;
			}
			if (cA == 'S' && (cB == 'S' || cB == 'P')){
				tmp.push_back(a);
				continue;
			}
			if (cA == 'P' && (cB == 'P' || cB == 'R')){
				tmp.push_back(a);
				continue;
			}
			tmp.push_back(b);
		}
		// cerr << ans.size() << ' ' << tmp.size() << '\n';
		ans.swap(tmp);
		// cerr << "herewewewe\n";
	}
	// cerr << "lol";
	PutInt(0, ans.size());
	for (int i : ans)
		PutInt(0, i);
	Send(0);
}
void master(){
	n = GetN();
	int l = 0;
	int toEach = (1 <<  n) / numberNodes;
	for (int i = 0; i < numberNodes; i++){
		if (i == 0){
			PutInt(i, 0);
			PutInt(i, l = toEach + (1 << n) % numberNodes);
		}
		else {
			PutInt(i, l);
			PutInt(i, l += toEach);
		}
		Send(i);
	}
	slave();
	vector<int> ans;
	for (int i = 0; i < numberNodes; i++){
		Receive(i);
		int cnt = GetInt(i);
		for (int j = 0; j < cnt; j++){
			ans.push_back(GetInt(j));
		}
	}
	while (ans.size() > 1){
		vector<int> tmp;
		for (int i =0; i < ans.size(); i += 2){
			int a = ans[i];
			int b = ans[i + 1];
			char cA = GetFavoriteMove(a);
			char cB = GetFavoriteMove(b);
			if (cA == 'R' && (cB == 'R' || cB == 'S')){
				tmp.push_back(a);
				continue;
			}
			if (cA == 'S' && (cB == 'S' || cB == 'P')){
				tmp.push_back(a);
				continue;
			}
			if (cA == 'P' && (cB == 'P' || cB == 'R')){
				tmp.push_back(a);
				continue;
			}
			tmp.push_back(b);
		}
		swap(ans, tmp);
	}
	cout << ans[0] << '\n';
}

void solve(){
	init();
	if (nodeId == 0)
		master();
	else
		slave();
}
int main(){
	// #ifdef LOCAL
	// 	freopen(".in", "r", stdin);
	// 	freopen(".out", "w", stdout);
	// #endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();

}