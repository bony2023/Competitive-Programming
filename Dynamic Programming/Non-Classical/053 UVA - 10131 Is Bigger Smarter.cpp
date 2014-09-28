// Author : Bony Roopchandani
// 10131 - Is Bigger Smarter?
// Sorting + LIS

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

vector<PIII> A;
int P[10000+5]={0};

bool cmp(PIII a, PIII b)
{
	return a.ss.ss>b.ss.ss;
}

void PR(int i)
{
	if(P[i]==-1)
	{
		pfi(A[i].ff);
		return;
	}
	
	PR(P[i]);
	pfi(A[i].ff);
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	
	int x, y, i=1;
	
	while(scanf("%d %d", &x, &y)==2)
	{
		A.pb(mp(i++, mp(x, y)));
	}
	
	sort(all(A), cmp);
	
	int LIS[i+5], a, indi, mxpos=0, mx=0;
	memset(LIS, 0, sizeof LIS);
	
	LIS[0]=1;
	P[0]=-1;
	
	rept(i, 1, A.sz-1)
	{
		LIS[i]=1;
		indi=-1;
		
		rep(j, i)
		{
			if(A[i].ss.ff>A[j].ss.ff && A[i].ss.ss < A[j].ss.ss && LIS[i]<LIS[j]+1)
			{
				LIS[i]=LIS[j]+1;
				indi=j;
			}
		}
		
		if(mx<LIS[i])
		mx=LIS[i], mxpos=i;
		P[i]=indi;
	}
	
	pfi(mx);
	PR(mxpos);
	
	return (0);
}