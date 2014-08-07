// Author : Bony Roopchandani
// 260 - Il Gioco dell'X
// Connected Components/Flood Fill

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

char foo[201][201] = { {0} };
bool vis[201][201] = { {0} };
int N;
bool W;

short dx[] = { 0, -1, -1, 0, 1, 1 };
short dy[] = { -1, -1, 0, 1, 1, 0 };

bool valid(int i, int j)
{
	return ((i >= 0 && i < N) && (j >= 0 && j < N));
}

void dfs(int i, int j)
{
	vis[i][j] = 1;

	if (j == (N - 1))
	{
		W=true;
		return;
	}

	rep(x, 6)
	{
		int a = i + dx[x];
		int b = j + dy[x];

		if (foo[a][b] == 'w' && !vis[a][b] && valid(a, b))
			dfs(a, b);
	}
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int cs = 1;
	while (sfi(N) && N)
	{
		rep(i, N) sfs(foo[i]);

		bool cond=false;
		W=false;

		rep(i, N)
		{
			if (foo[i][0] == 'w' && !vis[i][0])
				dfs(i, 0);

			if (W)
			{
				printf("%d W\n", cs++);
				cond = true;
				break;
			}
		}

		if (!cond)
		{
			printf("%d B\n", cs++);
		}
		memset(vis, 0, sizeof vis);
		memset(foo, '\0', sizeof foo);
	}

	return 0;
}