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
const int MAXN = 1e3 + 7;
int n;
const int OPEN = 1, CLOSE = -1;
struct Event{
    int type, id;
    bool operator<(const Event& oth) const {
        return tie(type, id) < tie(oth.type, oth.id);
    }
};
vector<Event> hori[MAXN][MAXN];
vector<Event> vert[MAXN][MAXN];
set<int> not_feeded_hori[MAXN]; 
set<int> not_feeded_vert[MAXN];
set<int> hori_now[MAXN];
set<int> vert_now[MAXN];
inline void solve(){
    for (int i = 0; i < n; i++){
        int xgg, ygg, xhh, yhh;
        cin >> xgg >> ygg >> xhh >> yhh;
        int x1 = min(xgg, xhh);
        int x2 = max(xgg, xhh);
        int y1 = min(ygg, yhh);
        int y2 = max(ygg, yhh);
        if (x1 == x2){
            vert[x1][y1].push_back({OPEN, i});
            vert[x2][y2].push_back({CLOSE, i});
        }
        if (y1 == y2){
            hori[x1][y1].push_back({OPEN, i});
            hori[x2][y2].push_back({CLOSE, i});
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            for (auto e : hori[i][j]){
                if (e.type == OPEN){
                    cerr << "\t" << e.id + 1 << '\n';
                    hori_now[i].insert(e.id);
                    not_feeded_hori[i].insert(e.id);
                }
            }
            for (auto e : vert[i][j]){
                if (e.type == OPEN){
                    cerr << "\t" << e.id + 1 << '\n';
                    vert_now[j].insert(e.id);
                    not_feeded_vert[j].insert(e.id);
                }
            }
            int ind_vert = 0x3f3f3f3f;
            if (!not_feeded_vert[j].empty())
                ind_vert = *(not_feeded_vert[j].begin());
            int ind_hori = 0x3f3f3f3f;
            if (!not_feeded_hori[i].empty())
                ind_hori = *(not_feeded_hori[i].begin());
            if (ind_hori < ind_vert && *(hori_now[i].begin()) == ind_hori){
                not_feeded_hori[i].erase(ind_hori);
                cerr << ind_hori + 1 << '\n';
                ans.push_back({i, j});   
            }
            if (ind_vert < ind_hori && *(vert_now[j].begin()) == ind_vert){
                not_feeded_vert[j].erase(ind_vert);
                cerr << ind_vert + 1 << '\n';
                ans.push_back({i, j});
            }

            for (auto e : hori[i][j]){
                if (e.type == CLOSE){
                    cerr << "\t" << e.id + 1 << ' ' << not_feeded_vert[j].count(e.id) << '\n';
                    if (not_feeded_hori[i].count(e.id)){
                        cout << "0\n";
                        return;
                    }
                    hori_now[i].erase(e.id);
                }
            }
            for (auto e : vert[i][j]){
                if (e.type == CLOSE){
                    cerr << "\t" << e.id + 1 << ' ' << not_feeded_vert[j].count(e.id) << '\n';
                    if (not_feeded_vert[j].count(e.id)){
                        cout << "0\n";
                        return;
                    }
                    vert_now[j].erase(e.id);
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto i :ans)
        cout << i.first << ' ' << i.second << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#else
        freopen("flashmob.in", "r", stdin);
        freopen("flashmob.out", "w", stdout);
    #endif
    
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}