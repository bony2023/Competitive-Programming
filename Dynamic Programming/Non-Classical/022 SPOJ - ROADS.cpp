// Author : Bony Roopchandani
// ROADS
// Dijkstra Variant

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// MACROS
#define all(a) a.begin(), a.end()
#define bg begin()
#define en end()
#define ff first
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define pb push_back
#define pf(a) printf("%d ",a)
#define pfi(a) printf("%d\n",a)
#define pfl(a) printf("%lld\n",(ll)a)
#define pfs(a) printf("%s\n",a)
#define rep(i, n) for(int i=0; i<n; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define repl(i, n) for(ll i=0; i<n; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define sfi(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define ss second
#define sz size()

// CONSTS
const double EPS = (1e-11);
const double PI = acos(-1.0);
const int INF = 9999999;
const int MOD = (1e9 + 7);

// TYPEDEFS
typedef list < int > LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int > MII;
typedef map < int, ll > MIL;
typedef map < ll, int > MLI;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef set < int > SI;
typedef set < ll > SLL;
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

bool vis[100+5][10000+5];

class node
{
	public:
	
	int u, Toll, dist;
	
	node(int a, int b, int c)
	{
		dist=a, Toll=b, u=c;
	}
	
	bool operator < (node Q)
	const
	{
		if(dist!=Q.dist)
		return dist>Q.dist;
		
		return Toll>Q.Toll;
	}
};

class ROADS
{
	vector<PIII>* A;
	int K, N, R;
	int S, D, L, T;
	
	public:
	
	ROADS()
	{
		sfi(K), sfi(N), sfi(R);
		A = new vector<PIII> [N+5];
		memset(vis, 0, sizeof vis);
	}
	
	~ROADS()
	{
		delete []A;
	}
	
	void process()
	{
		rep(i, R)
		{
			sfi(S), sfi(D), sfi(L), sfi(T);
			A[S].pb(mp(L, mp(T, D)));
		}
		
		pfi(Dijkstra(1));
	}
	
	int Dijkstra(int s)
	{
		int foo=-1;
		priority_queue<node> Q;
		Q.push(node(0, 0, s));
		
		while(!Q.empty())
		{
			node z=Q.top();
			Q.pop();
			
			if(z.u==N)
			{
				foo=z.dist;
				break;
			}
			
			if(vis[z.u][z.dist])
			continue;
			
			vis[z.u][z.Toll]=1;
			
			rep(i, A[z.u].sz)
			{
				int v=A[z.u][i].ss.ss;
				int newToll=A[z.u][i].ss.ff;
				int DIST=A[z.u][i].ff;
				
				if((z.Toll+newToll)<=K)
				Q.push(node(DIST+z.dist, z.Toll+newToll, v));
			}
		}
		
		return foo;
	}
};

int main()
{
	int T; sfi(T);
	
	while(T--)
	{
		{
			ROADS R;
			R.process();
		}
	}
	
	return (0);
}