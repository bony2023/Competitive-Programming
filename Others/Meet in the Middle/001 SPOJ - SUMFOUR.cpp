// Author : Bony Roopchandani
// SUMFOUR
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

int Y[10000000+5], y;
int Z[10000000+5], z;

int binSearch(int V)
{
	int lo=0, hi=y, mi;
	
	while(lo<=hi)
	{
		mi=(lo+hi)>>1;
		
		if(Y[mi]==V)
		{
			int ret=1, pos=mi-1;
			
			while(Y[pos]==V && pos>=0)
			pos--, ret++;
			
			pos=mi+1;
			
			while(Y[pos]==V && pos<y)
			pos++, ret++;
			
			return ret;
		}
		
		else if(Y[mi]>V)
		hi=mi-1;
		
		else
		lo=mi+1;
	}
	
	return 0;
}

int main(void)
{
	int N; sfi(N);
	int A[4000+5], B[4000+5];
	int C[4000+5], D[4000+5];
	
	rep(i, N)
	sfi(A[i]), sfi(B[i]), sfi(C[i]), sfi(D[i]);
	
	rep(i, N)
	{
		rep(j, N)
		{
			Y[y++]=A[i]+B[j];
		}
	}
	
	rep(i, N)
	{
		rep(j, N)
		{
			Z[z++]=-(C[i]+D[j]);
		}
	}
	
	sort(Y, Y+y);
	sort(Z, Z+z);
	int res=0, p1, p2;
	
	for(int i=0; i<z; )
	{
		p1=1;
		p2=binSearch(Z[i]);
		i++;
		
		while(Z[i]==Z[i-1] && i<z)
		i++, p1++;
		
		res+=(p1*p2);
	}
	
	pfi(res);
	
	return (0);
}