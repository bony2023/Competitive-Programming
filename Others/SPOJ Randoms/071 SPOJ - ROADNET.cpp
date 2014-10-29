// Author : Bony Roopchandani
// ROADNET
// Graph

// INCLUDES
#include <cstdio>

int A[201][201];

int main(void)
{
	int T; scanf("%d", &T);
	bool nL=false;
	
	while(T--)
	{
		int N; scanf("%d", &N);

		for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		scanf("%d", &A[i][j]);
		
		if(nL)
		puts("");
		else
		nL=true;
		
		bool ok;
		
		for(int a=0; a<N; a++)
		{
			for(int b=a+1; b<N; b++)
			{
				for(int c=0; c<N; c++)
				{
					ok=true;
					if(c!=a && c!=b)
					{
						if(A[a][c]+A[c][b] == A[a][b])
						{
							ok=false;
							break;
						}
					}
				}
				
				if(ok)
				printf("%d %d\n",a+1, b+1);
			}
		}
	}
	return (0);
}