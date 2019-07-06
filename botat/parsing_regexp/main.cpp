#include <iostream>
#include <string>
#include <cassert>

using namespace std;

struct RegExp {
    string expression;
    int pos = 0;
    string cur_lexem;
    explicit RegExp(const string &s){
        expression = s + '#';
        pos = 0;
        next_lexem();
    }
    void next_lexem() {
        assert(pos < expression.size());
        if (isalpha(expression[pos])) {
            string nxt;
            while (pos < expression.size() && isalpha(expression[pos]))
                nxt += expression[pos];
            swap(nxt, cur_lexem);
            return;
        }
        cur_lexem = expression[pos++];
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}