// Author : Bony Roopchandani
// 760 - DNA Sequencing
// Suffix Array LCS

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

char T[650+10], temp[300+10];

class myComp
{
	public:
	const
	bool operator()(string a, string b)
	{
		return a<b;
	}
};

class SuffixArray
{
	int *SA, *RA, *tempRA, *tempSA;
	int N;
	int* LCP;
	set<string, myComp> SUBS;
	
	public:
	
	SuffixArray()
	{
		N = strlen(T);
		SA = new int[N+10];
		RA = new int[N+10];
		tempSA = new int[N+10];
		tempRA = new int[N+10];
		LCP = new int[N+10];
	}
	
	~SuffixArray()
	{
		delete []RA;
		delete []SA;
		delete []tempSA;
		delete []tempRA;
		delete []LCP;
	}
	
	void process()
	{
		buildSA();
		computeLCP();
		computeLCS();
		
		if(!SUBS.sz)
		puts("No common sequence.");
		
		else
		{
   		set<string>::iterator t=SUBS.bg;
   		
   		for(; t!=SUBS.en; t++)
   		cout<<(*t), nl;
		}
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
		int maxi=max(300, N);
		int c[650+10]={0};
		
		rep(i, N)
		c[i+k<N?RA[i+k]:0]++;
		
		rep(i, maxi)
		T=c[i], c[i]=sum, sum+=T;
		
		rep(i, N)
		tempSA[c[SA[i]+k<N?RA[SA[i]+k]:0]++]=SA[i];
		
		rep(i, N)
		SA[i]=tempSA[i];
	}
	
	void computeLCP()
	{
		int Phi[N+10], PLCP[N+10];
		int L=0;
		
		Phi[SA[0]]=-1;
		
		rept(i, 1, N-1)
		Phi[SA[i]]=SA[i-1];
		
		rep(i, N)
		{
			if(Phi[i]==-1) continue;
			
			while(T[i+L]==T[Phi[i]+L])
			L++;
			
			PLCP[i]=L;
			
			L=max(L-1, 0);
		}
		
		rep(i, N)
		LCP[i]=PLCP[SA[i]];
	}
	
	void computeLCS()
	{
		int mid, maxLen=-1;
		
		rep(i, N)
		if(T[i]=='.')
		{
			mid=i;
			break;
		}
		
		rept(i, 1, N-1)
		{
			if((SA[i-1]<mid && SA[i]>mid) || (SA[i-1]>mid && SA[i]<mid))
			{
				if(maxLen<LCP[i] && LCP[i])
				{
					maxLen=LCP[i];
					SUBS.clear();
					strncpy(temp, T+SA[i], LCP[i]);
					temp[LCP[i]]='\0';
					string t(temp);
					SUBS.insert(t);
				}
				else if(maxLen==LCP[i])
				{
					strncpy(temp, T+SA[i], LCP[i]);
					temp[LCP[i]]='\0';
					string t(temp);
					SUBS.insert(t);
				}
			}
		}
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int cs=1, N;
	
	while(gets(T))
	{
		if(!strlen(T))
		gets(T);
		N=strlen(T);
		gets(temp);
		
		T[N++]='.';
		T[N]='\0';
		strcat(T, temp);
		N+=strlen(temp);
		T[N]='$';
		T[N+1]='\0';
		
		if(cs !=1)
		nl;
		cs++;
		
		SuffixArray S;
		S.process();
	}
	return (0);
}