// Author : Bony Roopchandani
// 10930 - A-Sequence
// Backtracking

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

int A[30+5], currNum;
bool vis[30+5][1000+5][100];
bool ans;

void solve(int currInd, int Num, int count)
{
	if(Num==currNum && count>=2)
	{
		ans=true;
		return;
	}
	
	if(currInd<0)
	return;
	
	if(vis[currInd][Num][count])
	return;
	
	vis[currInd][Num][count]=1;
	
	solve(currInd-1, Num+A[currInd], count+1);
	solve(currInd-1, Num, count);
}

bool is_sorted(int N)
{
	int i=0, j=1;
	
	while(j<N)
	{
		if(A[i]>=A[j])
		return false;
		
		i++, j++;
	}
	
	return true;
}

int main(void)
{
//	in("input.txt");
	
	int N, cs=1;
	
	while(cin>>N)
	{
		rep(i, N)
		sfi(A[i]);
		
		bool cond=true;
		
		if(!is_sorted(N))
		cond=false;
		
		else
		{
			memset(vis, 0, sizeof vis);
		
      		rept(i, 1, N-1)
      		{
      			currNum=A[i];
      			ans=false;
      			solve(i-1, 0, 0);
			
      			if(ans)
      			{
	      			cond=false;
      				break;
	      		}
			
	      		memset(vis, 0, sizeof vis);
      		}
		}
		
		printf("Case #%d: %d", cs++, A[0]);
		rept(i, 1, N-1)
		printf(" %d", A[i]); nl;
		
		if(cond)
		puts("This is an A-sequence.");
		else
		puts("This is not an A-sequence.");
	}
	return (0);
}