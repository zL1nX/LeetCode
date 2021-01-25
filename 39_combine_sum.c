#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*void dfs(int* candidates,int candidatesSize,int target,int* columnSize,int* returnSize,int* stack,int** res,int len,int index)
{
    printf("here2\n");
    if(target == 0)
    {
        res[*returnSize] = (int*)malloc(sizeof(int)*len);
        memcpy(res[*returnSize],stack,sizeof(int)*len);
        columnSize[*returnSize] = len;
        (*returnSize)++;
        printf("size:%d\n",*returnSize);
        return;
    }
    else if(target > 0)
    {
        int i;
        for(i=index;i<candidatesSize;i++)
        {
            if(i>0 && candidates[i] == candidates[i-1])
                continue;
            stack[len++] = candidates[i];
            printf("len:%d\n",len);
            dfs(candidates,candidatesSize,target-candidates[i],columnSize,returnSize,stack,res,len,i);
        }

    }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
    int **res = (int**)malloc(sizeof(int*)*1000);
    int *stack = (int*)malloc(sizeof(int)*target);
    *columnSizes = (int*)malloc(sizeof(int)*1000);
    printf("here1\n");
    dfs(candidates,candidatesSize,target,*columnSizes,returnSize,stack,res,0,0);
    return res;
}*/
/*static void dfs(int *nums, int size, int start, int target, int *stack,
                int len, int **results, int *column_sizes, int *count)
{
    int i;
    if (target == 0) {
        results[*count] = malloc(len * sizeof(int));
        memcpy(results[*count], stack, len * sizeof(int));
        column_sizes[*count] = len;
        (*count)++;
    } else if (target > 0) {
        for (i = start; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            stack[len] = nums[i];
            dfs(nums, size, i, target - nums[i], stack, len + 1, results, column_sizes, count);
        }
    }
}


static int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
    int cap = 100;
    int *stack = malloc(target * sizeof(int));
    int **results = malloc(cap * sizeof(int *));
    *columnSizes = malloc(cap * sizeof(int));
    *returnSize = 0;
    dfs(candidates, candidatesSize, 0, target, stack, 0, results, *columnSizes, returnSize);
    return results;
}*/

/*这道题要先排个序才好做，使得数字是从小到大排的*/
/*int cmp(int* a, int* b)
{
    return *a - *b > 0;
}

void dfs(int* candidates, int candidatesSize, int target, int** ret, int* stack, int** columnSizes, int* returnSize, int count, int num)
{
    int i, j;
    for(i = num; i < candidatesSize; i++) //i从num开始，是为了数字不要往前走，一直从当前点往后走
    {
        if(target - candidates[i] > 0)
        {
            stack[count] = candidates[i]; //如果target - candidates[i] > 0，那么ret[*returnSize][count] = candidates[i]
   //         printf("(%d - %d)a%d %d ", target, candidates[i], i, count);
            dfs(candidates, candidatesSize, target-candidates[i], ret, stack, columnSizes, returnSize, count+1, i);
        }
        else if(target - candidates[i] < 0)
        {
    //        printf("(%d - %d)b%d %d ", target, candidates[i], i, count);
            return;
        }
        else if(target - candidates[i] == 0)
        {
            stack[count] = candidates[i];
            columnSizes[0][*returnSize] = count+1;
            ret[*returnSize] = (int*)malloc(sizeof(int) * (count+1));
            memcpy(ret[*returnSize], stack, (count+1) * sizeof(int));
            (*returnSize)++;
  //          printf("f%d %d ", *returnSize, count);
  //          printf("\n");
            return;
        }

    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
    columnSizes[0] = (int*)calloc(500, sizeof(int));
    *returnSize = 0;
    int** ret = (int**)calloc(500, sizeof(int*));
    int* stack = (int*)calloc(100, sizeof(int));
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    dfs(candidates, candidatesSize, target, ret, stack, columnSizes, returnSize, 0, 0);
    return ret;
}
int main()
{
    int num,target,*returnSize = 0,i,j,**columnSizes;
    scanf("%d %d",&num,&target);
    int nums[num];
    for(i=0;i<num;i++)
    {
        scanf("%d",&nums[i]);
    }
    int** res = combinationSum(nums,num,target,columnSizes,returnSize);
    for(i=0;i<*returnSize;i++)
    {
        for(j=0;j<*columnSizes[i];j++)
            printf("%d ",res[i][j]);
        printf("\n");
    }
    return 0;
}*/
