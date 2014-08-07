// Author : Bony Roopchandani
// 796 - Critical Links
// Bridges

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

VI A[101];
bool vis[101] = { 0 };

vector < PII > B;
int dfsCounter;
int dfsLow[101], dfsNum[101];
int dfsParent[101];

void AB(int u)
{
	vis[u] = 1;
	dfsLow[u] = dfsNum[u] = dfsCounter++;
	int s = A[u].sz;

	rep(i, s)
	{
		int z = A[u][i];

		if (!vis[z])
		{
			dfsParent[z] = u;

			AB(z);

			if (dfsLow[z] > dfsNum[u])
			{
				if(u<z)
				B.pb(mp(u, z));
				else
				B.pb(mp(z, u));
			}

			dfsLow[u] = min(dfsLow[u], dfsLow[z]);
		}
		else if (z != dfsParent[u])
			dfsLow[u] = min(dfsLow[u], dfsNum[z]);
	}
}

void getNeighbors(int x)
{
	int Q = 0, y, i = 0;
	char c[201];
	sfs(c);

	while (c[i] != ')')
	{
		if (c[i] >= '0' && c[i] <= '9')
			Q *= 10, Q += (c[i] - '0');
		i++;
	}

	rep(i, Q)
	{
		sfi(y);
		A[x].pb(y);
		A[y].pb(x);
	}
}

void clearAll(int V)
{
	rep(i, V) A[i].clear();
	B.clear();

	memset(vis, 0, sizeof vis);
	memset(dfsParent, 0, sizeof dfsParent);
}

bool comp(PII a, PII b)
{
	return (a.ff<b.ff || (a.ff==b.ff && a.ss<b.ss));
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int N;

	while (sfi(N) != EOF)
	{
		int x;
		rep(i, N)
		{
			sfi(x);
			getNeighbors(x);
		}

		dfsCounter = 0;

		rep(i, N)
		{
			if (!vis[i])
			{
				AB(i);
			}
		}
		
		sort(B.bg, B.en, comp);

		printf("%d critical links\n", B.sz);

		rep(i, B.sz) printf("%d - %d\n", B[i].ff, B[i].ss);
		nl;

		clearAll(N);
	}
	return 0;
}