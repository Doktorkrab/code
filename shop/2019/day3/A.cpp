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

string to_string(const string& s){
    return s;
}
template<typename T>
string to_string(const vector<T>& vec){
    string res;
    res += '{';
    bool is_first = 1;
    for (const T& i : vec){
        if (!is_first)
            res += ", ";
        res += to_string(i);
    }
    res += '}';
    return res;
}

void prn(){
    cout << '\n';
}
template<typename T, typename... Ts>
void prn(const T& t, const Ts&... ts){
    cout << to_string(t) << ' ';
    prn(ts...);

}
#ifdef DEBUG
    template<typename T, typename... Ts>
    void deb() {}
    template<typename T, typename... Ts>
    void deb(const T& t, const Ts&... ts){}
#else
    void deb(){
        cerr << '\n';
    }
    template<typename T, typename... Ts>
    void deb(const T& t, const Ts&... ts){
        cerr << to_string(t) << ' ';
        deb(ts...);
    }
#endif

int n;

inline void init(){

}

inline void solve(){

}


int main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}