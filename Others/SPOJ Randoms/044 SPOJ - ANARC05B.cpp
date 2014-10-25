// Author : Bony Roopchandani
// ANARC05B
// Greedy

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// MACROS
#define all(a) a.begin(), a.end()
#define bg begin()
#define en end()
#define ff first
#define in(a) freopen(a, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(a) freopen(a, "w", stdout)
#define pb push_back
#define pf(a) printf("%d ",a)
#define pfi(a) printf("%d\n",a)
#define pfl(a) printf("%lld\n",(ll)a)
#define pfs(a) printf("%s\n",a)
#define rep(i, n) for(int i=0; i<n; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define repl(i, n) for(ll i=0; i<n; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define sfi(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define ss second
#define sz size()

// CONSTS
const double EPS = (1e-11);
const double PI = acos(-1.0);
const int INF = 9999999;
const int MOD = (1e9 + 7);

// TYPEDEFS
typedef list < int >LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int >MII;
typedef map < int, ll > MIL;
typedef map < ll, int >MLI;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef set < int >SI;
typedef set < ll > SLL;
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

const int offset = 10000 + 5;

int go(int N)
{
	bool foo[10010 + offset] = { 0 };
	VI points, a, b;
	VI A(N, 0);

	rep(i, N) sfi(A[i]), foo[A[i] + offset] = true;

	sfi(N);
	VI B(N, 0);

	rep(i, N)
	{
		sfi(B[i]);
		if (foo[B[i] + offset])
		{
			points.pb(B[i]);
		}
	}

	int curr = 0;
	int sumA = 0, sumB = 0;
	int inda = 0, indb = 0;

	while (curr < points.sz)
	{
		while (A[inda] != points[curr] && A[inda] < points[curr])
			sumA += A[inda], inda++;

		a.pb(sumA);

		while (B[indb] != points[curr] && B[indb] < points[curr])
			sumB += B[indb], indb++;

		b.pb(sumB);

		a.pb(points[curr]);
		b.pb(points[curr]);

		sumA = sumB = 0;
		inda++, indb++, curr++;
	}

	sumA = sumB = 0;

	rept(i, inda, A.sz - 1) 
	sumA += A[i];
	a.pb(sumA);

	rept(i, indb, B.sz - 1) 
	sumB += B[i];
	b.pb(sumB);

	int res = 0;

	rep(i, a.sz)
	{
		res += max(a[i], b[i]);

		if (i == a.sz - 1)
			break;

		res += a[i + 1];
		i++;
	}

	return res;
}

int main(void)
{
	int N;
	
	while (sfi(N) && N)
	{
		pfi(go(N));
	}

	return (0);
}