// Author : Bony Roopchandani
// PRPOTION
// Greedy

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
	int R, G, B, M;
	ll color[3][100+5];
	
	while(T--)
	{
		sfi(R), sfi(G), sfi(B), sfi(M);
		
		ll currMax=0;
		int currID;
		
		rep(i, R)
		{
			sfl(color[0][i]);
			
			if(color[0][i]>currMax)
			{
				currMax=color[0][i];
				currID=0;
			}
		}
		
		rep(i, G)
		{
			sfl(color[1][i]);
			
			if(color[1][i]>currMax)
			{
				currMax=color[1][i];
				currID=1;
			}
		}
		
		rep(i, B)
		{
			sfl(color[2][i]);
			
			if(color[2][i]>currMax)
			{
				currMax=color[2][i];
				currID=2;
			}
		}
		
		ll res=currMax;
		
		rep(i, M)
		{
			currMax=0;
			
			switch(currID)
			{
				case 0:
				rep(j, R)
				{
					color[0][j]/=2;
					if(currMax<color[0][j])
					currMax=color[0][j], currID=0;
				}
				
				rep(j, G)
				{
					if(currMax<color[1][j])
					currMax=color[1][j], currID=1;
				}
				
				rep(j, B)
				{
					if(currMax<color[2][j])
					currMax=color[2][j], currID=2;
				}
				
				break;
				
				case 1:
				
				rep(j, R)
				{
					if(currMax<color[0][j])
					currMax=color[0][j], currID=0;
				}
				
				rep(j, G)
				{
					color[1][j]/=2;
					if(currMax<color[1][j])
					currMax=color[1][j], currID=1;
				}
				
				rep(j, B)
				{
					if(currMax<color[2][j])
					currMax=color[2][j], currID=2;
				}
				
				break;
				
				case 2:
				
				rep(j, R)
				{
					if(currMax<color[0][j])
					currMax=color[0][j], currID=0;
				}
				
				rep(j, G)
				{
					if(currMax<color[1][j])
					currMax=color[1][j], currID=1;
				}
				
				rep(j, B)
				{
					color[2][j]/=2;
					if(currMax<color[2][j])
					currMax=color[2][j], currID=2;
				}
			}
			
			res=min(res,currMax);
		}
		
		pfl(res);
	}
	
	return (0);
}