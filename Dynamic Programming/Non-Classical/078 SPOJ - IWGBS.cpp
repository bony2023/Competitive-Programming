// Author : Bony Roopchandani
// IWGBS
// DP

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
typedef list < int >LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int >MII;
typedef map < int, ll > MIL;
typedef map < ll, int >MLI;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef set < int >SI;
typedef set < ll > SLL;
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

char Fib[10000 + 5][4000];
bool done[10000+5];

class Fibonacci
{
  public:

	Fibonacci()
	{
		strcpy(Fib[0], "1");
		Fib[0][1]='\0';
		strcpy(Fib[1], "2");
		Fib[1][1]='\0';
	}

	void init()
	{
		rept(i, 2, 10000)
		{
			Add(Fib[i - 1], strlen(Fib[i-1]), Fib[i - 2], strlen(Fib[i-2]), 0, Fib[i]);
		}
	}

	int Add(char *const f, const int f_len, char *const s, const int s_len, const int null, char* vysledek)
	{
		int max_len = (s_len < (f_len + null)) ? (f_len + null) : s_len;
		int s_idx = 0, f_idx = 0, last = 0, idx_null = null, nula = -1;
		int n;
		while (f_idx < max_len)
		{
			n = ((s_len > s_idx)?(s[s_idx] - '0') : 0) + ((idx_null >0) ? 0 : ((f_len >f_idx)?(f[f_idx]-'0'): 0)) +last;
			
			if (n > 9)
			{
				last = 1;
				n -= 10;
			}
			else
				last = 0;
			vysledek[s_idx] = n + '0';
			if (!n && s_idx > 0)
			{
				if (nula == -1)
					nula = s_idx;
			}
			else
				nula = -1;
			++s_idx;
			if (idx_null-- <= 0)
				++f_idx;
		}
		if (last)
		{
			vysledek[s_idx++] = '1';
			nula = -1;
		}
		if (nula > 0)
			s_idx = nula;
		vysledek[s_idx] = '\0';
		return 3;
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	Fibonacci F;
	 F.init();
	 int N;
	 fill(done, done+10000+5, 0);
	 
	 while(sfi(N)==1)
	 {
	 	if(!done[N])
	 	reverse(Fib[N], Fib[N]+strlen(Fib[N])), done[N]=1;
	 	
	 	printf("%s\n", Fib[N]);
	 }
	return (0);
}