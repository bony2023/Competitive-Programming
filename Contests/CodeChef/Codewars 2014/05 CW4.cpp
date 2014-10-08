// Author : Bony Roopchandani
// CW4
// Rank if Lexicographic Permutation

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
#define in(a) freopen(a, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(a) freopen(a, "w", stdout)
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

int fact(int n)
{
	if(n<=1)
	return 1;
	else
	return n*fact(n-1);
}

int find(char *str, int lo, int hi)
{
	int countLeft = 0, i;
	
	rept(i, lo+1, hi)
	if (str[i] > str[lo])
	++countLeft;
			
	return countLeft;
}

int Rank(char *str)
{
	int len = strlen(str);
	int mul = fact(len);
	int rank = 1;
	int countLeft;
	
	rep(i, len)
	{
		mul /= len - i;
		countLeft=find(str, i, len - 1);
		rank += countLeft * mul;
	}
	
	return rank;
}


int main(void)
{
	int T; sfi(T);
	char str[50];
	
	while(T--)
	{
		sfs(str);
		int P=Rank(str);
		P-=1;
		string S;
		int k=0;
		
		while(P>=0)
		{
			S.pb((P%26)+'A');
			P=floor((double)P/26)-1;
		}
		
		reverse(S.bg, S.en);
		cout<<S<<endl;
	}
	
	return (0);
}