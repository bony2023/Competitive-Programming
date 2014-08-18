// Author : Bony Roopchandani
// EPALIN
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
const int MAX = 200000+10;
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

char str[200000+10];

class KMP
{
	int* b;
	
	public:
	
	KMP(int N)
	{
		b = new int[2*N+10];
	}
	
	~KMP()
	{
		delete []b;
	}
	
	void process()
	{
		char Reverse[MAX];
		int len=strlen(str);
		
		repd(i, len-1, 0)
		Reverse[len-i-1]=str[i];
		Reverse[len]='\0';
		
		strcat(Reverse, str);
		
		int i=1, j=-1;
		b[0]=-1;
		
		while(i<=len<<1)
		{
			while(j>=0 && Reverse[i-1] != Reverse[j])
			j = b[j];
			
			b[i++]=++j;
		}
		
		int k=0;
		
		repd(i, len-1-b[len<<1], 0)
		str[len+k]=str[i], k++;
		
		str[len+k]='\0';
		
		puts(str);
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	while(gets(str))
	{
		KMP K(strlen(str));
		K.process();
	}
	
	return (0);
}