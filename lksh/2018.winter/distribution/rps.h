#include <stdlib.h>
#include <assert.h>

long long GetN() {
    return 3LL;
}

char GetFavoriteMove(long long i) {
  switch ((int)i) {
  case 0: return 'R';
  case 1: return 'P';
  case 2: return 'S';
  case 3: return 'R';
  case 4: return 'P';
  case 5: return 'S';
  case 6: return 'R';
  case 7: return 'P';
  default: assert(0);
  }
}
