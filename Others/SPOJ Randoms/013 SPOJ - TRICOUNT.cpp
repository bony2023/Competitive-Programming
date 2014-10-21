// Author : Bony Roopchandani
// TRICOUNT
// Ad-Hoc
#include<cstdio>
#include<cmath>
#define sfl(a) scanf("%llu",&a);
#define ull unsigned long long
ull count(ull N)
{
	if(N%2)
	return (N*(N+2)*(2*N+1)-1)/8;
	else 
	return (N*(N+2)*(2*N+1))/8;
}
int main(void)
{
	ull T; sfl(T);
	ull N;
	while(T--)
	{
		sfl(N);
		printf("%llu\n",count(N));
	}
	return (0);
}