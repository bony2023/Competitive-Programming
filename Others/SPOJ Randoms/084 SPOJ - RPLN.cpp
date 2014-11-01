// Author : Bony Roopchandani
// RPLN
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

void scanint(int &x)
{
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for (; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
	{
		x = (x << 1) + (x << 3) + c - 48;
	}
	if (neg)
		x = -x;
}

struct node
{
	int mn;
	
	node()
	{
		mn=1e9+1;
	}
	
	void merge(node& a, node& b)
	{
		mn=min(a.mn, b.mn);
	}
};

node Tree[4*100010], tmp, P;

void update(int root, int start, int end, int pos, int val)
{
	if(start>end)
	return;
	
	if(pos==start && pos==end)
	{
		Tree[root].mn=val;
		return;
	}
	
	int mid=(start+end)>>1;
	
	if(pos<=mid)
	update(root<<1, start, mid, pos, val);
	
	if(pos>mid)
	update((root<<1)+1, mid+1, end, pos, val);
	
	Tree[root].merge(Tree[root<<1], Tree[(root<<1)+1]);
	
	return;
}

node query(int root, int start, int end, int u, int v)
{
	if(start>end || start>v || end<u)
	{
		return tmp;
	}
	
	if(u<=start && v>=end)
	{
		return Tree[root];
	}
	
	int mid=(start+end)>>1;
	node L, R;
	
	L=query(root<<1, start, mid, u, v);
	R=query((root<<1)+1, mid+1, end, u, v);
	
	P.merge(L, R);
	
	return P;
}

int main(void)
{
//	in("input.txt");
	
	int T; scanint(T);
	int N, Q, cs=1;
	int x;
	
	while(T--)
	{
      	scanint(N), scanint(Q);

      	rep(i, N)
      	scanint(x), update(1, 0, N-1, i, x);
 	
      	int u, v;
      	
      	printf("Scenario #%d:\n\n", cs++);
      	
      	while(Q--)
      	{
	      	scanint(u), scanint(v);
		
	      	pfi(query(1, 0, N-1, u-1, v-1).mn);
      	}
	}
	
	return (0);
}