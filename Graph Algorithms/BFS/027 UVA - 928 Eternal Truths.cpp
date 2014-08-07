// Author : Bony Roopchandani
// 928 - Eternal Truths
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
typedef pair<int, PIII> PIIII;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LL;

int R, C;
char A[301][301];
int dx[]={0, -1, 0, 1};
int dy[]={-1, 0, 1, 0};

int valid(int i, int j)
{
	return ((i>=0 && i<R) && (j>=0 && j<C));
}

int BFS(PII u, PII v)
{
	queue<PIIII>Q;
	bool vis[301][301][4]={{0}};
	vis[u.ff][u.ss][0]=1;
	Q.push(mp(0, mp(0, mp(u.ff, u.ss))));
	
	while(!Q.empty())
	{
		PIIII z=Q.front();
		Q.pop();
		
		int currS=z.ff;
		int currD=z.ss.ff;
		int a=z.ss.ss.ff;
		int b=z.ss.ss.ss;
		
		rep(i, 4)
		{
			int nextS=(currS+1)%4;
			if(nextS==0)
			nextS=1;
			int nextD=currD+1;
			int p=a, q=b;
			bool cond;
			
			rep(j, nextS)
			{
			    cond=true;
				p+=dx[i];
				q+=dy[i];
				
				if(A[p][q]=='#' || !valid(p, q))
				{
					cond=false;
					break;
				}
			}
			
			if(cond && !vis[p][q][nextS])
			{
				vis[p][q][nextS]=1;

				if(p==v.ff && q==v.ss)
				return nextD;
				
				Q.push(mp(nextS, mp(nextD, mp(p, q))));
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
	
	while(T--)
	{
		sfi(R); sfi(C);
		
		PII S, E;
		memset(A, '\0', sizeof(A));
		
		rep(i, R)
		{
			sfs(A[i]);
			rep(j, C)
			{
				if(A[i][j]=='S')
				S=mp(i,j);
				else if(A[i][j]=='E')
				E=mp(i,j);
			}
		}
		
		int P=BFS(S, E);
		
		if(P==-1)
		pfs("NO");
		else
		pfi(P);
	}
	
	return 0;
}