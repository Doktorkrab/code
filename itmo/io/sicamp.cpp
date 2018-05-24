#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>

using namespace std;

int ml = 1000000000, cnt = 0;


int main() {
    //freopen("queue.in", "r", stdin);
    //freopen("queue.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <int> lst2;
    for (int i = 0; i < n + m; i++) {
        int x;
        cin >> x;
        lst2.push_back(x);
    }
    int d;
    cin >> d;
    if (m == 1) {
        int ind, mn = 1000000000;
        for (int i = 0; i < n + m; i++)
            if (lst2[i] < mn){
                mn = lst2[i];
                ind = i;
            }
        cout << mn << '\n' << ind + 1;
        return 0;
    }
    if (m == 0){
        cout << 0;
        return 0;
    }

    vector <vector <int> > lst(m);
    vector <vector <pair <int, int>>> prev(m);
    lst[0].push_back(lst2[0]);
    prev[1].push_back(make_pair(0, 0));
    pair <int, int> x = make_pair(0, 0);
    cerr << "here\n";
    for (int i = 1; i < n + m; i++){
        lst[0].push_back(min(lst[0][i - 1] + d, lst2[i]));
        if (lst[0][i] == lst2[i])
            prev[1][i] = x, x = make_pair(0, i);
        else
            prev[1][i] = x;
        // cout << prev[1][i].first << "     " << prev[1][i].second <<  endl;
    }
    int ind = -1, xn = 1000000000;
    for (int i = 1; i < m; i++){
        for (int j = 0; j < i; j++) {
            lst[i].push_back(1000000000);
            prev[i].push_back(make_pair(-1, -1));
        }
        int mn = lst[i - 1][0];
        pair <int, int> ind2 = make_pair(i - 1, 0);
        for (int j = i; j <= n + i; j++){
            if (mn + d < lst[i - 1][j - 1])
                mn += d;
            else {
                ind2 = make_pair(i - 1, j - 1);
                mn = lst[i - 1][j - 1];
            }
            if (j != i)
                lst[i].push_back(min(lst[i][j - 1] + d + lst2[j], mn + lst2[j]));
            else
                lst[i].push_back(lst[i - 1][j - 1] + lst2[j]);

            if (i > 1){
                if (lst[i][j] == lst[i - 1][j - 1] + lst2[j])
                    prev[i].push_back(make_pair(i - 1, j - 1));
                else if (lst[i][j] == mn + lst2[j])
                    prev[i].push_back(ind2);
                else
                    prev[i].push_back(prev[i][j - 1]);
            }
            cout << prev[i][j].first << ", " << prev[i][j].second << ' ' << i << ' ' << j << endl;
            if (i == m - 1 && lst[i][j] < xn){
                ind = j;
                xn = lst[i][j];
            }
        }
    }
    cout << xn << endl;
    pair <int, int> cur = prev[m - 1][ind];
    vector <int> ans;
    ans.push_back(ind + 1);

    while (cur.first != 0){
        ans.push_back(cur.second + 1);
        cur = prev[cur.first][cur.second];
    }

    for (int i = m; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}