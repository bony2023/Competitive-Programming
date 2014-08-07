// Author : Bony Roopchandani
// 610 - Street Directions
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
#define RES(a) memset(a, 0, sizeof a)
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

VI A[1000 + 10];
vector < PII > Bridges;
bool vis[1000 + 10] = { 0 };
int dfsCounter;
int dfsNum[1000 + 10];
int dfsLow[1000 + 10];
int dfsParent[1000 + 10];
bool done[1010][1010] = { {0} };

void AB(int u)
{
	dfsLow[u] = dfsNum[u] = dfsCounter++;
	vis[u] = 1;
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
				if (!done[u][z])
				{
					Bridges.pb(mp(u, z));
					Bridges.pb(mp(z, u));
					done[u][z] = done[z][u] = 1;
				}
			}
			else if (!done[u][z])
			{
				Bridges.pb(mp(u, z));
				done[u][z] = done[z][u] = 1;
			}

			dfsLow[u] = min(dfsLow[u], dfsLow[z]);
		}
		else if (z != dfsParent[u])
		{
			dfsLow[u] = min(dfsLow[u], dfsNum[z]);

			if (!done[u][z])
			{
				done[u][z] = done[z][u] = 1;
				Bridges.pb(mp(u, z));
			}
		}
	}
}

bool comp(PII a, PII b)
{
	return ((a.ff<b.ff) || (a.ff==b.ff && a.ss<b.ss));
}

void clearAll(int V)
{
	RES(done);
	RES(vis);
	
	rept(i, 1, V)
	A[i].clear();
	
	Bridges.clear();
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int N, M, cs=1;

	while (1)
	{
		sfi(N);
		sfi(M);

		if (!N && !M)
			break;

		int x, y;

		rep(i, M)
		{
			sfi(x);
			sfi(y);
			A[x].pb(y);
			A[y].pb(x);
		}

		dfsCounter = 0;

		rept(i, 1, N)
		{
			if (!vis[i])
			{
				AB(i);
			}
		}

		vector < PII >::iterator t;
		sort(Bridges.bg, Bridges.en, comp);
		
		pfi(cs++);
		nl;

		for (t = Bridges.bg; t != Bridges.en; t++)
			pf((*t).ff), pfi((*t).ss);
		
		pfs("#");
		
		clearAll(N);
	}
	return 0;
}