// Author : Bony Roopchandani
// CRSCNTRY
// DP + LCS

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

int Agness[2000+5];
int Tom[2000+5];
int dp[1000+5][1000+5];

int LCS(int a, int b)
{
	if(a<0 || b<0)
	return 0;
	
	if(dp[a][b] != -1)
	return dp[a][b];
	
	if(Agness[a]==Tom[b])
	return dp[a][b]=1+LCS(a-1, b-1);
	else
	return dp[a][b]=max(LCS(a-1, b), LCS(a, b-1));
}

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	
	while(T--)
	{
		int A=0, B=0;
		
		int N, end;
		
		while(sfi(N) && N)
		{
			Agness[A++]=N;
		}
		
		int mx=0;
		
		while(sfi(end) && end)
		{
			memset(dp, -1, sizeof dp);
			
			Tom[B++]=end;
			
			while(sfi(N) && N)
			Tom[B++]=N;
			
			mx=max(mx, LCS(A-1, B-1));
			B=0;
		}
		
		pfi(mx);
	}
	return (0);
}