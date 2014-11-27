n, m=map(int, input().split())
c=n//m
print((m*c*(c-1))//2+c*(n%m), end=' '); print(((n+1-m)*(n-m))//2)