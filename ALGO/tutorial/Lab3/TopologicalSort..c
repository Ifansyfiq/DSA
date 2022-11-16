#include<stdio.h>
int a[6][6]={
	            //adjacency matrix here
	};

int d[6],f[6],n=6;
char q[6],s[6];

void dfs(int v)
{
    int i, cnt=0,indQ=-1,indS=-1;

    d[v]=1;
    q[++indQ]=v;

    while(cnt<n-1)
    {
        for(i=0; i<n; i++)
        {
            if((a[v][i]) == 1)
            {
                a[v][i]=0;

                if(d[i]==0)
                {
                    d[i]=1;
                    q[++indQ]=i;
                    v=i;
                }

                else if(d[i]==1)
                {
                    f[v]=1;
                    s[++indS]=q[indQ];
                    indQ--;
                    v=q[indQ];
                }
            }

            else if (i==n-1)
            {
                f[v]=1;
                s[++indS]=q[indQ];
                indQ--;
                v=q[indQ];
            }
        }


        cnt++;
    }
}
int main()
{
  int i,j,count=0;

  for (i=0;i<n;i++)
  {
    d[i]=0;
    f[i]=0;
  }

  dfs(2);

  printf("\nPop out order ");
 for (i=n-1;i>=0;i--)
    printf("%d ",s[i]);

return 0;
}
