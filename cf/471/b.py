s = input()
st = {}
used = {}
for i in s:
    st[i] = st.get(i, 0) + 1
    used[i] = 0
if len(st) == 2:
    for i in st:
        if st[i] < 2:
            print('No')
            exit(0)
for i in st:
    mx = 10 ** 9
    ind = i
    if used[i] and st[i] > 0:
        continue
    for j in st:
        if i != j and st[j] > 0:
            if st[j] < mx:
                ind = j
                mx = st[j]
    st[ind] -= 1
    used[ind] = 1
    used[i] = 1
    if mx == 10**9:
        # print(i, st, used)
        print('No')
        exit(0)
for i in st:
    if not used[i]:
        print('No')
        break
else:
    print('Yes')
    # print(st, used)
