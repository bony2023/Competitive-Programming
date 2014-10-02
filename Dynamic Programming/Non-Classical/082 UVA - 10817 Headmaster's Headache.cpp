// Author : Bony Roopchandani
// 10817 - Headmaster's Headache
// DP+Bitmask

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

int S, N, M;
int Cost[100+5];
VI A[100+5];
ll dp[101][1<<9][1<<9];

ll input1(int& bt1, int& bt2)
{
	char str[1000];
	ll ret=0;
	int i=0, temp=0;
	
	gets(str);
	
	while(str[i])
	{
		if(str[i]>='0' && str[i]<='9')
		temp*=10, temp+=(str[i]-'0');
		
		else if(str[i]==' ')
		{
			if(temp>=10000 && temp<=50000)
			ret=temp;
			else
			{
				if(!(bt1 & (1<<temp)))
				bt1 |= (1<<temp);
				else
				bt2 |= (1<<temp);
			}
			
			temp=0;
		}
		
		i++;
	}
	
	if(temp)
	if(!(bt1 & (1<<temp)))
	bt1 |= (1<<temp);
	else
	bt2 |= (1<<temp);
	
	return ret;
}

int input2(int id)
{
	char str[1000];
	ll ret=0;
	int i=0, temp=0;
	
	gets(str);
	
	while(str[i])
	{
		if(str[i]>='0' && str[i]<='9')
		temp*=10, temp+=(str[i]-'0');
		
		else if(str[i]==' ')
		{
			if(temp>=10000 && temp<=50000)
			ret=temp;
			else
			{
				A[id].pb(temp);
			}
			
			temp=0;
		}
		
		i++;
	}
	
	if(temp)
	A[id].pb(temp);
	
	return ret;
}

ll F(int pos, int bM1, int bM2)
{
	if(bM1==((1<<S)-1) && bM2==((1<<S)-1))
	return 0;
	
	if(dp[pos][bM1][bM2] != -1)
	return dp[pos][bM1][bM2];
	
	if(pos>=N)
	return (INF<<2);
	
	int P=bM1;
	int Q=bM2;
	
	rep(i, A[pos].sz)
	{
		int x=A[pos][i];
		
		if(!(bM1 & (1<<x)))
      	P=P | (1<<x);
      	else
      	Q=Q | (1<<x);
	}
	
	return dp[pos][bM1][bM2]=min(F(pos+1, bM1, bM2), Cost[pos]+F(pos+1, P, Q));
}

int main(void)
{
	while(1)
	{
		sfi(S), sfi(M), sfi(N);
		
		if(!S)
		break;
		
		cin.ignore();
		
		ll res=0;
		int bitmask1=1, bitmask2=1;
		S++;
		
		rep(i, M)
		{
			res+=input1(bitmask1, bitmask2);
		}
		
		rep(i, N)
		{
			Cost[i]=input2(i);
		}
		
		rep(i, N+1)
		rep(j, 1<<S)
		rep(k, 1<<S)
		dp[i][j][k]=-1;
		
		res+=F(0, bitmask1, bitmask2);
		
		pfl(res);
		
		rep(i, N+1)
		A[i].clear();
	}
	
	return (0);
}