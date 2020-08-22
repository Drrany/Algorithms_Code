

class FindMinRotatedArray {

    public static int findMin(int[] nums) {

        int len = nums.length;

        int left = 0, right = len - 1;
        while (left < right) {

            int mid = (left + right) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            }
        }

        return nums[left];

    }

}