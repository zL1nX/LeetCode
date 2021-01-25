/*#include <stdio.h>
#include <stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int num3[nums1Size+nums2Size];
    int p1=0,p2=0,k=0;
    while(p1<nums1Size && p2<nums2Size)
    {
        num3[k++] = nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
    }
    while(p1<nums1Size)
        num3[k++] = nums1[p1++];
    while(p2<nums2Size)
        num3[k++] = nums2[p2++];

    if((nums1Size+nums2Size)%2==1)
        return num3[(nums1Size+nums2Size-1)/2];
    else
        return (num3[(nums1Size+nums2Size)/2 - 1] + num3[(nums1Size+nums2Size)/2])/2.0;

}

int main()
{
    double mid_num;
    int i,n,m;
    scanf("%d %d",&n,&m);
    int num1[n],num2[m];
    for(i=0;i<n;i++)
        scanf("%d",&num1[i]);
    for(i=0;i<m;i++)
        scanf("%d",&num2[i]);
    mid_num = findMedianSortedArrays(num1,n,num2,m);
    printf("%.1lf\n",mid_num);
    return 0;

}*/
