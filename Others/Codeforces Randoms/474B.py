def search(a, x, limit):
    lo=0; hi=limit-1
    while lo<=hi:
        mid=(lo+hi)//2
        if mid==0 and a[mid]>=x:
            return mid+1
        elif a[mid]>=x and (a[mid-1]+1)<=x:
            return mid+1
        elif a[mid]<x:
            lo=mid+1
        else:
            hi=mid

n=int(input())
a=list(map(int, input().split()))
k=int(input())
tofind=list(map(int, input().split()))
cnt=1

while cnt<len(a):
    a[cnt]+=a[cnt-1]
    cnt+=1

for i in tofind:
    print(search(a, i, n))