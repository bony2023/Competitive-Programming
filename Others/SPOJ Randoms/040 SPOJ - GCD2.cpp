// Author : Bony Roopchandani
// GCD2
// GCD + Reduction to MOD

#include <cstdio>
#include <cstring>
#define sfi(a) scanf("%d",&a)

int ReduceMOD(char* b, int a)
{
	int B=b[0]-'0';
	
	for(int i=1; i<strlen(b); i++)
	{
		B*=10;
		B+=(b[i]-'0');
		B%=a;
	}
	
	return B;
}

int gcd(int a, int b)
{
	if(!b)
	return a;
	
	else return gcd(b, a%b);
}

int main(void)
{
	int T; sfi(T);
	int a;
	
	while(T--)
	{
		char b[300]={0};
		sfi(a), scanf("%s",b);
		
		if(!a)
		puts(b);
		else
		printf("%d\n",gcd(a, ReduceMOD(b, a)));
	}
	
	return (0);
}