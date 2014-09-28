// Author : Bony Roopchandani
// RAINBOW
// Knapsack + Graph(CC)

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
typedef list < int >LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int >MII;
typedef map < int, ll > MIL;
typedef map < ll, int >MLI;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef set < int >SI;
typedef set < ll > SLL;
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

int dp[1000+5][1000+5];

class Knapsack
{
	int N, C;
	int *P, *W, *w;
	VI* A;
	bool* vis;

  public:

    Knapsack(int n, int c)
	{
		N = n, C = c;
		P = new int[N + 5]();
	    W = new int[N + 5]();
	    w = new int[N+5]();
	    A = new VI[N+5];
	    vis = new bool[N+5]();
	    memset(dp, -1, sizeof dp);
	}

	 ~Knapsack()
	{
		delete []P;
		delete []W;
		delete []A;
		delete []vis;
		delete []w;
	}

	void process()
	{
		rep(i, N)
		sfi(w[i]);
		
		int K, x;
		
		rep(i, N)
		{
			sfi(K);
			
			rep(j, K)
			{
				sfi(x);
				A[i+1].pb(x);
				A[x].pb(i+1);
			}
		}
		
		N=FindCC();
		
		pfi(get(0, C));
	}
	
	int FindCC()
	{
		int k=-1;
		
		rept(i, 1, N)
		{
			if(!vis[i])
			{
				k++;
				dfs(i, k);
			}
		}
		
		return k;
	}
	
	void dfs(int u, int k)
	{
		vis[u]=1;
		
		P[k]++;
		W[k]+=w[u-1];
		
		rep(i, A[u].sz)
		{
			if(!vis[A[u][i]])
			dfs(A[u][i], k);
		}
	}
	
	int get(int pos, int RemW)
	{
		if(pos>N || RemW<=0)
		return 0;
		
		if(dp[pos][RemW] != -1)
		return dp[pos][RemW];
		
		if(W[pos]>RemW)
		return dp[pos][RemW]=get(pos+1, RemW);
		else
		return dp[pos][RemW]=max(get(pos+1, RemW), P[pos]+get(pos+1, RemW-W[pos]));
	}
};

int main()
{
	int N, C;

	while (scanf("%d%d",&N,&C)==2)
	{
		if (!N && !C)
			break;
		{
			Knapsack H(N, C);
			H.process();
		}
	}
	return (0);
}