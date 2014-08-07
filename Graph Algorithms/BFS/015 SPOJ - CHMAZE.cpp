// Author : Bony Roopchandani
// CHMAZE
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
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef pair<int, PII>PIII;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LL;

char foo[12][22][22];
int R, C, P;

int dx[]={0, 0, -1, 0, 1};
int dy[]={0, -1, 0, 1, 0};

int BFS(PIII u)
{
	int dist[12][22][22];
	queue<PIII>Q;
	Q.push(u);
	dist[u.ff][u.ss.ff][u.ss.ss]=0;
	foo[u.ff][u.ss.ff][u.ss.ss]='1';
	
	while(!Q.empty())
	{
		PIII z=Q.front();
		Q.pop();
		
		int a=z.ff, b=z.ss.ff, c=z.ss.ss;
		int p, q, r;
		
		rep(i, 5)
		{
			p=(a+1)%P;
			q=b+dx[i];
			r=c+dy[i];
			
			if(foo[p][q][r]=='0')
			{
				foo[p][q][r]='1';
			
		dist[p][q][r]=dist[a][b][c]+1;
				if(q==R-1 && r==C-1)
				return dist[p][q][r];
				
				Q.push(mp(p, mp(q, r)));
			}
		}
	}
	
	return INF;
}

int main(void)
{
//	freopen("input.txt","r",stdin);
	int cs=1;
	
	while(true)
	{
		sfi(R); sfi(C); sfi(P);
		
		if(!R && !C && !P)
		break;
		
		rep(i, P)
		{
			rep(j, R)
			{
				sfs(foo[i][j]);
			}
		}
		
		int p=BFS(mp(0,mp(0, 0)));
		
		if(p>=INF)
		printf("Case %d: Luke and Leia cannot escape.\n",cs++);
		else
		printf("Case %d: Luke and Leia can escape in %d steps.\n",cs++,p);
	}
	
	return 0;
}