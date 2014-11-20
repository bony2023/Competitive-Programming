     // Author : Bony Roopchandani
	// FNCS
	// SegTree
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
typedef list < int >LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int >MII;
typedef map < int, ll > MIL;
typedef map < ll, int >MLI;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef set < int >SI;
typedef set < ll > SLL;
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
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
	inline operator   bool()
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
struct node
{
	int L, R;
	ll sum;
	  node()
	{
		L = R = INF;
		sum = 0;
	}
	void merge(const node & a, const node & b)
	{
		L = min(a.L, b.L);
		R = max(a.R, b.R);
		sum = a.sum + b.sum;
	}
};

node Tree[4 * 100010];
ll a[100010];
ll dp[100010];
ll flag[4 * 100010];
int L[100010], R[100010];
void initTree(int root, int start, int end)
{
	if (start > end)
		return;
	flag[root] = 0;
	if (start == end)
	{
		Tree[root].L = L[start] - 1;
		Tree[root].R = R[start] - 1;
		Tree[root].sum = dp[R[start] - 1] - dp[L[start] - 2];
		return;
	}
	initTree((root << 1), start, ((start + end) >> 1));
	initTree((root << 1) + 1, ((start + end) >> 1) + 1, end);
	Tree[root].merge(Tree[root << 1], Tree[(root << 1) + 1]);
}

void refresh(int root, int start, int end)
{
	if (flag[root])
	{
		Tree[root].sum += flag[root];
		if (start != end)
		{
			flag[root << 1] = flag[(root << 1) + 1] = flag[root];
		}
		flag[root] = 0;
	}
}

void update(int root, int start, int end, int pos, ll val)
{
	if (Tree[root].L > pos || Tree[root].R < pos || start > end)
	{
		refresh(root, start, end);
		return;
	}
	if (start == end)
	{
		if (Tree[root].L <= pos && Tree[root].R >= pos)
		{
			flag[root] = val;
			refresh(root, start, end);
		}
		return;
	}
	refresh(root, start, end);
	update((root << 1), start, ((start + end) >> 1), pos, val);
	update((root << 1) + 1, ((start + end) >> 1) + 1, end, pos, val);
	if (start != end)
	{
		Tree[root].merge(Tree[root << 1], Tree[(root << 1) + 1]);
	}
}

ll query(int root, int start, int end, int u, int v)
{
	refresh(root, start, end);
	if (start > end || start > v || end < u)
		return 0;
	if (u <= start && end <= v)
		return Tree[root].sum;
	return (query((root << 1), start, ((start + end) >> 1), u, v) +
			query((root << 1) + 1, ((start + end) >> 1) + 1, end, u, v));
}

int main(void)
{
	// in("input.txt");
	int N;
	cin >> N;
	rep(i, N)
	{
		sfl(a[i]);
		if (i)
			dp[i] = a[i] + dp[i - 1];
		else
			dp[i] = a[i];
	}
	rep(i, N) cin >> L[i] >> R[i];
	initTree(1, 0, N - 1);
	int Q;
	cin >> Q;
	int op;
	while (Q--)
	{
		sfi(op);
		if (op == 1)
		{
			int u;
			ll x;
			cin >> u >> x;
			update(1, 0, N - 1, u - 1, x - a[u - 1]);
			a[u - 1] = x;
		}
		else
		{
			int u, v;
			cin >> u >> v;
			pfl(query(1, 0, N - 1, u - 1, v - 1));
		}
	}
	return (0);
}