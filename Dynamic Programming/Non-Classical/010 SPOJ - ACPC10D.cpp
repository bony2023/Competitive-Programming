// Author : Bony Roopchandani
// ACPC10D
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

class DP
{
	int dp[100000+5][4];
	int A[100000+5][4];
	
	public:
	
	void process(int N)
	{
		rep(i, N+5)
		fill(dp[i], dp[i]+4, INF);
		
		rep(i, N)
		sfi(A[i][0]), sfi(A[i][1]), sfi(A[i][2]);
		
		dp[0][1]=A[0][1];
		
		rep(i, N)
		{
			rep(j, 3)
			{
				if(!i && j<2)
				continue;
				
				if(i-1>=0)
				{
					if(i==1 && j<1)
					goto Y;
					
					dp[i][j]=min(dp[i][j], dp[i-1][j]+A[i][j]);
				}
				
				Y:
				
				if(j-1>=0)
				{
					dp[i][j]=min(dp[i][j], dp[i][j-1]+A[i][j]);
				}
				
				if(i-1>=0 && j-1>=0)
				{
					if(i==1 && j<2)
					goto X;
					
					dp[i][j]=min(dp[i][j], dp[i-1][j-1]+A[i][j]);
				}
				
				X:
				
				if(i-1>=0 && j+1<3)
				{
					dp[i][j]=min(dp[i][j], dp[i-1][j+1]+A[i][j]);
				}
			}
		}
		
		pfi(dp[N-1][1]);
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N, cs=1;
	
	while(sfi(N) && N)
	{
		printf("%d. ", cs++);
		DP D;
		D.process(N);
	}
	return (0);
}