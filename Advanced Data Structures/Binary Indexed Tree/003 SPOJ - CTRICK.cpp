// Author : Bony Roopchandani
// CTRICK
// Binary Indexed Tree

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
	VI tree;
	int N;
	
	public:
	
	BIT(int n)
	{
		N=n;
		tree.assign(N+1, 0);
		
		rept(i, 1, N)
		update(i, 1);
	}
	
	void process()
	{
		int foo[N+5];
		int rot=1;
		int R=N;
		
		rept(i, 1, N)
		{
			rot=(rot+i)%R;
			rot=(!rot)?R:rot;
			R--;
			
			int l=1, r=N;
			
			while(l<=r)
			{
				int mid=(l+r)>>1;
				
				if(get(mid)>=rot)
				r=mid-1;
				else
				if(get(mid)<rot)
				l=mid+1;
			}
			
			update(l, -1);
			foo[l]=i;
		}
		
		rept(i, 1, N-1)
		pf(foo[i]);
		pfi(foo[N]);
	}
	
	void update(int pos, int val)
	{
		while(pos<=tree.sz)
		{
			tree[pos]+=val;
			pos+=(pos&(-pos));
		}
	}
	
	int get(int pos)
	{
		int S=0;
		
		while(pos>0)
		{
			S+=tree[pos];
			pos-=(pos&(-pos));
		}
		
		return S;
	}
};

int main()
{
	int T, N; sfi(T);
	
	while(T--)
	{
		sfi(N);
		BIT B(N);
    	B.process();
	}
	
	return (0);
}