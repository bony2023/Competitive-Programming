color=list(map(int, input().split()))
color=sorted(color)
if color[2]>=2*(color[0]+color[1]): print(color[0]+color[1])
else: 
    summ=0; 
    for i in color: summ+=i; 
    print(summ//3)