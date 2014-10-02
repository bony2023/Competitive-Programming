// Author : Bony Roopchandani
// 10364 - Square
// DP+Bitmask

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

int N, K;
int A[20+5];
bool dp[5][1<<20];
bool vis[5][1<<20];

bool F(int id, int bitmask, int currSum)
{
	if(id==4 && bitmask==((1<<N)-1))
	return true;
	
	if(vis[id][bitmask])
	return dp[id][bitmask];
	
	vis[id][bitmask]=1;
	
	bool ans=false;
	
	rep(i, N)
	{
		if(!(bitmask & (1<<i)) && (A[i]+currSum)<=K)
		{
			if((currSum+A[i])==K)
			ans |= F(id+1, (bitmask | (1<<i)), 0);
			else
			ans |= F(id, (bitmask | (1<<i)), currSum+A[i]);
		}
	}
	
	return dp[id][bitmask]=ans;
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		sfi(N);
		
		int sum=0;
		
		rep(i, N)
		{
			sfi(A[i]);
			sum+=A[i];
		}
		
		if(sum%4)
		puts("no");
		
		else
		{
			K=sum/4;
			
			memset(vis, 0, sizeof vis);
			
			if(F(0, 0, 0))
      		puts("yes");
      		
      		else
      		puts("no");
		}
	}
	
	return (0);
}