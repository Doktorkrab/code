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

using namespace std;

int n;

inline void init(){

}
int check(vector<string> &arr, char c){
    for (int i = 0; i < 3; i++){
        int sum = 0;
        for (int j = 0; j < 3; j++){
            sum += arr[i][j] == c;
        }
        if (sum == 3)
            return 1;
        sum = 0;
        for (int j = 0; j < 3; j++)
            sum += arr[j][i] == c;
        if (sum == 3)
            return 1;
    }
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum += arr[i][i] == c;
    if (sum == 3)
        return 1;
    sum = 0;
    for (int i = 0; i < 3; i++)
        sum += arr[i][2 - i] == c;
    return sum == 3;
}
string ch = "xo";
vector<int> minimax(vector<string> &state, int depth, int player){
    vector<int> best = {-1, -1, (int)1e9};
    if (!player)
        best.back() *= -1;
    if (depth == 0 || check(state, ch[0]) || check(state, ch[1])){
        if (check(state, ch[0]))
            return {-1, -1, +1};
        if (check(state, ch[1]))
            return {-1, -1, -1};
        return {-1, -1, 0};
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++){
            if (state[i][j] != '.')
                continue;
            state[i][j] = ch[player];
            auto score = minimax(state, depth - 1, player ^ 1);
            state[i][j] = '.';
            score[0] = i;
            score[1] = j;
            if (player == 0){
                if (score[2] > best[2])
                    best = score;
            } else {
                if (score[2] < best[2])
                    best = score;
            }
        }
    return best;
}
inline void solve(){
    vector<string> end(3, string(3, 'x'));
    while (1){
        vector<string> arr(3);
        for (string& i : arr)
            cin >> i;
        if (arr == end)
            break;
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cnt += arr[i][j] == '.';
        auto gg = minimax(arr, cnt, 0);
        arr[gg[0]][gg[1]] = 'x';
        for (auto i : arr)
            cout << i << endl;
    }
}


int main(){
        solve();

}
