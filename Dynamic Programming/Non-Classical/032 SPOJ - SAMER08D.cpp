// Author : Bony Roopchandani
// SAMER08D
// LCS + DP

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

int dp[1000+1][1000+1];

class LCS
{
	char A[1000+5];
	char B[1000+5];
	int K;
	
	public:
	
	void process(int k)
	{
		K=k;
		memset(dp, 0, sizeof dp);
		sfs(A+1), sfs(B+1);
		int a=strlen(A+1);
		int b=strlen(B+1);
		
		pfi(get(a, b));
	}
	
	int get(int a, int b)
	{
		rept(i, K, a)
		{
			rept(j, K, b)
			{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
				
				rept(p, 0, i)
				{
					if(p>=K)
					dp[i][j]=max(dp[i][j], dp[i-p][j-p]+p);
					
					if(A[i-p] != B[j-p])
					break;
				}
			}
		}
		
		return dp[a][b];
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int K;
	
	while(sfi(K)==1 && K)
	{
		LCS A;
		A.process(K);
	}
	
	return (0);
}