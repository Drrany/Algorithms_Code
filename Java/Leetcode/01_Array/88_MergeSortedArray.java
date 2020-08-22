package Leetcode;

class MergeSort {

    //双指针从后往前遍历，大的放后面
    public void merge2(int[] nums1, int m, int[] nums2, int n) {

        if (n < 1)
            return;

        int p = m + n - 1;
        int i = m - 1, j = n - 1;

        while (i >= 0 || j >= 0) {
            if (i < 0)
                nums1[p--] = nums2[j--];
            else if (j < 0)
                nums1[p--] = nums1[i--];
            else {
                if(nums1[i]>nums2[j])
                    nums1[p--] = nums1[i--];
                else
                    nums1[p--] = nums2[j--];
            }
        }

    }


    public void merge(int[] nums1, int m, int[] nums2, int n) {

        if (n < 1)
            return;

        int i = 0;
        while (i < m) {
            if (nums1[i] > nums2[0]) {
                int tmp = nums1[i];
                nums1[i] = nums2[0];
                int j = 1;
                while (j < n && tmp > nums2[j]) {
                    nums2[j - 1] = nums2[j++];
                }
                nums2[j - 1] = tmp;
            }
            i++;
        }

        for (int k = 0; k < n; k++) {
            nums1[m + k] = nums2[k];
        }

    }

    

}
