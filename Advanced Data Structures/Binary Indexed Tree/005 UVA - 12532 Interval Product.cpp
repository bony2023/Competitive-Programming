// Author : Bony Roopchandani
// 12532 - Interval Product
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
	VI treeZero;
	VI treeNeg;
	int N;
	
	public:
	
	BIT(int n)
	{
		N=n;
		treeZero.assign(N+5, 0);
		treeNeg.assign(N+5, 0);
	}
	
	void process()
	{
		int Q; sfi(Q);
		int A[N+5];
		
		rep(i, N)
		{
			sfi(A[i]);
			
			if(!A[i])
			updateZero(i+1);
			else if(A[i]<0)
			updateNeg(i+1);
		}
		
		char c;
		int u, v;
		
		while(Q--)
		{
			cin>>c;
			sfi(u), sfi(v);
			
			if(c=='C')
			{
				if(!v)
				{
					if(A[u-1]<0)
					updateNeg(u, -1);
					
					if(A[u-1] != 0)
					updateZero(u);
				}
				else if(v<0)
				{
					if(!A[u-1])
					updateZero(u, -1);
					
					if(A[u-1]>=0)
					updateNeg(u);
				}
				else
				{
					if(A[u-1]<0)
					updateNeg(u, -1);
					else
					if(A[u-1]==0)
					updateZero(u, -1);
				}
				
				A[u-1]=v;
			}
			else
			{
				if((getZero(v)-getZero(u-1)))
				putchar('0');
				else
				if((getNeg(v)-getNeg(u-1))%2==1)
				putchar('-');
				else
				putchar('+');
			}
		}
	}
	
	void updateZero(int pos, int val=1)
	{
		while(pos<=N)
		{
			treeZero[pos]+=val;
			pos+=(pos&(-pos));
		}
	}
	
	void updateNeg(int pos, int val=1)
	{
		while(pos<=N)
		{
			treeNeg[pos]+=val;
			pos+=(pos&(-pos));
		}
	}
	
	int getZero(int pos)
	{
		int S=0;
		
		while(pos>0)
		{
			S+=treeZero[pos];
			pos-=(pos&(-pos));
		}
		
		return S;
	}
	
	int getNeg(int pos)
	{
		int S=0;
		
		while(pos>0)
		{
			S+=treeNeg[pos];
			pos-=(pos&(-pos));
		}
		
		return S;
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N;
	
	while(sfi(N) != EOF)
	{
		BIT B(N);
		B.process();
		nl;
	}
	
	return (0);
}