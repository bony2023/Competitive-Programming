m,n=map(int, input().split())
res=float(0.0)

for i in range(m):
    res=res+((i+1)*(((i+1)/m)**n-(i/m)**n))
print(res)