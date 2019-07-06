#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <string>
#include <cassert>

using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int &i : arr) cin >> i;
    for (int i = 0; i < q; i++) {
        int l, r;
        char type;
        cin >> type >> l >> r;
        if (type == '!'){
            arr[l - 1] = r;
            continue;
        }
        --l;
        unordered_set<int> gg;
        for (int j = l; j < r; j++) gg.insert(arr[j]);
        int ans = 0;
        while (gg.count(ans)) ans++;
        cout << ans << " \n";
    }
}