#include <bits/stdc++.h>

using namespace std;
#define int long long

struct Decomposition{
    vector<vector<int>> blocks;
    vector<int> arr;
    vector<int> add;
    int BLOCK_SIZE;
    Decomposition(int BLOCK_SIZE, const vector<int>& arr) : arr(arr), BLOCK_SIZE(BLOCK_SIZE){
        int n = arr.size();
        blocks.resize((n + BLOCK_SIZE - 1) / BLOCK_SIZE);
        add.resize((n + BLOCK_SIZE - 1) / BLOCK_SIZE);
        int block = -1;
        for (int i = 0; i < n;i++){
            if (i % BLOCK_SIZE == 0) block++;
            blocks[block].push_back(arr[i]);
        }
        for (int i = 0;i < (int)blocks.size();i++){
            sort(blocks[i].begin(), blocks[i].end());
        }
    }
    void pull(int block){
        blocks[block].clear();
        int start = block * BLOCK_SIZE;
         for (int i = 0; i < BLOCK_SIZE && start + i < (int)arr.size();i++){
            blocks[block].push_back(arr[i + start]);
        }
        sort(blocks[block].begin(), blocks[block].end());
    }
    void push(int block){
        int start = block * BLOCK_SIZE;
        for (int i = 0; i < BLOCK_SIZE && start + i < (int)arr.size();i++){
            arr[i + start] += add[block];
        }
        add[block] = 0;
        pull(block);
    }
    int get(int l, int r, int x){
        int bl_l = l / BLOCK_SIZE;
        int bl_r = r / BLOCK_SIZE;
        push(bl_l);
        push(bl_r);
        int j = l, cnt = 0;
        for (; j <= min(r, BLOCK_SIZE * (bl_l + 1) - 1); j++){
            if (arr[j] < x) cnt++;
        }
        if (j > r) return cnt;
        for (int kek = bl_l + 1; kek < bl_r; kek++){
            cnt += (int)(lower_bound(blocks[kek].begin(), blocks[kek].end(), x - add[kek]) - blocks[kek].begin());
        }
        j = max(j, bl_r * BLOCK_SIZE);
        for (; j <= r; j++){
            if (arr[j] < x) cnt++;
        }
        return cnt;
    }

    void add_sum(int l, int r, int x){
        int bl_l = l / BLOCK_SIZE, bl_r = r / BLOCK_SIZE;
        push(bl_l);
        push(bl_r);
        int j = l;
        for (; j <= min(r, BLOCK_SIZE * (bl_l + 1) - 1); j++){
            arr[j] += x;
        }

        for (int kek = bl_l + 1; kek < bl_r; kek++){
            add[kek] += x;
        }
        j = max(j, bl_r * BLOCK_SIZE);
        for (; j <= r; j++){
            arr[j] += x;
        }
        pull(bl_l);
        pull(bl_r);
    }
};

signed main(){
    //freopen("stress.in", "r", stdin);
    //freopen("stress.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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