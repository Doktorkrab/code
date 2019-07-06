#include <stdlib.h>
#include <assert.h>

long long GetN() {
    return 2LL;
}

long long GetFavoriteMove(long long i) {
    switch ((int)i) {
    case 0: return 'R';
    case 1: return 'R';
    case 2: return 'R';
    case 3: return 'R';
    default: assert(0);
    }
}
