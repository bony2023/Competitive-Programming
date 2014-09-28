// Author : Bony Roopchandani
// TWENDS
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

int A[1000+5];
int dp[1000+5][1000+5];

int count(int l, int r)
{
	if(l>r)
	return 0;
	
	if(dp[l][r] != -1)
	return dp[l][r];
    	
	int ans=0;
	
	if(A[l+1]>=A[r])
	{
		ans=max(ans, A[l]+count(l+2, r));
	}
	else
	{
		ans=max(ans, A[l]+count(l+1, r-1));
	}
	
	if(A[l]>=A[r-1])
	{
		ans=max(ans, A[r]+count(l+1, r-1));
	}
	else
	{
		ans=max(ans, A[r]+count(l, r-2));
	}

	return dp[l][r]=ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N, cs=1;
	
	while(sfi(N)==1 && N)
	{
		memset(dp, -1, sizeof dp);
		int Sum=0;
		
		rep(i, N)
		{
			sfi(A[i]);
			Sum+=A[i];
		}
		
		int A=count(0, N-1);
		int B=Sum-A;
		
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", cs++, A-B);
	}
	
	return (0);
}