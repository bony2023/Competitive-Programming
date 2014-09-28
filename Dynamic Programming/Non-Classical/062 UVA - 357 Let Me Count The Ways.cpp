// Author : Bony Roopchandani
// 357 - Let Me Count The Ways
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

int C[]={1, 5, 10, 25, 50};
ll dp[6][30000+5];

ll F(int RemV, int c)
{
	if(RemV==0)
	return 1;
	else if(c==5 || RemV<0)
	return 0;
	
	if(dp[c][RemV] != -1)
	return dp[c][RemV];
	
	ll ans=0;
	
	rept(i, c, 4)
	{
		if(RemV>=C[i])
		{
			ans+=F(RemV-C[i], i);
		}
	}
	
	return dp[c][RemV]=ans;
}

int main(void)
{
	int N;
	memset(dp, -1, sizeof dp);
	
	while(cin>>N)
	{
		ll P=F(N, 0);
		
		(P==1)?printf("There is only 1 way to produce %d cents change.\n", N):printf("There are %lld ways to produce %d cents change.\n", P, N);
	}
	
	return (0);
}