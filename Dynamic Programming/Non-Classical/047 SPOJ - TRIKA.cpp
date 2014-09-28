// Author : Bony Roopchandani
// TRIKA
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

int Tx, Ty;
int N, M;
int dp[20+5][20+5];

int F(int TP)
{
	rept(i, Tx+1, N)
	dp[i][Ty]=dp[i-1][Ty]-dp[i][Ty];
	
	rept(j, Ty+1, M)
	dp[Tx][j]=dp[Tx][j-1]-dp[Tx][j];
	
	rept(i, Tx+1, N)
	rept(j, Ty+1, M)
	dp[i][j]=max(dp[i-1][j]-dp[i][j], dp[i][j-1]-dp[i][j]);
	
	return dp[N][M];
}

int main()
{
	sfi(N), sfi(M);
	sfi(Tx), sfi(Ty);
	
	rept(i, 1, N)
	rept(j, 1, M)
	sfi(dp[i][j]);
	
	int P=F(dp[Tx][Ty]);
	
	if(P>=0)
	printf("Y %d\n", P);
	else
	puts("N");
	
	return (0);
}