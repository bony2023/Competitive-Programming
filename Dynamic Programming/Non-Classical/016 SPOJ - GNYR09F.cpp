// Author : Bony Roopchandani
// GNYR09F
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

ll dp[100+5][100+5];

class DP
{
	public:
	
	DP()
	{
		rep(i, 100+5)
		fill(dp[i], dp[i]+100+5, -1);
		
		dp[1][0]=2;
		dp[2][0]=3;
		
		rept(i, 3, 100+4)
		{
			dp[i][0]=dp[i-1][0]+dp[i-2][0];
		}
	}
	
	ll init()
	{
		rept(i, 1, 100+4)
		{
			rept(j, 1, 100+3)
			{
				if(dp[i][j] == -1)
				{
					if(j>=i)
					dp[i][j]=0;
					else
					if(i-j==1)
					dp[i][j]=1;
					else
					if(i-j==2)
					dp[i][j]=2;
					else
					{
						int a=i-1, b=j;
						dp[i][j]=dp[a][b];
						a--;
						
						while(b>=0 && a>=1)
						{
							dp[i][j]+=dp[a][b];
							a--, b--;
						}
					}
				}
			}
		}
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	DP D;
	D.init();
	
	int T, C, N, K;
	sfi(T);
	
	while(T--)
	{
		sfi(C), sfi(N), sfi(K);
		
		pf(C), pfl(dp[N][K]);
	}
	
	return (0);
}