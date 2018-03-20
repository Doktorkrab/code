#include <bits/stdc++.h>
using namespace std;
struct test{
    int x = 0;
    void test1(){
        if (!this)cout << "LOL";
        else cout << "KEK";
    }
};

int main(){
    test *a = nullptr;
    a->test1();
}