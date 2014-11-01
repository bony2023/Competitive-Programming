// Author : Bony Roopchandani
// LCA
// Lowest Common Ancestor DP

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

void scanint(int &x)
{
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for (; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
	{
		x = (x << 1) + (x << 3) + c - 48;
	}
	if (neg)
		x = -x;
}

VI A[1000+5];
int depth[1000+5];
int p[1000+5][1000+5];
int N;

void dfs(int u)
{
	rep(i, A[u].sz)
	{
		int v=A[u][i];
		
		if(!depth[v])
		{
			depth[v]=depth[u]+1;
			p[v][0]=u;
			dfs(v);
		}
	}
}

int LCA(int u, int v)
{
	if(depth[u]<depth[v])
	swap(u, v);
	
	int log, i;
	
	for(log=1; (1<<log)<=depth[u]; log++);
	log--;
	
	for(i=log; i>=0; i--)
	if(depth[u]-(1<<i)>=depth[v])
	u=p[u][i];
	
	if(u==v)
	return u;
	
	for(i=log; i>=0; i--)
	{
		if(p[u][i] != -1 && p[u][i] != p[v][i])
		u=p[u][i], v=p[v][i];
	}
	
	return p[u][0];
}

int main(void)
{
	int T; scanint(T);
	int M, x, u, v, cs=1;
	
	while(T--)
	{
		scanint(N);
		
		rep(i, N+1)
		for(int j=0; (1<<j)<N; j++)
		p[i][j]=-1;
		
		rept(i, 1, N)
		{
			scanint(M);
			
			rep(j, M)
			{
				scanint(x);
				p[x][0]=i;
				A[i].pb(x);
			}
		}
		
		memset(depth, 0, sizeof depth);
		depth[1]=1;
		dfs(1);
		
		for(int j=1; (1<<j)<N; j++)
		{
			rept(i, 1, N)
			{
				if(p[i][j-1] != -1)
				p[i][j]=p[p[i][j-1]][j-1];
			}
		}
		
		int Q; scanint(Q);
		
		printf("Case %d:\n", cs++);
		
		while(Q--)
		{
			scanint(u), scanint(v);
			pfi(LCA(u, v));
		}
		
		rept(i, 1, N)
		A[i].clear();
	}
	return (0);
}