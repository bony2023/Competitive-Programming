// Author : Bony Roopchandani
// 

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

ll Cost[100000+5];
VI a[100000+5], stackq, dfslo, dfsnum;
int dfscount=1;
bool vis[100000+5]={0};
ll res=0, ways=1;

void dfs(int u)
{
	vis[u]=1;
	stackq.pb(u);
	dfsnum[u]=dfslo[u]=dfscount++;
	
	rep(i, a[u].sz)
	{
		if(dfsnum[a[u][i]]==-1)
		dfs(a[u][i]);
		
		if(vis[a[u][i]])
		{
			dfslo[u]=min(dfslo[u], dfslo[a[u][i]]);
		}
	}
	
	if(dfslo[u]==dfsnum[u])
	{
		ll nways=0, mn=10000000000;
		
		while(1)
		{
			int z=stackq.back();
			stackq.pop_back();
			if(Cost[z]<mn)
			mn=Cost[z], nways=1;
			else if(Cost[z]==mn)
			nways+=1;
			vis[z]=0;
			
			if(u==z) break;
		}
		
		res+=mn;
		ways=(ways*(nways%MOD))%MOD;
	}
}

int main(void)
{
	int N; sfi(N);
	rept(k, 1, N)
	sfl(Cost[k]);
	
	int m, x, y; sfi(m);
	
	rep(i, m)
	{
		sfi(x), sfi(y);
		a[x].pb(y);
	}
	
	dfsnum.assign(N+5, -1);
	dfslo.resize(N+5);
	
	rept(i, 1, N)
	{
		if(dfsnum[i]==-1) dfs(i);
	}
	
	printf("%lld %lld\n", res, ways);
	
	return (0);
}