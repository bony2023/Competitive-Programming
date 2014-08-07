// Author : Bony Roopchandani
// 10203 - Snow Clearing
// Euler Tour

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

class Euler
{
	ll TotalTime;
	double T;
	const double V=2000/6;
	
	public:
	
	Euler()
	{
		TotalTime=T=0;
	}
	
	void process()
	{
		input();
		
		T*=2;
		
		T/=V;
		
		TotalTime=floor(T+0.5);
		
	printf("%lld:%.2lld\n",TotalTime/60, TotalTime%60);
	}
	
	void input()
	{
		int a, b, c, d;
		double D;
		
		scanf("%d %d\n",&a, &b);
		a=b=c=d=0;
		
		string foo;
		
		while(getline(cin, foo) && sscanf(foo.c_str(), "%d%d%d%d", &a, &b, &c, &d) == 4)
		{
			D=compute(a, b, c, d);
			T+=D;
		}
	}
	
	double compute(int x1, int y1, int x2, int y2)
	{
		double a=(x1-x2);
		double b=(y1-y2);
		
		return hypot(a, b);
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	int cs=1;
	
	while(T--)
	{
   	Euler E;
   	
   	if(cs!=1)
   	nl;
   	cs++;
   	
   	E.process();
	}
	
	return 0;
}