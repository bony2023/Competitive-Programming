#include<cstdio>
#define S(a)scanf("%d",&a)
#define R(i,N)for(int i=1;i<=N;i++)
#define M(a,b)a>b?a:b
main(){int T;S(T);R(p,T){int A[103][103]={0},N,Q=0;S(N);R(i,N)R(j,i)S(A[i][j]),A[i][j]+=M(A[i-1][j],A[i-1][j-1]),Q=A[i][j]>Q?A[i][j]:Q;printf("%d\n",Q);}}