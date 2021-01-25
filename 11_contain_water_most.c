/*#include <stdio.h>
#include <stdlib.h>
int maxArea(int* num,int numSize)
{
    int left,right,max_area = 0,min_height,current_area;
    for(left = 0,right = numSize-1;left<right;)
    {
        min_height = num[left] > num[right] ? num[right] : num[left];
        current_area = min_height*(right-left);
        if(max_area < current_area) max_area = current_area;
        if(num[left] > num[right])
            right--;
        else
            left++;
    }
    return max_area;
}
int main()
{
    int n,i,volume;
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    volume = maxArea(num,n);
    printf("%d\n",volume);
    return 0;
}*/

