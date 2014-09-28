// Author : Bony Roopchandani
// ASSIGN
// DP+Bitmask

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
#define isSet(x, i) ((x>>i)&1)
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
const int MAX = 21;
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

int Count[1<<MAX];
ll dp[1<<MAX];

void preCompute()
{
	rep(i, 1<<MAX)
	Count[i]=__builtin_popcount(i);
}

class ASSIGN
{
	bool A[MAX][MAX];
	int N;
	
	public:
	
	void process()
	{
		sfi(N);
		
		rep(i, N)
		rep(j, N)
		sfi(A[i][j]);
		
		dp[0]=1;
		
		rept(i, 1, (1<<N)-1)
		{
			dp[i]=0;
			
			rep(k, N)
			{
				if(A[Count[i]-1][k] && isSet(i, k))
				dp[i]+=dp[i & ~(1<<k)];
			}
		}
		
		pfl(dp[(1<<N)-1]);
	}
};

int main()
{
	preCompute();
	int T; sfi(T);
	
	while(T--)
	{
		ASSIGN A;
		A.process();
	}
	
	return (0);
}