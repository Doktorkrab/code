#include <bits/stdc++.h>

using namespace std;
using ld = long double;
const ld EPS = 1e-14;
struct Vector{
    ld x, y;
    Vector operator-(Vector& ot){
        return {x - ot.x, y - ot.y};
    }
    Vector operator+(Vector& ot){
        return {x + ot.x, y + ot.y};
    }
};
istream& operator>>(istream& st, Vector& a){
    st >> a.x >> a.y;
    return st;
}
struct Line{
    ld a, b, c;
};
struct Node{
    ld x;
    bool is_start;
};
Line get_Line(Vector a, Vector b){
    return {a.y - b.y, b.x - a.x, a.x*b.y - a.y*b.x};
}
ld vector_product(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}
ld scalar_product(Vector a, Vector b){
    return a.x * b.x + a.y * b.y;
}
Vector rotate(Vector a, ld angle){
    return {a.x * cos(angle) - a.y * sin(angle), a.y * cos(angle) - a.x * sin(angle)};
}
ld mod(ld a){
    while (a < 0) a += 2.0L * M_PI;
    while (a >= 2.0L * M_PI) a -= 2.0L * M_PI;
    return a;
}
ld get_angle(Vector a, Vector b, Vector c, Vector nul){
    Vector kek = {1e9, 0};
    if (a.x == 0 && a.y == 0){
        nul = {1e9, 0};
    }
    Line al = get_Line(a, nul), bl = get_Line(b, b + kek);
    ld angle1 = atan2(vector_product(nul - a, b - a), scalar_product(nul - a, b - a));
    ld ans;
    if (a.x == 0 && a.y == 0){
        al = get_Line(a, {1e9, 0});
        Line ab = get_Line(a, b);
        ans = acos((al.a * ab.a + al.b * ab.b) / sqrt((al.a * al.a + al.b * al.b) * (ab.a * ab.a + ab.b * ab.b)));
    }
    else{
        ld angle = acos((al.a * bl.a + al.b * bl.b) / sqrt((al.a * al.a + al.b * al.b) * (bl.a * bl.a + bl.b * bl.b)));
        ans = mod(angle1 - angle);
    }
    Vector rotated_a1 = rotate(a, -ans), rotated_b = rotate(b, -ans);
    if (fabs(rotated_a1.y - rotated_b.y) >= EPS) ans = M_PI - ans;
    Vector rotated_a = rotate(a, -ans), rotated_c = rotate(c, -ans);
    if(rotated_a.y >= rotated_c.y){
        ans = mod(ans + M_PI);
    }
   // cerr << ans << '\n';
    return ans;

}

pair<ld, ld> get_end(Vector a, Vector b, Vector c){
    Vector nul = {0, 0};
    ld an = get_angle(a, b, c, nul), an1 = get_angle(a, c, b, nul);
    an = mod(an);
    an1 = mod(an1);
    if (an > an1) swap(an, an1);
    ld t = (an + an1) / 2.0L;
    Vector rotated_a = rotate(a, -t), rotated_b = rotate(b, -t), rotated_c = rotate(c, -t);
    //cerr << rotated_a.y << ' ' << rotated_b.y << ' ' << rotated_c.y << endl;
    if (rotated_a.y <= rotated_b.y && rotated_a.y <= rotated_c.y)
        return {an, an1};
    return {an1, an};
}
bool cmp(Node a, Node b){
    return make_pair(a.x, 1 - a.is_start) < make_pair(b.x, 1 - b.is_start);
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    // assert(n != 1);
    vector<Node> scanline;
    int ans = 0, cnt = 0;
    for (int i = 0;i < n;i++){
        Vector a, b, c;
        cin >> a >> b >> c;
        auto angles = get_end(a, b, c);
        angles.second += EPS;
        angles.second = mod(angles.second);
        if (angles.second <= angles.first) cnt++;
        scanline.push_back({angles.first, 1});
        scanline.push_back({angles.second, 0});
        cerr << angles.first << ' ' << angles.second << endl;
    }
    ans = cnt;
    //cerr << cnt << " CNT\n";
    sort(scanline.begin(), scanline.end(), cmp);
    for (Node u : scanline){
        if (u.is_start) ans = max(ans, ++cnt);
        else --cnt;
    }
    assert (ans != 0);
    cout << ans << '\n';
}