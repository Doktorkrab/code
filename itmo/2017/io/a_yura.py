import itertools
s = list(input().replace(' ', ''))
perms = list(set(itertools.permutations(s)))
ans = set()
# arr = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
for perm in perms:
    year = int(''.join(perm[:4]))
    month = int(''.join(perm[4:6]))
    day = int(''.join(perm[6:8]))
    arr = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if year % 400 == 0 or (year % 100 and year % 4 == 0):
        arr[2] += 1
    if month == 0 or month > 12 or arr[month] < day or year == 0 or day == 0:
        continue
    ans.add('0' * (4 - len(str(year))) + str(year) + ' ' + '0' * (2 - len(str(month))) + str(month) + ' ' + '0' * (2 - len(str(day))) + str(day))
print(len(ans))
for i in sorted(list(ans)):
    print(i)
