
class Solution {

    public static void main(String[] args) {
        int[] a = { 1, 2 };
        int[] b = { 3, 4 };
        double mid = findMedianSortedArrays(a, b);
        System.out.println(mid);
    }

    public double findMedianSortedArrays2(int[] nums1, int[] nums2) {

        int len1 = nums1.length;
        int len2 = nums2.length;
        int mid = (len1 + len2) / 2 + 1;
        int p1 = 0, p2 = 0;
        double mid1 = 0, mid2 = 0;
        while (mid-- > 0) {
            mid1 = mid2;
            if (p1 < len1 && (p2 >= len2 || nums1[p1] < nums2[p2]))
                mid2 = nums1[p1++];
            else
                mid2 = nums2[p2++];

        }

        if ((len1 + len2) % 2 == 0)
            return (double) (mid1 + mid2) / 2;
        else
            return mid2;
    }

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int len = nums1.length + nums2.length;
        int midindex1 = (len + 1) / 2;
        int midindex2 = (len + 2) / 2;

        return (reCur(nums1, nums2, midindex1, 0, 0) + reCur(nums1, nums2, midindex2, 0, 0)) / 2;

    }

    public static double reCur(int[] nums1, int[] nums2, int k, int start1, int start2) {

        if (start1 > nums1.length - 1)
            return nums2[start2 + k - 1];
        if (start2 > nums2.length - 1)
            return nums1[start1 + k - 1];

        if (k == 1)
            return Math.min(nums1[start1], nums2[start2]);
        else {
            int n1 = ((k / 2 + start1 - 1) < nums1.length) ? nums1[k / 2 + start1 - 1] : Integer.MAX_VALUE;
            int n2 = ((k / 2 + start2 - 1) < nums2.length) ? nums2[k / 2 + start2 - 1] : Integer.MAX_VALUE;

            if (n1 <= n2) {
                start1 += k / 2;
                k -= k / 2;
            } else {
                start2 += k / 2;
                k -= k / 2;
            }
            return reCur(nums1, nums2, k, start1, start2);
        }

    }
}
