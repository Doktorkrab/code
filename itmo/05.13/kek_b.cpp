#include <iostream>
#include <unordered_map>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;

int check(int x, int cnt) {
    unordered_map<int, int> kek;
    int old = x;
    for (int f = 2; f * f <= old; f++) {
        while (x % f == 0) {
            kek[f]++;
            if (kek[f] == cnt)
                return f;
            x /= f;
        }
    }
    if (x > 1) {
        kek[x]++;
        if (kek[x] == cnt)
            return x;
    }
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    clock_t start_t = clock();
    for (int start = 1; start < 1000; start++) {
        int good = 1;
//        if (fabs(clock() - start_t) / 1. / CLOCKS_PER_SEC > 1.95){
//            cout << "No Solution\n";
//            return 0;
//        }
        for (int gg = 0; gg < n; gg++) {
            if (!check(start + gg, k)) {
                good = 0;
                break;
            }
        }
        if (good) {
            cout << start << '\n';
//            for (int gg = 0; gg < n; gg++)
//                cout << check(start + gg, k) << '\n';
//            break;
        }
    }
}