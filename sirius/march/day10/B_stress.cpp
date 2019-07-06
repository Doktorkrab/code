#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>
#include <chrono>
using namespace std;
 
const int MAXN = 1e5 + 7;
int n, t, k;
set<int> marks = {-1};
int free_sum = 0, ship_sum = 0;
int get_ship(int l, int r){
    return (r - l + 1) / (k + 1);
}
int get_free(int l, int r){
    int ships = get_ship(l, r);
    if ((r - l - ships * k - ships + 1) == 0)
        return ships * k;
    return max(0, (k - (r - l - ships * k - ships + 1))) * ships;
}
inline void smart_recalc(int x){
    if (marks.count(x))
        return;
    auto it = marks.upper_bound(x);
    int r = *it;
    --it;
    int l = (*it) + 1;
    marks.insert(x);
    cerr << get_ship(l, r) << ' ' << get_ship(l, x) << ' ' << get_ship(x + 1, r) << '\n';
    cerr << get_free(l, r) << ' ' << get_free(l, x) << ' ' << get_free(x + 1, r) << '\n';
    ship_sum -= get_ship(l, r);
    free_sum -= get_free(l, r);
    ship_sum += get_ship(l, x) + get_ship(x + 1, r);
    free_sum += get_free(l, x) + get_free(x + 1, r);
    // for (auto i : marks)
    //     cerr << i << ' ';
    // cerr << '\n';
}
inline int get_ans(){
    if (ship_sum > t)
        return 0;
    if (ship_sum < t)
        return -1;
    return free_sum;
}
inline bool smart_is_good(int x){
    if (marks.count(x))
        return 0;
    if (get_ans() == -1)
        return 1;
    auto it = marks.upper_bound(x);
    int r = *it;
    --it;
    int l = (*it) + 1;
    int ships = get_ship(l, r);
    int sf = r - l - ships * k - ships + 1;
    x -= sf + l;
    if (x < 0)
        return 0;
    int block = x / (k + 1);
    int start_block = (k + 1) * block;
    if (x - start_block < k - sf)
        return 1;
    return 0;
}
inline pair<int, int> solve_smart(int x = -1){
    if (x == -1){
        marks.insert(n);
        ship_sum = get_ship(0, n);
        free_sum = get_free(0, n);
        return {get_ans(), -1};
    }
    // for (int q = 0; q < n; q++){
        bool ans = smart_is_good(x);
        smart_recalc(x);
        if (ans){
            return {1, -1};
        }
        return {0, get_ans()};
 
    // }
}


int field[MAXN];
struct Block{
    int l, r, sz;
};
vector<Block> blocks;
inline int find_cells(){
    int ship_sum = 0;
    int block_size = 0;
    blocks.clear();
    for (int i = 0; i < n; i++){
        if (field[i]){
            if (block_size != 0)
                blocks.push_back({i - block_size, i, block_size});
            block_size = 0;
        }
        else
            block_size++;
    }
    if (block_size > 0)
        blocks.push_back({n - block_size, n, block_size});
    for (Block block : blocks)
        ship_sum += (block.sz + 1) / (k + 1);
    if (ship_sum < t)
        return -1;
    if (ship_sum > t)
        return 0;
    int cells = 0;
    for (Block block : blocks){
        // cerr << block.l << ' ' << block.sz << ' ' << block.r << '\n';
        cells += max(0, (k - (block.sz - (block.sz + 1) / (k + 1) * k - (block.sz + 1) / (k + 1) + 1)) * ((block.sz + 1) / (k + 1)));
    }
    return cells;
}
inline bool is_good(int x){
    int tmp = find_cells();
    if (tmp == 0)
        return 0;
    if (tmp == -1)
        return 1;
    for (Block block : blocks){
        if (!(block.l <= x && x < block.r))
            continue;
        int sf = block.sz - (block.sz + 1) / (k + 1) * k - (block.sz + 1) / (k + 1) + 1;
        return (x - sf - block.l) % (sf + 1) == 0;
    }
    return 0;
 
}
inline pair<int, int> solve_st(int x = -1){
    if (x == -1)
        return {find_cells(), -1};
    // for (int q = 0; q < n; q++){
        field[x] = 1;
        bool ans = is_good(x);
        int cnt = find_cells();
        if (ans){
            return {1, -1};
        }
        return {0, cnt};
    // }
}

 
int main(){
    mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
    // while (1){
        cout << "----------------------------------------";
        n = rnd() % 15 + 1;
        t = rnd() % 15 + 1;
        k = rnd() % 15 + 1;
        while (t * k + t - 1 > n){
            t = rnd() % 15 + 1;
            k = rnd() % 15 + 1;
        }
        cout << n << ' ' << t << ' ' << k << '\n';
        auto st = solve_smart();
        auto st1 = solve_st();
        cout << '\t';
        cout << st.first << "\n\t" << st1.first << '\n';
        if (st != st1)
            return 1;
        while (1){
            int x = rnd() % n;
            st = solve_st(x);
            st1 = solve_smart(x);
            cout << x + 1 << '\n';
            cout << '\t' << st1.first << ' ' << st1.second << '\n';
            cout << '\t' << st.first << ' ' << st.second << '\n';
            if (st != st1 || st1.first == 1)
                break;
        } 
        if (st != st1)
            return 1;
}