// Author : Bony Roopchandani
// ELIS
// LIS

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

class ELIS
{
	int* LIS;
	int N;
	int* Arr;
	
	public:
	
	ELIS(int n)
	{
		N=n;
		LIS = new int[N+5]();
		Arr = new int[N+5];
	}
	
	~ELIS()
	{
		delete []Arr;
		delete []LIS;
	}
	
	void process()
	{
		rep(i, N)
		sfi(Arr[i]);
		
		LIS[0]=1;
		int a;
		
		rept(i, 1, N-1)
		{
			a=0;
			
			rep(j, i)
			if(Arr[j]<Arr[i]) 
			a=max(LIS[j], a);
			
			LIS[i]=a+1;
		}
		
		a=0;
		rep(i, N)
		a=max(a, LIS[i]);
		
		pfi(a);
	}
};

int main()
{
	int N; sfi(N);
	
	ELIS EL(N);
	EL.process();
	return (0);
}