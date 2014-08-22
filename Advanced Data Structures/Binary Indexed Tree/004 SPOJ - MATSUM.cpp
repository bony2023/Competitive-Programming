// Author : Bony Roopchandani
// MATSUM
// 2-D Binary Indexed Tree

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

class BIT2D
{
	int N;
	int** tree;
	
	public:
	
	BIT2D(int n)
	{
		N=n;
		tree = new int*[N+2];
		
		rep(i, N+2)
		tree[i] = new int[N+2]();
	}
	
	~BIT2D()
	{
		rep(i, N+2)
		delete []tree[i];
		
		delete []tree;
	}
	
	void update(int x, int y, int val)
	{
		while(x<=N)
		{
			updatey(x, y, val);
			x+=(x&(-x));
		}
	}
	
	void updatey(int x, int y, int val)
	{
		while(y<=N)
		{
			tree[x][y]+=val;
			y+=(y&-(y));
		}
	}
	
	int get(int x, int y)
	{
		int S=0;
		
		while(x>0)
		{
			gety(x, y, S);
			x-=(x&(-x));
		}
		return S;
	}
	
	void gety(int x, int y, int& S)
	{
		while(y>0)
		{
			S+=tree[x][y];
			y-=(y&(-y));
		}
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	int N;
	int x1, y1, x2, y2, val;
	char P[10];
	
	while(T--)
	{
		sfi(N);
		BIT2D B(N);
		
		while(1)
		{
			sfs(P);
			
			if(!strcmp(P, "SET"))
			{
				sfi(x1), sfi(y1), sfi(val);
				int S;
				S=B.get(x1+1, y1+1);
				S-=B.get(x1+1, y1);
				S-=B.get(x1, y1+1);
				S+=B.get(x1, y1);
				
				B.update(x1+1, y1+1, val-S);
			}
			else
			if(!strcmp(P, "SUM"))
			{
				sfi(x1), sfi(y1), sfi(x2), sfi(y2);
				
				int ans;
				ans=B.get(x2+1, y2+1);
				ans-=B.get(x2+1, y1);
				ans-=B.get(x1, y2+1);
				ans+=B.get(x1, y1);
				
				pfi(ans);
			}
			else if(P[0]=='E')
			break;
		}
		
		nl;
	}
	return (0);
}