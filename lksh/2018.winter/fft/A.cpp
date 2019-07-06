#include <bits/stdc++.h>


using namespace std;

//const int MAXN = 3;
const int BASE = 1e1;
const int BASELEN = 1;
const double pi = acos(-1);
const int MAXLOG = 19 - (int) floor(log(BASELEN) / log(2));
const int MAXN = 1 << MAXLOG;
vector<complex<double>> root(MAXN);
vector<int> rev(MAXN);

void fft(const vector<complex<double>> &a, vector<complex<double>> &res) {
    for (int i = 0; i < MAXN; i++) {
        res[rev[i]] = a[i];
    }
    for (int k = 1; k < MAXN; k *= 2) {
        for (int i = 0; i < MAXN; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                auto tmp = root[k + j] * res[k + j + i];
                res[i + j + k] = res[i + j] - tmp;
                res[j + i] = res[i + j] + tmp;
            }
        }
    }

}

int main() {
    string s, t;
    cin >> s >> t;
    int res1 = 1;
    if (s[0] == '-') {
        res1 *= -1;
        string tmp;
        for (int i = 1; i < s.size(); i++)
            tmp += s[i];
        s = tmp;
    }
    if (t[0] == '-') {
        res1 *= -1;
        string tmp;
        for (int i = 1; i < t.size(); i++)
            tmp += t[i];
        t = tmp;
    }
    root.resize(s.size() + t.size() + 20);
    for (int k = 1; k < MAXN; k *= 2) {
        root[k] = {1, 0};
        for (int i = 0; i < k; i++) {
            root[i + k] = {cos(pi * i / k), sin(pi * i / k)};
        }
    }
    for (int i = 0; i < MAXN; i++) {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (MAXLOG - 1));
    }
    vector<complex<double>> a(MAXN), b(MAXN);
    int pnt = 0;
    int x = 1;
    while (!s.empty()) {
        a[pnt] += x * (s.back() - '0');
        s.pop_back();
        x *= 10;
        if (x == BASE)
            pnt++, x = 1;
    }
    pnt = 0, x = 1;
    while (!t.empty()) {
        b[pnt] += x * (t.back() - '0');
        t.pop_back();
        x *= 10;
        if (x == BASE)
            pnt++, x = 1;
    }
    vector<complex<double>> fa(MAXN), fb(MAXN), tmp(MAXN);
    fft(a, fa);
    fft(b, fb);
    for (int i = 0; i < MAXN; i++)
        tmp[i] = fa[i] * fb[i];

    fft(tmp, fa);
    reverse(fa.begin() + 1, fa.end());

    int i;
    vector<int64_t> res(MAXN);
    for (int i = 0; i < MAXN; i++) {
        res[i] += (int64_t) (fa[i].real() / MAXN + 0.5);
        if (res[i] >= BASE)
            res[i + 1] += res[i] / BASE, res[i] %= BASE;
    }
    for (i = MAXN - 1; i > 0 && res[i] == 0; --i) {}
    if (res1 == -1)
        cout << '-';
    printf("%d", res[i--]);
    for (; i >= 0; --i)
        printf("%0*d", BASELEN, res[i]);
    printf("\n");
}