// Author : Bony Roopchandani
// PERIOD
// KMP Reset Table Variant

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

int b[1<<20];
string A;

class myComp
{
	public:
	
	bool operator()(PII a, PII b)
	const
	{
		return (a.ff<b.ff);
	}
};

class KMP
{
	set<PII, myComp> S;
	
	public:
	
	void process()
	{
		int len;
		cin>>len;
		cin>>A;
		bool cond=false;
		
		int j;
		j=b[0]=-1;
		
		rept(i, 1, A.sz)
		{
			while(j>=0 && A[i-1] != A[j])
			j = b[j];
			
			b[i]=++j;
		}
		
		int pieces;
		
		rept(i, 1, len)
		{
			if(i%(i-b[i])==0)
			{
				pieces=i/(i-b[i]);
				
				if(pieces !=1)
				S.insert(PII(i, pieces));
			}
		}
		
		set<PII>::iterator T=S.bg;
		
		for(; T!=S.en; T++)
		pf((*T).ff), pfi((*T).ss);
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int cs=1, T; sfi(T);
	
	while(T--)
	{
		printf("Test case #%d\n",cs++);
		KMP K;
    	K.process();
    	nl;
	}
	
	return (0);
}