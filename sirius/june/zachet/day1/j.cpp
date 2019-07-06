#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string left;
    int pos;
    for (pos = 0; pos < n; pos++) {
        if (s[pos] == '=') break;
        left += s[pos];
    }
    int lft = stoi(left);
    vector<int> seq;
    string tmp;
    for (int i = pos + 1; i < n; i++) {
        if (s[i] == '+') {
            seq.push_back(stoi(tmp));
            tmp.clear();
        } else tmp += s[i];
    }

    if (tmp.size()) seq.push_back(stoi(tmp));

    if (lft == seq[0]) {
        cout << "No solution\n";
        return 0;
    }

    int ind = ((int) seq.size()) - 2;
    if (seq[ind + 1] - seq[ind] > 1) {
        int tmp = seq[ind + 1] - 1;
        seq[ind]++;
        seq.pop_back();
        while(tmp >= seq[ind]) seq.push_back(seq[ind]), tmp -= seq[ind];
        if (tmp) seq.back() += tmp;

    } else {
        seq[ind] += seq.back();
        seq.pop_back();
    }
    cout << lft << "=";
    for (int i = 0; i < seq.size(); i++) cout << seq[i] << "+\n"[i + 1 == seq.size()];
}