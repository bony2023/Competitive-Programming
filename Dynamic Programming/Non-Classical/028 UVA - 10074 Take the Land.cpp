// Author : Bony Roopchandani
// 10074 - Take the Land
// Matrix Sum - DP

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

class MatSum
{
	int A[100+5][100+5];
	
	public:
	
	void process(int N, int M)
	{
		rep(i, N)
		rep(j, M)
		{
			sfi(A[i][j]);
			
			A[i][j]=!A[i][j];
			
			if(i && A[i][j])
			{
				A[i][j]=A[i-1][j]+1;
			}
		}
		
		int T;
		int MaxSum=0;
		
		rep(i, N)
		rep(j, M)
		{
			T=1;
			
			for(int k=j-1; A[i][k]>=A[i][j] && k>=0; k--)
			T++;
			
			for(int k=j+1; A[i][k]>=A[i][j] && k<M; k++)
			T++;
			
			MaxSum=max(T*A[i][j], MaxSum);
		}
		
		pfi(MaxSum);
	}
};

int main()
{
	int N, M;
	
	while(1)
	{
		sfi(N), sfi(M);
		
		if(!N && !M)
		break;
		
		MatSum F;
		F.process(N, M);
	}
	
	return (0);
}