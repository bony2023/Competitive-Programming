// Author : Bony Roopchandani
// 10130 - SuperSale
// Knapsack 0-1

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

class Knapsack
{
	int dp[1000+5][30+5];
	int N;
	int P[1000+5], W[1000+5];
	
	public:
	
	void process()
	{
		memset(dp, -1, sizeof dp);
		
		sfi(N);
		rep(i, N)
		sfi(P[i]), sfi(W[i]);
		
		int G, Sum=0, x;
		sfi(G);
		
		while(G--)
		{
			sfi(x);
			Sum+=count(0, x);
		}
		
		pfi(Sum);
	}
	
	int count(int id, int RemW)
	{
		if(id==N || RemW<=0)
		return 0;
		
		if(dp[id][RemW] != -1)
		return dp[id][RemW];
		
		if(W[id]>RemW)
		return dp[id][RemW]=count(id+1, RemW);
		
		if(W[id]<=RemW)
		return dp[id][RemW]=max(count(id+1, RemW), P[id]+count(id+1, RemW-W[id]));
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	
	while(T--)
	{
		Knapsack K;
		K.process();
	}
	
	return (0);
}