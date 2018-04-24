#include <bits/stdc++.h>
using namespace std;

unsigned read_ip(){
    unsigned a, b, c, d;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    return (a << 24) + (b << 16) + (c << 8) + d;
}

vector<vector<unsigned>> computer_raw;
vector<int> parent, dist, used;
int n;
void bfs(int s){
    deque<int> q = {s};
    dist[s] = 0;
    while (q.size()){
        int top = q.front();
        q.pop_front();
        if (used[top]) continue;
        used[top] = 1;
        for (int i = 0; i < computer_raw[top].size();i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k < computer_raw[j].size(); k++){
                    if (computer_raw[top][i] == computer_raw[j][k] && dist[top] + 1 < dist[j]){
                        q.push_back(j);
                        dist[j] = dist[top] + 1;
                        parent[j] = top;
                    }
                }
            }
        }
    }
}
int main(){
    cin >> n;
    computer_raw.resize(n);
    parent.assign(n, -1);
    dist.assign(n, 1e9);
    used.resize(n);
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        computer_raw[i].resize(k);
        // cout << computer_raw.size() << computer_raw[i].size() << '\n';
        for (int j = 0; j < k; j++){
            computer_raw[i][j] = read_ip() & read_ip();
        }
    }
    int s, t;
    cin >> s >> t;
    bfs(s - 1);
    if (dist[t - 1] == (int)1e9){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    t--, --s;
    vector<int> ans;
    while (t != s){
        ans.push_back(t + 1);
        t = parent[t];
    }
    ans.push_back(t + 1);
    reverse(ans.begin(), ans.end());
    for (int i : ans){
        cout << i << ' ';
    }
    cout << '\n';
}2