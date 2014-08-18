// Author : Bony Roopchandani
// BEADS
// Suffix Array

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

char T[10010];

class SuffixArray
{
	int* SA;
	int* tempSA;
	int* RA;
	int* tempRA;
	int N;
	
	public:
	
	SuffixArray()
	{
		N = strlen(T);
		SA = new int[N+5];
		tempSA = new int[N+5];
		RA = new int[N+5];
		tempRA = new int[N+5];
	}
	
	~SuffixArray()
	{
		delete []SA;
		delete []tempSA;
		delete []RA;
		delete []tempRA;
	}
	
	void process()
	{
		buildSA();

		pfi(SA[0]+1);
	}
	
	void buildSA()
	{
		int r;
		
		rep(i, N)
		SA[i]=i, RA[i]=T[i];
		
		for(int k=1; k<N; k<<=1)
		{
			countSort(k);
			countSort(0);
			
			tempRA[SA[0]]=r=0;
			int s1, s2;
			bool eq;
			
			rept(i, 1, N-1)
			{
				s1=SA[i], s2=SA[i-1];
				
				eq=(RA[s1]==RA[s2]);
				eq&=(RA[(s1+k)%N]==RA[(s2+k)%N]);
				
				tempRA[SA[i]]=eq?r:++r;
			}
			rep(i, N)
			RA[i]=tempRA[i];
			
			if(RA[SA[N-1]]==N-1)
			break;
		}
	}
	
	void countSort(int k)
	{
		int maxi=max(N, 300);
		int T, sum=0;
		
		int c[20010]={0};
		
		rep(i, N)
		c[RA[(i+k)%N]]++;
		
		rep(i, maxi)
		T=c[i], c[i]=sum, sum+=T;
		
		rep(i, N)
		tempSA[c[RA[(SA[i]+k)%N]]++]=SA[i];
		
		rep(i, N)
		SA[i]=tempSA[i];
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int t; sfi(t);
	getchar();
	
	while(t--)
	{
   	gets(T);
   	SuffixArray S;
   	S.process();
	}
	
	return (0);
}