// Author : Bony Roopchandani
// LCA
// Lowest Common Ancestor

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
#define in(a) freopen(a, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(a) freopen(a, "w", stdout)
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

int P[1000+5];

int LCA(int u, int v, int N)
{
	bool vis[N+5];
	fill(vis, vis+N+5, 0);
	
	while(P[u] != u)
	vis[u]=1, u=P[u];
	
	vis[u]=1;
	
	while(!vis[v])
	v=P[v];
	
	return v;
}

int main(void)
{
//	in("input.txt");
	
	int T, cs=1; sfi(T);
	
	while(T--)
	{
		int N, M, x; sfi(N);
		
		rept(i, 1, N)
		P[i]=i;
		
		rept(i, 1, N)
		{
			sfi(M);
			
			rep(j, M)
			{
				sfi(x);
				P[x]=i;
			}
		}
		
		printf("Case %d:\n", cs++);
		
		int Q, u, v; sfi(Q);
		
		while(Q--)
		{
			sfi(u), sfi(v);
			pfi(LCA(u, v, N));
		}
	}
	
	return (0);
}