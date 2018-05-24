n, k = map(int, input().split())
if k == 0 or k & 1:
    # print("АХахахахахаах кривые тесты ну наканецта")
    exit(1488)
cnt = 0
print('Move')
ans1 = int(input())
ans = k // 2
while ans != ans1:
    print('Move')
    ans1 = int(input())
print('Finish')
