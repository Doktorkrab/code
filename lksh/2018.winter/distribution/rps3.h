#include <stdlib.h>
#include <assert.h>

long long GetN() {
    return 2LL;
}

char GetFavoriteMove(long long i) {
    switch ((int)i) {
    case 0: return 'S';
    case 1: return 'R';
    case 2: return 'P';
    case 3: return 'P';
    default: assert(0);
    }
}
