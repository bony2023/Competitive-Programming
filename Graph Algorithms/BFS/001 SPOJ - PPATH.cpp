// Author : Bony Roopchandani
// SPOJ - PPATH
// Algorithm - BFS

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=0; i<=n; i++)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define repli(i, n) for(ll i=0; i<=n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
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
typedef vector < long long >VL;
typedef pair < int, int >PI;

int prime[10000];

bool IsPrime(int a)
{
	if (a == 2) return true;

	if (a % 2 == 0) return false;

	int sq = (double)sqrt(a);

	rept(i, 3, sq)
	 if (a % i == 0) return false;

	return true;
}

void pre()
{
	memset(prime, false, sizeof prime);
	rept(i, 1000, 9999)
	 if (IsPrime(i)) prime[i] = true;
}

int BFS(int a, int b)
{
	char num[5];
	int dist[10000],           visited[10000]={0};

	repi(i, 10000) dist[i] = -1;

	queue < int >Q;
	Q.push(a);
	dist[a] = 0;
	visited[a] = 1;

	while (!Q.empty())
	{
		int z = Q.front();
		Q.pop();

		rep(i, 4)
		{
			sprintf(num, "%d", z);
			rep(j, 10)
			{
				if (i == 0 && j == 0)
					continue;

				num[i] = j + '0';
				int t = atoi(num);

				if (!visited[t] && prime[t] == true && t != a)
				{
					Q.push(t);
					visited[t] = 1;
					dist[t] = dist[z] + 1;

					if (t == b)
						return dist[b];
				}
			}
		}
	}
	
	return dist[b];
}

int main(void)
{
	pre();

	int t;
	sfi(t);

	while (t--)
	{
		int a, b;
		sfi(a);
		sfi(b);
		if (a == b) pfi(0);
		else
		{
			int p = BFS(a, b);
			(p == -1) ? pfs("Impossible") : pfi(p);
		}
	}
	
	return 0;
}