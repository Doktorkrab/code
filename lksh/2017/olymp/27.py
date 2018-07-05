st = set()


def reroll(a):
    st.add(a)
    return gg


n = int(input())
arr = []
s = input()
arr.append({})
arr[len(arr) - 1][s[0]] = s[1]
arr[len(arr) - 1][s[1]] = s[0]
arr[len(arr) - 1][s[2]] = s[3]
arr[len(arr) - 1][s[3]] = s[2]
arr[len(arr) - 1][s[4]] = s[5]
arr[len(arr) - 1][s[5]] = s[4]
for i in range(1, n):
    s = input()
    # print(arr)
    f1 = 0
    for j in arr:
        f = 0
        for k in range(6):
            # print(j, k, s[k], s[k + 1], s[k - 1])
            if k % 2 == 0:
                if j[s[k]] == s[k + 1]:
                    continue
            else:
                if j[s[k]] == s[k - 1]:
                    continue
            f = 1
            break
        if not f:
            f1 = 1
            break
    if not f1:
        # print('\n!!!!', s, sep='')
        arr.append({})
        arr[len(arr) - 1][s[0]] = s[1]
        arr[len(arr) - 1][s[1]] = s[0]
        arr[len(arr) - 1][s[2]] = s[3]
        arr[len(arr) - 1][s[3]] = s[2]
        arr[len(arr) - 1][s[4]] = s[5]
        arr[len(arr) - 1][s[5]] = s[4]
print(len(arr))