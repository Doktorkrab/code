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
#include "pancakes.h"

using namespace std;

int n, nodeId, numberNodes;

inline void init(){
	nodeId = MyNodeId();
	numberNodes = NumberOfNodes();
}
struct Query{
	int start, ans, finish;
};
void slave(){
	Receive(0);
	int l = GetInt(0);
	int r = GetInt(0);
	// fprintf(stderr, "Slave %d do a segment[%d, %d)\n", nodeId, l, r);
	int start = INT_MAX, finish = INT_MIN;
	int prev = -1;
	int ans = 0;
	for (int i = l; i < r; i++){
		int now = GetStackItem(i);
		// fprintf(stderr, "Slave %d do %d, prev is %d, ans is %d\n", nodeId, now, prev, ans);
		if (i == l) start = now;
		if (i == r - 1) finish = now;
		if (i != l && (prev > now)) ans++;
		prev = now;
	}
	// fprintf(stderr, "Ans for slave %d is (%d, %d, %d)\n", nodeId, start, ans, finish);
	PutInt(0, start);
	PutInt(0, ans);
	PutInt(0, finish);
	Send(0);
}

Query getQuery(int node){
	int a, b, c;
	a = GetInt(node);
	b = GetInt(node);
	c = GetInt(node);
	return {a, b, c};
}
void master(){
	n = GetStackSize();
	int toEach = n / numberNodes;
	// fprintf(stderr, "StackSize: %d, Nodes: %d, toEach:%d\n", n, numberNodes, toEach);
	int mod = n % numberNodes;
	int l = 0;
	for (int i = 0;i < numberNodes; i++){
		if (i == numberNodes - 1){
			PutInt(i, l);
			PutInt(i, n);
		}
		else {
			PutInt(i, l);
			PutInt(i, l += toEach + 1 * ((bool)max(0, mod--)));
		}
		Send(i);
	}
	slave();
	Receive(0);
	Query prev = getQuery(0);
	int ans = prev.ans + 1;
	for (int i = 1; i < numberNodes; i++){
		Receive(i);
		Query now = getQuery(i);
		ans += now.ans;
		if (prev.finish > now.start) ans++;
		prev = now;
	}
	cout << ans << '\n';
}

void solve(){
	init();
	if (nodeId == 0) master();
	else slave();
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