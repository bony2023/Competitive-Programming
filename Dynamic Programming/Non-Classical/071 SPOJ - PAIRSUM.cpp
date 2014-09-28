// Author : Bony Roopchandani
// PAIRSUM
// DP+Math

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
#define in(x) freopen(x, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(x) freopen(x, "w", stdout)
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

ll Sum[100000+5];
ll Sqr[100000+5];

ll P(int u, int v)
{
	return Sum[u]*Sum[v];
}

ll D(int u, int v)
{
	return Sqr[v]-Sqr[u-1];
}

ll F(int u, int v)
{
	return ((P(v, v)-2*P(u-1, v)+P(u-1, u-1)+D(u, v))/2);
}

int main(void)
{
	int N; sfi(N);
	int A[100000+5];
	
	rep(i, N)
	sfi(A[i]);
	
	Sum[0]=A[0];
	Sqr[0]=pow(A[0], 2);
	
	rept(i, 1, N-1)
	{
		Sum[i]=A[i]+Sum[i-1];
		Sqr[i]=pow(A[i], 2)+Sqr[i-1];
	}
	
	int Q; sfi(Q);
	int u, v;
	
	rep(i, Q)
	{
		sfi(u), sfi(v);
		pfl(F(u, v));
	}
	return (0);
}