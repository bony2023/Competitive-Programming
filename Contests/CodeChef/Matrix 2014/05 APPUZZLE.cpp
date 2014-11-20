// Author : Bony Roopchandani
// APPUZZLE

// INCLUDES
#include <cstdio>
#define ll long long
#define nl printf("\n")
#define sfl(a) scanf("%lld",&a)

int main(void)
{
	ll T;
	sfl(T);
	while (T--)
	{
		ll a, b, Sum;
		sfl(a), sfl(b), sfl(Sum);
		
		ll N = 2 * Sum / (a + b);
		ll d = (b - a) / (N - 5);
		ll F = a - 2 * d;
		
		printf("%lld\n", N);
		for (ll i = 0, j = F; i < N; i++)
			printf("%lld ", j), j += d;
		nl;
	}
	return (0);
}