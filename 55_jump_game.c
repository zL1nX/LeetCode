#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*void jump(int* nums,int step,int jump_cap,int place,int size,int* flag)
{
    //printf("jump_cap:%d step:%d place:%d\n",jump_cap,step,place);
    if(place == size-1)
    {
        *flag = 1;
        return;
    }
    else if(jump_cap == 0)
    {
        *flag = 0;
        return;
    }
    else
    {
        int this_jump = nums[place];
        //printf("this_jump:%d\n",this_jump);
        int i;
        for(i=1;i <= this_jump && (place + i) <= size - 1;i++)
            jump(nums,i,this_jump,place+i,size,flag);
    }
}
bool canJump(int* nums, int numsSize)
{
    if(numsSize <=0 )
        return false;
    int first_jump = nums[0];
    int *flag = malloc(sizeof(int));
    jump(nums,0,first_jump,0,numsSize,flag);
    return *flag == 1 ? true : false;
}*/
/*int max(int a, int b)
{
    return a > b ? a : b;
}
bool canJump(int* nums, int numsSize)
{
    int i,cur=0;
    if(numsSize <=0 )
        return false;
    for(i=0;i<numsSize;i++)
    {
        if(cur < i || cur > numsSize - 1)
            break;
        cur = max(i + nums[i],cur);
    }
    return cur >= numsSize - 1;
}
int main()
{
    int num,i;
    scanf("%d",&num);
    int n[num];
    for(i=0;i<num;i++)
        scanf("%d",&n[i]);
    bool res = canJump(n,num);
    printf(res==true ? "Yes\n" : "No\n");
    return 0;
}*/
