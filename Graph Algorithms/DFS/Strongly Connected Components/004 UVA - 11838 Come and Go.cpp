// Author : Bony Roopchandani
// 11838 - Come and Go
// SCC - Tarjan's

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
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int >PII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LLL;
typedef set < int >SI;
typedef set < ll > SLL;

VI A[2000+5];
VI dfsLow, dfsNum, vis, S;
int dfsCounter, tot;

void Tarjan(int u)
{
	vis[u]=1;
	dfsLow[u]=dfsNum[u]=dfsCounter++;
	S.pb(u);
	int s=A[u].sz;
	
	rep(i, s)
	{
		int z=A[u][i];
		
		if(dfsNum[z]==-1)
		Tarjan(z);
		
		if(vis[z])
		dfsLow[u]=min(dfsLow[u], dfsLow[z]);
	}
	
	if(dfsLow[u]==dfsNum[u])
	{
		while(1)
		{
			int z=S.back();
			S.pop_back();
			vis[z]=0;
			if(u==z)
			break;
		}
		tot++;
	}
}

void clearAll(int V)
{
	rept(i, 1, V)
	A[i].clear();
	S.clear();
	dfsNum.clear();
	dfsLow.clear();
	vis.clear();
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	while (1)
	{
		int N, M;
		
		sfi(N);
		sfi(M);

		if (!N && !M)
			break;

		int x, y, P;

		rep(i, M)
		{
			sfi(x), sfi(y), sfi(P);
			A[x].pb(y);
			if (P == 2)
				A[y].pb(x);
		}
		
		dfsCounter=tot=0;
		dfsNum.assign(N+5, -1);
		dfsLow.assign(N+5, 0);
		vis.assign(N+5, 0);
		
		rept(i, 1, N)
		{
			if(dfsNum[i]==-1)
			Tarjan(i);
		}
		
		pfi((tot==1)?1:0);
		
		clearAll(N);
	}
	return 0;
}