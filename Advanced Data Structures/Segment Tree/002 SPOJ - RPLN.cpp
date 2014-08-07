// Author : Bony Roopchandani
// RPLN
// Segment Tree

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
#define INF (1e9 + 9)
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

class SegmentTree
{
	class node;
	node* tree;
	
	class node
	{
		public:
		
		ll val;
		
		node()
		{
			val=INF;
		}
		
		void merge(node a, node b)
		{
			val=min(a.val, b.val);
		}
	};
	
	public:
	
	SegmentTree(int n)
	{
		int RightMost=1<<(n+1);
		tree=new node[RightMost];
	}
	
	~SegmentTree()
	{
		if(tree)
		delete []tree;
	}
	
	void range_update(int root, int LM, int RM, int u, int v, ll val)
	{
		if(u<=LM && RM<=v)
		{
			tree[root].val=val;
			return;
		}
		
		int mid=(LM+RM)>>1;
		int LC=root<<1;
		int RC=LC+1;
		
		if(u<mid)
		range_update(LC, LM, mid, u, v, val);
		
		if(v>mid)
		range_update(RC, mid, RM, u, v, val);
		
		tree[root].merge(tree[LC], tree[RC]);
	}
	
	void update(int n, int pos, ll val)
	{
		return range_update(1, 1<<n, 1<<(n+1), (1<<n)+pos, (1<<n)+1+pos, val);
	}
	
	node query(int root, int LM, int RM, int u, int v)
	{
		if(u<=LM && RM<=v)
		return tree[root];
		
		int mid=(LM+RM)>>1;
		int LC=root<<1;
		int RC=LC+1;
		
		node L, R;
		
		if(u<mid)
		L=query(LC, LM, mid, u, v);
		
		if(v>mid)
		R=query(RC, mid, RM, u, v);
		
		tree[root].merge(tree[LC], tree[RC]);
		
		node P;
		P.merge(L, R);
		
		return P;
	}
	
	ll find(int u, int v, int n)
	{
		return query(1, 1<<n, 1<<(n+1), (1<<n)+u, (1<<n)+v+1).val;
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T, N, Q, n, u, v, cs=1;
	ll x;
    sfi(T);
	
	while(T--)
	{
		sfi(N), sfi(Q);
		
		n=ceil(log(N)/log(2));
		
		SegmentTree S(n);
		
		rep(i, N)
		{
			sfl(x);
			S.update(n, i, x);
		}
		
	printf("Scenario #%d:\n\n",cs++);
	
		while(Q--)
		{
			sfi(u), sfi(v);
			u--, v--;
			
			printf("%lld\n", S.find(u, v, n));
		}
	}
	
	return 0;
}