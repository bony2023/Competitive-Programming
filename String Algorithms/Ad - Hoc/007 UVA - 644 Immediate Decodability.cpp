// Author : Bony Roopchandani
// 644 - Immediate Decodability
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

class ID
{
	string* A;
	
	public:
	
	ID()
	{
		A = new string[20];
	}
	
	~ID()
	{
		delete []A;
	}
	
	void process(string T)
	{
		int k=0;
		A[0]=T;
		
		while(A[k]!="9")
		cin>>A[++k];
		
		int low;
		bool cond=true;
		
		rep(i, k)
		rep(j, k)
		{
			if(i==j)
			continue;
			
			low=(A[i].sz<A[j].sz)?A[i].sz:A[j].sz;
			string a(A[i].bg, A[i].bg+low);
			string b(A[j].bg, A[j].bg+low);
			
			if(a==b)
			{
				cond=false;
				goto end;
			}
		}
		
		end:
		
		if(cond)
		puts("is immediately decodable");
		else
		puts("is not immediately decodable");
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int cs=1;
	string foo;
	
	while(cin>>foo)
	{
		printf("Set %d ", cs++);
		ID I;
		I.process(foo);
	}
	
	return 0;
}