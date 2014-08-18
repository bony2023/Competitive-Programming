// Author : Bony Roopchandani
// 11512 - GATTACA
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

char T[1000+10];

class SuffixArray
{
	map<string, PII> track;
	int* RA;
	int* SA;
	int* tempRA;
	int* tempSA;
	int* LCP;
	int N;
	
	public:
	
	SuffixArray()
	{
		N = strlen(T);
		RA = new int[N+5];
		SA = new int[N+5];
		tempSA = new int[N+5];
		tempRA = new int[N+5];
		LCP = new int[N+5];
	}
	
	~SuffixArray()
	{
		delete []RA;
		delete []SA;
		delete []tempRA;
		delete []tempSA;
		delete []LCP;
		track.clear();
	}
	
	void process()
	{
		T[N++]='$';
		
		buildSA();
		computeLCP();

		char foo[N+5];
		int cnt;
		int maxLen=0, c;
		string ans;
		
		rep(i, N)
		{
			strncpy(foo, T+SA[i], LCP[i]);
			foo[LCP[i]]='\0';
			string temp(foo);
			
			cnt=track[temp].ss;
			
			track[temp]=mp(LCP[i], cnt+1);
			
			if(maxLen<track[temp].ff || (ans==temp && c<track[temp].ss))
			{
				maxLen=track[temp].ff;
				ans=temp;
				c=track[temp].ss;
			}
		}  
		
		if(!maxLen)
		puts("No repetitions found!");
		else
		cout<<ans<<" ", pfi(c+1); 
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
		int c[1000+10]={0};
		
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
		int PLCP[N+5];
		int Phi[N+5];
		int L=0;
		
		Phi[SA[0]]=-1;
		
		rept(i, 1, N-1)
		Phi[SA[i]]=SA[i-1];
		
		rep(i, N)
		{
			if(Phi[i]==-1)
			{
				PLCP[i]=0;
				continue;
			}
			
			while(T[i+L]==T[Phi[i]+L])
			L++;
			
			PLCP[i]=L;
			
			L=max(L-1, 0);
		}
		
		rep(i, N)
		LCP[i]=PLCP[SA[i]];
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int t; sfi(t); getchar();
	
	while(t--)
	{
		gets(T);
    	SuffixArray S;
    	S.process();
	}
	
	return (0);
}