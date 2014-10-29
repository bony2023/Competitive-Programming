// Author : Bony Roopchandani
// BABTWR
// Stacking Box Problem (DP/LIS)

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
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
typedef list < int > LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int > MII;
typedef map < int, ll > MIL;
typedef map < ll, int > MLI;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef set < int > SI;
typedef set < ll > SLL;
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

struct Box
{
	int x, y, z;
};

bool cmp(Box a, Box b)
{
	return ((a.y*a.z)<(b.y*b.z));
}

ll generate(Box* B, int& N)
{
	int n=N, x, y, z;

	rep(i, n)
	{
		x=B[i].x, y=B[i].y, z=B[i].z;
		B[N].x=y, B[N].y=x, B[N].z=z;
		++N;
		B[N].x=z, B[N].y=y, B[N].z=x;
		++N;
	}
	
	sort(B, B+N, cmp);
	
	ll LIS[N+5], P;
	LIS[0]=B[0].x;
	
	rept(i, 1, N-1)
	{
		P=0;
		
		rep(j, i)
		{
			if((B[j].y<B[i].y && B[j].z<B[i].z) || (B[j].z<B[i].y && B[j].y<B[i].z))
			P=max(P, LIS[j]);
		}
		
		LIS[i]=B[i].x+P;
	}

	return LIS[N-1];
}

int main(void)
{
	int N;
	
	while(sfi(N) && N)
	{
		Box B[3*N+5];
		
		rep(i, N)
		{
			sfi(B[i].x);
			sfi(B[i].y);
			sfi(B[i].z);
		}
		
		pfl(generate(B, N));
	}
	
	return (0);
}