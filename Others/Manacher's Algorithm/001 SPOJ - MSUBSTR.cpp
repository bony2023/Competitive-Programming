// Author : Bony Roopchandani
// MSUBSTR
// Manacher's Algorithm

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

char S[4000+5], T[8000+10];
int P[8000+10], res, cnt;

void solve()
{
	int len=strlen(S), k=1;
	T[0]='@';
	
	rep(i, len)
	{
		T[k++]='#';
		T[k++]=S[i];
	}
	
	T[k++]='#';
	T[k]='\0';
	P[0]=0;
	
	int mx=0, id=0;
	
	rept(i, 1, k-1)
	{
		P[i]=(mx>i)?min(mx-i, P[(id<<1)-i]):1;
		
		while(i-P[i]>=0 && i+P[i]<k && T[i-P[i]]==T[i+P[i]])
		P[i]++;
		
		if(mx<(P[i]+i))
		mx=P[i]+i, id=i;
		
		if(res<(P[i]-1))
		res=P[i]-1, cnt=1;
		
		else if(res==(P[i]-1))
		cnt++;
	}
}

int main(void)
{
	int t; sfi(t);
	
	while(t--)
	{
		sfs(S);
		
		res=cnt=0;
		
		solve();
		
		pf(res), pfi(cnt);
	}
	
	return (0);
}