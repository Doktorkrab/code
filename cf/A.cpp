




#include <iostream>

#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

#define int int64_t
int32_t main(){
    int n, a, b;
    cin >> n >> a >> b;
    set<pair<int, int>> setik;

    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++) {
            setik.insert({(j + (j / b)) % a, j % b});
//            cerr << j << ' ' << (i + (i / b)) % a << ' ' << i % b << '\n';
        }
    }
    cout << setik.size() << '\n';
}
