// Author : Bony Roopchandani
// 11385 - Da Vinci Code
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
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int >LI;
typedef list < ll > LLL;
typedef set < int >SI;
typedef set < ll > SLL;

ll T[] =
	{ 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584,
   4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,
   514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352,
   24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437,
   701408733, 1134903170, 1836311903, 2971215073, 4807526976 };

VLL Fib(T, T + 48);
VLL::iterator low;

class Decipher
{
	char *in;
	char *out;

  public:

	  Decipher()
	{
		in = new char[200] ();
		  out = new char[200] ();
	}

	 ~Decipher()
	{
		delete[]in;
		delete[]out;
	}

	void process()
	{
		ll num[200]={0}, N, maxx = 0;
		sfl(N);

		rep(i, N)
		{
			sfl(num[i]);
			if (maxx < num[i])
				maxx = num[i];
		}

		rep(i, 48) if (maxx == Fib[i])
		{
			maxx = i;
			break;
		}
		
		rep(i, maxx+5)
		out[i]=' ';

		char c;
		int k = 0, t = 0;
		char temp[200];
		
		getchar();
		gets(in);

		while(in[k])
		{
			if(isupper(in[k]))
			temp[t++]=in[k];
			k++;
		}
		
		k = 0;

		while (k < t)
		{
			rep(i, 48) 
			if (num[k] == Fib[i])
				out[i] = temp[k];
			k++;
		}
		
		out[maxx+1]= '\0';

		pfs(out);
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);

	int T;
	sfi(T);

	while (T--)
	{
		Decipher D;
		D.process();
	}

	return 0;
}