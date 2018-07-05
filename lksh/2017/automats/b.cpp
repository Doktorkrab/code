// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;

struct Edge {
  int u = -1;
  int can_add = 0;  // 0 - can't, 1 - can, 2 - maybe / in comment or / not in
                    // coment, 3 - only slash
};

struct Node {
  bool is_terminate = 0;
  vector<Edge> edges;
  Node() : edges(512) {}
};

void base_setup(int index, Node& node, int can_add = 0) {
  for (int i = 0; i < 512; i++) node.edges[i] = {index, can_add};
}
int main() {
  freopen("comments.in", "r", stdin);
  freopen("comments.out", "w", stdout);
  // setlocale(LC_ALL, "Russian");
  vector<Node> nodes(6);

  nodes[0].is_terminate = 1;  // main vertex(not comment)
  base_setup(0, nodes[0], 1);
  nodes[0].edges['/' + 255] = {1, 0};
  nodes[0].edges['{' + 255] = {2, 0};

  base_setup(0, nodes[1], 2);  // first slash
  nodes[1].edges['/' + 255] = {3, 0};
  nodes[1].edges['*' + 255] = {4, 0};
  nodes[1].edges['{' + 255] = {2, 3};

  base_setup(2, nodes[2]);  // { comment
  nodes[2].edges['}' + 255] = {0, 0};

  base_setup(3, nodes[3]);  // one line comment
  nodes[3].edges['\n' + 255] = {0, 1};

  base_setup(4, nodes[4]);  // multi line comment
  nodes[4].edges['*' + 255] = {5, 0};

  base_setup(4, nodes[5], 4);  // multi line comment ending
  nodes[5].edges['/' + 255] = {0, 0};
  nodes[5].edges['*' + 255] = {5, 0};

  string s;
  string tmp;
  while (getline(cin, tmp)) {
    s += tmp + '\n';
  }
  string ans;
  int pos = 0;
  for (char c : s) {
    // cout << "CHAR " << c << '\n';
    auto edge = nodes[pos].edges[c + 255];
    if (edge.can_add == 2) {
      ans += '/';
      ans += c;
    } else if (edge.can_add == 1)
      ans += c;
    else if (edge.can_add == 3)
      ans += '/';
    pos = edge.u;
  }
  cout << ans;
  // cout << (char) - 256 << '\n';
}
