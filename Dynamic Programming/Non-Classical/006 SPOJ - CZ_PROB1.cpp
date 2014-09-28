// Author : Bony Roopchandani
// CZ_PROB1
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

int SP[600];
ll dp[8000][5][5];
int C[]={0, 1, 2, 3, 4, 5};

class NWay
{
	int K;
	
	public:
	
	void process()
	{
		int N;
		
		sfi(N), sfi(K);
		
		pfl(Get(SP[N], 1));
	}
	
	ll Get(int N, int c)
	{
		if(N==0)
		return 1;
		
		if(c>K)
		return 0;
		
		if(dp[N][c][K] != -1)
		return dp[N][c][K];
		
		ll ans=0;
		
		for(int i=0; i*C[c]<=N; i++)
		ans+=Get(N-i*C[c], c+1);
		
		return dp[N][c][K]=ans;
	}
};

bool isPrime(int n)
{
	if(n%2==0)
	return false;
	
	int S=sqrt(n)*1.0;
	
	rept(i, 2, S)
	if(n%i==0)
	return false;
	
	return true;
}

void pre()
{
	SP[1]=2;
	SP[2]=5;
	int k=3;
	
	for(int i=2; ((4*i)+1)<=8000; i++)
	if(isPrime(4*i+1))
	SP[k++]=4*i+1;
	
	rep(i, 8000)
	rep(j, 6)
	fill(dp[i][j], dp[i][j]+5, (ll)-1);
}

int main()
{
	pre();
	
	int T; sfi(T);
	
	while(T--)
	{
		NWay Nw;
		Nw.process();
	}
	
	return (0);
}