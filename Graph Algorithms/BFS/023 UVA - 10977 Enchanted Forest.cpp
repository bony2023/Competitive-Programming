// Author : Bony Roopchandani
// 10977 - Enchanted Forest
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

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int R, C;
bool A[201][201];

int valid(int i, int j)
{
	return ((i >= 0 && j >= 0) && (i < R && j < C));
}

int BFS()
{
	int vis[201][201] = { {0} };
	int dist[201][201];
	vis[0][0] = 1;
	dist[0][0] = 0;

	queue < int >Q;
	Q.push(0);
	Q.push(0);

	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		int b = Q.front();
		Q.pop();

		rep(i, 4)
		{
			int x = a + dx[i];
			int y = b + dy[i];

			if (!vis[x][y] && valid(x, y) && !A[x][y])
			{
				vis[x][y] = 1;
				dist[x][y] = dist[a][b] + 1;

				if (x == R - 1 && y == C - 1)
					return dist[x][y];
				Q.push(x);
				Q.push(y);
			}
		}
	}
	return INF;
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	while (1)
	{
		sfi(R);
		sfi(C);
		memset(A, 0, sizeof A);

		if (!R && !C)
			break;

		int M;
		sfi(M);
		int x, y, L;

		rep(i, M)
		{
			sfi(x);
			sfi(y);
			A[x - 1][y - 1] = 1;
		}

		int N;
		sfi(N);

		rep(i, N)
		{
			sfi(x);
			sfi(y);
			sfi(L);
			x--;
			y--;
			A[x][y] = 1;

			for (int i = x - L; i <= x + L; i++)
			{
				for (int j = y - L; j <= y + L; j++)
				{
					if (valid(i, j) && (double)hypot(x - i, (double)y - j) <=
						L)
						A[i][j] = 1;
				}
			}
		}
		if (R == 1 && C == 1)
			pfi(0);
		else
		{

			int P = BFS();

			if (P >= INF)
				pfs("Impossible.");
			else
				pfi(P);
		}
	}

	return 0;
}