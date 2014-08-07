// Author : Bony Roopchandani
// 10305 - Ordering Tasks
// Topological Sort

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
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
#define MOD 1000000007
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef pair<int, PII>PIII;
typedef pair<int, PIII> PIIII;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LL;

VI A[101];
LI foo;
bool vis[101];

void dfs(int u)
{
	vis[u]=1;
	
	rep(i, A[u].sz)
	{
		if(!vis[A[u][i]])
		dfs(A[u][i]);
	}
	
	foo.push_front(u);
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int N, M;
	
	while(1)
	{
		sfi(N); sfi(M);
		
		if(!N && !M)
		break;
		
		int x, y;
		
		rep(i, M)
		{
			sfi(x); sfi(y);
			A[x].pb(y);
		}
		
		memset(vis, 0, sizeof vis);
		
		rept(i, 1, N)
		if(!vis[i])
		dfs(i);
		
		LI::iterator t;
		
		for(t=foo.bg; t!=foo.en; t++)
		pf(*t);
		nl;
		
		rept(i, 1, N)
		A[i].clear();
		foo.clear();
	}
	return 0;
}