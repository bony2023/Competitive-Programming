// Author : Bony Roopchandani
// 11504 - Dominos
// TopoSort + SCC

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=0; i<=n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define repli(i, n) for(ll i=0; i<=n; i++)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define CHUNK_SIZE 65536
#define MOD 1000000007
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LLL;
typedef set<int> SI;
typedef set<ll> SLL;

VI A[100001];
LI foo;
bool vis[100001]={0};

void TopoSort(int u)
{
	vis[u]=1;
	
	int s=A[u].sz;
	
	rep(i, s)
	{
		int z=A[u][i];
		
		if(!vis[z])
		TopoSort(z);
	}
	
	foo.push_front(u);
}

void dfs(int u)
{
	vis[u]=1;
	
	int s=A[u].sz;
	
	rep(i, s)
	{
		int z=A[u][i];
		
		if(!vis[z])
		dfs(z);
	}
}

void clearAll(int V)
{
	rept(i, 1, V)
	A[i].clear();
	foo.clear();
	memset(vis, 0, sizeof vis);
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T; sfi(T);
	
	while(T--)
	{
		int N, M;
		sfi(N); sfi(M);
		
		int x, y;
		
		rep(i, M)
		{
			sfi(x); sfi(y);
			A[x].pb(y);
		}
		
		rept(i, 1, N)
		if(!vis[i])
		TopoSort(i);
		
		memset(vis, 0, sizeof vis);
		
		LI::iterator t;
		int tot=0;
		
		for(t=foo.bg; t!=foo.en; t++)
		if(!vis[*t])
		tot++, dfs(*t);
		
		pfi(tot);
		
		clearAll(N);
	}
	
	return 0;
}