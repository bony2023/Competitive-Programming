// Author : Bony Roopchandani
// 10851 - 2D Hieroglyphs decoder
// String - Ad - Hoc

// INCLUDES
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// MACROS
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i=0; i<n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD (1e9 + 7)

// TYPEDEFS
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef map < int, int > MII;
typedef map < ll, int > MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int > LI;
typedef list < ll > LLL;
typedef set < int > SI;
typedef set < ll > SLL;

int TWO[]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

class Decipher
{
	char STR[12][100];
	int len;
	
	public:
	
	void process()
	{
		input();
		int t[100];
		t['/']=0;
		t['\\']=1;
		int foo;
		bool cond, next;
		
		rept(i, 1, len)
		{
			next=true;
			rept(j, 32, 126)
			{
				cond=true;
				rept(k, 1, 8)
				{
					foo=j/TWO[k-1];
					foo%=2;
					if(foo==t[STR[k][i]])
					continue;
					else
					{
						cond=false;
						break;
					}
				}
				
				if(cond)
				{
					next=false;
					printf("%c", j);
					break;
				}
			}
		}
		nl;
	}
	
	void input()
	{
		rep(i, 10)
		sfs(STR[i]);
		len=strlen(STR[0]);
		len-=2;
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	int T; sfi(T);
	
	while(T--)
	{
		Decipher D;
    	D.process();
	}
	
	return 0;
}