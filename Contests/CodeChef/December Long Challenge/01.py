t=int(input())
while t:
    t-=1
    n=int(input())
    a=list(map(int, input().split()))
    print(len(set(a)))
    