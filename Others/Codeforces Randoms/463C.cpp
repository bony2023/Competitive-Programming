// Author : Bony Roopchandani
// 

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
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

int n;
ll a[2000+5][2000+5];
ll first[4000+5]={0}, second[4000+5]={0};

int firstdiag(int i, int j)
{
	return i+j-1;
}

int secdiag(int i, int j)
{
	return n-i+j;
}

bool isWhite(int i, int j)
{
	return ((i+j)&1);
}

int main(void)
{
	sfi(n);
	rept(i, 1, n) rept(j, 1, n) sfl(a[i][j]), first[firstdiag(i, j)]+=a[i][j], second[secdiag(i, j)]+=a[i][j];
	
	ll mx1=-1, mx2=-1;
	int x1, y1, x2, y2;
	
	rept(i, 1, n) rept(j, 1, n) {
		ll currmx=first[firstdiag(i, j)]+second[secdiag(i, j)]-a[i][j];
		
		if(isWhite(i, j))
		{
			if(mx1<currmx)
			{
				mx1=currmx;
				x1=i, y1=j;
			}
		}
		else
		{
			if(mx2<currmx)
			{
				mx2=currmx;
				x2=i, y2=j;
			}
		}
	}
	
	pfl(mx1+mx2);
	pf(x2), pf(y2), pf(x1), pfi(y1);
	
	return (0);
}