def solve(l, r):
    if r-l+1<3:
        print(-1)
        return
    if l%2==0:
        print(l, end=' '); print(l+1, end=' '); print(l+2)
        return
    if r-l+1>3:
        print(l+1, end=' '); print(l+2, end=' '); print(l+3)
        return
    print(-1)

l, r=map(int, input().split())
solve(l, r)
''''''