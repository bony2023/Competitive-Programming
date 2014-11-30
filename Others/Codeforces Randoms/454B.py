n=int(input())
a=list(map(int, input().split()))
lenfirst=0
cnt=0
i=1

while i<len(a):
    if a[i]<a[i-1]:
        if not cnt:
            lenfirst=i
        cnt+=1
    i+=1

if not cnt:
    print(0)
elif cnt>1:
    print(-1)
else:
    if a[lenfirst]<=a[0] and a[n-1]<=a[0]:
        print(n-lenfirst)
    else:
        print(-1)