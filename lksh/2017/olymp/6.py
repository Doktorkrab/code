n = int(input())
arr = []
mx = 0
max_c = 0
st = set()
for i in range(n):
    s = input()
    arr.append(s)
    for j in s:
        if j in st:
            continue
        st.add(j)
    if mx < len(s):
        mx = len(s)
        max_c = i
d = {}
now = 9
for i in arr[max_c]:
    if i in d:
        continue
    d[i] = now
    now -= 1
for i in st:
    if i in d:
        continue
    d[i] = now
    now -= 1
ans = 0
arr1 = [0] * n

for i in range(n):
    power = 0
    for j in arr[i][::-1]:
        arr1[i] += d[j] * (10 ** power)
        power += 1
print(arr1)
print(sum(arr1))
