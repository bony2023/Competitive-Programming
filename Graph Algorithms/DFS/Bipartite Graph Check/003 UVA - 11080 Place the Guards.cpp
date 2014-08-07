// Author : Bony Roopchandani
// 11080 - Place the Guards
// Bipartite Graph Check

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
map<int, bool>a;
bool isBipartite=true;
int one=0, zero=0;

void dfs(int u)
{
	if(a[u])
	one++;
	else
	zero++;
	
	rep(i, A[u].sz)
	{
		if(!a.count(A[u][i]))
		a[A[u][i]]=1-a[u], dfs(A[u][i]);
		
		else if(a[u]==a[A[u][i]])
		isBipartite=false;
	}
}

void clearAll(int V)
{
	rep(i, V)
	A[i].clear();
	a.clear();
	one=zero=0;
	isBipartite=true;
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
			sfi(x), sfi(y);
			
			if(x>=0 && x<N && y>=0 && y<N)
			A[x].pb(y), A[y].pb(x);
		}
		
		int tot=0;
		
		rep(i, N)
		{
			if(!a.count(i))
			{
				a[i]=0, dfs(i);
				if(!one)
				one=INF;
				if(isBipartite)
				tot+=min(zero, one);
				else
				{
					tot=-1;
					break;
				}
				one=zero=0;
				isBipartite=true;
			}
		}
		
		if(tot)
		pfi(tot);
		else
		pfi(-1);
		
		clearAll(N);
	}
	return 0;
}