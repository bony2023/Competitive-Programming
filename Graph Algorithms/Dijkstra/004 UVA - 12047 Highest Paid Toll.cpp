// Author : Bony Roopchandani
// 12047 - Highest Paid Toll
// Two Source Dijkstra

// INCLUDES
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
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
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int >LI;
typedef list < ll > LLL;
typedef set < int >SI;
typedef set < ll > SLL;

// Fast IO by "mukel" copied from
//discuss.codechef.com/questions/6677/cool-fast-io-implementation

static struct IO
{
	char tmp[1 << 10];

	// fast input routines
	char cur;

	// #define nextChar() (cur = getc_unlocked(stdin))
	// #define peekChar() (cur)
	inline char nextChar()
	{
		return cur = getc_unlocked(stdin);
	}
	inline char peekChar()
	{
		return cur;
	}

	inline operator  bool()
	{
		return peekChar();
	}
	inline static bool isBlank(char c)
	{
		return (c < '-' && c);
	}
	inline bool skipBlanks()
	{
		while (isBlank(nextChar()));
		return peekChar() != 0;
	}

	inline IO & operator >>(char &c)
	{
		c = nextChar();
		return *this;
	}

	inline IO & operator >>(char *buf)
	{
		if (skipBlanks())
		{
			if (peekChar())
			{
				*(buf++) = peekChar();
				while (!isBlank(nextChar()))
					*(buf++) = peekChar();
			}
			*(buf++) = 0;
		}
		return *this;
	}

	inline IO & operator >>(string & s)
	{
		if (skipBlanks())
		{
			s.clear();
			s += peekChar();
			while (!isBlank(nextChar()))
				s += peekChar();
		}
		return *this;
	}

	inline IO & operator >>(double &d)
	{
		if ((*this) >> tmp)
			sscanf(tmp, "%lf", &d);
		return *this;
	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

	defineInFor(int)defineInFor(unsigned int) defineInFor(long long)
		// fast output routines
		// #define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c)
	{
		putc_unlocked(c, stdout);
	}
	inline IO & operator <<(char c)
	{
		putChar(c);
		return *this;
	}
	inline IO & operator <<(const char *s)
	{
		while (*s)
			putChar(*s++);
		return *this;
	}

	inline IO & operator <<(const string & s)
	{
		for (int i = 0; i < (int)s.size(); ++i)
			putChar(s[i]);
		return *this;
	}

	char *toString(double d)
	{
		sprintf(tmp, "%lf%c", d, '\0');
		return tmp;
	}
	inline IO & operator <<(double d)
	{
		return (*this) << toString(d);
	}


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

	defineOutFor(int)defineOutFor(long long)
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;

int N;
vector<PII> A[10000+10];
vector<PII> B[10000+10];
VI Cost, CostR;

void Dijkstra(int u)
{
	priority_queue<PII, vector<PII>, greater<PII> >Q;
	Cost.assign(N+5, INF);
	
	Q.push(mp(0, u));
	Cost[u]=0;
	
	while(!Q.empty())
	{
		PII z=Q.top();
		Q.pop();
		
		int a=z.ss;
		int c=z.ff;
		
		if(Cost[a]==c)
		{
			rep(i, A[a].sz)
			{
				int p=A[a][i].ss;
				int w=A[a][i].ff;
				
				if(Cost[p]>Cost[a]+w)
				{
					Cost[p]=Cost[a]+w;
					Q.push(mp(Cost[p], p));
				}
			}
		}
	}
}

void DijkstraR(int v)
{
	priority_queue<PII, vector<PII>, greater<PII> >Q;
	CostR.assign(N+5, INF);
	
	Q.push(mp(0, v));
	CostR[v]=0;
	
	while(!Q.empty())
	{
		PII z=Q.top();
		Q.pop();
		
		int a=z.ss;
		int c=z.ff;
		
		if(CostR[a]==c)
		{
			rep(i, B[a].sz)
			{
				int p=B[a][i].ss;
				int w=B[a][i].ff;
				
				if(CostR[p]>CostR[a]+w)
				{
					CostR[p]=CostR[a]+w;
					Q.push(mp(CostR[p], p));
				}
			}
		}
	}
}

void clearAll(int V)
{
	rept(i, 1, V)
	A[i].clear(), B[i].clear();
	Cost.clear();
	CostR.clear();
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int T; cin>>T;
	
	while(T--)
	{
		int M, S, T, P;
		
		cin>>N>>M>>S>>T>>P;
		
		int x, y, c;
		
		rep(i, M)
		{
			cin>>x>>y>>c;
			A[x].pb(mp(c, y));
			B[y].pb(mp(c, x));
		}
		
		Dijkstra(S);
		DijkstraR(T);
		int res=-1;

		rept(u, 1, N)
		{
			rep(i, A[u].sz)
			{
				int v=A[u][i].ss;
				int w=A[u][i].ff;
				int tot;
				tot=w+Cost[u]+CostR[v];
				
				if(w>res && tot<=P)
				res=w;
			}
		}
		
		cout<<res<<"\n";
		
		clearAll(N);
	}
	
	return 0;
}