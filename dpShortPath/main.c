#include <stdio.h>
int dpShortestPath(int scale, int data[][scale], int source, int target);
int main()
{
    int scale;
    while((scanf("%d",&scale))!=EOF)
    {
        int data[scale][scale];
        int i,j;
        int source,target;
        for(i=0;i<scale;i++)
        {
            for(j=0;j<scale;j++)
            {
                scanf("%d",data[i]+j);
            }
        }
        scanf("%d %d",&source,&target);
        int result=dpShortestPath(scale,data,source,target);
        if(result>-1)
            printf("%d\n",result);
        else
            printf("no\n");
    }
    return 0;
}

int dpShortestPath(int scale, int data[][scale], int source, int target)
{
    int result[scale];
    int  i,j;
    int change=1;
    for(i=0;i<scale;i++)
    {
        if(i==target)
            result[i]=0;
        else
            result[i]=-1;
    }
    while(change==1)
    {
        change=0;
        for(i=0;i<scale;i++)
        {
            if(i!=target)
            {
                for(j=0;j<scale;j++)
                {
                    if(result[j]>-1)
                    {
                        if(result[i]>-1)
                        {
                            if(data[i][j]>-1 && ((result[j]+data[i][j])<result[i]))
                            {
                                result[i]=result[j]+data[i][j];
                                change=1;
                            }

                        }
                        else if(data[i][j]>-1)
                        {
                            result[i]=result[j]+data[i][j];
                            change=1;
                        }
                    }//result[j]>=0
                }//j<scale
            }//i!=target
        }//i<scale
    }//change==1
    return result[source];
}
