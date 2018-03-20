#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sqr(x) 1LL * x * x

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const double EPS = 1e-6;

struct Solver{
    int n, l, x, y, xt, yt;
    int scalar(int x, int y, int x1, int y1){
        return x * x1 + y * y1;
    }
    int vector1(int x, int y, int x1, int y1){
        return x * y1 - y * x1;
    }
    double angle(int x, int y, int x1, int y1){
        return atan2(1. * vector1(x, y, x1, y1), 1. * scalar(x, y, x1, y1));
    }
    double len(pair<int, int> x){
        
    }
    bool cmp(pair<int, int> a, pair<int, int> b){
        return 
    }
    Solver() {
        cin >> n >> l;
        l = sqrt(2.) * l; 
        cin >> x >> y;
        cout << "YES\n+";
        for (int i = 1;i < n;i++){
            cin >> xt >> yt;
            if (angle(x, y, xt, yt) < M_PI / 2) cout << "-", x -= xt, y -= yt;
            else cout << "+", x += xt, y += yt;
        }
        cout << '\n';
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