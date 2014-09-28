// Author : Bony Roopchandani
// 562 - Dividing coins
// Knapsack 0-1

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

 int dp[100+5][50000+5];

class Knapsack
{
   int A[100+5];
   int Sum, n;
   
   public:
   
   Knapsack(int N)
   {
   	n=N;
   	Sum=0;
   	
   	memset(dp, -1, sizeof dp);
   
   	rep(i, N)
   	sfi(A[i]), Sum+=A[i];
   }

   void process()
   {
   	int R=count(0, Sum>>1);
   	int S=Sum-R;
   	
   	pfi(abs(S-R));
   }

	int count(int id, int RemS)
	{
		if(dp[id][RemS] != -1)
		return dp[id][RemS];
		
		if (id == n)
			return 0;

		if (RemS <= 0)
			return 0;

		if (A[id] > RemS)
			return dp[id][RemS]=count(id + 1, RemS);
			
			if(A[id]<=RemS)
			return dp[id][RemS]=max(count(id + 1, RemS), A[id] + count(id + 1, RemS - A[id]));
	}
};

int main()
{
	int T; sfi(T);
	int N;
	
	while(T--)
	{
		sfi(N);
		Knapsack KS(N);
		KS.process();
	}
	return (0);
}