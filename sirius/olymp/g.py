a,b,c,d,x,y = map(int,input().split())

if a * c > y or b * d < x:
    print("NO")
    exit(0)
for jump in range(a,b+1):
    print((x+jump-1)//jump)
    if(((x+jump-1)//jump)*jump<=y and (x+jump-1)//jump>=x):
        
        ans = (x+jump-1)//jump
        if(ans>d or ans<c):
            continue
        print("YES")
        print(a,ans)
        exit(0)
else:
    print('NO')
