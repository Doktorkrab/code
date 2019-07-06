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
    int value;
    Node* nxt = nullptr;
    Node () {}
    Node (int val) : value(val) {}
};
vector<Node*> versions;
int n;

inline void init(){
    versions.clear();
}

inline void solve(){
    versions.push_back(new Node(0));
    for (int i = 0; i < n; i++){
        int t, m;
        cin >> t >> m;
        if (m == 0)
            versions.push_back(versions[t]->nxt);
        else {
            Node* now = new Node(m + versions[t]->value);
            now->nxt = versions[t];
            versions.push_back(now);
        }
    }
    int64_t ans = 0;
    for (auto i : versions)
        ans += i->value;
    cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}
