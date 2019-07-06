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

int h1, m1, h2, m2;

inline void init(){

}

inline void solve(){
	int time1 = h1 * 60 + m1;
	int time2 = h2 * 60 + m2;
	int time = (time2 - time1);
	if (time1 < time2) time += 24 * 60;
	while(time < 0)
		time += 24*60;
	printf("%02d:%02d\n", time / 60, time % 60);
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);
    cerr << "hrer";
	solve();

}