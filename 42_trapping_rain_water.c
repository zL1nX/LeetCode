#include <stdio.h>
#include <stdlib.h>
/*int min(int a,int b)
{
    return a > b ? b : a;
}
int max(int a,int b)
{
    return a > b ? a : b;
}
int trap(int* height, int heightSize)
{
    int temp = 0,i;
    for(i=0;i<heightSize;i++)
    {
        int left= i - 1,right = i + 1,lprev = i,rprev = i;
        while(i>0&&i<heightSize-1&&left >=0 && right<=heightSize-1&&height[lprev]<=height[left]&&height[rprev]<=height[right])
        {
            //printf("l:%d p:%d r:%d p:%d\n",left,lprev,right,rprev);
            temp += (min(height[left],height[right])-max(height[lprev],height[rprev]))*(right-left-1);
            //printf("%d %d\n",min(height[left],height[right]),max(height[lprev],height[rprev]));
            //printf("water:%d\n",temp);
            if(height[left]>height[right])
                rprev = right++;
            else if(height[right] > height[left])
                lprev = left--;
            else
                rprev = right++,lprev = left--;
            //printf("after:l:%d p:%d r:%d p:%d\n",left,lprev,right,rprev);


        }
    }
    return temp;
}*/
/*int trap(int* height, int heightSize)
{
    if(heightSize < 2)
        return 0;
    int i,j,water = 0,start,end=-1,level;
    for(i=0;i<heightSize;i++)
    {
        if(height[i]>0)
        {
            start = i;
            break;
        }

    }
    //printf("here1!\n");
    while(i<heightSize)
    {
        end = -1;
        for(j=i+1;j<heightSize;j++)
        {
            if(height[j] >= height[j-1])
            {
                if(height[end] <= height[j] || end < 0)
                //printf("here2!\n");
                end = j;
            }
            if(height[j] >= height[start])
                break;
        }
        if(end >= 0)
        {
            level = height[end] > height[start] ? height[start] : height[end];
            while(i<end)
            {
                //printf("here3!\n");
                if(level > height[i])
                    water += level-height[i];
                i++;
            }
            start = end;
            i = end;
            //printf("i:%d end:%d\n",i,end);
        }
        else
            i = j;
    }
    return water;
}
int main()
{
    int num,i,rain_water;
    scanf("%d",&num);
    int nums[num];
    for(i=0;i<num;i++)
        scanf("%d",&nums[i]);
    rain_water = trap(nums,num);
    printf("%d\n",rain_water);
    return 0;
}*/
