// Author : Bony Roopchandani
// 10986 - Sending email
// Dijkstra

// INCLUDES
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

// MACROS
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i=0; i<n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD (1e9 + 7)

// TYPEDEFS
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int >LI;
typedef list < ll > LLL;
typedef set < int >SI;
typedef set < ll > SLL;

vector<PII>A[20000+10];
int N;

int Dijkstra(int u, int v)
{
	VI dist(N+5, INF);
	priority_queue<PII, vector<PII>, greater<PII> >Q;
	dist[u]=0;
	Q.push(mp(0, u));
	
	while(!Q.empty())
	{
		PII z=Q.top();
		Q.pop();
		
		int a=z.ss;
		int c=z.ff;
		
		if(c==dist[a])
		{
			rep(i, A[a].sz)
			{
				int p=A[a][i].ss;
				int w=A[a][i].ff;
				
				if(dist[p]>dist[a]+w)
				{
					dist[p]=dist[a]+w;
					Q.push(mp(dist[p], p));
				}
			}
		}
	}
	return dist[v];
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int cs=1;
	
	int T; sfi(T);
	
	while(T--)
	{
		int M, S, T;
		
		sfi(N), sfi(M), sfi(S), sfi(T);
		int x, y, w;
		
		rep(i, M)
		{
			sfi(x), sfi(y), sfi(w);
			A[x].pb(mp(w, y));
			A[y].pb(mp(w, x));
		}
		
		int P=Dijkstra(S, T);
		
		printf("Case #%d: ",cs++);
		
		if(P>=INF)
		pfs("unreachable");
		else
		pfi(P);
		
		rep(i, N+3)
		A[i].clear();
	}
	
	return 0;
}