#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int main ()
{
    freopen("kek.in", "r", stdin);
    freopen("kek.out", "w", stdout);
    int a, b, c, d, ans = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    for (int i = 1; i * i <= b; i++){
//        cout << " " << i << endl;
        for (int j = (a + i - 1) / i; j * i  <= b; j++){
//            cout << "  " << j << endl;
            if (2 * (i + j) <= d && 2 * (i + j) >= c){
                ans++;
//              cout << "   " << ans << endl;
            }
        }
    }
    cout << ans;

}