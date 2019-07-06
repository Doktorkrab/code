#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
#define int ll

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
    Vector operator+(const Vector &oth) const {
        return {x + oth.x, y + oth.y};
    }
    friend istream &operator>>(istream &is, Vector &in) {
        is >> in.x >> in.y;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Vector &out){
        os << out.x << ' ' << out.y;
        return os;
    }

    bool operator<(const Vector& oth) const {
        return vector_product(oth) < 0;
    }

    bool operator<=(const Vector& oth) const {
        return vector_product(oth) <= 0;
    }

};

int64_t trap_square(const Vector& a, const Vector& b){
    return (a.x - b.x) * (a.y + b.y);
}

int cmp(const Vector &a, const Vector &b, const Vector &c) {
    if ((b - a).vector_product(c - b) < 0) return -1;
    if ((b - a).vector_product(c - b) == 0) return 0;
    return 1;
}

bool cmp1(const Vector& a, const Vector& b){
    return tie(a.x, a.y) < tie(b.x, b.y);
}

struct ConvexPolygon{
    int sz;
    int64_t sq = 0;
    vector<Vector> points;
    ConvexPolygon () {}
    ll square() const {
        ll ans = 0;
        for (int i = 0; i < sz; i++)
            ans += trap_square(points[i], points[(i + 1) % sz]);
        return abs(ans);
    }
    friend istream& operator>>(istream& is, ConvexPolygon& x){
        is >> x.sz;
        x.points.resize(x.sz);
        for (int i = 0; i < x.sz; i++)
            is >> x.points[i];

        x.sq = x.square();
        
        rotate(x.points.begin(), min_element(x.points.begin(), x.points.end(), cmp1), x.points.end());
        for (int i = 1; i < x.sz; i++)
            x.points[i] = x.points[i] - x.points[0];

        return is;
    }

    bool isInner(const Vector& toCheck) const {
        Vector for_check = toCheck - points[0];
        int l = 0, r = sz;

        while (r - l > 1){
            int m = (l + r) / 2;
            if (points[m].vector_product(for_check) > 0)
                l = m;
            else
                r = m;
        }
        if (r <= 1)
            return 0;
        
        if (r == sz)
            return points[l].vector_product(for_check) <= 0;
        return (points[l] - points[r]).vector_product(toCheck - (points[r] + points[0])) <= 0;
    }

    bool operator< (const ConvexPolygon& oth) const {
        return sq < oth.sq;
    }
};

int n;
vector<ConvexPolygon> polygons;
vector<Vector> points;
vector<bool> is_bad;
void init(){
    polygons.resize(n);
    is_bad.resize(n);
}
void solve() {
    init();
    for (int i = 0; i < n; i++){
        cin >> polygons[i];
    }
    sort(polygons.rbegin(), polygons.rend());
    ll ans = 0;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        Vector x;
        cin >> x;
        int l = 0, r = n;
        while (r - l > 1){
            int m = (l + r) / 2;
            if (polygons[m].isInner(x))
                l = m;
            else
                r = m;
        }
        if (l < n && polygons[l].isInner(x))
            is_bad[l] = 1;
    }
    for (int i = 0; i < n; i++)
        if (is_bad[i])
            ans += polygons[i].sq - (i == n - 1 ? 0 : polygons[i + 1].sq);
    cout << setprecision(20) << fixed <<  ans / 2.L << '\n';
}

int32_t main(){
    while(cin >> n)
    solve();
}