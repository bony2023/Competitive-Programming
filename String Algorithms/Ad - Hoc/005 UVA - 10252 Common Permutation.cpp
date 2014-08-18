// Author : Bony Roopchandani
// 10252 - Common Permutation
// String - Ad- Hoc

// INCLUDES
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// MACROS
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i=0; i<n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD (1e9 + 7)

// TYPEDEFS
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef map < int, int > MII;
typedef map < ll, int > MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int > LI;
typedef list < ll > LLL;
typedef set < int > SI;
typedef set < ll > SLL;

class Permute
{
	int* freq_a;
	int* freq_b;
	
	public:
	
	Permute()
	{
		freq_a=new int[30]();
		freq_b=new int[30]();
	}
	
	~Permute()
	{
		delete []freq_a;
		delete []freq_b;
	}
	
	void process(char a[])
	{
		char b[1000+5];
		
		gets(b);
		
		int k=0;
		
		while(a[k])
		{
			if(a[k] != ' ')
    		freq_a[a[k]-'a']++;
    		k++;
		}
		
		k=0;
		
		while(b[k])
		{
			if(b[k] != ' ')
    		freq_b[b[k]-'a']++;
    		k++;
		}
		
		vector<char>res;
		int c=0;
		k=0;
		
		rep(i, 26)
		{
			if(freq_a[i]>=1 && freq_b[i]>=1)
			{
				k=min(freq_a[i], freq_b[i]);
    			c=i;
    			rep(j, k)
    			res.pb(c+'a');
			}
		}
		
		sort(all(res));
		
		rep(i, res.sz)
		printf("%c",res[i]);
		nl;
	}
};

int main()
{
	char a[1000+5];
	
	while(gets(a))
	{
		Permute P;
    	P.process(a);
	}
	
	return 0;
}