#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;


struct Vector {
    ll x, y;

    Vector(ll x, ll y) : x(x), y(y) {}

    Vector() {}

    ll len() const {
        return x * x + y * y;
    }

    ll scalar_product(const Vector &oth) const {
        return x * oth.x + y * oth.y;
    }

    ll vector_product(const Vector &oth) const {
        return x * oth.y - y * oth.x;
    }

    Vector operator-(const Vector &oth) const {
        return {x - oth.x, y - oth.y};
    }

    friend istream &operator>>(istream &is, Vector &in) {
        is >> in.x >> in.y;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Vector &out){
        os << out.x << ' ' << out.y;
        return os;
    }
};

int n;
vector<Vector> points;


int cmp(const Vector &a, const Vector &b, const Vector &c) {
    if ((b - a).vector_product(c - b) < 0) return -1;
    if ((b - a).vector_product(c - b) == 0) return 0;
    return 1;
}

bool cmp1(const Vector &a, const Vector &b) {
    return cmp(a, b, points[0]) == 1 || (cmp(a, b, points[0]) == 0 && (a - points[0]).len() < (b - points[0]).len());
}

int64_t trap_square(Vector a, Vector b) {
    return (a.x - b.x) * (a.y + b.y);
}

int64_t get_area(const vector<Vector> &points) {
    vector<Vector> new_pnt = points;
    new_pnt.push_back(points[0]);
    ll ans = 0;
    for (int i = 0; i < new_pnt.size() - 1; i++)
        ans += trap_square(new_pnt[i], new_pnt[i + 1]);
    return ans;

}

long double get_p(const vector<Vector> &points){
    long double ret = 0;
    for (int i = 0; i < points.size() - 1; i++){
        ret += sqrtl((points[i + 1] - points[i]).len());
    }
    return ret;
}
void init() {
    points.clear();
}

void solve() {
    init();
    points.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (points[i].x > points[mx].x)
            mx = i;
    }
    swap(points[0], points[mx]);
    sort(points.begin() + 1, points.end(), cmp1);
    points.push_back(points[0]);
    vector<Vector> stack = {points[0], points[1]};
    for (int p = 2; p < n; p++) {
        while (stack.size() >= 2 && cmp(stack[stack.size() - 2], stack.back(), points[p]) <= 0)
            stack.pop_back();
        stack.push_back(points[p]);
    }
    n = stack.size() - 1;
    cout << setprecision(20) << fixed << get_p(stack) << '\n' << get_area(stack) / 2.L << '\n';
}

int main(){
    while(cin >> n)
    solve();
}
