// Author : Bony Roopchandani
// DISUBSTR
// Suffix Array LCP

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
const int MAX = 1000+5;
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

char T[MAX];

class SuffixArray
{
	int SA[MAX], RA[MAX];
	int tempSA[MAX], tempRA[MAX];
	int N;
	
	public:
	
	void process()
	{
		gets(T);
		N=strlen(T);
		T[N++]='$';
		
		buildSA();
		int TotLCP=computeLCP();
		int nC2=getComb(N);
		
		pfi(nC2-TotLCP);
	}
	
	void buildSA()
	{
		int r=0;
		
		rep(i, N)
		SA[i]=i, RA[i]=T[i];
		
		for(int k=1; k<N; k<<=1)
		{
			countSort(k);
			countSort(0);
			
			tempRA[SA[0]]=r=0;
			
			rept(i, 1, N-1)
			tempRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
			
			rep(i, N)
			RA[i]=tempRA[i];
			
			if(RA[SA[N-1]]==N-1)
			break;
		}
	}
	
	void countSort(int k)
	{
		int sum=0, T;
		int c[MAX]={0};
		int maxi=max(300, N);
		
		rep(i, N)
		c[i+k<N?RA[i+k]:0]++;
		
		rep(i, maxi)
		T=c[i], c[i]=sum, sum+=T;
		
		rep(i, N)
			tempSA[c[SA[i]+k<N?RA[SA[i]+k]:0]++]=SA[i];
			
			rep(i, N)
			SA[i]=tempSA[i];
	}
	
	int computeLCP()
	{
		int Phi[MAX];
		int L=0;
		int LCP=0;
		
		Phi[SA[0]]=-1;
		
		rept(i, 1, N-1)
			Phi[SA[i]]=SA[i-1];
			
		rep(i, N)
		{
			if(Phi[i]==-1)
			continue;
			
			while(T[i+L]==T[Phi[i]+L])
			L++;
			
			LCP+=L;
			
			L=max(L-1, 0);
		}
		
		return LCP;
	}
	
	int getComb(int N)
	{
		return (N*(N-1))/2;
	}
};

int main()
{
	int t; sfi(t); getchar();
	
	while(t--)
	{
		SuffixArray S;
		S.process();
	}
	
	return (0);
}