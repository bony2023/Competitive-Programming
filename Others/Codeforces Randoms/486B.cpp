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

bool Row[100+5]={0}, Col[100+5]={0};

int main(void)
{
	bool isOne=false;
	int R, C; sfi(R), sfi(C);
	bool a[R+5][C+5], Ori[R+5][C+5];
	
	rep(i, R)
	{
		rep(j, C)
		{
			sfi(a[i][j]);
			if(a[i][j]) isOne=true;
			
			if(!a[i][j])
			{
				if(!Row[i]) Row[i]=true;
				if(!Col[j]) Col[j]=true;
			}
			Ori[i][j]=a[i][j];
		}
	}
	
	if(!isOne)
	{
		puts("YES");
		
		rep(i, R)
		{
			rep(j, C)
			pf(0);
			nl;
		}
		return 0;
	}
	
	rep(k, max(R, C))
	{
		if(Row[k])
		{
			rep(j, C)
			a[k][j]=0;
		}
		
		if(Col[k])
		{
			rep(i, R)
			a[i][k]=0;
		}
	}
	
	bool ok=false;
	memset(Row, 0, sizeof Row);
	memset(Col, 0, sizeof Col);
	
	rep(i, R) rep(j, C) if(a[i][j]) {
													ok=true;
													if(!Row[i]) Row[i]=true;
													if(!Col[j]) Col[j]=true;
	}
	
	bool res[R+5][C+5];
	memcpy(res, a, sizeof a);
	
	if(ok)
	{
		rep(k, max(R, C))
		{
			if(Row[k])
			{
				rep(j, C)
		    	a[k][j]=1;
			}
			
			if(Col[k])
			{
				rep(i, R)
    			a[i][k]=1;
			}
		}
		
		rep(i, R) rep(j, C) if(a[i][j] != Ori[i][j]) {
																		ok=false;
																		break;
		}
	}
	
	if(ok)
	{
		puts("YES");
		rep(i, R)
		{
			rep(j, C)
			pf(res[i][j]); nl;
		}
	}
	else
	puts("NO");
	
	return (0);
}