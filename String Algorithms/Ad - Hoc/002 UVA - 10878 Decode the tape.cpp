// Author : Bony Roopchandani
// 10878 - Decode the tape
// String - Ad - Hoc

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

int TWO[]={1, 2, 4, 8, 16, 32, 64, 128, 256};

class Decipher
{
	char* str;
	
	public:
	
	Decipher()
	{
		str = new char[20];
	}
	
	~Decipher()
	{
		delete []str;
	}
	
	void process()
	{
		gets(str);
		
		int k, t;
		int ASCII;

		while(str[0]=='|')
		{
			k=2;
			t=6;
			ASCII=0;
			
			while(str[k])
			{
				if(str[k]=='o')
				ASCII+=TWO[t];
				else
				if(str[k]=='.')
				t++;
				k++;
				t--;
			}
			
			putchar(ASCII);
			gets(str);
		}
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	char temp[20];
	gets(temp);
	Decipher D;
	D.process();
}