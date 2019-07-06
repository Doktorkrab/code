#include <stdlib.h>
#include <assert.h>

long long GetNumStacks() {
    return 3LL;
}

long long GetStackHeight(long long i) {
    switch (int(i)) {
    case 1: return 2LL;
    case 2: return 2LL;
    case 3: return 4LL;
    default: assert(false);
    }
}
