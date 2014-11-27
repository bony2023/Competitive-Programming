R,C,x,y,z,p=map(int, input().split())
tmpR=R; tmpC=C

x%=4; y%=2; z%=4
z=4-z

for k in range(p):
    i, j=map(int, input().split())
    
    for t in range(x):
        tmpi=i
        i=j; j=R-tmpi+1
        R,C= C,R
    for t in range(y):
        j=C-(j-1)
    for t in range(z):
        tmpi=i
        i=j; j=R-tmpi+1
        R,C=C,R
    print(i, end=' '); print(j)
    R=tmpR; C=tmpC