// Author : Bony Roopchandani
// CNTPRIME
// SegTree

#include <cstdio>
#include <cstring>
#define in(a) freopen(a, "r", stdin)
#define ll long long
#define pfi(a) printf("%d\n",a)
#define rep(i, n) for(int i=0; i<n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)

void scanint(int &x)
{
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for (; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
	{
		x = (x << 1) + (x << 3) + c - 48;
	}
	if (neg)
		x = -x;
}

bool notPrime[1000000+5]={0};

void Sieve()
{
	rept(i, 2, 1000)
	{
		if(!notPrime[i])
		{
			for(int j=i*2; j<=1000000; j+=i)
			notPrime[j]=true;
		}
	}
}

int Tree[10010*4], flag[10010*4];
int a[10000+5];

void insert(int root, int start, int end)
{
	if(start>end)
	return;
	
	flag[root]=0;
	
	if(start==end)
	{
		if(!notPrime[a[start]])
		Tree[root]=1;
		else
		Tree[root]=0;
	}
	
	else
	{
		insert(root<<1, start, (start+end)>>1);
		insert((root<<1)+1, ((start+end)>>1)+1, end);
		
		Tree[root]=Tree[root<<1]+Tree[(root<<1)+1];
	}
}

void refresh(int root, int start, int end)
{
	if(flag[root])
	{
		if(!notPrime[flag[root]])
		Tree[root]=end-start+1;
		else
		Tree[root]=0;
		
		if(start != end)
		{
			flag[root<<1]=flag[(root<<1)+1]=flag[root];
		}
		
		flag[root]=0;
	}
}

void update(int root, int start, int end, int u, int v, int val)
{
	if(start>end || start>v || end<u)
	{
		refresh(root, start, end);
		return;
	}
	
	if(u<=start && end<=v)
	{
		flag[root]=val;
		refresh(root, start, end);
		return;
	}
	
	refresh(root, start, end);
	
	update(root<<1, start, (start+end)>>1, u, v, val);
	update((root<<1)+1, ((start+end)>>1)+1, end, u, v, val);
	
	if(start != end)
	{
		Tree[root]=Tree[root<<1]+Tree[(root<<1)+1];
	}
}

int query(int root, int start, int end, int u, int v)
{
	refresh(root, start, end);
	
	if(start>end || start>v || end<u)
	{
		return 0;
	}
	
	if(u<=start && end<=v)
	return Tree[root];

	return query(root<<1, start, (start+end)>>1, u, v)+query((root<<1)+1, ((start+end)>>1)+1, end, u, v);
}

int main(void)
{
//	in("input.txt");
	
	Sieve();
	int T; scanint(T);
	int N, Q, x, p, u, v, cs=1;
	
	while(T--)
	{
		scanint(N), scanint(Q);
		
		rep(i, N)
		{
			scanint(a[i]);
		}
		
		insert(1, 0, N-1);
		
		printf("Case %d:\n", cs++);
		
		while(Q--)
		{
			scanint(p);
			
			if(!p)
			{
				scanint(u), scanint(v), scanint(x);
				update(1, 0, N-1, u-1, v-1, x);
			}
			else
			{
				scanint(u), scanint(v);
				
				pfi(query(1, 0, N-1, u-1, v-1));
			}
		}
	}
	
	return (0);
}