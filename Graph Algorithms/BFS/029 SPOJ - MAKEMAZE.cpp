// Author : Bony Roopchandani
// MAKEMAZE
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
int dx[]={0, -1, 0, 1};
int dy[]={-1, 0, 1, 0};
char foo[21][21];

bool validBoundary(int i, int j)
{
	if(i==0 || j==0 || i==R-1 || j==C-1)
	return 1;
	
	return 0;
}

int valid(int i, int j)
{
	return ((i>=0 && j>=0) && (i<R && j<C));
}

int BFS(PII u, PII v)
{
	bool vis[21][21]={0};
	vis[u.ff][u.ss]=1;
	
	queue<PII>Q;
	Q.push(u);
	
	while(!Q.empty())
	{
		PII z=Q.front();
		Q.pop();
		
		rep(i, 4)
		{
			int p=z.ff+dx[i];
			int q=z.ss+dy[i];
			
			if(!vis[p][q] && foo[p][q]!='#' && valid(p, q))
			{
			   vis[p][q]=1;
			   if(p==v.ff && q==v.ss)
			   return 1;
		   	Q.push(mp(p,q));
			}
		}
	}
	return -1;
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T;
	sfi(T);

	while (T--)
	{
		sfi(R);
		sfi(C);
		
		memset(foo, '\0', sizeof foo);

		rep(i, R) 
		 sfs(foo[i]);
		 
		PII S, E;
		int c=0;
		bool cond=true;
		
		rep(i, R)
		  rep(j, C)
		    if(validBoundary(i, j))
		      if(foo[i][j]=='.')
		      {
		        c++;
		        if(cond==true)
		        cond=false, S=mp(i, j);
		        else if(cond==false)
		        E=mp(i, j);
		      }
		      
		 if(c!=2)
		 pfs("invalid");
		 else
		 {
		 	int P=BFS(S, E);
		 	
		 	if(P==-1)
		 	pfs("invalid");
		 	else
		 	pfs("valid");
		 }
	}
	return 0;
}