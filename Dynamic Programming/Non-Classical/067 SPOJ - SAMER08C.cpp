// Author : Bony Roopchandani
// SAMER08C
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
#define IN(x) freopen(x, "r", stdin)
#define OUT(x) freopen(x, "w", stdout)
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

VLL dp, foo;
int cost[100000+5];

ll F(int n, int indi)
{
	if(indi>=n)
	return 0;
	
	else if(dp[indi] != -1)
	return dp[indi];
	
	else return
	dp[indi]=max(cost[indi]+F(n, indi+2), F(n, indi+1));
}

ll F1(int n, int indi)
{
	if(indi>=n)
	return 0;
	
	else if(dp[indi] != -1)
	return dp[indi];
	
	else return
	dp[indi]=max(foo[indi]+F1(n, indi+2), F1(n, indi+1));
}

int main(void)
{
//	IN("input.txt");
	
	int N, M;
	
	while(1)
	{
		sfi(N), sfi(M);
		
		foo.assign(N+5, 0);
		
		if(!N && !M)
		break;
		
		rep(i, N)
		{
			rep(j, M)
    		{
    			sfi(cost[j]);
    		}
    		
    		dp.assign(M+5, -1);
    		foo[i]=F(M, 0);
		}

		dp.assign(N+5, -1);
		pfl(F1(N, 0));
		
		foo.clear();
		dp.clear();
	}
	return (0);
}