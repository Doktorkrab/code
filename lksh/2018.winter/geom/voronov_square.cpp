#include <bits/stdc++.h>

using namespace std;

struct Vector {
    double x, y;

    Vector() {}

    Vector(double x_, double y_) : x(x_), y(y_) {}

    friend ostream &operator<<(ostream &os, const Vector &point) {
        os << point.x << point.y;
        return os;
    }

    bool operator==(const Vector &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    friend istream &operator>>(istream &is, Vector &point) {
        is >> point.x >> point.y;
        return is;
    }

    Vector operator-(const Vector &oth) const {
        return {x - oth.x, y - oth.y};
    }

    Vector operator+(const Vector &oth) const {
        return {x + oth.x, y + oth.y};
    }

    Vector operator/(const double& oth) const{
        return {x / oth, y / oth};
    }
};

struct Edge {
    Vector left, right;

    Edge() {}

    Edge(const Vector &left, const Vector &right) : left(left), right(right) {}


};

template<typename T>
struct Node {
    T value;
    Node *next, *prev;

    Node() : value(), next(nullptr), prev(nullptr) {}

    Node(T value) : value(value), next(nullptr), prev(nullptr) {}
};

template<typename T>
struct List {
    Node<T> *front, *back;
    int sz = 0;

    void push_back(const T &value) {
        if (front == nullptr) {
            front = back = new Node<T>(value);
            front->next = front->prev = front;
        } else {
            auto *newNode = new Node<T>(value);
            newNode->next = front;
            newNode->prev = back;
            back->next = newNode;
            front->prev = newNode;
            back = newNode;
        }
        sz++;
    }

    int size() {
        return sz;
    }

};

int64_t get_length_sqr(const Vector &v1, const Vector &v2) {
    return (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y);
}

struct Line {
    int a, b, c;

    Line() {}

    Line(const Vector &pnt1, const Vector &pnt2) {
        Vector tmp = pnt2 - pnt1;
        a = tmp.y;
        b = -tmp.x;
        c = -(a * pnt1.x + b * pnt1.y);
    }
};

int main() {
    double x, y;
    int n;
    cin >> x >> y >> n;
    vector<List<Edge>> edges(n);
    vector<Vector> points(n);
    cin >> points[0];
    edges[0].push_back(Edge({0, 0}, {x, 0}));
    edges[0].push_back(Edge({x, 0}, {x, y}));
    edges[0].push_back(Edge({x, y}, {0, y}));
    edges[0].push_back(Edge({0, y}, {0, 0}));

    for (int i = 1; i < n; i++) {
        cin >> points[i];
        int closest = 0;
        for (int j = 0; j < i; ++j) {
            if (get_length_sqr(points[closest], points[i]) > get_length_sqr(points[j], points[i]))
                closest = j;
        }
        Vector middle = (points[i] + points[closest]) / 2.;
        Vector between = points[i] - points[closest];
        Vector middle2 = middle + Vector(-between.y, between.x);
        Line ortogonal = Line(middle, middle2);

    }

}