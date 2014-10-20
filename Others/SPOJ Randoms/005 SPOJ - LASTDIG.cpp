/* Note: The Problem has a source limit of 700B. You have remove this comment and all the indentation to get it ACed. I have indented this to ensure readability */

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
#define pb push_back
#define pfl(a) printf("%lld\n",a)
#define sfl(a) scanf("%lld",&a)
#define sz size()
vector < ll > A[10 + 5];
ll getlastdig(ll x)
{
	char S[100] = { 0 };
	sprintf(S, "%lld", x);
	return S[strlen(S) - 1] - '0';
}

void preprocess()
{
	A[1].pb(1);
	for (int i = 2; i <= 20; i++)
	{
		ll x = i;
		A[i].pb(x);
		x = getlastdig(i * x);
		while (getlastdig(i) != x)
			A[i].pb(x), x = getlastdig(i * x);
	}
}

int main(void)
{
	ll x, y, T;
	sfl(T);
	preprocess();
	while (T--)
	{
		sfl(x), sfl(y);
		if (x >= 10)
			x -= 10;
		if (y == 0)
			pfl((ll) 1);
		else if (x == 0)
			pfl((ll) 0);
		else if (A[x].sz == 1)
			pfl(getlastdig(x));
		else
			y--, pfl(A[x][y % A[x].sz]);
	}
	return (0);
}