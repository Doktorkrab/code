s = input().replace('**', '^')
arr = s.split('+')
arr1 = []
for i in arr:
    arr1.extend(i.split('-'))
umn, step = 0, 0
for i in arr1:
    j = 0
    umn += i.count('*')
    step += i.count('^')
    while j < len(i):
        while j < len(i) and not ( 'a' <= i[j] <= 'z'):
            j += 1
        if j != 0 and j < len(i):
            if '0' <= i[j - 1] <= '9':
                umn+=1
        j += 1
print(umn, step)