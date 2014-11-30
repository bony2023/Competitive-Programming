n=int(input())
a=list(map(int, input().split()))
prevH=0
currEnergy=0
res=0

for i in a:
    cost=prevH-i
    if cost<0:
        if currEnergy<(-cost):
            res+=((-cost)-currEnergy)
            currEnergy=0
        elif currEnergy>=(-cost):
            currEnergy+=cost
    else:
        currEnergy+=cost
    prevH=i
print(res)