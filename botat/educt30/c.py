n, m, k = map(int, input().split())
k -= 1

arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int, input().split()))

prefix = [[0] * m for _ in range(n)]

for i in range(m):
    for j in range(n):
        if not j:
            prefix[j][i] = arr[j][i]
        else:
            prefix[j][i] = arr[j][i] + prefix[j - 1][i]
ans = 0
ans_cnt = 0
for i in range(m):
    cnt = 0
    ans_row = 0
    cnt_ans = 0
    for j in range(n):
        if arr[j][i] == 1:
            if not j:
                ans_n = prefix[min(n - 1, j + k)][i]
            else:
                ans_n = prefix[min(n - 1, j + k)][i] - prefix[j - 1][i]
            if ans_n > ans_row:
                ans_row = ans_n
                cnt_ans = cnt
            cnt += 1
    # print('!!!', ans_row, cnt_ans, i)
    ans += ans_row
    ans_cnt += cnt_ans
print(ans, ans_cnt)
