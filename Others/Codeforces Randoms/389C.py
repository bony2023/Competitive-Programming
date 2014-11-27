n=int(input())
listn=list(map(int, input().split()))
listn=sorted(listn)

i=0
res=0
vis=[]

while i<n:
    res+=1
    currPile=[]
    k=0
    while k<n:
        if listn[k]>=len(currPile) and not k in vis:
            i+=1; vis.append(k); currPile.append(1)
        k+=1
print(res)