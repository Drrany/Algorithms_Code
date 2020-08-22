

class SingleinSortedArray {

    public int singleNonDuplicate(int[] nums) {

        int len = nums.length;
        int left = 0, right = len - 1;
        while (left < right) {

            int mid = (left + right) / 2;
            if (nums[mid] == nums[mid + 1]) {
                if ((mid - left) % 2 == 1)
                    right = mid - 1;
                else
                    left = mid + 2;
            } else if (nums[mid - 1] == nums[mid]) {
                if ((mid - 1 - left) % 2 == 1)
                    right = mid - 2;
                else
                    left = mid + 1;
            } else {
                return nums[mid];
            }
        }

        return nums[left];

    }

}