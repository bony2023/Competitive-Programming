// Author : Bony Roopchandani
// HIGHWAYS
// Dijkstra Algorithm

//INCLUDES
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

//MACROS
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

//TYPEDEFS
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef map<int, bool> MIB;
typedef list<int> LI;
typedef list<ll> LLL;
typedef set<int> SI;
typedef set<ll> SLL;

vector<PII> A[100000+5];
VI dist;

void Dijkstra(int u, int d)
{
	priority_queue<PII, vector<PII>, greater<PII> >Q;
	Q.push(mp(d, u));
	dist[u]=d;
	
	while(!Q.empty())
	{
		PII z=Q.top();
		Q.pop();
		
		int D=z.ff;
		int v=z.ss;
		
		if(D==dist[v])
		{
			rep(i, A[v].sz)
			{
				int z=A[v][i].ss;
				int W=A[v][i].ff;
				
				if(dist[z]>dist[v]+W)
				{
					dist[z]=dist[v]+W;
					Q.push(mp(dist[z], z));
				}
			}
		}
	}
}
int main(void)
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	
	while(T--)
	{
		int N, M, s, t;
		
		sfi(N), sfi(M), sfi(s), sfi(t);
		
		dist.assign(N+5, INF);
		
		int x, y, l;
		
		rep(i, M)
		{
			sfi(x), sfi(y), sfi(l);
			A[x].pb(mp(l, y));
			A[y].pb(mp(l, x));
		}
		
		Dijkstra(s, 0);
		
		if(dist[t]==INF)
		pfs("NONE");
		else
		pfi(dist[t]);
		
		rep(i, N+5)
		A[i].clear();
	}
	return 0;
}