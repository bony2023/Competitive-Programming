// Author : Bony Roopchandani
// 10054 - The Necklace
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
typedef vector<pair<bool, int> >VB;

class Euler
{
	 VB* A;
	 LI cyc;
	
	public:
	
	Euler()
	{
		A = new VB[55];
	}
	
	~Euler()
	{
		if(A) delete []A;
		cyc.clear();
	}
	
	void process()
	{
		int N; sfi(N);
		int x, y, togg=0, init;
		
		rep(i, N)
		{
			sfi(x), sfi(y);
			
			if(togg==0)
			init=x, togg=1;
			
			A[x].pb(mp(1, y));
			A[y].pb(mp(1, x));
		}
		
		if(isEuler())
		{
			PrintPath(init, cyc.bg);
			
			if(N)
			cyc.push_front(init);
			
			LI::iterator t=cyc.bg;
			
			for(; t!=cyc.en ;)
			{
				pf(*t);
				t++;
				pfi(*t);
				
				t++;
				if(t==cyc.en)
				break;
				else
				t--;
			}
		}
		else
		puts("some beads may be lost");
	}
	
	bool isEuler()
	{
		rep(i, 55)
		if(1 & A[i].sz)
		return false;
		
		return true;
	}
	
	void PrintPath(int u, LI::iterator i)
	{
		VB::iterator j=A[u].bg;
		
		for(; j!=A[u].en; j++)
		{
			if(j->ff)
			{
				j->ff=0;
				
				VB::iterator k=A[j->ss].bg;
				
				for(; k!=A[j->ss].en; k++)
				{
					if(k->ff && k->ss==u)
					{
						k->ff=0;
						break;
					}
				}
				
				PrintPath(j->ss, cyc.insert(i, u));
			}
		}
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T, cs=1;
	sfi(T);
	
	while(T--)
	{
		if(cs!=1)
		nl;
		
		printf("Case #%d\n",cs++);
		
		Euler E;
		E.process();
	}
	
	return 0;
}