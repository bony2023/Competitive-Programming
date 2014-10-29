// Author : Bony Roopchandani
// CHICAGO
// Dijkstra

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
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

vector<pair<double, int> > a[100+5];
int N, M;

double dijkstra()
{
	vector<double> prob(N+5, 0);
	prob[1]=1.0;
	priority_queue<pair<double, int> > Q;
	Q.push(mp(1, 1));
	
	while(!Q.empty())
	{
		double d=Q.top().ff;
		int u=Q.top().ss;
		Q.pop();
		
		if(d==prob[u])
		{
			rep(i, a[u].sz)
			{
				double D=a[u][i].ff;
				int v=a[u][i].ss;
				
				if(prob[v]<prob[u]*D)
				{
					prob[v]=prob[u]*D;
					Q.push(mp(prob[v], v));
				}
			}
		}
	}
	
	return prob[N]*100.0;
}

int main(void)
{
	while(sfi(N) && N)
	{
		sfi(M);
		int x, y;
		double d;
		
		rep(i, M)
		{
			sfi(x), sfi(y);
			scanf("%lf", &d);
			a[x].pb(mp(d/100.0, y));
			a[y].pb(mp(d/100.0, x));
		}
		
		printf("%lf percent\n", dijkstra());
		
		rept(i, 1, N)
		a[i].clear();
	}
	
	return (0);
}