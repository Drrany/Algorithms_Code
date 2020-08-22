#include <stdio.h>


int reCur(int *nums1, int nums1Size, int start1, int *nums2, int nums2Size, int start2, int k)
{

    if (start1 >= nums1Size)
        return nums2[start2 + k - 1];
    if (start2 >= nums2Size)
        return nums1[start1 + k - 1];
    if (k == 1)
        return (nums1[start1] > nums2[start2]) ? nums2[start2] : nums1[start1];
    else
    {
        int n1 = (nums1Size > (start1 + k / 2 - 1)) ? nums1[start1 + k / 2 - 1] : (int)(~0U >> 1);
        int n2 = (nums2Size > (start2 + k / 2 - 1)) ? nums2[start2 + k / 2 - 1] : (int)(~0U >> 1);

        if (n1 <= n2)
        {
            start1 += k / 2;
            k -= k / 2;
        }
        else
        {
            start2 += k / 2;
            k -= k / 2;
        }
        return reCur(nums1, nums1Size, start1, nums2, nums2Size, start2, k);
    }
}
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{

    int len = nums1Size + nums2Size;
    int left = reCur(nums1, nums1Size, 0, nums2, nums2Size, 0, (len + 1) / 2);
    int right = reCur(nums1, nums1Size, 0, nums2, nums2Size, 0, (len + 2) / 2);
    return (double)(left + right) / 2;
}


int main(){
    int a[] = {1, 2};
    int b[] = {3, 4};
    double mid = findMedianSortedArrays(a, 2, b, 2);
    printf("%f", mid);
}