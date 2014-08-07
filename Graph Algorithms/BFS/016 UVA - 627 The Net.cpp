// Author : Bony Roopchandani
// 627 - The Net
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
typedef pair < int, PII > PIII;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LL;

VI A[305];
int pred[305];

int BFS(int u, int v)
{
	int vis[305] = { 0 };
	int dist[305];
	memset(dist, INF, sizeof dist);

	queue < int >Q;
	Q.push(u);
	dist[u] = 0;
	vis[u] = 1;
	pred[u] = -1;

	while (!Q.empty())
	{
		int z = Q.front();
		// pf(z);
		Q.pop();

		int s = A[z].sz;

		rep(i, s)
		{
			if (!vis[A[z][i]])
			{
				vis[A[z][i]] = 1;
				if (dist[A[z][i]] > dist[z] + 1)
					dist[A[z][i]] = dist[z] + 1;
				pred[A[z][i]] = z;
				if (A[z][i] == v)
					return dist[v];
				Q.push(A[z][i]);
			}
		}
	}

	return INF;
}

void print(int u)
{
	if (pred[u] == -1)
	{
		printf("%d",u);
		return;
	}
	print(pred[u]);
	printf(" %d",u);
}

int main(void)
{
//freopen("input.txt","r",stdin);
	int N;
	while (sfi(N) == 1)
	{
		getchar();
		char foo[200];
		rep(i, N)
		{
			gets(foo);
			int z = 0, p=0;
			
			while(foo[z]!='-')
			{
				p*=10;
				p+=(foo[z]-'0');
   		 	z++;
			}
			z++;
			
			while (z<strlen(foo))
			{
				if (foo[z] >= '0' && foo[z] <= '9')
				{
					int t = 0;
					while (foo[z]>='0' && foo[z]<='9')
					{
						t *= 10;
						t += (foo[z] - '0');
						z++;
					}
					A[p].pb(t);
				}
				
				z++;
			}
		}

		int M, S, E, P;
		sfi(M);
		
		printf ("-----\n");
		
		rep(i, M)
		{
			sfi(S);
			sfi(E);
			
			P = BFS(S, E);

			if (P >= INF)
				printf("connection impossible\n");
			else
			{
				print(E);
				nl;
			}
		}

		rept(i, 1, N) A[i].clear();
	}
	return 0;
}