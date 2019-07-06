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

const int MAXN = 1e7 + 7;
int n;
string s;
int used[MAXN];
int kek[MAXN];
inline void init(){
    n = s.size();
}

inline void solve(){
    init();
    vector<int> stack;
    for (int i = 0; i < n; i++){
        if (s[i] == '(')
            stack.push_back(i);
        if (s[i] == ')' && stack.size()){
            used[i] = 1;
            kek[i] = -1;
            used[stack.back()] = 1;
            kek[stack.back()] = -1;
            stack.pop_back();
        }
    }
    int cur_block = 0;
    int start = 0;
    string t;
    for (int i = 0; i < n; i++)
        if (!used[i]) {
            kek[i] = t.size();
            t += s[i];
        }
    n = t.size();
    int open = n;
    for (int i = 0; i < n; i++)
        if (t[i] == '('){
            open = i;
            break;
        }
    int status = 0;
    for (int i = 0; i < open; i++){
        if (t[i] == '?'){
            if (cur_block == 0)
                start = i;
            cur_block++;
            continue;
        }
        int cnt = 0;
        while (i < n){
            if (t[i] != ')')
                break;
            cnt++;
            i++;
        }
        --i;
        char anti = '(';
        while (cur_block > 0 && cnt > 0){
            t[start++] = anti;
            cur_block--;
            cnt--;
        }
        if (cur_block & 1){
            if (status)
                t[start++] = ')';
            else
                t[start++] = '(';
            status ^= 1;
            cur_block--;
        }
        int ds = (cur_block - cnt) / 2;
        for (int j = 0; j < ds; j++){
            t[start] = '(';
            t[start + 1] = ')';
            cur_block -= 2;
            start += 2;
        }
    }
    if (cur_block & 1){
        if (status)
            t[start++] = ')';
        else
            t[start++] = '(';
        status ^= 1;
        cur_block--;
    }
    int ds = cur_block / 2;
    while (ds > 0){
        t[start++] = '(';
        t[start++] = ')';
        cur_block -= 2;
        --ds;
    }
    for (int i = open; i < n; i++){
        if (t[i] == '('){
            if (cur_block == 0)
                start = i;
            cur_block++;
            continue;
        }
        int cur = i;
        while (t[i] == '?')
            i++;
        int cnt = i-- - cur;
        while (cnt > 0 && cur_block > 0){
            t[cur++] = ')';
            cnt--;
            cur_block--;
        }
        if (cnt & 1){
            if (status)
                t[cur++] = ')';
            else
                t[cur++] = '(';
            status ^= 1;
            cnt--;
        }
        int ds = cnt / 2;
        for (int j = 0; j < ds; j++){
            t[cur++] = '(';
            t[cur++] = ')';
            cnt -= 2;
        }
    }
    for (int i = 0; i < s.size(); i++)
        if (kek[i] == -1)
            cout << s[i];
        else
            cout << t[kek[i]];
    cout << '\n';
}


int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
        solve();

}
