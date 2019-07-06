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
int cnt = 0;
bool query(string napr){
    cout << "move " << napr << endl;
    string s;
    cin >> s;
    return s == "found" || s == "win";
}
inline void solve(){
    string up = "north";
    string down = "south";
    string left = "west";
    string right = "east";
    if (query(up)){
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        query(down);
        query(up);
        return;
    }
    if (query(left)){
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        query(right);
        query(left);
        return;
    }
    if (query(down)){
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        query(up);
        query(down);
        return;
    }
    if (query(down)){
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        query(up);
        query(down);
        return;
    }
    if (query(right)){
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        query(left);
        query(right);
        return;
    }
    if (query(right)){
        cout << "echo kek" << endl;
        cout << "echo kek" << endl;
        query(left);
        query(right);
        return;
    }
    if (query(up)){
        cout << "echo kek" << endl;
        query(down);
        query(up);
        return;
    }
    if (query(up)){
        query(down);
        query(up);
        return;
    }
    query(left);
    query(down);
}


int main(){
    solve();
    
}
