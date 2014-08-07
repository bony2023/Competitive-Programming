// Author : Bony Roopchandani
// 10047 - The Monocycle
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
typedef pair < int, PIII > PIIII;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LL;

int R, C;
char A[30][30];
int dx[] = {0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int dist[30][30][6][5];

int valid(int i, int j)
{
	return ((i>=0 && i<R) && (j>=0 && j<C));
}

int BFS(PII u, PII v)
{
	queue<PIIII>Q;
	Q.push(mp(0, mp(1, mp(u.ff, u.ss))));
	bool vis[30][30][6][5]={{0}};
	vis[u.ff][u.ss][0][1]=1;
	dist[u.ff][u.ss][0][1]=0;
	
	while(!Q.empty())
	{
		PIIII z=Q.front();
		Q.pop();
		
		int currS=z.ff;
		int currDir=z.ss.ff;
		int a=z.ss.ss.ff;
		int b=z.ss.ss.ss;
		
		int p=a+dx[currDir];
		int q=b+dy[currDir];
		int nextS=(currS+1)%5;
		
		rep(i, 2)
		{
			int nextDir;
			if(i==0)
			nextDir=currDir-1;
			else
			nextDir=currDir+1;
			
			if(nextDir==-1)
			nextDir=3;
			if(nextDir==4)
			nextDir=0;
			
			if(!vis[a][b][currS][nextDir])
			{
				vis[a][b][currS][nextDir]=1;
				dist[a][b][currS][nextDir]=dist[a][b][currS][currDir]+1;
				
				if(currS==0 && a==v.ff && b==v.ss)
				return dist[a][b][currS][nextDir];
				
				Q.push(mp(currS, mp(nextDir, mp(a, b))));
			}
		}
		
		if(valid(p, q) && !vis[p][q][nextS][currDir] && A[p][q]!='#')
		{
			vis[p][q][nextS][currDir]=1;
			dist[p][q][nextS][currDir]=dist[a][b][currS][currDir]+1;
			
			if(nextS==0 && p==v.ff && q==v.ss)
				return dist[p][q][nextS][currDir];
			
			Q.push(mp(nextS, mp(currDir, mp(p, q))));
		}
	}
	return -1;
}

int main(void)
{
// freopen("input.txt", "r", stdin);
	
	int cs=1;
	
	while (1)
	{
		sfi(R);
		sfi(C);

		if (!R && !C)
			break;

		PII S, E;
		memset(A, '\0', sizeof(A));

		rep(i, R)
		{
			sfs(A[i]);
			rep(j, C)
			{
				if (A[i][j] == 'S')
					S = mp(i, j);
				else if (A[i][j] == 'T')
					E = mp(i, j);
			}
		}
		
		if(cs==1)
		printf("Case #%d\n",cs++);
		else printf("\nCase #%d\n",cs++);
		
		int P = BFS(S, E);
		
		if(P==-1)
		printf("destination not reachable\n");
		else
		printf("minimum time = %d sec\n",P);
	}

	return 0;
}