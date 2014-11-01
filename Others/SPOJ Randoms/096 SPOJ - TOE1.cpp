// Author : Bony Roopchandani
// TOE1
// Ad-Hoc

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

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		char foo[4][4];
		int Xtot=0, Otot=0;
		
		rep(i, 3)
		{
			sfs(foo[i]);
			
			rep(j, 3)
			if(foo[i][j]=='X')
			Xtot++;
			else if(foo[i][j]=='O')
			Otot++;
		}
		
		if(Xtot-Otot != 1 && Xtot-Otot != 0)
		{
			puts("no");
			continue;
		}
		
		bool Xwin=0, Owin=0;
		
		rep(i, 3)
		{
			char curr=foo[i][0];
			int c=0;
			
			rep(j, 3)
			{
				if(foo[i][j]==curr)
				c++;
			}
			
			if(c==3)
			{
				if(curr=='X')
		      	Xwin=1;
	      		else if(curr=='O')
	      		Owin=1;
			}
		}
		
		rep(i, 3)
		{
			char curr=foo[0][i];
			int c=0;
			
			rep(j, 3)
			{
				if(foo[j][i]==curr)
				c++;
			}
			
			if(c==3)
			{
				if(curr=='X')
				Xwin=1;
				else if(curr=='O')
				Owin=1;
			}
		}
		
		char curr=foo[0][0];
		int c=0;
		
		rep(i, 3)
		if(foo[i][i]==curr)
		c++;
		
		if(c==3)
		{
			if(curr=='X')
			Xwin=1;
			else if(curr=='O')
			Owin=1;
		}
		
		curr=foo[0][2];
		c=0;
		
		for(int i=0, j=2; j>=0; i++, j--)
		if(foo[i][j]==curr)
		c++;
		
		if(c==3)
		{
			if(curr=='X')
			Xwin=1;
			else if(curr=='O')
			Owin=1;
		}
		
		if(Xwin && Owin)
		{
			puts("no");
			continue;
		}
		
		if(Xwin && Xtot-Otot != 1)
		{
			puts("no");
			continue;
		}
		
		if(Owin && Xtot!=Otot)
		{
			puts("no");
			continue;
		}
		
		puts("yes");
	}
	
	return (0);
}