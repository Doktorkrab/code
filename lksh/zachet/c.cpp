#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> g(max(a, max(b, c)) + 1);
    g[0] = g[1] = 0;
    for (int i = 2; i <= max(a, max(b, c)); i++){
        unordered_set<int> kek;
        for (int j = i / 2 + i % 2; j < i; j++){
            kek.insert(g[j]);
        }
        int j = 0;
        while (1){
            if (!kek.count(j)){
                g[i] = j;
                break;
            }
            j++;
        }
    }
    if ((g[a] ^ g[b] ^ g[c]) == 0){
        cout << "NO\n";
        return 0;
    }
    for (int i = a / 2 + a % 2; i < a; i++){
        if ((g[i] ^ g[b] ^ g[c]) == 0){
            cout << "YES\n";
            cout << i << ' ' << b << ' ' << c << '\n';
            return 0;
        }
    }
    for (int i = b / 2 + b % 2; i < b; i++){
        if ((g[a] ^ g[i] ^ g[c]) == 0){
            cout << "YES\n";
            cout << a << ' ' << i << ' ' << c << '\n';
            return 0;
        }
    }
    for (int i = c / 2 + c % 2; i < c; i++){
        if ((g[a] ^ g[b] ^ g[i]) == 0){
            cout << "YES\n";
            cout << a << ' ' << b << ' ' << i << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}