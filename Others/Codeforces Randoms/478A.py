a, b, c, d, e=map(int, input().split())
a=a+b+c+d+e
if not a or a%5:
    print(-1)
else:
    print(a%5)