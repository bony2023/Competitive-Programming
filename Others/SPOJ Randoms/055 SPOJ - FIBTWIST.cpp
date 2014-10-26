// Author : Bony Roopchandani
// FIBTWIST
// Matrix Exponentiation

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

ll N, M;

void multi(ll a[2][2], ll b[2][2])
{
		ll tmp[2][2];
	
	tmp[0][0]=(a[0][0]*b[0][0])%M+(a[0][1]*b[1][0])%M; 
	tmp[0][1]=(a[0][0]*b[0][1])%M+(a[0][1]*b[1][1])%M;
	tmp[1][0]=(a[1][0]*b[0][0])%M+(a[1][1]*b[1][0])%M;
	tmp[1][1]=(a[1][0]*b[0][1])%M+(a[1][1]*b[1][1])%M;
	
	a[0][0]=tmp[0][0]%M;
	a[0][1]=tmp[0][1]%M;
	a[1][0]=tmp[1][0]%M;
	a[1][1]=tmp[1][1]%M;
}

void power(ll a[2][2], ll N)
{
	if(!N || N==1)
	return;
	
	ll ret[2][2]={1, 0, 0, 1};
	
	while(N)
	{
		if(N&1)
		{
			multi(ret, a);
		}
		
		multi(a, a);
		
		N>>=1;
	}
	
	a[0][0]=ret[0][0]%M;
	a[0][1]=ret[0][1]%M;
	a[1][0]=ret[1][0]%M;
	a[1][1]=ret[1][1]%M;
}

ll Fib(ll N)
{
	if(N==0)
	return 0;
	
	ll F[2][2]={1, 1, 1, 0};
	
	power(F, N-1);
	
	return (F[0][0]%M);
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		sfl(N), sfl(M);
		ll res;
		
		res=(2*(Fib(N+2)-1)-N)%M;
		if(res<0)
		res+=M;
		
		pfl(res);
	}
	
	return (0);
}