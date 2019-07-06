#include <bits/stdc++.h>

using namespace std;

struct Node {
    int rgt = 0, lft;
    char c;
    bool need_square;
    int lft_sz, rgt_sz;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(const char c, bool sq = 0) : c(c), rgt(0), lft(0), need_square(sq) {}
};

string expression;

char cur_lexem;
int pos = 0;

inline void next_lexem() {
    assert(pos < expression.size());
    cur_lexem = expression[pos++];
}


Node *bld_right(int pos, const vector<Node *> &kek, const vector<char> &symbols) {
    if (pos >= kek.size())
        return nullptr;
    if (pos + 1 == kek.size())
        return kek[pos];
    if (pos + 2 == kek.size()) {
        Node *ret = new Node(symbols[pos], 1);
        ret->left = kek[pos];
        ret->right = kek[pos + 1];
        return ret;
    }
    Node *ret = new Node(symbols[pos], 1);
    ret->need_square = 1;
    ret->left = kek[pos];
    ret->right = bld_right(pos + 1, kek, symbols);
    return ret;
}

Node *bld_left(int pos, const vector<Node *> &kek, const vector<char> &lol) {
    if (pos < 0)
        return nullptr;
    if (pos == 0)
        return kek[pos];
    if (pos == 1) {
        Node *ret = new Node(lol[0], 1);
        ret->left = kek[0];
        ret->right = kek[1];
        return ret;
    }
    Node *ret = new Node(lol[pos - 1], 1);
    ret->right = kek[pos];
    ret->left = bld_left(pos - 1, kek, lol);
    return ret;
}

Node *power();

Node *factor();

Node *addent();

Node *expr() {
    vector<Node *> addents;
    vector<char> symbols;
    while (pos < expression.size()) {
        if (cur_lexem == '+') {
            symbols.push_back('+');
            next_lexem();
        }
        if (cur_lexem == '-') {
            symbols.push_back('-');
            next_lexem();
        }
        if (cur_lexem == ')' || cur_lexem == '$') {
            next_lexem();
            break;
        }
        addents.push_back(addent());
    }
    return bld_left(addents.size() - 1, addents, symbols);
}

Node *addent() {
    vector<Node *> factors;
    vector<char> symbols;
    while (pos < expression.size()) {
        if (cur_lexem == '*') {
            symbols.push_back('*');
            next_lexem();
        }
        if (cur_lexem == '/') {
            symbols.push_back('/');
            next_lexem();
        }
        if (cur_lexem == '+' || cur_lexem == '-' || cur_lexem == ')')
            break;
        factors.push_back(factor());
    }
    return bld_left(factors.size() - 1, factors, symbols);
}

Node *factor() {
    vector<Node *> powers;
    vector<char> symbols;
    while (pos < expression.size()) {
        if (cur_lexem == '^') {
            symbols.push_back('^');
            next_lexem();
        }
        if (!isalpha(cur_lexem) && cur_lexem != '(')
            break;
        powers.push_back(power());
    }
    return bld_right(0, powers, symbols);
}

Node *power() {
    if (cur_lexem == '(') {
        next_lexem();
        return expr();
    }
    Node *ret = new Node(cur_lexem);
    next_lexem();
    return ret;
}

int max_d = 0;

void dfs(Node *v, int d = 1) {
    max_d = max(d, max_d);
    if (!v->need_square){
        v->lft_sz = 0;
        v->rgt_sz = 0;
        v->rgt = 1;
        v->lft = 1;
        return;
    }
    dfs(v->left, d + 1);
    v->lft_sz = v->left->lft_sz + v->left->rgt + 2;
    v->lft = v->left->rgt_sz + 3 + v->left->lft;
    dfs(v->right, d + 1);
    v->rgt = v->right->lft_sz + 3 + v->right->rgt;
    v->rgt_sz = v->right->rgt_sz + v->right->lft + 2;
}

vector<vector<char>> ans;

int dfs1(Node *a, int h = 0, int lft = 0){
    if (a->need_square == 0){
        ans[h][lft] = a->c;
        return lft;
    }
    lft = dfs1(a->left, h + 2, lft);
    ans[h][lft] = '.';
    ans[h + 1][lft] = '|';
    for (int i = 0; i <= a->left->rgt; i++)
        ans[h][++lft] = '-';
    ans[h][lft++] = '[';
    ans[h][lft++] = a->c;
    int ret = lft;
    ans[h][lft++] = ']';
    for (int i = 0; i < a->right->lft; i++)
        ans[h][lft++] = '-';
    ans[h][lft] = '.';
    ans[h + 1][lft] = '|';
    dfs1(a->right, h + 2, ret + 2);
    return ret - 1;
}

int main() {
    cin >> expression;
    expression += '$';
    next_lexem();
    auto kek = expr();
    dfs(kek);
    ans = vector<vector<char>>(2 * max_d - 1, vector<char>(kek->rgt + kek->lft, ' '));
    dfs1(kek);
    for (auto i : ans) {
        for (char j : i)
            cout << j;
        cout << '\n';
    }
    return 0;
}