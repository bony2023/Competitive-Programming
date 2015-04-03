// Author : Bony Roopchandani
// SEATSR
// DP - Levenshtein Distance

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

char A[100000+5], B[100000+5];
int dp[2][100000+5];

int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int F(int a, int b, int k)
{
	if(!strcmp(A, B))
	return 0;
	
	if(!a && !b)
	return 0;
	
	if(!a)
	return 0;
	
	int Len1=strlen(A);
	int Len2=strlen(B);
	
	if(Len2>Len1)
	{
		swap(A, B);
		swap(Len1, Len2);
	}
	
	int Q=min(Len2+1, k+1);
	
	fill(dp[0], dp[0]+Len2+1, INF);
	fill(dp[1], dp[1]+Len2+1, INF);
	
	rep(i, Q)
	dp[0][i]=i*a;
	
	int mn, mx;
	
	rept(i, 1, Len1)
	{
		dp[i&1][0]=i*a;
		
		mn=max(1, i-k);
		mx=min(Len2+1, i+k+1);
		
		if(mn>1)
		dp[i&1][mn-1]=INF;
		
		rept(j, mn, mx-1)
		{
			if(A[i-1]==B[j-1])
			dp[i&1][j]=dp[(i-1)&1][j-1];
			
			else
			dp[i&1][j]=min(b+dp[(i-1)&1][j-1], a+dp[i&1][j-1], a+dp[(i-1)&1][j]);
		}
	}
	
	if(dp[Len1&1][Len2]>k || dp[Len1&1][Len2]>=INF)
	return -1;
	else
	return dp[Len1&1][Len2];
}

int main(void)
{
//	in("input.txt");
	
	int T; sfi(T);
	int a, b, k;
	
	while(T--)
	{
		sfs(A), sfs(B);
		sfi(a), sfi(b), sfi(k);
		
		pfi(F(a, b, k));
	}
	return (0);
}