/*#include <stdio.h>
#include <stdlib.h>
struct Interval {
    int start;
    int end;
};
int comp(const void* a,const void* b)
{
    return (*(struct Interval*)a).start > (*(struct Interval*)b).start ? 1 : -1;
}
int max(int a,int b)
{
    return a > b ? a: b;
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize)
{
    if(intervalsSize <=0)
        return NULL;
    qsort(intervals,intervalsSize,sizeof(struct Interval),comp);
    struct Interval *res = (struct Interval*)malloc(sizeof(struct Interval)*intervalsSize);
    int cur = 0,pos = 1,count = 0;
    res[0].start = intervals[0].start;res[0].end = intervals[0].end;
    while(cur < intervalsSize && pos < intervalsSize)
    {
        if(intervals[cur].end >= intervals[pos].start)
        {
            res[count].start = intervals[cur].start;
            res[count].end = max(intervals[cur].end,intervals[pos].end);
            intervals[cur].end = res[count].end;
            pos++;
        }
        else
        {
            cur = pos;count++;
            res[count].start = intervals[cur].start;
            res[count].end = intervals[cur].end;
            pos++;
        }
        //printf("in:%d %d %d\n",cur,pos,count);
    }
    *returnSize = count+1;
    return res;
}
int main()
{
    int num,i,start,end;
    scanf("%d",&num);
    struct Interval *intervals = (struct Interval*)malloc(sizeof(struct Interval) * num);
    int *returnSize = (int*)malloc(sizeof(int));
    *returnSize = 0;
    for(i=0;i<num;i++)
    {
        scanf("%d %d",&start,&end);
        intervals[i].start = start;
        intervals[i].end = end;
    }
    struct Interval *res = merge(intervals,num,returnSize);
    for(i=0;i<*returnSize;i++)
        printf("%d %d\n",res[i].start,res[i].end);
    return 0;
}*/
