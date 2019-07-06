#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int q = 0;
    cin >> q;
    for (int i = -1; i < q; i++){
        int a = 1;
        int b = arr[0];
        if (i != -1)
            cin >> a >> b;
        --a;
        arr[a] = b;
        //cerr << a << ' ' << b << "!!!\n";
        int good = 1;
        for (int mask = 0; mask < (1 << 10); mask++){
            good = 1;
            for (int j = 0; j < n - 1; j++)
                good &= (arr[j] ^ mask) <= (arr[j + 1] ^ mask);
            if (good){
                cout << mask << '\n';
                break;
            }
        }
        if (!good)
            cout << "-1\n";
    }
}
