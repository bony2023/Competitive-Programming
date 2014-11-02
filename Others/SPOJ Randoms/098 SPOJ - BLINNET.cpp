// Author : Bony Roopchandani
// BLINNET
// Kruskal MST

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

int pa[10000+5];

void init(int N)
{
	memset(pa, 0, sizeof pa);
	
	rept(i, 1, N)
	{
		pa[i]=i;
	}
}

int findpa(int u)
{
	return pa[u]==u?u:findpa(pa[u]);
}

bool sameSet(int u, int v)
{
	return findpa(u)==findpa(v);
}

void unionSet(int u, int v)
{
	pa[findpa(u)]=findpa(v);
}

bool cmp(pair<ll, PII> a, pair<ll, PII> b)
{
	return a.ff<b.ff;
}

int main(void)
{
	int T; sfi(T);
	char name[15];
	int M, x;
	ll c;
	
	while(T--)
	{
		int N; sfi(N);
		vector<pair<ll, PII> > a;
		
		rept(i, 1, N)
		{
			sfs(name);
			sfi(M);
			
			rep(j, M)
			{
				sfi(x), sfl(c);
				a.pb(mp(c, mp(i, x)));
			}
		}
		
		sort(all(a), cmp);
		ll mincost=0;
		init(N);
		
		rep(i, a.sz)
		{
			int u=a[i].ss.ff;
			int v=a[i].ss.ss;
			
			if(!sameSet(u, v))
			{
				unionSet(u, v);
				mincost+=a[i].ff;
			}
		}
		
		pfl(mincost);
		a.clear();
	}
	
	return (0);
}