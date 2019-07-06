x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())

# if (x1 == x2 and x1 == 0) or (y1 == y2 and y1 == 0) or ((y1 != 0 and (y2 - y1) != 0) and (x2 - x1) / (y2 - y1) == (x1 / y1)):
#     print("Infinity")
# else:
#     print(abs(x1 * y2 - y1 * x2))
if abs(x1 * y2 - y1 * x2) == 0:
    print("Infinity")
else:
    print(abs(x1 * y2 - y1 * x2))
