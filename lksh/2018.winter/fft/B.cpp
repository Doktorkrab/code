#include <bits/stdc++.h>

using namespace std;
using cd = complex<double>;

const int MAXLOG = 19;
const int MAXN = 1 << MAXLOG;
const double pi = acos(-1);
cd W[MAXN];
int rev[MAXN];

void precalc() {
    int last = 0;
    for (int i = 1; i < MAXN; i++) {
        if (i == (2 << last))
            last += 1;
        rev[i] = rev[i ^ (1 << last)] | (1 << (MAXLOG - 1 - last));
    }

    for (int i = 0; i < MAXN; i++)
        W[i] = {cos(2 * pi * i / MAXN), sin(2 * pi * i / MAXN)};
}

void fft(vector<cd> &a) {
    for (int i = 0; i < MAXN; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int lvl = 0; lvl < MAXLOG; ++lvl) {
        int len = (1 << lvl);
        for (int st = 0; st < MAXN; st += 2 * len)
            for (int i = 0; i < len; i++) {
                cd first = a[st + i];
                cd second = a[st + i + len] * W[i << (MAXLOG - (lvl + 1))];

                a[st + i] = first + second;
                a[st + i + len] = first - second;
            }
    }
}

void inv_fft(vector<cd> &a) {
    fft(a);
    for (cd &el : a)
        el /= MAXN;
    reverse(a.begin() + 1, a.end());
}

int main() {
    precalc();
    string s;
    cin >> s;
    vector<cd> polynom(MAXN);
    vector<int> polynom_orig(MAXN);
    for (int i = 0; i < (int) s.size(); i++)
        polynom[i] = polynom_orig[i] = s[i] - '0';
    fft(polynom);
    for (cd &el : polynom)
        el *= el;
    inv_fft(polynom);
    int64_t ans = 0;
    for (int i = 0; i < MAXN; i += 2) {
        if (polynom_orig[i / 2] == 1)
            ans += (round(polynom[i].real()) - 1) / 2;
    }
    cout << ans << '\n';
}