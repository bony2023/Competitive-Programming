// Author : Bony Roopchandani
// CHEFWORD
// Probability

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

long double P[30][30];
int K;

void multiply(long double ret[30][30], long double tmp[30][30])
{
	long double res[30][30]={0};
	
	rep(i, 26)
	rep(j, 26)
	rep(k, 26)
	res[i][j]+=(ret[i][k]*tmp[k][j]);
	
	rep(i, 26) rep(j, 26) ret[i][j]=res[i][j];
}

void MatrixExp()
{
	long double res[30][30]={0};
	rep(i, 26)
	res[i][i]=1;
	
	while(K>0)
	{
		if(K&1)
		{
			multiply(res, P);
		}
		
		multiply(P, P);
		K>>=1;
	}
	
	rep(i, 26) rep(j, 26) P[i][j]=res[i][j];
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		int N; sfi(N), sfi(K);
		char S[10], tmp[10];
		sfs(S);
		map<string, bool> done;
		
		rep(i, 26)
		rep(j, 26)
		scanf("%Lf", &P[i][j]);
		
		MatrixExp();
		long double res, tot=0;
		
		rep(j, N)
		{
			sfs(tmp);
			
			string z(tmp);
			if(done[z]) continue;
			done[z]=1;
			
			if(strlen(S) != strlen(tmp))
			res=0;
			else
			{
				res=1;
				rep(i, strlen(tmp))
				{
					if(S[i]>='a' && S[i]<='z' && tmp[i]>='a' && tmp[i]<='z')
					res*=P[S[i]-'a'][tmp[i]-'a'];
					else
					{
						res=0; break;
					}
				}
			}
			
			tot+=res;
		}
		
		printf("%.15Lf\n", tot);
		done.clear();
	}
	return (0);
}