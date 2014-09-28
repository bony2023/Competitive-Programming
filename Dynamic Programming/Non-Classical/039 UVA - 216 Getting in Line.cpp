// Author : Bony Roopchandani
// 216 - Getting in Line
// TSP

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

struct node
{
	int x, y, z;
	
	node(int a, int b, int c)
	{
		x=a, y=b, z=c;
	}
	
	bool operator < (node & aa)
	const
	{
		return z<aa.z;
	}
};

class TSP
{
	vector<node> A, B;
	double Best;
	static int cs;
	
	public:
	
	void process(int N)
	{
		int x, y;
		
		rep(i, N)
		{
			sfi(x), sfi(y);
			A.pb(node(x, y, i));
		}
		
		getBest(N);
		outputSet(N);
	}
	
	void getBest(int N)
	{
		Best=INF<<1;
		double C;
		
		do
		{
			C=0;
			
			rept(i, 1, N-1)
			{
				C+=(hypot((A[i].x-A[i-1].x), (A[i].y-A[i-1].y))+16);
			}
				
			if(C<Best)
			{
				Best=C;
				B=A;
			}
		}
		while(next_permutation(all(A)));
	}
	
	void outputSet(int N)
	{
		puts("**********************************************************");
		
		printf("Network #%d\n", cs++);

		rept(i, 1, N-1)
		{
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %0.2lf feet.\n", B[i-1].x, B[i-1].y, B[i].x, B[i].y, hypot((B[i].x-B[i-1].x), (B[i].y-B[i-1].y))+16);
		}
			
		printf("Number of feet of cable required is %0.2lf.\n", Best);
	}
};

int TSP::cs=1;

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N;
	
	while(sfi(N)==1 && N)
	{
		TSP P;
		P.process(N);
	}
	
	return (0);
}