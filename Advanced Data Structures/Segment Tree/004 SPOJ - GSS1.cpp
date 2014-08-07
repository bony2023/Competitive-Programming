// Author : Bony Roopchandani
// GSS1
// SegTree

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

class SegTree
{
	class node
	{
		ll SegSum;
		ll bestPrefix;
		ll bestSuffix;
		
		public:
		
		ll bestSum;
		
		node()
		{
			SegSum=-INF;
			bestPrefix=-INF;
			bestSuffix=-INF;
			bestSum=-INF;
		}
		
		void merge(node& a, node& b)
		{
			SegSum=a.SegSum+b.SegSum;
			bestPrefix=max(a.bestPrefix, a.SegSum+b.bestPrefix);
			bestSuffix=max(b.bestSuffix, b.SegSum+a.bestSuffix);
  	bestSum=max(max(a.bestSum, b.bestSum), a.bestSuffix+b.bestPrefix);
		}
		
		void create(ll val)
		{
			SegSum=bestSum=bestSuffix=bestPrefix=val;
		}
	};
	
	node* tree;
	
	public:
	
	SegTree(int n)
	{
		tree=new node[1<<(n+1)];
	}
	
	~SegTree()
	{
		if(tree) delete []tree;
		tree=NULL;
	}
	
	void mergeup(int pos)
	{
		pos>>=1;
		
		while(pos>0)
		{
			int root=pos;
			int LC=root<<1;
			int RC=LC+1;
			
			tree[root].merge(tree[LC], tree[RC]);
			
			pos>>=1;
		}
	}
	
	void update(int n, int pos, ll val)
	{
		tree[(1<<n)+pos].create(val);
		mergeup((1<<n)+pos);
	}
	
	node query(int root, int LM, int RM, int u, int v)
	{
		if(u<=LM && RM<=v)
		return tree[root];
		
		int mid=(LM+RM)/2;
		int LC=root<<1;
		int RC=LC+1;
		node L, R;
		
		if(u<mid)
		L=query(LC, LM, mid, u, v);
		
		if(v>mid)
		R=query(RC, mid, RM, u, v);
		
		node P;
		P.merge(L, R);
		
		return P;
	}
	
	ll find(int n, int u, int v)
	{
		return query(1, 1<<n, 1<<(n+1), (1<<n)+u, (1<<n)+1+v).bestSum;
	}
};

int main()
{
	int N, Q, u, v, n;
	ll x;
	
	sfi(N);
	
	n=ceil(log(N)/log(2));
	
	SegTree S(n);
	
	rep(i, N)
	{
		sfl(x);
		S.update(n, i, x);
	}
	
	sfi(Q);
	
	while(Q--)
	{
		sfi(u), sfi(v);
		
		u--, v--;
		
		printf("%lld\n", S.find(n, u, v));
	}
	
	return 0;
}