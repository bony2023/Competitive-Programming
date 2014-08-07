// Author : Bony Roopchandani
// 558 - Wormholes
// Bellman Ford

// INCLUDES
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
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
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef map < int, int > MII;
typedef map < ll, int > MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int > LI;
typedef list < ll > LLL;
typedef set < int > SI;
typedef set < ll > SLL;

vector<PII> A[1000+5];

bool Bellman(int u, int N)
{
	bool hasNeg=false;
	VI dist(N, INF);
	dist[u]=0;
	
	rep(k, N-1)
	rep(i, N)
	rep(j, A[i].sz)
	{
		int a=A[i][j].ss;
		int w=A[i][j].ff;
		
		dist[a]=min(dist[a], dist[i]+w);
	}
	
	rep(i, N)
	rep(j, A[i].sz)
	{
		int a=A[i][j].ss;
		int w=A[i][j].ff;
		
		if(dist[a]>dist[i]+w)
		hasNeg=true;
	}
	
	return hasNeg;
}

int main()
{
	int T; sfi(T);
	int N, M;
	
	while(T--)
	{
		sfi(N), sfi(M);
		
		int x, y, c;
		
		rep(i, M)
		{
			sfi(x), sfi(y), sfi(c);
			A[x].pb(mp(c, y));
		}
		
		bool P=Bellman(0, N);
		
		if(P)
		pfs("possible");
		else
		pfs("not possible");
		
		rep(i, N)
		A[i].clear();
	}
	
	return 0;
}