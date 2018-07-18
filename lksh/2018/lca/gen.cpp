#include <bits/stdc++.h>

using namespace std;
vector<char> gg = {'+', '-', '?'};
int main(){
    srand(time(0));
    int m = rand() % 50 + 1;
    cout << m << '\n';
    int nxt = 2;
    unordered_set<int> now = {1};
    for (int i = 0;i < m; i++){
        if (now.size() == 1){
            cout << '+' << " 1" << '\n';
            now.insert(nxt++);
        }
        else{
            int ch = rand() % 3;
            // cerr << ch << '\n';
            if (ch == 0){
                int vertex = rand() % (now.size() - 1) + 1;
                auto ans = now.begin();
                // cerr << vertex << ' ' << now.size() << '\n';
                while (--vertex) ans++;
                cout << "+ " << *ans << '\n';
                now.insert(nxt);
                nxt++;
            }
            if (ch == 1){
                int a = rand() % (now.size() - 1) + 1;
                int b = rand() % (now.size() - 1) + 1;
                // cerr << a << ' ' << b << ' ' << now.size() << '\n';
                auto ans = now.begin(), ans1 = now.begin();
                while (--a) {
                    // cout << a << '\n';
                    ans++;
                
                }
                while (--b) ans1++;
                cout << "? " << *ans << ' ' << *ans1 << '\n';  
            }
            if (ch == 2){
                int a = rand() % (now.size() - 1) + 1;
                auto ans = now.begin();
                while(--a) ans++;
                cout << "- " << *ans << '\n';
                now.erase(ans);
            }
        }
    }
}