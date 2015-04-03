// Author : Bony Roopchandani
// CHEFPNT
// Ad-Hoc

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

char foo[100+5][100+5];
vector<PII> LR, UD;

int countLR(int N, int M)
{
	int cnt=0;
	
	rep(i, N)
	rep(j, M)
	{
		while(foo[i][j]=='1')
		j++;
		
		if(foo[i][j-1]=='1' && j)
		{
			LR.pb(mp(i+1, j));
			cnt++;
		}
	}
	
	return cnt;
}

int countUD(int N, int M)
{
	int cnt=0;
	
	rep(j, M)
	rep(i, N)
	{
		while(foo[i][j]=='1')
		i++;
		
		if(foo[i-1][j]=='1' && i)
		{
			UD.pb(mp(i, j+1));
			cnt++;
		}
	}
	
	return cnt;
}

int main(void)
{
	int N, M, K;
	
	sfi(N), sfi(M), sfi(K);
	
	rep(i, N)
	rep(j, M)
	foo[i][j]='1';
	
	int x, y;
	
	rep(i, K)
	{
		sfi(x), sfi(y);
		foo[x-1][y-1]='0';
	}
	
	int a=countLR(N, M), b=countUD(N, M), D;
	
	if(a<=b)
	D=0;
	else D=1;
	
	if(D)
	{
		pfi(UD.sz);
		rep(i, UD.sz)
		pf(UD[i].ff), pf(UD[i].ss), pfi(D);
	}
	else
	{
		pfi(LR.sz);
		rep(i, LR.sz)
		pf(LR[i].ff), pf(LR[i].ss), pfi(D);
	}
	
	return (0);
}