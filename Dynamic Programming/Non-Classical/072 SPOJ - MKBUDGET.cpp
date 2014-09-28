// Author : Bony Roopchandani
// MKBUDGET
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

int N;
int NEmp[24+5];
int Sal, Agen, Seve;
ll dp[24+5][30+5];

ll F(int c, int last)
{
	if(c>=N)
	return 0;
	
	else if(dp[c][last] != -1)
	return dp[c][last];
	
	ll ans=INF<<1;
	
	if(NEmp[c]==last)
	{
		ans=(NEmp[c]*Sal)+F(c+1, NEmp[c]);
	}
	
	else if(NEmp[c]>last)
	{
		ans=((Sal*NEmp[c])+(Agen*(NEmp[c]-last))+F(c+1, NEmp[c]));
	}
	
	else if(NEmp[c]<last)
	{
		repd(i, last, NEmp[c])
		{
			ans=min(ans, (last-i)*Seve+(Sal*i)+F(c+1, i));
		}
	}
	
	return dp[c][last]=ans;
}

int main(void)
{
//	in("input.txt");
	
	int cs=1;
	
	while(1)
	{
		sfi(N);
		
		if(!N) break;
		
		memset(dp, -1, sizeof dp);
		
		sfi(Agen), sfi(Sal), sfi(Seve);
		
		rep(i, N)
		sfi(NEmp[i]);
		
		printf("Case %d, cost = $", cs++);
		pfl(F(0, 0));
	}
	
	return (0);
}