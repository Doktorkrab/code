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
#include "message.h"
#include "max.h"

using namespace std;

int n, nodeId, numberNodes;

inline void init(){
	nodeId = MyNodeId();
	numberNodes = NumberOfNodes();
}
void master(){
	n = GetN();
	// cerr << "master Founded: " << n << ' ' << numberNodes << ' ' << nodeId << '\n';
	if (numberNodes == 1){
		PutInt(0, 0);
		PutInt(0, n);
		Send(0);
		return;
	}
	int toOneNode = n / (numberNodes - 1);
	int l = 0;
	for (int i = 1; i < numberNodes; i++){
		if (i == numberNodes - 1){
			PutInt(i, l);
			PutInt(i, n);
			Send(i);
		}
		else {
			PutInt(i, l);
			PutInt(i, l += toOneNode);
			Send(i);
		}
	}
	int mx = 0;
	for (int i = 1; i < numberNodes; i++){
		Receive(i);
		mx = max(mx, GetInt(i));
	}
	cout << mx << '\n';
}
void slave(){
	Receive(0);
	int l = GetInt(0);
	int r = GetInt(0);
	// cerr << "Slave " << nodeId << " " << l << ' ' << r << '\n';
	int ans = 0;
	for (int i = l; i < r; i++){
		int tmp = GetElement(i);
		// cerr << "Slave " << nodeId << " testing " << tmp << '\n';
		ans = max(ans, tmp);
	}
	PutInt(0, ans);
	Send(0);
	// cerr << "Slave " << nodeId << " succeded " << ans << '\n';

}
inline void solve(){
	init();
	if (nodeId == 0){
		master();
	}
	if (nodeId > 0 || numberNodes == 1)
	slave();
	if (numberNodes == 1){
		Receive(0);
		cout << GetInt(0) << '\n';
	}
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