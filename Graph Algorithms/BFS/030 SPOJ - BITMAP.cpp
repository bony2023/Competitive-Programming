// Author - Bony Roopchandani
// BITMAP
// BFS

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=0; i<=n; i++)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define repli(i, n) for(ll i=0; i<=n; i++)
#define pf(a) printf("%d\n",a)
#define sf(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define nl printf("\n")
#define INF 9999999
#define MOD 1000000007
#define MAX 192

int dist[MAX * MAX], N, M;
int visited[MAX * MAX];

void BFS()
{
	queue < int >Q;

	rep(i, N * M) visited[i] = false;

	rep(i, N * M) if (dist[i] == 0)
	{
		Q.push(i);
		visited[i] = true;
	}

	while (!Q.empty())
	{
		int z = Q.front();
		Q.pop();

		// pf(z);

		rep(i, 4)
		{
			int foo = z - M;
			if (foo >= 0 && visited[foo] == false)
			{
				if (dist[foo] > dist[z] + 1)
					dist[foo] = dist[z] + 1;
				visited[foo] = true;
				Q.push(foo);
			}

			foo = z + M;
			if (foo < N * M && visited[foo] == false)
			{
				if (dist[foo] > dist[z] + 1)
					dist[foo] = dist[z] + 1;
				visited[foo] = true;
				Q.push(foo);
			}

			foo = z - 1;
			if (foo >= 0 && visited[foo] == false && (foo + 1) % M != 0)
			{
				if (dist[foo] > dist[z] + 1)
					dist[foo] = dist[z] + 1;
				visited[foo] = true;
				Q.push(foo);
			}

			foo = z + 1;
			if (foo < N * M && visited[foo] == false && foo % M != 0)
			{
				if (dist[foo] > dist[z] + 1)
					dist[foo] = dist[z] + 1;
				visited[foo] = true;
				Q.push(foo);
			}
		}

		visited[z] = true;
	}
}


int main(void)
{
	int T;
	char foo;

	sf(T);

	while (T--)
	{
		sf(N);
		sf(M);
		getchar();

		rep(i, N * M)
		{
			foo = getchar();
			if (foo == '\n')
			{
				i--;
				continue;
			}
			// putchar(foo);
			if (foo == '1')
				dist[i] = 0;
			else
				dist[i] = INF;

			// printf("%d ",dist[i]);
		}

		BFS();

		int c = 0;
		rep(i, N * M)
		{
			c++;
			printf("%d ", dist[i]);

			if (c == M)
			{
				c = 0, nl;
			}
		}
	}

	return 0;
}