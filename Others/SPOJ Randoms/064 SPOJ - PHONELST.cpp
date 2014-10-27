// Author : Bony Roopchandani
// PHONELST
// Trie

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
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

class Trie
{
	Trie* Num[10];
	bool end;
	
	public:
	
	Trie()
	{
		rep(i, 10)
		Num[i]=NULL;
		end=false;
	}
	
	bool insert(char* str, Trie* tail)
	{
		bool flag=1;
		int i=0;
		
		while(str[i])
		{
			if(tail->end)
			{
				flag=0;
				break;
			}
			
			int q=str[i]-'0';

			if(tail->Num[q]==NULL)
			tail->Num[q]=new Trie;
			
			tail=tail->Num[q];
			
			i++;
		}
		
		tail->end=true;
		
		rep(i, 10)
		if(tail->Num[i])
		{
			flag=0;
			break;
		}
		
		return flag;
	}
};

int main(void)
{
	int T; sfi(T);
	char C[50];
	
	while(T--)
	{
		bool flag=true;
		int N; sfi(N);
		Trie *head, *tail;
		head = new Trie;
		
		rep(i, N)
		{
			sfs(C);
			if(flag)
			{
				flag=head->insert(C, tail=head);
			}
		}
		
		if(flag)
		puts("YES");
		else
		puts("NO");
	}
	return (0);
}