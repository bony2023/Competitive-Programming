// Author : Bony Roopchandani
// 111 - History Grading
// LIS - O(n^2)

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

class Longest_Increasing
{
	int*  LIS;
	int* Hash;
	int* Arr;
	int N;
	
	public:
	
	Longest_Increasing(int n)
	{
		N=n;
		LIS = new int[N+5];
		Hash = new int[N+5];
		Arr = new int[N+5];
	}
	
	~Longest_Increasing()
	{
		delete []LIS;
		delete []Hash;
		delete []Arr;
	}
	
	void process()
	{
		int P;
		rept(i, 1, N)
		sfi(Hash[i]);
		
		while(sfi(P) != EOF)
		{
			Arr[P]=Hash[1];
			
			rept(i, 2, N)
			sfi(P), Arr[P]=Hash[i];
			
			fill(LIS, LIS+N+5, 0);
			LIS[1]=1;
			
			pfi(LIs());
		}
	}
	
	int LIs()
	{
		int a;
		rept(i, 2, N)
		{
			a=0;
			
			rept(j, 1, i-1)
			{
				if(Arr[j]<Arr[i])
				a=max(a, LIS[j]);
			}
			
			LIS[i]=1+a;
		}
		
		sort(LIS, LIS+N+1);
		
		return LIS[N];
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N; sfi(N);
	Longest_Increasing L(N);
	L.process();
	return (0);
}