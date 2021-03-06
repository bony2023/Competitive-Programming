// Author : Bony Roopchandani
// FILRTEST
// KMP Reset Table Variant

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

char A[1000000+10];
int b[1000000+10];

class KMP
{
	int Total, len;
	
	public:
	
	KMP(int toBe, int N)
	{
		Total = toBe;
		len = N;
	}
	
	void process()
	{
		int i=1, j=-1;
		b[0]=-1;
		
		while(i<=len)
		{
			while(j>=0 && A[i-1] != A[j])
			j = b[j];
			
			b[i++]=++j;
		}
		
		if(Total<len)
		pfi(0);
		else
		{
    		Total-=len;
    		len = len - b[len];
    		
    		pfi((Total/len)+1);
		}
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int a;
	
	while(1)
	{
		sfi(a); sfs(A);
		
		if(a==-1 && A[0]=='*')
		break;
		
		KMP K(a, strlen(A));
		K.process();
	}
	
	return (0);
}