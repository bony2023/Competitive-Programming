// Author : Bony Roopchandani
// 10067 - Playing with Wheels
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

int pred[10000];

int BFS(int u, int v, MII & forb)
{
	int vis[10001], dist[10001], p;
	char num[5];

	rep(i, 10000) vis[i] = 0, dist[i] = INF;

	queue < int >Q;
	Q.push(u);
	dist[u] = 0;
	vis[u] = 1;

	while (!Q.empty())
	{
		int z = Q.front();
		Q.pop();
		// pfi(z);
		if (forb[z] == 'R')
			continue;

		// pfi(z);
		if (z == v)
			return dist[v];

		repd(i, 3, 0)
		{
			sprintf(num, "%4d", z);

			rep(j, 4) if (num[j] < '0' || num[j] > '9')
				num[j] = '0';

			int t = z;

			if (num[i] == '0')
			{
				num[i] = '9';
				p = atoi(num);
			}
			else
				p = t - pow(10, 3 - i);

			if (!vis[p] && forb[p] != 'R')
			{
				vis[p] = 1;
				if (dist[p] > dist[z] + 1)
					dist[p] = dist[z] + 1;
				Q.push(p);
				pred[p] = z;
			}

			sprintf(num, "%4d", z);

			rep(j, 4) if (num[j] < '0' || num[j] > '9')
				num[j] = '0';

			if (num[i] == '9')
			{
				num[i] = '0';
				p = atoi(num);
			}
			else
				p = t + pow(10, 3 - i);

			if (!vis[p] && forb[p] != 'R')
			{
				vis[p] = 1;
				if (dist[p] > dist[z] + 1)
					dist[p] = dist[z] + 1;
				Q.push(p);
				pred[p] = z;
			}
		}
	}

	return dist[v];
}

/*void print(int a, int b)
{
	if (b == a)
		return;

	print(a, pred[b]);

	pfi(pred[b]);
} */

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T;
	sfi(T);

	while (T--)
	{
		int S, E, foo;
		S = E = 0;
		MII forb;

		repd(i, 3, 0)
		{
			sfi(foo);
			S += pow(10, i) * foo;
		}

		repd(i, 3, 0)
		{
			sfi(foo);
			E += pow(10, i) * foo;
		}

		int N, t;
		sfi(N);

		rep(i, N)
		{
			t = 0;
			repd(j, 3, 0)
			{
				sfi(foo);
				t += pow(10, j) * foo;
			}
			forb[t] = 'R';
		}

		int p = BFS(S, E, forb);

		if (p >= INF)
			pfi(-1);
		else
			pfi(p);

//		print(S, E);

		getchar();
	}

	return 0;
}