// Author : Bony Roopchandani
// GRAVITY
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

int dx[] = { 1, 0, -1, -1, -1, 0, 1, 1 };
int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };

int R, C, O, A[101][101];

int valid(int i, int j)
{
	return ((i>=0 && i<R) && (j>=0 && j<C));
}

PII BFS(PII u, PII v, int O)
{
	int dist[101][101];
	bool vis[101][101]={{0}};
	queue<pair<int, PII> >Q;
	pair<int, PII>z;
	
	vis[u.ff][u.ss]=1;
	dist[u.ff][u.ss]=0;
	
	Q.push(mp(O, mp(u.ff, u.ss)));
	
	while(!Q.empty())
	{
		z=Q.front();
		if(z.ss.ff==v.ff && z.ss.ss==v.ss)
		return mp(dist[v.ff][v.ss], z.ff);
		Q.pop();
		
		rep(i, 8)
		{
			int x=z.ss.ff+dx[i];
			int y=z.ss.ss+dy[i];
			int o=z.ff-1;
			
			if(valid(x,y) && !vis[x][y] && A[x][y])
			{
				vis[x][y]=1;
				dist[x][y]=dist[z.ss.ff][z.ss.ss]+1;
				Q.push(mp(o, mp(x,y)));
			}
		}
	}
	return mp(INF,INF);
}

int main(void)
{
//	freopen("input.txt","r",stdin);
	int T;
	sfi(T);

	while (T--)
	{
		sfi(O);
		sfi(R);
		sfi(C);
		getchar();
		char foo[101][101];
		PII S,E;

		rep(i, R)
		{
			gets(foo[i]);
			rep(j, C)
			{
				if (foo[i][j] == '#')
					A[i][j] = 0;
				else
					A[i][j] = 1;

				if (foo[i][j] == 'S')
					S = mp(i, j);
				if (foo[i][j] == 'T')
					E = mp(i, j);
			}
		}
		PII P=BFS(S, E, O);
		
		if(P.ff>=INF && P.ss>=INF)
		pfs("Impossible");
		else
		if(P.ss<0)
		pfs("Impossible");
		else
		pfs("Possible");
	}
	return 0;
}