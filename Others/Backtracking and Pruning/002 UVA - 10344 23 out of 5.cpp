// Author : Bony Roopchandani
// 10344 - 23 out of 5
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

int A[10];

bool find(int currNum, int id)
{
	if(id==5)
	{
		if(currNum==23)
		return true;
		else
		return false;
	}
	
	bool ret=false;
	
	ret |= find(currNum+A[id], id+1);
	ret |= find(currNum-A[id], id+1);
	ret |= find(currNum*A[id], id+1);
	
	return ret;
}

int main(void)
{
	int sum;
	
	while(1)
	{
		sum=0;
		
		rep(i, 5)
		sfi(A[i]), sum+=A[i];
		
		if(!sum)
		break;
		
		bool cond=false;
		sort(A, A+5);
		
		do
		{
			cond=find(A[0], 1);
			if(cond)
			break;
			
		}while(next_permutation(A, A+5));
		
		if(cond)
		puts("Possible");
		else
		puts("Impossible");
	}
	return (0);
}