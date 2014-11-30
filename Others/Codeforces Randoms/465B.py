n=int(input())
a=list(map(int, input().split()))
cnt=0
c=0
pos=-1
while cnt<len(a):
    if a[cnt]:
        c+=1
        if pos==-1:
            pos=cnt
    cnt+=1
res=0
cnt=1
while c:
    if a[pos]==1:
        if cnt<=2:
            res+=cnt
        else:
            res+=2
        cnt=0
        c-=1
    pos+=1
    cnt+=1
print(res)