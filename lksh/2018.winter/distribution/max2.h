#include <cassert>

long long GetN() {
  return 6;
}

long long GetElement(long long i) {
    assert(0 <= i and i < GetN());
    return 1;
}
