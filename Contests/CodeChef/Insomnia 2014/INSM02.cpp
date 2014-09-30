// Author : Bony Roopchandani
// INSM02
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

int N, M;
int T[500+5][500+5];

bool F(int A)
{
	ll dp[N+5][M+5];
	
	rep(i, N+5)
	rep(j, M+5)
	dp[i][j]=INF<<1;
	
	rep(i, M)
	dp[0][i]=T[0][i];
	
	int x, y, z;
	
	rept(i, 1, N-1)
	rep(j, M)
	{
		x=y=z=INF<<1;
		
		if(i && j)
		x=dp[i-1][j-1]+T[i][j];
		
		if(i)
		y=dp[i-1][j]+T[i][j];
		
		if(i)
		z=dp[i-1][j+1]+T[i][j];
		
		dp[i][j]=min(x, min(y, z));
	}
	
	rep(j, M)
	if(dp[N-1][j]<A)
	return true;
	
	return false;
}

int main(void)
{
	int t; sfi(t);
	int A;
	
	while(t--)
	{
		sfi(A);
		sfi(N), sfi(M);
		
		rep(i, N)
		rep(j, M)
		sfi(T[i][j]);
		
		if(F(A))
		puts("YES");
		else
		puts("NO");
	}
	return (0);
}