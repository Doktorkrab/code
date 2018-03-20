/*Ребята, не стоит вскрывать эту тему. 
Вы молодые, шутливые, вам все легко. 
Это не то. Это не Чикатило и даже не архивы спецслужб. 
Сюда лучше не лезть. Серьезно, любой из вас будет жалеть. 
Лучше закройте тему и забудьте, что тут писалось. 
Я вполне понимаю, что данным сообщением вызову дополнительный интерес, но хочу сразу предостеречь пытливых - стоп. 
Остальные просто не найдут.*/
#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
vector<vector<unsigned int>> mul(vector<vector<unsigned int>> const& A, vector<vector<unsigned int>> const& B, int module){
    unsigned int n = A.size(), m = B[0].size();
    vector<vector<unsigned int>> ret(n, vector<unsigned int>(m));
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int k = 0; k < (unsigned int) B.size(); k++){
            for (unsigned int j = 0; j < m; j++){
                ret[i][j] += ((long long) A[i][k] * B[k][j]) % module;
                ret[i][j] %= module;
            }
        }
    }
    return ret;
}


vector<vector<unsigned int>> I
vector<vector<unsigned int>> pow(vector<vector<unsigned int>>& A, int power){
    auto res = I;
    while (power) {
        if (power & 1)
            res = mul(res, A, MOD);
        A = mul(A, A, MOD);
        power >>= 1;
    }
    return res;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int k;
            cin >> k;
            g[i][j] = k - 1;
        }
    }
    string s;
    cin >> s;
    vector<bool> now(n, 1);
    for (char c : s){
        vector<bool> go_to(n, 0);
        for (int i = 0; i < n; i++){
            if (!now[i]) continue;
            go_to[g[i][c - 'a']] = 1;
        }
        // for (int i : go_to) cout << i << ' ';
        // cout << '\n';
        swap(now, go_to);
    }
    int ans = 0;
    for (int i : now) ans += i;
    // cerr << ans << '\n';
    if (ans == 1) cout << "YES\n" << 1 << ' ' << s.size() << '\n';
    else cout << "NO\n";
}