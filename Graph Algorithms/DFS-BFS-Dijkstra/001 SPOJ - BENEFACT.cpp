// Author : Bony Roopchandani
// BENEFACT
// Diameter of a Tree

//INCLUDES
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

//MACROS
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i=0; i<n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD (1e9 + 7)

//TYPEDEFS
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef map<int, bool> MIB;
typedef list<int> LI;
typedef list<ll> LLL;
typedef set<int> SI;
typedef set<ll> SLL;

int maxx, pos;
vector<PII> A[50000+5];
VI vis;

void dfs(int u, int d)
{
	vis[u]=1;
	
	rep(i, A[u].sz)
	{
		int z=A[u][i].ff;
		int D=A[u][i].ss;
		
		if(!vis[z])
		{
			dfs(z, d+D);
		}
	}
	
	if(maxx<d)
	{
		maxx=d;
		pos=u;
	}
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		int N; sfi(N);
		vis.assign(N+5, 0);
		
		int x, y, l;
		
		rep(i, N-1)
		{
			sfi(x), sfi(y), sfi(l);
			
			A[x].pb(PII(y, l));
			A[y].pb(PII(x, l));
		}
		
		maxx=pos=0;
		
		dfs(1, 0);
		
		vis.assign(N+5, 0);
		
		dfs(pos, 0);
		
		pfi(maxx);
		
		rep(i, N+5)
		A[i].clear();
	}
	
	return 0;
}