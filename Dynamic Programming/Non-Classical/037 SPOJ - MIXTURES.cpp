// Author : Bony Roopchandani
// MIXTURES
// DP + BIT

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

int A[100+5];
int dp[102][102];
int tree[100+5]={0};

void update(int x, int N, int val)
{
	while(x<=N)
	{
		tree[x]+=val;
		x+=(x & (-x));
	}
}

int query(int x)
{
	int S=0;
	
	while(x>0)
	{
		S+=tree[x];
		x-=(x & (-x));
	}
	
	return S;
}

int sum(int a, int b)
{
	return ((query(b+1)-query(a))%100);
}

int f(int a, int b)
{
	if(a==b)
	return 0;
	
	if(dp[a][b] != -1)
	return dp[a][b];
	
	int ans=INF<<1;
	
	rept(i, a, b-1)
	{
		ans=min(ans, f(a, i)+f(i+1, b)+sum(a, i)*sum(i+1, b));
	}
	
	return dp[a][b]=ans;
}

int main()
{
	int N;
	
	while(sfi(N)==1)
	{
		memset(dp, -1, sizeof dp);
		
		rep(i, N)
		{
			sfi(A[i]);
			update(i+1, N+3, A[i]);
		}
		
		pfi(f(0, N-1));
		
		memset(tree, 0, sizeof tree);
	}
	
	return (0);
}