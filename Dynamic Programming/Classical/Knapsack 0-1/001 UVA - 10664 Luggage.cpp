// Author : Bony Roopchandani
// 10664 - Luggage
// Knapsack 0-1

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

class Knapsack
{
	int A[20+5];
	int dp[20+5][300];
	int N;
	
	public:
	
	void process()
	{
		rep(i, 20+5)
		fill(dp[i], dp[i]+300, -1);
		
		input();
		int Sum=0;
		
		rep(i, N)
		Sum+=A[i];
		
		if(Sum&1)
		puts("NO");
		else
		{
			int P=count(0, Sum>>1);
			if(P==(Sum>>1))
			puts("YES");
			else
			puts("NO");
		}
	}
	
	void input()
	{
		int x, togg=0;
		N=0;
		string S;
		getline(cin, S);
		
		rep(i, S.sz)
		{
			if(S[i]>='0' && S[i]<='9' && togg)
			{
				x*=10;
				x+=S[i]-'0';
			}
			else
			if(S[i]==' ' && togg)
			{
				togg=0;
				A[N++]=x;
				x=1;
			}
			else if(S[i]<='9' && S[i]>='0' && !togg)
			{
				x=S[i]-'0';
				togg=1;
			}
		}
		
		A[N++]=x;
	}
	
	int count(int id, int RemW)
	{
		if(id==N || RemW<=0)
		return 0;
		
		if(dp[id][RemW] != -1)
		return dp[id][RemW];
		
		if(A[id]>RemW)
		return dp[id][RemW]=count(id+1, RemW);
		
		if(A[id]<=RemW)
		return dp[id][RemW]=max(count(id+1, RemW), A[id]+count(id+1, RemW-A[id]));
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	getchar();
	
	while(T--)
	{
		Knapsack K;
		K.process();
	}
	
	return (0);
}