// Author : Bony Roopchandani
// CW6
// Ad - Hoc

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

int main(void)
{
//	in("input.txt");

	int T; sfi(T);
	int Hash[300]={0};
	
	Hash['C']=0;
	Hash['c']=1;
	Hash['D']=2;
	Hash['d']=3;
	Hash['E']=4;
	Hash['F']=5;
	Hash['f']=6;
	Hash['G']=7;
	Hash['g']=8;
	Hash['A']=9;
	Hash['B']=10;
	Hash['S']=11;
	
	while(T--)
	{
		char a, b, c;
		cin>>a>>b>>c;
		
		int x=Hash[a], y=Hash[b], z=Hash[c];
		
		if(x<y && y<z)
		{
			if((y-x)==4 && (z-y)==3)
			puts("Major");
			else
			puts("Minor");
		}
		else
		{
			if(y<x)
			y+=12, z+=12;
			else if(z<y)
			z+=12;
			
			if((y-x)==4 && (z-y)==3)
			puts("Major");
			else
			puts("Minor");
		}
	}
	
	return (0);
}