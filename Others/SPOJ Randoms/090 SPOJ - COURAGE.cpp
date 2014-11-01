// Author : Bony Roopchandani
// COURAGE
// SegTree

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
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
#define in(a) freopen(a, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(a) freopen(a, "w", stdout)
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

struct node
{
	ll sum, mn;
	
	node()
	{
		sum=0;
		mn=1e10;
	}
	
	void merge(node& a, node& b)
	{
		sum=a.sum+b.sum;
		mn=min(a.mn, b.mn);
	}
	
	void addmn(ll val)
	{
		mn=val;
	}

	void add(ll val)
	{
		sum+=val;
		mn+=val;
	}
};

node Tree[4*100010], tmp;
ll a[100010];
bool lazy[4*100010];

void initTree(int root, int start, int end)
{
	if(start>end)
	return;
	
	lazy[root]=0;
	
	if(start==end)
	{
		Tree[root].add(a[start]);
		Tree[root].addmn(a[start]);
		return;
	}
	
	initTree(root<<1, start, (start+end)>>1);
	initTree((root<<1)+1, ((start+end)>>1)+1, end);
	
	Tree[root].merge(Tree[root<<1], Tree[(root<<1)+1]);
}

void update(int root, int start, int end, int pos, ll val)
{
	if(start>end || start>pos || end<pos)
	{
		return;
	}
	
	if(pos==start && end==pos)
	{
		Tree[root].add(val);
		return;
	}
	
	update(root<<1, start, (start+end)>>1, pos, val);
	update((root<<1)+1, ((start+end)>>1)+1, end, pos, val);
	
		Tree[root].merge(Tree[root<<1], Tree[(root<<1)+1]);
}

node query(int root, int start, int end, int u, int v)
{
	if(start>end || start>v || end<u)
	{
		return tmp;
	}
	
	if(u<=start && end<=v)
	{
		return Tree[root];
	}
	
	node L, R;
	
	L=query(root<<1, start, (start+end)>>1, u, v);
	
	R=query((root<<1)+1, ((start+end)>>1)+1, end, u, v);
	
	Tree[root].merge(Tree[root<<1], Tree[(root<<1)+1]);
	
	node P; P.merge(L, R);
	
	return P;
}

int main(void)
{
//	in("input.txt");
	
	int N; sfi(N);
	
	rep(i, N)
	sfl(a[i]);
	
	initTree(1, 0, N-1);
	
	int Q; sfi(Q);
	char c[10];
	int u, v;
	ll x;
	node mY;
	
	while(Q--)
	{
		sfs(c);
		
		if(!strcmp(c, "COUNT"))
		{
			sfi(u), sfi(v);
			mY=query(1, 0, N-1, u, v);
			pfl(mY.sum-mY.mn);
		}
		
		else if(!strcmp(c, "GROW"))
		{
			sfl(x), sfi(u);
			update(1, 0, N-1, u, x);
		}
		
		else
		{
			sfl(x), sfi(u);
			update(1, 0, N-1, u, -x);
		}
	}
	
	return (0);
}