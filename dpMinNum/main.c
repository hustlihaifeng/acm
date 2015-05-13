#include <stdio.h>
int dpMinNum(int cond_num,int *cond,int prob);
int main()
{
    int cond_num;
    while((scanf("%d",&cond_num))!=EOF)
    {
        int cond[cond_num];
        int i;
        int prob;
        for(i=0;i<cond_num;i++)
        {
            scanf("%d",cond+i);
        }
        scanf("%d",&prob);
        int result=dpMinNum(cond_num,cond,prob);
        if(result>-1)
            printf("%d\n",result);
        else
            printf("NO\n");
    }
    return 0;
}

int dpMinNum(int cond_num, int *cond, int prob)
{
    if(prob==0)
        return 0;

    int result[cond_num];
    int min;
    int i=0;
    while((prob-cond[i]>=0) && (result[i]=dpMinNum(cond_num,cond,prob-cond[i]))<0 && i<cond_num)
        i++;
    if(i<cond_num && (prob-cond[i])>=0)
        min=result[i]+1;
    else
        return -1;
    int j;
    for(j=i+1;j<cond_num && ((prob-cond[j])>=0);j++)
    {
        if((result[i]=dpMinNum(cond_num,cond,prob-cond[j]))>=0)
        {
            if((result[i]+=1)<min)
                min=result[i];
        }
    }
    return min;
}
