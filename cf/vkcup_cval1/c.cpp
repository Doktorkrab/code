#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sqr(x) 1LL * x * x

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct project{
    string name;
    int ver;
    vector<int> deps;
};

struct Node{
    bool is_terminal = false; // if word ends here
    map<char, Node*> edges;
};
Node* root = new Node();
struct Solver{
    vector<project> projects;
    map<pair<string, int>, int> ids;
    map<string, int> ans;
    int id_start = -1, n;
    void bfs(){
        unordered_map<string, pii> cur_level;
        cur_level[projects[id_start].name] = {projects[id_start].ver, id_start};
        while(cur_level.size()){
            unordered_map<string, pii> new_level;
            for (auto u : cur_level){
                if (ans.count(u.first)) continue;
                ans[u.first] = u.second.first;
                for (auto w : projects[u.second.second].deps){
                    auto new_prj = projects[w];
                    if (ans.count(new_prj.name)) continue;
                    if (new_level.count(new_prj.name) && new_level[new_prj.name].first > new_prj.ver) continue;
                    new_level[new_prj.name] = {new_prj.ver, w};
                }
            }
            swap(cur_level, new_level);

        }

    }
    int add(string s, int t){
        if (ids.count({s, t})) return ids[{s, t}];
        ids[{s, t}] = projects.size();
        projects.push_back({s, t, {}});
        return projects.size() - 1;
    }
    Solver() {
        cin >> n;
        for (int i = 0;i < n;i++){
            string s;
            int t;
            cin >> s >> t;
            int id = add(s, t);
            if (id_start == -1) id_start = id;
            int m;
            cin >> m;
            for (int j = 0;j < m;j++){
                string s_1;
                int t_1;
                cin >> s_1 >> t_1;
                int tmp = add(s_1, t_1);
                projects[id].deps.push_back(tmp);
            }
        }
        bfs();
        cout << ans.size() - 1 << '\n';
        for (auto u : ans){
            if (u.first != projects[id_start].name) cout << u.first << ' ' << u.second << '\n';
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int t = 1;
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    cin >> t;
    #endif
    while(t--) Solver a;
}