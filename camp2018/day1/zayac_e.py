def res(z, m, n):
    ans = 0
    for i in range(1, m + 1):
        ans += z // i
        if z < i or ans >= n:
            return ans
    return ans
 
def bin_search(n, m):
    left, right = 1, n
    while right - left > 1:
        mid = (left + right) // 2
        if res(mid, m, n) >= n:
            right = mid
        else:
            left = mid
    return right
 
 
fin = open('bigset.in', 'r')
fout = open('bigset.out', 'w')
n, m = map(int, fin.readline().split())
print(bin_search(n, m), file=fout)
fin.close()
fout.close()
