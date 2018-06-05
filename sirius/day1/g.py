s = input()
day, month, year = int(s[:2]), int(s[2:4]), int(s[4:])
ans = 0
months = [31, 28 + int(year % 4 == 0 and year % 100 != 0 or year % 400 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31]
for y in range(1, year):
    ans += 365 + int(y % 4 == 0 and y % 100 != 0 or y % 400 == 0)
print(ans + sum(months[:month-1]) + day)