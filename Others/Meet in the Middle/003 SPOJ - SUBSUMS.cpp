// Author : Bony Roopchandani
// SUBSUMS
// Meet in the Middle

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

int X[1<<18];
int Y[1<<18];
int x=0, y=0;

int main(void)
{
	int N, a, b, q;
	sfi(N), sfi(a), sfi(b);
	int n1=N>>1;
	int n2=(N+1)>>1;
	
	int P1[n1+1];
	int P2[n2+1];
	
	rep(i, n1)
	{
		sfi(P1[i]);
	}
	
	rep(i, n2)
	{
		sfi(P2[i]);
	}
	
	rep(i, 1<<n1)
	{
		q=0;
		
		rep(j, n1)
		{
			if((i>>j) & 1)
			q+=P1[j];
		}
		
		X[x++]=q;
	}
	
	rep(i, 1<<n2)
	{
		q=0;
		
		rep(j, n2)
		{
			if((i>>j)&1)
			q+=P2[j];
		}
		
		Y[y++]=q;
	}
	
	sort(X, X+x);
	sort(Y, Y+y);
	
	int m1, m2;
	ll res=0;
	
	rep(i, x)
	{
		m1=lower_bound(Y, Y+y, a-X[i])-Y;
		m2=upper_bound(Y, Y+y, b-X[i])-Y;
		
		if(m2>=m1)
		res+=(m2-m1);
	}
	
	pfl(res);
	
	return (0);
}