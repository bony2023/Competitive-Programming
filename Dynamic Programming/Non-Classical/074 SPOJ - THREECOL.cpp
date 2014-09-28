// Author : Bony Roopchandani
// THREECOL
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
typedef list < int >LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int >MII;
typedef map < int, ll > MIL;
typedef map < ll, int >MLI;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef set < int >SI;
typedef set < ll > SLL;
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

int counter = 1;
char foo[10000 + 5];
VI A[10000 + 5];
int dp[2][10000 + 5];

int F2(bool isGreen, int currNode)
{
	if (dp[isGreen][currNode] != -1)
		return dp[isGreen][currNode];

	else
	{
		int &ans = dp[isGreen][currNode];

		if (!A[currNode].sz)
		{
			if (isGreen)
				return ans = 1;
			else
				return ans = 0;
		}

		else if (A[currNode].sz == 1)
		{
			if (isGreen)
				return ans = 1 + F2(0, A[currNode][0]);
			else
				return ans = min(F2(1, A[currNode][0]), F2(0, A[currNode][0]));
		}

		else if (A[currNode].sz == 2)
		{
			if (isGreen)
			{
				return ans = 1 + F2(0, A[currNode][0]) + F2(0, A[currNode][1]);
			}
			else
			{
				int x = F2(1, A[currNode][0]) + F2(0, A[currNode][1]);

				int y = F2(0, A[currNode][0]) + F2(1, A[currNode][1]);

				return ans = min(x, y);
			}
		}
	}
}

void build(int currNode)
{
	if (foo[currNode] == '0')
		return;

	rep(i, (foo[currNode] - '0'))
	{
		A[currNode].pb(counter);
		build(counter++);
	}
}

int F1(bool isGreen, int currNode)
{
	if (dp[isGreen][currNode] != -1)
		return dp[isGreen][currNode];

	else
	{
		int &ans = dp[isGreen][currNode];

		if (!A[currNode].sz)
		{
			if (isGreen)
				return ans = 1;
			else
				return ans = 0;
		}

		else if (A[currNode].sz == 1)
		{
			if (isGreen)
				return ans = 1 + F1(0, A[currNode][0]);
			else
				return ans = max(F1(1, A[currNode][0]), F1(0, A[currNode][0]));
		}

		else if (A[currNode].sz == 2)
		{
			if (isGreen)
			{
				return ans = 1 + F1(0, A[currNode][0]) + F1(0, A[currNode][1]);
			}
			else
			{
				int x = F1(1, A[currNode][0]) + F1(0, A[currNode][1]);

				int y = F1(0, A[currNode][0]) + F1(1, A[currNode][1]);

				return ans = max(x, y);
			}
		}
	}
}

void clear(int V)
{
	rep(i, V+5)
	A[i].clear();
	counter=1;
}

int main(void)
{
	int T;
	sfi(T);

	while (T--)
	{
		sfs(foo);

		build(0);
		
		memset(dp, -1, sizeof dp);
		int x=F1(1, 0);
		int y=F1(0, 0);
		pf(max(x, y));
		
		memset(dp, -1, sizeof dp);
		x=F2(1, 0);
		y=F2(0, 0);
		pfi(min(x, y));
		
		clear(strlen(foo));
	}
	return (0);
}