// Author : Bony Roopchandani
// RENT
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

struct Ele
{
	int start, dur, cost, end;
}A[10000+5];

bool cmp(Ele a, Ele b)
{
	return a.start<b.start;
}

int dp[10000+5];

int BinSearch(int l, int h, int a)
{
	int mi;
	
	while(l<h)
	{
		mi=l+((h-l)>>1);
		
		if(A[mi].start>=a)
		h=mi;
		else
		l=mi+1;
	}
	
	if(A[l].start>=a)
	return dp[l];
	else
	return 0;
}

int getMax(int N)
{
	memset(dp, 0, sizeof dp);
	
	repd(i, N-1, 0)
	{
		dp[i]=dp[i+1];
		
		int mx=BinSearch(i+1, N-1, A[i].end);
		
		dp[i]=max(dp[i], mx+A[i].cost);
	}
	
	return dp[0];
}

int main()
{
	int N, T;
	sfi(T);
	
	while(T--)
	{
		sfi(N);
		
		rep(i, N)
		{
			sfi(A[i].start), sfi(A[i].dur), sfi(A[i].cost);
			A[i].end=A[i].start+A[i].dur;
		}
		
		sort(A, A+N, cmp);
		
		pfi(getMax(N));
	}
	
	return (0);
}