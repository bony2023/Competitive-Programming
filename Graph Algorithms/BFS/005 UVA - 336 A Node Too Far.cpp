// Author : Bony Roopchandani
// 336 - A Node Too Far
// BFS

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
typedef vector < int >VI;
typedef vector < ll > VL;
typedef pair < int, int >PII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LL;

VI A[31];
int vis[31];

int BFS(int a, int TTL)
{
	int tot = 1;
	int dist[31];

	rep(i, 31) vis[i] = 0, dist[i] = INF;

	queue < int >Q;
	Q.push(a);
	dist[a] = 0;
	vis[a] = 1;

	while (!Q.empty())
	{
		int z = Q.front();
		Q.pop();

		rep(i, A[z].sz)
		{
			if (!vis[A[z][i]])
			{
				vis[A[z][i]] = 1;
				if (dist[A[z][i]] > dist[z] + 1 && dist[z] + 1 <= TTL)
				{
					dist[A[z][i]] = dist[z] + 1;
					tot++;
				}

				Q.push(A[z][i]);
			}
		}
	}
	return tot;
}

int main(void)
{
//freopen("output.txt", "w", stdout);
	int N, cse = 0;
	MII mp;

	while (1)
	{
		sfi(N);
		if (N == 0)
			break;

		int c = 1, a, b, i, j;

		rep(k, N)
		{
			sfi(a);
			sfi(b);
			if (mp[a] != 0)
				i = mp[a];
			else
				i = mp[a] = c++;

			if (mp[b] != 0)
				j = mp[b];
			else
				j = mp[b] = c++;

			A[i].pb(j);
			A[j].pb(i);
		}

		while (1)
		{
			sfi(a);
			sfi(b);
			cse++;
			if (!a && !b)
			{
				cse--;break;
			}

			int z = BFS(mp[a], b);

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cse, c-z-1, a, b);  
		}

		rep(i, c) A[i].clear();
		mp.clear();
	}
	
	return 0;
}