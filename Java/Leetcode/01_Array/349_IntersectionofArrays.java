

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;



class IntersectionofTwoArrays {

    public int[] intersection(int[] nums1, int[] nums2) {

        List<Integer> ans = new ArrayList<>();

        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int len1 = nums1.length;
        int len2 = nums2.length;
        int i = 0, j = 0;

        while (i < len1 && j < len2) {

            if (nums1[i] == nums2[j]) {
                ans.add(nums1[i]);
                i++;
                j++;
            }

            while (i < len1 && j < len2 && ((nums1[i] < nums2[j])||(i != 0 && nums1[i] == nums1[i - 1])))
                i++;

            while (i < len1 && j < len2 && ((nums1[i] > nums2[j])||(j != 0 && nums2[j] == nums2[j - 1])))
                j++;

        }

        int[] arr = new int[ans.size()];
        int l = 0;
        for (Integer k : ans) {
            arr[l++] = k;
        }

        return arr;

    }
}
