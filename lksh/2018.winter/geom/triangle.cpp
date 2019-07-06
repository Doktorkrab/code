#include <bits/stdc++.h>
#include <ostream>

using namespace std;

struct Vector {
    int x, y;

    Vector() {}

    Vector(int x_, int y_) : x(x_), y(y_) {}

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
};

struct Node {
    Node *prev = nullptr, *next = nullptr;
    Vector value;
    int index;

    Node(Vector val, int ind) : value(val), index(ind) {}
};

int vectorProduct(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}

int getTwicedTriangleSquare(const Vector &vertex1, const Vector &vertex2, const Vector &vertex3) {
    return vectorProduct(vertex1 - vertex2, vertex3 - vertex2);
}

bool inTriangle(const Vector &vertex1, const Vector &vertex2, const Vector &vertex3, const Vector &to_check) {
    if (vertex1 == to_check || vertex2 == to_check || vertex3 == to_check)
        return 0;
    int square = abs(getTwicedTriangleSquare(vertex1, vertex2, vertex3));
    int square1 = abs(getTwicedTriangleSquare(vertex1, vertex2, to_check));
    int square2 = abs(getTwicedTriangleSquare(vertex1, to_check, vertex3));
    int square3 = abs(getTwicedTriangleSquare(to_check, vertex2, vertex3));
    return square == square1 + square2 + square3;
}

int main() {
    freopen("triang.in", "r", stdin);
    freopen("triang.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<Vector, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    int square = 0;
    arr.push_back(arr[0]);
    for (int i = 0; i < n; i++){
        square += getTwicedTriangleSquare({0, 0}, arr[i].first, arr[i + 1].first);
    }
    if (square < 0)
        reverse(arr.begin(), arr.end());

    Node *front = new Node(arr[0].first, arr[0].second);
    front->next = front->prev = front;
    Node *back = front;

    for (int i = 1; i < n; i++) {
        Node *newNode = new Node(arr[i].first, arr[i].second);

        newNode->prev = back;
        newNode->next = front;
        front->prev = newNode;
        back->next = newNode;
        back = newNode;
    }

    auto isConvex = [&](Vector left, Vector middle, Vector right) {
        int tmp = vectorProduct(left - middle, right - middle);
        return tmp > 0;
    };
    Node *now = front;
    int sz = n;
    vector<pair<int, int>> ans;
    while (sz > 3) {
        Node *now = front;
        for (int i = 0; i < sz; ++i, now = now->next) {
            Vector pNow = now->value;
            Vector pPrev = now->prev->value;
            Vector pNext = now->next->value;
            if (!isConvex(pPrev, pNow, pNext))
                continue;
            if (inTriangle(pPrev, pNow, pNext, front->value))
                continue;
            int good = 1;
            for (Node *toCheck = front->next; toCheck != front; toCheck = toCheck->next)
                if (inTriangle(pPrev, pNow, pNext, toCheck->value)) {
                    good = 0;
                    break;
                }
            if (good) {
                ans.emplace_back(now->prev->index, now->next->index);
                --sz;
                if (front == now) {
                    front = now->next;
                }
                if (back == now) {
                    back = now->prev;
                }
                now->prev->next = now->next;
                now->next->prev = now->prev;
                break;
            }
        }
    }

    for (const auto &i : ans) {
        cout << i.first << ' ' << i.second << '\n';
    }
}