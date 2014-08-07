// Author : Bony Roopchandani
// BRCKTS
// Segment Tree

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

int n;

class node
{
	public:
	
	int sum, minn;
	
	void init()
	{
		sum=minn=0;
	}
	
	void create_leaf(int val)
	{
		sum=minn=val;
	}
	
	void merge(node a, node b)
	{
		sum=a.sum+b.sum;
		minn=min(a.minn, a.sum+b.minn);
	}
}tree[1<<16];

void range_update(int root, int LeftMost, int RightMost, int u, int v, int val)
{
	if(u<=LeftMost && RightMost<=v)
	{
		tree[root].create_leaf(val);
		return;
	}
	
	int mid, LC, RC;
	mid=(LeftMost+RightMost)/2;
	LC=root*2;
	RC=LC+1;
	
	if(u<mid)
	range_update(LC, LeftMost, mid, u, v, val);
	
	if(v>mid)
	range_update(RC, mid, RightMost, u, v, val);
	
	tree[root].merge(tree[LC], tree[RC]);
}

void tree_init()
{
	rep(i, (1<<(n+1)))
	tree[i].init();
}

void update(int pos, int val)
{
	return range_update(1, 1<<n, 1<<(n+1), (1<<n)+pos, (1<<n)+1+pos, val);
}

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N, Q, k, cs=1;
	char foo[30000+5], c;
	int T=10;
	
	while(T--)
	{
		cin>>N;
		
		gets(foo);
		
		n=ceil(log(N)/log(2));
		
   	tree_init();

		rep(i, strlen(foo))
		{
			if(foo[i]=='(')
			update(i, 1);
			else
			update(i, -1);
		}
		
		cin>>Q;
		printf("Test %d:\n",cs++);
		
		while(Q--)
		{
			cin>>k;
			
			if(!k)
			{
				if(!tree[1].sum && !tree[1].minn)
				puts("YES");
				else
				puts("NO");
			}
			else
			{
				k--;
				
				if(foo[k]=='(')
				{
					update(k, -1);
					foo[k]=')';
				}
				else
				{
					update(k, 1);
					foo[k]='(';
				}
			}
		}
	}
	
	return 0;
}