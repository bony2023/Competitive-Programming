curr, k=map(int, input().split())
done=[]
unused=[]

for i in range(k):
    op=list(map(int, input().split()))
    op.pop(0)
    for j in op:
        done.append(j)
    
i=1
while i<curr:
    if not i in done:
        unused.append(i)
    i+=1

i=0
res=0
while i<len(unused):
    if (i+1)<len(unused) and unused[i]+1==unused[i+1]:
        i+=2
    else:
        i+=1
    res+=1

print(res, end=' '); print(len(unused))