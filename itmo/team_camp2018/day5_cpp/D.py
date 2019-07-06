
# i1, i2 = 0, 0
# ans = 0
# i = 0
# ans2 = 0
# while True:
#     if 2 * (h2 - i) <= (m - i):
#         if 2 * (h2 - i) + h1 - (i + (h2 - i)) <= m - i:
#             ans2 += 2
#             break
#         ans2 += 3
#         break
#     i += (m - i) / 2
#     ans2 += 2
#
# while i1 != h1 or i2 != h2:
#     # print(i1, i2)
#     if i2 == h2:
#         ans += 1
#         i1 = h1
#         continue
#     if 2 * h2 - 2 * i2 + h1 < m:
#         ans += 2
#         break
#     if 2 * h2 - i2 < m:
#         ans += 3
#         break
#     i1 = min(m, 2 * h2 - i2)
#     ans += 2
#     t = (i1 + i2) / 2
#     i2 = t
#     i1 = t
# print(ans)
# print(ans2)
m = int(input())

h1, h2 = map(float, input().split())
if h2 > h1 or h2 == m:
    print(-1)
    exit(0)

if h2 > m:
    print(-1)
    exit(0)
print(2 + int(h1 != h2))