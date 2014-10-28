// Author : Bony Roopchandani
// DICT
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

struct Trie
{
	Trie* next[26];
	bool end;
	
	Trie()
	{
		rep(i, 26)
		{
			next[i]=NULL;
		}
		end=false;
	}
};

void insert(char* str, Trie* tail)
{
	int i=0, p;
	
	while(str[i])
	{
		p=str[i]-'a';
		
		if(tail->next[p]==NULL)
		tail->next[p]=new Trie();
		
		tail=tail->next[p];
		i++;
	}
	
	tail->end=true;
}

void print(char* str, int c, Trie* tail, int k)
{
	str[k]=c+'a';
	
	if(tail->end)
	str[k+1]='\0', puts(str);
	
	rep(i, 26)
	{
		if(tail->next[i])
		{
			print(str, i, tail->next[i], k+1);
		}
	}
}

bool search(char* str, Trie* tail)
{
	int i=0, p;
	
	while(str[i])
	{
		p=str[i]-'a';
		
		if(tail->next[p]==NULL)
		return 0;
		
		tail=tail->next[p];
		i++;
	}
	
	bool cond=false;
	int len=strlen(str);
	
	rep(i, 26)
	{
		if(tail->next[i])
		{
			print(str, i, tail->next[i], len);
			cond=true;
		}
	}
	
	return cond;
}

int main(void)
{
	int N, K;
	sfi(N);
	char S[30];
	
	Trie *head, *tail;
	head=new Trie();
	
	rep(i, N)
	sfs(S), insert(S, tail=head);
	
	sfi(K);
	int cs=1;
	
	rep(i, K)
	{
		printf("Case #%d:\n", cs++);
		sfs(S);
		if(!search(S, tail=head))
		puts("No match.");
	}
	return (0);
}