#include <bits/stdc++.h>


using namespace std;

unordered_set<string> kek;
string s;
int n;
string now;
inline int check(string s){
    if (s[0] == '0')
        return 0;
    int gg = stoi(s);
    return ('a' <= gg && gg <= 'z') || ('A' <= gg && gg <= 'Z');
}
void rec(int pos, char d){
    if (pos == n){
        kek.insert(now);
        return;
    }
    string tmp;
    for (int i = 0; i < 3; i++)
        tmp += s[pos + i];
    if (check(tmp)){
        now.push_back((char) (stoi(tmp)));
        rec(pos + 3, d);
        now.pop_back();
    }
    string tmp1(2, 'a');
    if (tmp[0] == d){
        tmp1[0] = tmp[1];
        tmp1[1] = tmp[2];
        if (check(tmp1)){
            now.push_back((char) (stoi(tmp1)));
            rec(pos + 3, d);
            now.pop_back();
        }
    }
    if (tmp[1] == d){
        tmp1[0] = tmp[0];
        tmp1[1] = tmp[2];
        if (check(tmp1)){
            now.push_back((char) (stoi(tmp1)));
            rec(pos + 3, d);
            now.pop_back();
        }
    }
    if (tmp[2] == d){
        tmp1[0] = tmp[0];
        tmp1[1] = tmp[1];
        if (check(tmp1)){
            now.push_back((char) (stoi(tmp1)));
            rec(pos + 3, d);
            now.pop_back();
        }
    }
}

int main(){
    cin >> s;
    n = s.size();
    for (char c = '0'; c <= '9'; c++)
        rec(0, c);
    cout << kek.size() << '\n';
}
