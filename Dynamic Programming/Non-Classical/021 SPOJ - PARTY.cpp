// Author : Bony Roopchandani
// PARTY
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

int dp[100 + 5][500 + 5];

class Knapsack
{
	int *P;
	int *F;
	int N;
	
  public:

	  Knapsack(int n)
	{
		N = n;
		memset(dp, -1, sizeof dp);
		P = new int[N + 5];
		F = new int[N + 5];
	}

	 ~Knapsack()
	{
		delete[]P;
		delete[]F;
	}

	void process(int B)
	{
		rep(i, N) 
		sfi(P[i]), sfi(F[i]);

		int P=count(0, B);
		int lo=0, hi=B, mid;
		
		while(lo<hi)
		{
			mid=(lo+hi)>>1;
			
			if(count(0, mid)<P)
			lo=mid+1;
			else
			hi=mid;
		}
		
		pf(lo), pfi(P);
	}

	int count(int id, int RemW)
	{
		if (id == N || RemW == 0)
			return 0;

		if (dp[id][RemW] != -1)
		{
			return dp[id][RemW];
		}

		if (P[id] > RemW)
		{
			return dp[id][RemW] = count(id + 1, RemW);
		}

		if (F[id] <= RemW)
		{
			return dp[id][RemW] =
				max(count(id + 1, RemW), F[id] + count(id + 1, RemW - P[id]));
		}
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int B, N;

	while (1)
	{
		{
			sfi(B), sfi(N);

			if (!B && !N)
				break;

			Knapsack K(N);
			K.process(B);
		}
	}
	return (0);
}