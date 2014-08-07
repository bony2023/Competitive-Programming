// Author : Bony Roopchandani
// 469 - Wetlands of Florida
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

char foo[101][101] = { {0} };

int P, R, C;
bool vis[101][101] = { {0} };
short dx[] = { 1, 0, -1, -1, -1, 0, 1, 1 };
short dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };

bool valid(int i, int j)
{
	return ((i >= 0 && i < R) && (j >= 0 && j < C));
}

void dfs(int i, int j)
{
	vis[i][j] = 1;
	P += 1;

	rep(x, 8)
	{
		int a = i + dx[x];
		int b = j + dy[x];

		if (!vis[a][b] && foo[a][b] == 'W' && valid(a, b))
			dfs(a, b);
	}
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T;
	sfi(T);
	getchar();
	getchar();

	while (T--)
	{
		char temp[101];

		R = 0;

		while(gets(temp) && strlen(temp))
		{
			if(temp[0]=='L' || temp[0]=='W')
			{
				strcpy(foo[R++], temp);
				C=strlen(temp);
			}
			else
			{
				int a, b;
				sscanf(temp, "%d %d", &a, &b);
				a--, b--;
				
				P=0;
				
				if(foo[a][b]=='W')
				dfs(a, b);
				pfi(P);
				memset(vis, 0, sizeof vis);
			}
		}
		
		if(T!=0)
		nl;
	}
	return 0;
}