import math


x, y = map(int, input().split())
x = abs(x)
y = abs(y)
ans = 0.0
x_0, y_0 = (x // 4) * 4, (y // 4) * 4
ans += abs(float(min(x_0 // 4, y_0 // 4))) * (4.0 + 2 * math.sqrt(2))
ans += abs(float((max(x_0 // 4, y_0 // 4) - min(x_0 // 4, y_0 // 4)))) * (2 + 2 * math.sqrt(2))
x_1 = x - x_0
y_1 = y - y_0
mat_ans = [
    [0, -1, -1, -1, 2 + 2 * math.sqrt(2)],
    [-1, math.sqrt(2), math.sqrt(2) + 1, math.sqrt(2) + 2, -1],
    [-1, math.sqrt(2) + 1, -1, math.sqrt(2) + 3, -1],
    [-1, math.sqrt(2) + 2, math.sqrt(2) + 3, math.sqrt(2) + 4, -1],
    [2 + 2 * (math.sqrt(2)), -1, -1, -1, 4 + 2 * math.sqrt(2)]
]
if mat_ans[x_1][y_1] == -1:
    print(-1)
else:
    print(ans + mat_ans[x_1][y_1])
