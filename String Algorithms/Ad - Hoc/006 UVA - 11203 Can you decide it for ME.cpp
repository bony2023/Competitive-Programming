// Author : Bony Roopchandani
// 11203 - Can you decide it for ME?
// String - Ad - Hoc

// INCLUDES
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// MACROS
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i=0; i<n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD (1e9 + 7)

// TYPEDEFS
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef map < int, int > MII;
typedef map < ll, int > MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int > LI;
typedef list < ll > LLL;
typedef set < int > SI;
typedef set < ll > SLL;

class ME
{
	char* STR;
	int a, b, c;
	
	public:
	
	ME()
	{
		STR = new char[50+10];
	}
	
	~ME()
	{
		delete []STR;
	}
	
	void process()
	{
		gets(STR);
		
		if(cond1() && cond2() && cond3())
		puts("theorem");
		else
		puts("no-theorem");
	}
	
	bool cond1()
	{
		int k=0, M=0, E=0;
		
		while(STR[k])
		{
			if(STR[k]=='M')
			M++;
			else if(STR[k]=='E')
			E++;
			else if(STR[k]=='?')
			{
				//do Nothing
			}
			else
			return false;
			
			k++;
		}
		
		if(M==1 && E==1)
		return true;
		else
		return false;
	}
	
	bool cond2()
	{
		a=b=c=0;
		int k=0;
		
		while(STR[k])
		{
			if(STR[k]=='M')
			break;
			
			a++; k++;
		} 
		
		k++; 
		
		while(STR[k])
		{
			if(STR[k]=='E')
			break;
			
			b++; k++;
		}
		
		k++;
		
		while(STR[k])
		c++, k++;
		
		if(a && b && c)
		return true;
		else
		return false;
	}
	
	bool cond3()
	{
		while(b>1)
		b--, c--;
		
		if(c==(a+1))
		return true;
		else return false;
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);

	int T; sfi(T);
	
	getchar();
	
	while(T--)
	{
		ME M;
		M.process();
	}
	
	return 0;
}