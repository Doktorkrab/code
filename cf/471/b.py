s = input()
if len(s) < 4:
    print('No')
    exit(0)
st = {}
used = {}
for i in s:
    st[i] = st.get(i, 0) + 1
    used[i] = 0
if 2 <= len(st) <= 4:
    if len(st) > 2:
        print('YES')
    else:
        cnt = 0
        for i in st:
            if st[i] < 2:
                print('No')
                exit(0)
        print('Yes')
else:
    print('No')
