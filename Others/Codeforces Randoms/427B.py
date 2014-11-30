n,limit,c=map(int, input().split())
listn=list(map(int, input().split()))
res=0
prev=-1
i=0

while i<n:
    if listn[i]>limit:
        res+=max(i-prev-c, 0)
        prev=i
    i+=1
res+=max(n-prev-c, 0)
print(res)