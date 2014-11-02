// Author : Bony Roopchandani
// MICEMAZE
// Dijkstra

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

vector<PLI> a[100+5];
int N, E, T;

ll dijkstra(int s)
{
	VLL dist(N+5, 1e8);
	dist[s]=0;
	priority_queue<PLI, vector<PLI>, greater<PLI> > Q;
	Q.push(mp(0, s));
	
	while(!Q.empty())
	{
		int u=Q.top().ss;
		ll d=Q.top().ff;
		Q.pop();
		
		if(d==dist[u])
		{
			rep(i, a[u].sz)
			{
				int v=a[u][i].ss;
				ll vdist=a[u][i].ff;
				
				if(dist[v]>dist[u]+vdist)
				{
					dist[v]=dist[u]+vdist;
					Q.push(mp(dist[v], v));
				}
			}
		}
	}
	
	ll cnt=0;
	
	rept(i, 1, N)
	{
		if(dist[i]<=T)
		{
			cnt++;
		}
	}
	
	return cnt;
}

int main(void)
{
	sfi(N), sfi(E), sfi(T);
	int M, x, y; sfi(M);
	ll c;
	
	rep(i, M)
	{
		sfi(x), sfi(y), sfl(c);
		a[y].pb(mp(c, x));
	}
	
	pfl(dijkstra(E));
	
	return (0);
}