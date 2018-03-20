x, y = map(int, input().split())
# print(x - y + 1)
if y == 0 or (y == 1 and x != 0):
    print('No')
elif x - y + 1 < 0 or (x - y + 1) % 2 == 1:
    print('No')
else:
    print('Yes')