// Author : Bony Roopchandani
// 1112 - Mice and Maze
// Multi - Source Dijkstra

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

vector<PII>A[100+50];
int N;

int Dijkstra(int u, int v)
{
	priority_queue<PII, vector<PII>, greater<PII> >Q;
	
	VI dist(N+5, INF);
	
	Q.push(mp(0, u));
	dist[u]=0;
	
	while(!Q.empty())
	{
		PII z=Q.top();
		Q.pop();
		
		int a=z.ss;
		int c=z.ff;
		
		if(dist[a]==c)
		{
			rep(i, A[a].sz)
			{
				int p=A[a][i].ss;
				int w=A[a][i].ff;
				
				if(dist[p]>dist[a]+w)
				{
					dist[p]=dist[a]+w;
					Q.push(mp(dist[p], p));
				}
			}
		}
	}
	return dist[v];
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int T; cin>>T;
	
	int cs=1;
	
	while(T--)
	{
		int E, T;
		
		cin>>N>>E>>T;
		
		int M; cin>>M;
		int x, y, t;
		
		rep(i, M)
		{
			cin>>x>>y>>t;
			
			A[x].pb(mp(t, y));
		}
		
		int C=0;
		
		rept(i, 1, N)
		{
			int P=Dijkstra(i, E);
			
			if(P<=T)
			C++;
		}
		
		if(cs!=1)
		nl;
		cs++;
		
		cout<<C<<"\n";
		
		rep(i, N+5)
		A[i].clear();
	}
	
	return 0;
}