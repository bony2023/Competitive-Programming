// Author : Bony Roopchandani
// POWERMUL
// SegTree + Modular Exponentiation

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

struct P
{
	ll a;
	ll b;
};

P Tree[4*100010];
VI primes;
int MOD, indi[100010+500];
ll P[100011], Q[100011];

ll expMod(ll a, ll b)
{
	ll ret=1;
	
	while(b>0)
	{
		if(b&1)
		ret*=a, ret%=MOD;
		
		a*=a;
		a%=MOD;
		b>>=1;
	}
	
	return ret;
}

void insert(int root, int start, int end, int pos, ll val)
{
	if(start==end)
	{
		Tree[root].a+=val;
		Tree[root].b=expMod(primes[start], Tree[root].a);
		return;
	}
	
	int mid=(start+end)>>1;
	
	if(pos<=mid)
	insert(root<<1, start, mid, pos, val);
	else
	insert((root<<1)+1, mid+1, end, pos, val);
	
	Tree[root].b=((Tree[root<<1].b)*(Tree[(root<<1)+1].b))%MOD;
}

void generate()
{
	P[1]=1;
	primes.pb(1);
	Q[1]=1;
	
	rept(i, 2, 100000)
	{
		Q[i]=Q[i-1];
		
		if(!P[i])
		{
			Q[i]+=1;
			primes.pb(i);
			for(int j=i; j<=100000; j+=i)
			{
				P[j]=i;
			}
		}
	}
}

int main(void)
{
	ll res[100010+50];
	generate();
	
	rep(i, primes.sz)
	{
		indi[primes[i]]=i;
	}
	indi[primes[0]]=1;

	int T; sfi(T);
	
	while(T--)
	{
		int N, q; sfi(N), sfi(MOD), sfi(q);
		
		rept(i, 0, 4*Q[N])
		{
			Tree[i].a=0; Tree[i].b=1;
		}
		
		repd(i, N, (N+1)>>1)
		{
			int height=i;
			int x=N+1-i;
			
			if(x>i)
			{
				break;
			}
			
			while(P[height]>1)
			{
				insert(1, 1, Q[N], indi[P[height]], i), height/=P[height];
			}
			
			height=x;
			
			while(P[height]>1)
			{
				insert(1, 1, Q[N], indi[P[height]], -x), height/=P[height];
			}
			
			res[x]=res[N-x]=Tree[1].b;
		}
		
		int x;
		
		while(q--)
		{
			sfi(x);
			
			if(x>=N)
			puts("1");
			else
			pfl(res[x]);
		}
	}
}