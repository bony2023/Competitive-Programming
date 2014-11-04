// Author : Bony Roopchandani
// HASHIT
// Hashing

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

string table[101];
bool done[101];

int HValue(const char* str)
{
	int ret=0;
	
	rept(i, 1, strlen(str))
	{
		ret+=(i*str[i-1]);
	}
	
	return ((ret*19)%101);
}

int find(int key)
{
	rept(i, 0, 19)
	{
		if(!done[(key+(23+i)*i)%101])
		return (key+(23+i)*i)%101;
	}
	
	return -1;
}

int main(void)
{
	int T, N; sfi(T);
	
	while(T--)
	{
		sfi(N);
		map<string, int> key;
		string S, op, str;
		int tot=0;
		memset(done, 0, sizeof done);
		
		rep(i, N)
		{
			cin>>S;
			op=S.substr(0, 3);
			str=S.substr(4, S.sz-4);
			
			if(op=="ADD")
			{
				if(!key.count(str))
				{
					int k=find(HValue(str.c_str()));
				
			      	if(k != -1)
	      			{
		      			tot++;
			      		done[k]=true;
			      		table[k]=str;
			      		key[str]=k;
		      		}
				}
			}
			else
			{
				if(key.count(str))
				{
					done[key[str]]=0;
					key.erase(str);
					tot--;
				}
			}
		}
		
		pfi(tot);
		
		rep(i, 101)
		{
			if(done[i])
			{
				printf("%d:", i);
				cout<<table[i]<<endl;
			}
		}
	}
	return (0);
}