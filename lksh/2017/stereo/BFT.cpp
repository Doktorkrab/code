#include <bits/stdc++.h>
using namespace std;

struct Vector {
  long double x = 0, y = 0, z = 0;
  Vector(long double x, long double y, long double z) : x(x), y(y), z(z) {}
  Vector vector_product(Vector const& b) {
    return {y * b.z - this->z * b.y, z * b.x - this->x * b.z,
            x * b.y - this->y * b.x};
  }

  Vector() {}
  Vector(Vector a, Vector b) : x(a.x - b.x), y(a.y - b.y), z(a.z - b.z) {}
  long double dot_product(Vector const& b) {
    return x * b.x + y * b.y + z * b.z;
  }

  Vector operator*(long double k) { return {x * k, y * k, z * k}; }
  Vector operator-(Vector& a) { return {x - a.x, y - a.y, z - a.z}; }
  Vector operator+(Vector& a) { return {x + a.x, y + a.y, z + a.z}; }
  bool operator==(Vector a) { return tie(x, y, z) == tie(a.x, a.y, a.z); }
  bool operator!=(Vector a) { return !((*this) == a); }
  bool operator<(Vector a) { return tie(x, y, z) < tie(a.x, a.y, a.z); }
  double len() { return sqrt((double)x * x + y * y + z * z); }

  void normalize() {
    double len_ = len();
    x /= len_;
    y /= len_;
    z /= len_;
  }

  double angle(Vector b) {
    return atan2(vector_product(b).len(), dot_product(b));
  }
  Vector ortogonal() {
    if (x == 0 && y == 0) return {1, 1, 0};
    return {y, -x, 0};
  }
};

istream& operator>>(istream& stream, Vector& v) {
  stream >> v.x >> v.y >> v.z;
  return stream;
}
ostream& operator<<(ostream& stream, const Vector& v) {
  stream << v.x << ' ' << v.y << ' ' << v.z;
  return stream;
}

struct Plane {
  long double a, b, c, d;
  Plane() {}
  Plane(Vector fir, Vector sec, Vector third) {
    Vector vector_product = (fir - sec).vector_product(third - sec);
    a = vector_product.x;
    b = vector_product.y;
    c = vector_product.z;
    d = -(a * fir.x + b * fir.y + c * fir.z);
  }
  bool is_point_on_plane(Vector pnt) {
    return a * pnt.x + b * pnt.y + c * pnt.z + d == 0;
  }
  Vector normal() { return {a, b, c}; }
  double dist_point(Vector pnt) {
    double h = (a * pnt.x + b * pnt.y + c * pnt.z + d) / (normal().len());
    return h;
  }
};
ostream& operator<<(ostream& stream, const Plane& p) {
  stream << p.a << ' ' << p.b << ' ' << p.c << ' ' << p.d << '\n';
  return stream;
}
istream& operator>>(istream& stream, Plane& p) {
  stream >> p.a >> p.b >> p.c >> p.d;
  return stream;
}
struct Line {
  Vector a, b;
  Line() {}
  Line(Vector _a, Vector _b) {
    a = _a;
    b = _b;
  }
  double dist(Vector pnt) {
    Vector edge1 = pnt - a, edge2 = pnt - b;
    // cout << edge1 << ' ' << edge2 << '\n';
    return edge1.vector_product(edge2).len() / (b - a).len();
  }
};

struct Segment : Line {
  Segment(Vector _a, Vector _b) {
    a = _a;
    b = _b;
  }
  double dist(Vector pnt) {
    Vector edge1 = pnt - a, edge2 = pnt - b, edge3 = a - b, edge4 = b - a;
    // cout << edge1.dot_product(edge4) << '\n';
    if (edge1.dot_product(edge4) <= 0) {
      // cout << edge1 << ' ' << pnt << ' ' << a << '\n';
      return edge1.len();
    }
    if (edge2.dot_product(edge3) < 0) {
      return edge2.len();
    }
    return Line::dist(pnt);
  }
};
long double mixed_product(Vector a, Vector b, Vector c) {
  return a.dot_product(b.vector_product(c));
}

const Vector null_v = {0, 0, 0};
int main() {
  cout.precision(20);
  Vector point, point1;
  cin >> point >> point1;
  // cerr << "!!! " << point << '\n';
  Plane plane;
  cin >> plane;
  double h = plane.dist_point(point);
  double h1 = plane.dist_point(point1);
  if (h == 0 && h1 == 0) {
    cout << "1\n";
    return 0;
  }
  if (h == h1) {
    cout << "0\n";
    return 0;
  }
  double t = -((double)point.x * plane.a + point.y * plane.b +
               point.z * plane.c + plane.d) /
             ((double)plane.a * (point1.x - point.x) +
              plane.b * (point1.y - point.y) + plane.c * (point1.z - point.z));
  // cerr << point.x * plane.a << ' ' << point.y * plane.b << ' ' << point.z *
  // plane.c << '\n';
  cout << (point1.x - point.x) * t + (double)point.x << ' '
       << (point1.y - point.y) * t + (double)point.y << ' '
       << (point1.z - point.z) * t + (double)point.z << '\n';
}
