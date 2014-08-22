// Author : Bony Roopchandani
// HORRIBLE
// BIT

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

class BIT
{
	VLL tree1;
	VLL tree2;
	int N;
	
	public:
	
	BIT(int n)
	{
		tree1.assign(n+5, (ll)0);
		tree2.assign(n+5, (ll)0);
		N=n;
	}
	
	void process()
	{
		int Q; sfi(Q);
		int c, u, v;
		ll x;
		
		while(Q--)
		{
			sfi(c), sfi(u), sfi(v);
			
			if(!c)
			{
				sfl(x);
				update1(u, x);
				update1(v+1, -x);
				update2(u, x*(u-1));
				update2(v+1, -x*v);
			}
			else
			{
				pfl(sum(v)-sum(u-1));
			}
		}
	}
	
	void update1(int pos, ll val)
	{
		while(pos<=tree1.sz)
		{
			tree1[pos]+=val;
			pos+=(pos&(-pos));
		}
	}
	
	ll get1(int pos)
	{
		ll S=0;
		
		while(pos>0)
		{
			S+=tree1[pos];
			pos-=(pos&(-pos));
		}
		
		return S;
	}
	
	void update2(int pos, ll val)
	{
		while(pos<=tree2.sz)
		{
			tree2[pos]+=val;
			pos+=(pos&(-pos));
		}
	}
	
	ll get2(int pos)
	{
		ll S=0;
		
		while(pos>0)
		{
			S+=tree2[pos];
			pos-=(pos&(-pos));
		}
		
		return S;
	}
	
	ll sum(ll x)
	{
		return (get1(x)*x - get2(x));
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	int N;
	
	while(T--)
	{
		sfi(N);
		BIT B(N);
    	B.process();
	}
	
	return (0);
}