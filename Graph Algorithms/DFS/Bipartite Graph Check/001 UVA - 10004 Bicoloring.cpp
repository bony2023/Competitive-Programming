// Author : Bony Roopchandani
// 10004 - Bicoloring
// Bipartite Graph Checking

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

VI A[200+5];
MII a;
bool isBicolored=true;

void dfs(int u)
{
	rep(i, A[u].sz)
	{
		if(!a.count(A[u][i]))
		a[A[u][i]]=1-a[u], dfs(A[u][i]);
		else
		if(a[A[u][i]]==a[u])
		{
			isBicolored=false;
			return;
		}
	}
}

void clearAll(int V)
{
	rep(i, V)
	A[i].clear();
	a.clear();
	isBicolored=true;
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int N;
	while(sfi(N) && N)
	{
		int M; sfi(M);
		
		int x, y;
		
		rep(i, M)
		{
			sfi(x), sfi(y);
			A[x].pb(y);
			A[y].pb(x);
		}
		
		a[0]=1;
		
		dfs(0);
		
		if(isBicolored)
		pfs("BICOLORABLE.");
		else
		pfs("NOT BICOLORABLE.");
		
		clearAll(N);
	}
	return 0;
}