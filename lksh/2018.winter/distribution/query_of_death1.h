#include <stdlib.h>
#include <assert.h>
#include <random>

long long GetLength() {
    return 3LL;
}

int GetValue(long long i) {
    static int data[] = {1, 1, 0};
    static int isthenodebroken = 0;
    static std::mt19937 rnd(31031999);
    
    if (i < 0LL || i >= GetLength())
        assert(false);
    
    int val = (int)(data[i]^(rnd() % (isthenodebroken + 1)));
    if (i == 1)
        isthenodebroken = 1;
    return val;
}
