// Author : Bony Roopchandani
// MUSKET
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
#define in(x) freopen(x, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(x) freopen(x, "w", stdout)
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

bool A[100+5][100+5];
int dp[100+5][100+5];
int N;

int F(int lo, int hi)
{
	if((lo==hi) || ((hi-lo)==1) || (hi==0 && lo==N-1))
	return 1;
	
	if(dp[lo][hi] != -1)
	return dp[lo][hi];
	
	for(int mi=(lo+1)%N; mi!=hi; mi=(mi+1)%N)
	{
		if(A[lo][mi] || A[hi][mi])
    	{
    		if(F(lo, mi) && F(mi, hi))
        	return dp[lo][hi]=1;
    	}
	}
	
	return dp[lo][hi]=0;
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		sfi(N);
		
		char foo[100+5];
		int q[100+5], k=0;
		
		rep(i, N)
		{
			sfs(foo);
			
			rep(j, N)
			A[i][j]=foo[j]-'0';
		}
		
		memset(dp, -1, sizeof dp);
		
		rep(i, N)
		rep(j, N)
		{
			if(i != j && A[i][j])
				if(F(i, j) && F(j, i))
    			{
    				q[k++]=i+1;
    				break;
    			}
		}
		
		pfi(k);
		rep(i, k)
		pfi(q[i]);
	}
	return (0);
}