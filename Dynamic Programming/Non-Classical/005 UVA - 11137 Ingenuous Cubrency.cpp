// Author : Bony Roopchandani
// 11137 - Ingenuous Cubrency
// DP

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

int C[30];
ll dp[10000+5][23];

class Cube
{
	public:
	
	void process(int N)
	{
		pfl(Get(N, 1));
	}
	
	ll Get(int N, int c)
	{
		if(N==0)
			return 1;
		
		if(c==22)
	   	return 0;
	   	
	   if(dp[N][c] != -1)
	   return dp[N][c];
		
		ll ans=0;
		
		for(int i=0; i*C[c]<=N; i++)
			ans+=Get(N-C[c]*i, c+1);
			
		return dp[N][c]=ans;
	}
};

void pre()
{
	rept(i, 1, 21)
	{
		C[i]=i*i*i;
	}
	
	rept(i, 0, 10000+3)
	fill(dp[i], dp[i]+23, (ll)-1);
	
	Cube Q;
	Q.Get(9999, 1);
}

int main()
{
	pre();
	int N;
	
	while(sfi(N)==1)
	{
		Cube C;
    	C.process(N);
	}
	return (0);
}