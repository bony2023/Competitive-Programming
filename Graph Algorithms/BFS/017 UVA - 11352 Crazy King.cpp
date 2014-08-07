// Author : Bony Roopchandani
// 11352 - Crazy King
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

PII S, E;
vector<PII>H;
int R, C;
char foo[105][105];
int Kdist[105][105];

int Hx[]={2,1,-1,-2,-2,-1,1,2};
int Hy[]={-1,-2,-2,-1,1,2,2,1};
int Kx[]={1,0,-1,-1,-1,0,1,1};
int Ky[]={-1,-1,-1,0,1,1,1,0};

int valid(int i, int j)
{
	if(i>=0 && j>=0 && i<R && j<C)
	return 1;
	return 0;
}

void KBFS()
{
	queue<PII>Q;
	bool vis[R+1][C+1];
	
	rep(i, R)
	rep(j, C)
	vis[i][j]=0, Kdist[i][j]=INF;
	
	Q.push(S);
	Kdist[S.ff][S.ss]=0;
	vis[S.ff][S.ss]=1;
	
	while(!Q.empty())
	{
		PII z=Q.front();
		if(z==E)
		return;
		Q.pop();
		
		rep(i, 8)
		{
			int x=z.ff+Kx[i];
			int y=z.ss+Ky[i];
			
			if(!vis[x][y] && valid(x,y) && foo[x][y]!='Z')
			{
				vis[x][y]=1;
				if(Kdist[x][y]>Kdist[z.ff][z.ss]+1)
			Kdist[x][y]=Kdist[z.ff][z.ss]+1;
			
			Q.push(mp(x,y));
			}
		}
	}
}

void Hmov()
{
	rep(i, H.sz)
	{
		rep(j, 8)
		{
			int x=H[i].ff+Hx[j];
			int y=H[i].ss+Hy[j];
			if(foo[x][y]=='.' && valid(x,y))
			foo[x][y]='Z';
		}
	}
}

int main(void)
{
//	freopen("input.txt","r",stdin);
	int T;
	sfi(T);
	
	while(T--)
	{
		sfi(R); sfi(C);
		
		rep(i, R)
		{
	  	sfs(foo[i]);
	  	  rep(j, C)
	  	  {
	  	  	if(foo[i][j]=='Z')
	  	  	H.pb(mp(i,j));
	  	  	else
	  	  	if(foo[i][j]=='A')
	  	  	S=mp(i,j);
	  	  	else
	  	  	if(foo[i][j]=='B')
	  	  	E=mp(i,j);
	  	  }
		}
		
		Hmov();
		KBFS();

		if(Kdist[E.ff][E.ss]>=INF)
		pfs("King Peter, you can't go now!");
		else
		printf("Minimal possible length of a trip is %d\n",Kdist[E.ff][E.ss]);
		

		H.clear();
	}
	
	return 0;
}