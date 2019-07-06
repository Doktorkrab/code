#include <bits/stdc++.h>

using namespace std;
struct Decomposition{
    vector<int> arr;
    vector<int> blocks;
    int len;
    Decomposition(int len, const vector<int>& arr) : arr(arr), len(len){
        int n = arr.size();
        blocks.resize((n + len - 1) / len);
        int block = -1;
        for (int i = 0; i < n;i++){
            if (i % len == 0) block++;
            blocks[block] = max(blocks[block], arr[i]);
        }
    }

    void pull(int bl){
        blocks[bl] = -1;
        for (int i = 0; i < len && i + bl * len < (int)arr.size(); i++){
            blocks[bl] = max(blocks[bl], arr[i + bl * len]);
        }
    }   
};
int main(){
    int h, w, n;
    cin >> h >> w >> n;
    Decomposition dec = Decomposition(200, vector<int>(min(h, n), w));
    for (int j = 0;j < n;j++){
        int t;
        cin >> t;
        int kek = -1;
        for (int i = 0;i < (int)dec.blocks.size(); i++){
            if (t <= dec.blocks[i]){
                kek = i;
                break;
            }
        }
        if (kek == -1){
            cout << -1 << '\n';
            continue;
        }
        for (int i = kek * dec.len; i < (kek + 1) * dec.len; i++){
            if (t <= dec.arr[i]){
                cout << i + 1 << '\n';
                dec.arr[i] -= t;
                break;
            }
        }
        dec.pull(kek);
    }
}