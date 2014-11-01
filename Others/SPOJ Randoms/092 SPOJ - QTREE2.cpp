// Author : Bony Roopchandani
// QTREE2
// Lowest Common Ancestor

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

const int MAXN=1<<17;
const int logN=17;

vector<pair<int, long> >A[MAXN];
int depth[MAXN], N;
int p[logN][MAXN];
long dist[MAXN];

void dfs(int pa, int u, int dep)
{
	depth[u]=dep;
	
	rep(i, A[u].sz)
	{
		int v=A[u][i].ff;
		long d=A[u][i].ss;
		
		if(v != pa)
		{
			p[0][v]=u;
			dist[v]=dist[u]+d;
			dfs(u, v, dep+1);
		}
	}
}

int LCA(int u, int v)
{
	if(depth[u]<depth[v])
	swap(u, v);
	
	int log;
	
	for(log=1; (1<<log)<=depth[u]; log++);
	log--;
	
	for(int i=log; i>=0; i--)
	{
		if(depth[u]-(1<<i)>=depth[v])
		u=p[i][u];
	}
	
	if(u==v) return v;
	
	for(int i=log; i>=0; i--)
	{
		if(p[i][u] != -1 && p[i][u] != p[i][v])
		u=p[i][u], v=p[i][v];
	}
	
	return p[0][v];
}

int query(int u, int depthL)
{
	int log;
	
	for(log=1; (1<<log)<=depth[u]; log++);
	log--;
	
	for(int i=log; i>=0; i--)
	if(depth[u]-(1<<i)>=depthL)
	u=p[i][u];
	
	return u;
}

int main(void)
{
//	in("input.txt");
	
	int T; sfi(T);
	int x, y, K;
	long c, d;
	char z[10];
	
	while(T--)
	{
		sfi(N);
		
		rep(i, N-1)
		{
			sfi(x), sfi(y);
		      scanf("%ld",&c);
		      A[x].pb(mp(y, c));
		      A[y].pb(mp(x, c));
		}
		
		memset(dist, 0, sizeof dist);
		memset(p, -1, sizeof p);
		depth[1]=0;
		dist[1]=0;
		dfs(-1, 1, 0);
		
		for(int i=1; i<=N; i++)
		{
			for(int j=1; (1<<j)<N; j++)
			{
				if(p[j-1][i] != -1)
				p[j][i]=p[j-1][p[j-1][i]];
			}
		}
		
		while(1)
		{
			sfs(z);
			
			if(!strcmp(z, "DONE"))
			break;
			
			sfi(x), sfi(y);
			
			if(!strcmp(z, "DIST"))
			{
				d=dist[x]+dist[y]-2*dist[LCA(x, y)];
				printf("%ld\n", d);
			}
			
			else
			{
				int q=LCA(x, y);
				sfi(K);
				
				if(depth[x]-depth[q]+1 >=K)
				d=query(x, depth[x]-K+1);
				else
				d=query(y, 2*depth[q]+K-depth[x]-1);
				printf("%ld\n", d);
			}
		}
		
		nl;
		
		rept(i, 1, N)
		A[i].clear();
	}
	
	return (0);
}