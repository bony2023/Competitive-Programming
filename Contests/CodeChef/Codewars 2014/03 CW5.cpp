// Author : Bony Roopchandani
// CW5
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

short Rx[]={0, -1, 0, 1};
short Ry[]={-1, 0, 1, 0};

short Bx[]={-1, -1, 1, 1};
short By[]={-1, 1, 1, -1};

bool valid(int a, int b)
{
	return (a>=0 && b>=0 && a<8 && b<8);
}

int main(void)
{
//	in("input.txt");
	
	char foo[10];
	bool A[10][10];
	int indi, indj;
	memset(A, 0, sizeof A);
	
	rep(i, 8)
	{
		sfs(foo);
		
		rep(j, 8)
		{
			if(foo[j]=='_');
			else
			{
				if(foo[j]=='P')
				indi=i, indj=j;
				else
				
				if(foo[j]=='R')
				{
					A[i][j]=1;
					
					rep(k, 4)
					{
						int x=i+Rx[k];
						int y=j+Ry[k];
						
						while(valid(x, y))
						{
							A[x][y]=1;
							x+=Rx[k];
							y+=Ry[k];
						}
					}
				}
				else
				
				if(foo[j]=='B')
				{
					rep(k, 4)
					{
						int x=i+Bx[k];
						int y=j+By[k];
						
						while(valid(x, y))
						{
							A[x][y]=1;
							x+=Bx[k];
							y+=By[k];
						}
					}
				}
				else
				
				if(foo[j]=='Q')
				{
					rep(k, 4)
					{
						int x=i+Rx[k];
						int y=j+Ry[k];
						
						while(valid(x, y))
						{
							A[x][y]=1;
							x+=Rx[k];
							y+=Ry[k];
						}
					}
					
					rep(k, 4)
					{
						int x=i+Bx[k];
						int y=j+By[k];
						
						while(valid(x, y))
						{
							A[x][y]=1;
							x+=Bx[k];
							y+=By[k];
						}
					}
				}
				else
				
				if(foo[j]=='S')
				{
					rep(k, 4)
					{
						int x=i+Rx[k];
						int y=j+Ry[k];
						
						if(valid(x, y))
						A[x][y]=1;
					}
					
					rep(k, 4)
					{
						int x=i+Bx[k];
						int y=j+By[k];
						
						if(valid(x, y))
						A[x][y]=1;
					}
				}
			}
		}
	}
	
	bool cond=0;
	
	rep(i, 4)
	{
		int x=Bx[i]+indi;
		int y=By[i]+indj;
		
		if(!A[x][y] && valid(x, y))
		{
			cond=true;
			break;
		}
		
		x=Rx[i]+indi;
		y=Ry[i]+indj;
		
		if(!A[x][y] && valid(x, y))
		{
			cond=true;
			break;
		}
	}

	if(cond)
	puts("NOT YET!");
	else
	puts("CHECKMATE!");
	
	
	return (0);
}