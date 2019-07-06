#include <bits/stdc++.h>

using namespace std;


struct Decomposition{
    vector<vector<int>> blocks;
    vector<int> arr;
    vector<int> add;
    int len;
    Decomposition(int len, const vector<int>& arr) : arr(arr), len(len){
        int n = arr.size();
        blocks.resize((n + len - 1) / len);
        add.resize((n + len - 1) / len);
        int block = -1;
        for (int i = 0; i < n;i++){
            if (i % len == 0) block++;
            blocks[block].push_back(arr[i]);
        }
        for (int i = 0;i < blocks.size();i++){
            sort(blocks[i].begin(), blocks[i].end());
        }
    }
    void pull(int block){
        blocks[block].clear();
        int start = block * len;
         for (int i = 0; i < len && start + i < (int)arr.size();i++){
            blocks[block].push_back(arr[i + start]);
        }
        sort(blocks[block].begin(), blocks[block].end());
    }
    void push(int block){
        int start = block * len;
        for (int i = 0; i < len && start + i < (int)arr.size();i++){
            arr[i + start] += add[block];
        }
        add[block] = 0;
    }
    int get(int l, int r, int x){
        int bl_l = l / len;
        int bl_r = r / len;
        push(bl_l);
        push(bl_r);
        int j = l, cnt = 0;
        for (; j <= min(r, len * (bl_l + 1) - 1); j++){
            if (arr[j] < x) cnt++;
        }
        if (j > r) return cnt;
        for (int kek = bl_l + 1; kek < bl_r; kek++){
            cnt += (int)(lower_bound(blocks[kek].begin(), blocks[kek].end(), x - add[kek]) - blocks[kek].begin());
        }
        j = max(j, bl_r * len);
        for (; j <= r; j++){
            if (arr[j] < x) cnt++;
        }
        return cnt;
    }

    void add_sum(int l, int r, int x){
        int bl_l = l / len, bl_r = r / len;
        push(bl_l);
        push(bl_r);
        int j = l;
        for (; j <= min(r, len * (bl_l + 1) - 1); j++){
            arr[j] += x;
        }

        for (int kek = bl_l + 1; kek < bl_r; kek++){
            add[kek] += x;
        }
        j = max(j, bl_r * len);
        for (; j <= r; j++){
            arr[j] += x;
        }
        pull(bl_l);
        pull(bl_r);
    }
};

int main(){
    ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    Decomposition dec = Decomposition(200, arr);
    for (int i = 0;i < q;i++){
        int query, l, r, x;
        cin >> query >> l >> r >> x;
        --l, --r;
        if (query == 1){
            cout << dec.get(l, r, x) << '\n';
        }
        if (query == 2){
            dec.add_sum(l, r, x);
        }
    }
}