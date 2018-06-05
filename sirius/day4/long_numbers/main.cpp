#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll base_for_read = 1e1;
const ll base_for_read_size = 1;


struct Number {
    vector<ll> num;
    bool sign = 0;
    ll base = base_for_read;

//    ll base_size = base_for_read_size;
    Number(const string &s_first) {
        vector<ll> tmp;
        string cur;
        string s;
        bool is_first = 1;
        for (auto c : s_first) {
            if (c != '0' || !is_first) s += c, is_first = 0;
        }
        if (!s.size()) s = '0';
        int first_block = s.size() % base_for_read_size;
        int pos = 0;
        if (first_block) {
            for (; pos < first_block; pos++) {
                cur += s[pos];
            }
            tmp.push_back(stoll(cur));
            cur = "";
        }
        for (int i = pos; i < s.size(); i++) {
            cur += s[i];
            if (cur.size() == base_for_read_size) {
                tmp.push_back(stoul(cur));
                cur = "";
            }
        }
        reverse(tmp.begin(), tmp.end());
        num = tmp;
    }

    Number(ll x) : Number(to_string(x)) {}

    Number() {}

    int compareTo(const Number &oth) const {
        if (oth.num.size() > num.size()) return -1;
        if (oth.num.size() < num.size()) return 1;
        for (int i = num.size() - 1; i >= 0; i--) {
            if (num[i] < oth.num[i]) return -1;
            if (num[i] > oth.num[i]) return 1;
        }
        return 0;
    }

    bool operator<(const Number &oth) const {
        return compareTo(oth) == -1;
    }

    bool operator>(const Number &oth) const {
        return compareTo(oth) == 1;
    }

    bool operator==(const Number &oth) const {
        return compareTo(oth) == 0;
    }

    bool operator!=(const Number &oth) const {
        return !(*(this) == oth);
    }

    friend istream &operator>>(istream &is, Number &num) {
        string tmp;
        is >> tmp;
        Number tmp1(tmp);
        num = tmp1;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Number &Num) {
        if (Num.sign) {
            cout << '-';
        }
        for (int i = Num.num.size() - 1; i >= 0; i--) {
            if (i != Num.num.size() - 1) os << setw(base_for_read_size) << setfill('0') << abs(Num.num[i]);
            else os << Num.num[i];
        }
        return os;
    }

    Number operator+(const Number &oth) const {
        Number c;
        c.num.resize(max(num.size(), oth.num.size()) + 1);
        for (int i = 0; i < max(num.size(), oth.num.size()); i++) {
            if (i < num.size()) c.num[i] += num[i];
            if (i < oth.num.size()) c.num[i] += oth.num[i];
            c.num[i + 1] = c.num[i] / base;
            c.num[i] %= base;
        }
        if (c.num.back() == 0) c.num.pop_back();
        return c;
    }

    Number operator-(const Number &num) const {
        Number c;
        Number oth = min(num, *(this));
        Number that = max(num, *(this));
        if (that == num && that != oth) c.sign = 1;
        c.num.resize(max(that.num.size(), oth.num.size()));
        for (int i = 0; i < max(that.num.size(), oth.num.size()); i++) {
            c.num[i] += that.num[i];
            if (i < oth.num.size()) c.num[i] -= oth.num[i];
            if (c.num[i] < 0) {
                --c.num[i + 1];
                c.num[i] = base + c.num[i];
            }
        }
        while (c.num.back() == 0 && c.num.size() > 1) c.num.pop_back();

        return c;
    }

    Number operator*(const Number &oth) const {
        Number result;
        result.num.resize(num.size() + oth.num.size());
        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < oth.num.size(); j++) {
                result.num[i + j] += num[i] * oth.num[j];
            }
        }
        for (int i = 0; i < num.size() + oth.num.size() - 1; i++) {
            result.num[i + 1] += result.num[i] / base;
            result.num[i] %= base;
        }
        while (result.num.back() == 0 && result.num.size() > 1) result.num.pop_back();
        return result;
    }

    Number operator*(const ll &oth) const {
        ll carry = 0;
        Number c;
        c.num.resize(num.size());
        for (int i = 0; i < num.size(); i++) {
            c.num[i] = num[i] * oth;
            c.num[i] += carry;
            carry = c.num[i] / base;
            c.num[i] %= base;
        }
        while (carry > 0) c.num.push_back(carry % base), carry /= base;
        return c;
    }

    Number operator/(const ll &oth) const {
        ll mod = 0;
        Number result;
        result.num.resize(num.size());
        for (int i = num.size() - 1; i >= 0; --i) {
            ll cur = mod * base + num[i];
            result.num[i] = (cur / oth);
            mod = cur % oth;
        }
        while (result.num.back() == 0 && result.num.size() > 1) result.num.pop_back();
        return result;
    }

    ll operator%(const ll &oth) const {
        ll mod = 0;
        Number result;
        result.num.resize(num.size());
        for (int i = num.size() - 1; i >= 0; --i) {
            ll cur = mod * base + num[i];
            result.num[i] = (cur / oth);
            mod = cur % oth;
        }
        return mod;
    }


    Number operator/(const Number &num) const {
        Number l("0"), r = *(this) + 1;
        while (r - l > 1) {
            Number m = (l + r) / 2;
            if (m * num > *(this)) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    }

    Number operator%(const Number &num) const {
        return *(this) - num * (*(this) / num);
    }
};


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Number a, b, c;
    cin >> a >> b >> c;
    for (ll base = 2; base <= 2000; base++) {
        a.base = base;
        b.base = base;
        Number d = a + b;
        if (d == c) {
            cout << base << '\n';
            return 0;
        }
    }
    cout << "0\n";
}