from decimal import Decimal

a, d=map(Decimal, input().split())
n=int(input())
tot=Decimal(0.0)
x=Decimal(); y=Decimal()

for i in range(n):
    tot+=d
    tot%=4*a
    if tot<a: x=tot; y=0.0
    elif tot<2*a: x=a; y=tot-a
    elif tot<3*a: x=3*a-tot; y=a
    else: x=0.0; y=4*a-tot
    
    print(x, end=' '); print(y)
    