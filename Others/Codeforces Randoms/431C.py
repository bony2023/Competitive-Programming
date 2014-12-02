n,k,d=map(int, input().split())
dp={}
vis=[]

def F(curr, poss):
    if curr<0:
        return 0
    if curr==0 and poss==1:
        return 1
    if (curr, poss) in vis:
        return dp[(curr, poss)]
    i=1
    vis.append((curr, poss))
    dp[(curr, poss)]=0
    while i<d:
        dp[(curr, poss)]+=F(curr-i, poss)
        i+=1
    i=d
    while i<=k:
        dp[(curr, poss)]+=F(curr-i, 1)
        i+=1
    return dp[(curr, poss)]%1000000007
    
print(F(n, 0))
