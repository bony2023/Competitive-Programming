// Author : Bony Roopchandani
// CATM
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

int Cdist[101][101], Mdist[101][101], N, M;

void MBFS(PII a)
{
	int vis[101][101];

	rep(i, N)
	{
		rep(j, M) vis[i][j] = 0, Mdist[i][j] = INF;
	}

	vis[a.ff][a.ss] = 1;
	Mdist[a.ff][a.ss] = 0;
	queue < PII > Q;
	Q.push(a);

	while (!Q.empty())
	{
		PII z = Q.front();
		Q.pop();

		if (!vis[z.ff - 1][z.ss] && z.ff - 1 >= 0 && z.ff - 1 < N && z.ss >= 0
			&& z.ss < M)
		{
			vis[z.ff - 1][z.ss] = 1;
			if (Mdist[z.ff - 1][z.ss] > Mdist[z.ff][z.ss] + 1)
				Mdist[z.ff - 1][z.ss] = Mdist[z.ff][z.ss] + 1;
			Q.push(mp(z.ff - 1, z.ss));
		}

		if (!vis[z.ff + 1][z.ss] && z.ff + 1 >= 0 && z.ff + 1 < N && z.ss >= 0
			&& z.ss < M)
		{
			vis[z.ff + 1][z.ss] = 1;
			if (Mdist[z.ff + 1][z.ss] > Mdist[z.ff][z.ss] + 1)
				Mdist[z.ff + 1][z.ss] = Mdist[z.ff][z.ss] + 1;
			Q.push(mp(z.ff + 1, z.ss));
		}

		if (!vis[z.ff][z.ss - 1] && z.ff >= 0 && z.ff < N && z.ss - 1 >= 0
			&& z.ss - 1 < M)
		{
			vis[z.ff][z.ss - 1] = 1;
			if (Mdist[z.ff][z.ss - 1] > Mdist[z.ff][z.ss] + 1)
				Mdist[z.ff][z.ss - 1] = Mdist[z.ff][z.ss] + 1;
			Q.push(mp(z.ff, z.ss - 1));
		}

		if (!vis[z.ff][z.ss + 1] && z.ff >= 0 && z.ff < N && z.ss + 1 >= 0
			&& z.ss + 1 < M)
		{
			vis[z.ff][z.ss + 1] = 1;
			if (Mdist[z.ff][z.ss + 1] > Mdist[z.ff][z.ss] + 1)
				Mdist[z.ff][z.ss + 1] = Mdist[z.ff][z.ss] + 1;
			Q.push(mp(z.ff, z.ss + 1));
		}
	}
}

void CBFS(PII a, PII b)
{
	int vis[101][101];

	rep(i, N)
	{
		rep(j, M) vis[i][j] = 0, Cdist[i][j] = INF;
	}

	vis[a.ff][a.ss] = 1;
	vis[b.ff][b.ss] = 1;
	Cdist[a.ff][a.ss] = Cdist[b.ff][b.ss] = 0;
	queue < PII > Q;
	Q.push(a);
	Q.push(b);

	while (!Q.empty())
	{
		PII z = Q.front();
		Q.pop();

		if (!vis[z.ff - 1][z.ss] && z.ff - 1 >= 0 && z.ff - 1 < N && z.ss >= 0
			&& z.ss < M)
		{
			vis[z.ff - 1][z.ss] = 1;
			if (Cdist[z.ff - 1][z.ss] > Cdist[z.ff][z.ss] + 1)
				Cdist[z.ff - 1][z.ss] = Cdist[z.ff][z.ss] + 1;
			Q.push(mp(z.ff - 1, z.ss));
		}

		if (!vis[z.ff + 1][z.ss] && z.ff + 1 >= 0 && z.ff + 1 < N && z.ss >= 0
			&& z.ss < M)
		{
			vis[z.ff + 1][z.ss] = 1;
			if (Cdist[z.ff + 1][z.ss] > Cdist[z.ff][z.ss] + 1)
				Cdist[z.ff + 1][z.ss] = Cdist[z.ff][z.ss] + 1;
			Q.push(mp(z.ff + 1, z.ss));
		}

		if (!vis[z.ff][z.ss - 1] && z.ff >= 0 && z.ff < N && z.ss - 1 >= 0
			&& z.ss - 1 < M)
		{
			vis[z.ff][z.ss - 1] = 1;
			if (Cdist[z.ff][z.ss - 1] > Cdist[z.ff][z.ss] + 1)
				Cdist[z.ff][z.ss - 1] = Cdist[z.ff][z.ss] + 1;
			Q.push(mp(z.ff, z.ss - 1));
		}

		if (!vis[z.ff][z.ss + 1] && z.ff >= 0 && z.ff < N && z.ss + 1 >= 0
			&& z.ss + 1 < M)
		{
			vis[z.ff][z.ss + 1] = 1;
			if (Cdist[z.ff][z.ss + 1] > Cdist[z.ff][z.ss] + 1)
				Cdist[z.ff][z.ss + 1] = Cdist[z.ff][z.ss] + 1;
			Q.push(mp(z.ff, z.ss + 1));
		}
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);
	int T;
	int X, Y, P, Q;

	sfi(N);
	sfi(M);

	sfi(T);

	rep(i, T)
	{
		bool cond = false;
		sfi(X);
		sfi(Y);
		MBFS(mp(X - 1, Y - 1));

		sfi(X);
		sfi(Y);

		sfi(P);
		sfi(Q);
		CBFS(mp(X - 1, Y - 1), mp(P - 1, Q - 1));

		rep(j, N)
		{
			if (Mdist[j][0] < Cdist[j][0] || Mdist[j][M - 1] < Cdist[j][M - 1])
			{
				printf("YES\n");
				cond = true;
				break;
			}
		}

		if (!cond)
			rep(j, M)
		{
			if (Mdist[0][j] < Cdist[0][j] || Mdist[N - 1][j] < Cdist[N - 1][j])
			{
				printf("YES\n");
				cond = true;
				break;
			}
		}

		if (!cond)
			printf("NO\n");
	}

	return 0;
}