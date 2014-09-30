// Author : Bony Roopchandani
// 616 - Coconuts, Revisited
// Maths - Ad -Hoc

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
#define ll long long
#define mp make_pair
#define nl printf("\n")
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

class Maths
{
	public:
	
	void process(int N)
	{
		int Remain;
		int n=N;
		bool sol=false;
		int ans;
		int people;
		
		N=sqrt(N);
		
		rept(i, 2, N)
		{
			Remain=n;
			people=0;
			
			while(Remain%i==1)
			{
				people++;
				Remain-=(Remain/i+1);
			}
			
			if(Remain%i==0 && people==i)
			{
				sol=true;
				ans=people;
			}
		}
		
		if(n==3)
		printf("%d coconuts, %d people and 1 monkey\n", 3, 2);
		else
		if(sol)
		printf("%d coconuts, %d people and 1 monkey\n",n, ans);
		else
		printf("%d coconuts, no solution\n", n);
	}
};

int main()
{
	int N;
	
	while(sfi(N)==1 && N>=0)
	{
		Maths M;
		M.process(N);
	}
	
	return (0);
}