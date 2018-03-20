import sys


def jopa(n):
    d = 0
    a = 1 << (n.bit_length() >> 1)
    while 1:
        new = (a + n // a) >> 1
        if a == new or a < new and d:
            break
        d = new < a
        a = new
    return a


n = int(sys.stdin.readline())
# for n in range(100000000, 1000000000000000000):
sqrt = jopa(n)
# sys.stdout.write(sqrt)
sqrt1 = sqrt + 1
sqrt *= sqrt
if sqrt == n:
    sys.stdout.write('1')
    sys.exit(0)
    # continue
n -= sqrt
if n <= sqrt1:
    sys.stdout.write(str(n))
else:
    sys.stdout.write(str(sqrt1 + sqrt1 - n))
