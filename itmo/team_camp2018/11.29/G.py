k = int(input())
n = int(input())
if k < 4 or k == 6:
    print(0)
    exit(0)
print(n)
inpt = list(map(int, input().split()))
if k < 6:
    a = [2, 1, 2]
    if k == 4:
        a = [1, 2, 1]
    # a = [1, 2, 1, 0]
    for i in range(n):
        q = inpt[i]
        if q > 2:
            print(0, end=" ")
        else:
            print(a[q], end=" ")
else:
    a = [k - 4, 2, 1]
    for i in range(n):
        q = inpt[i]
        if q == k - 4:
            print(1, end=" ")
        elif q > 2:
            print(0, end=" ")
        else:
            print(a[q], end=" ")
