// Author : Bony Roopchandani
// 315 - Network
// Articulation Points on Graph

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
bool B[101] = { 0 };
int dfsRoot, dfsRootChild;
int dfsCounter, dfsParent[101];
int dfsNum[101], dfsLow[101];

void AP(int u)
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

			if (u == dfsRoot)
				dfsRootChild++;

			AP(z);

			if (dfsLow[z] >= dfsNum[u])
				B[u] = 1;

			dfsLow[u] = min(dfsLow[u], dfsLow[z]);
		}
		else if (z != dfsParent[u])
			dfsLow[u] = min(dfsLow[u], dfsNum[z]);
	}
}

void getNeighbor(int x)
{
	int y, togg = 0;
	char c[501];
	gets(c);

	rep(i, strlen(c))
	{
		if (c[i] == ' ' && togg == 1)
		{
			A[x].pb(y);
			A[y].pb(x);
			togg=0;
		}
		else if (c[i] <= '9' && c[i] >= '0' && togg == 0)
		{
			togg = 1;
			y = c[i] - '0';
		}
		else if (c[i] <= '9' && c[i] >= '0' && togg == 1)
		{
			y *= 10;
			y += (c[i] - '0');
		}
	}
	if(togg==1)
	A[x].pb(y), A[y].pb(x);
}

void clearAll(int V)
{
	rept(i, 1, V)
	A[i].clear();
	
	memset(vis, 0, sizeof vis);
	memset(B, 0, sizeof B);
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	
	int N;

	while (sfi(N) && N)
	{
		int x;
		sfi(x);
		while (x)
		{
			getNeighbor(x);
			sfi(x);
		}

		dfsCounter = 0;

		rept(i, 1, N)
		{
			if (!vis[i])
			{
				dfsRoot = i;
				dfsRootChild = 0;

				AP(i);

				B[dfsRoot] = (dfsRootChild > 1);
			}
		}
		
		int t=0;
		
		rept(i, 1, N)
		if(B[i])
		t++;
		
		pfi(t);
		
		clearAll(N);
	}

	return 0;
}