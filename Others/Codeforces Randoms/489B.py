def Fabs(a):
    if a<0:
        return -a
    else:
        return a

def solve(listB, listG):
    res=0;
    cntb=0
    
    while cntb<len(listB):
        cntg=0
        while cntg<len(listG):
            if Fabs(listB[cntb]-listG[cntg])<=1:
                res+=1
                listG[cntg]=10000
                listB[cntb]=10000
            cntg+=1
        cntb+=1
    return res
    
listB=[]
listG=[]
b=input()
listB=list(map(int, input().split()))
g=input()
listG=list(map(int, input().split())) 
listB=sorted(listB)
listG=sorted(listG)
print(solve(listB, listG))