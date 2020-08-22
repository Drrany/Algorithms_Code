
import java.util.PriorityQueue;

class KthLargestinArray {

        // 优先队列，默认为最小堆
        public static int findKthLargest2(int[] nums, int k) {

            PriorityQueue<Integer> q = new PriorityQueue<>();
            for (int i : nums)
                q.add(i);
    
            for (int i = 0; i < nums.length - k; i++)
                q.poll();
    
            return q.poll();
        }
    
        // 快排
        public static int findKthLargest(int[] nums, int k) {
    
            int len = nums.length;
            int left = 0, right = len - 1;
            int target = len - k;
    
            while (true) {
    
                int mid = fastSort(nums, left, right);
                if (mid == target)
                    return nums[mid];
                else if (mid < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
    
        }
    
        public static int fastSort(int[] nums, int left, int right) {
    
            int tmp = nums[left];
            while (left < right) {
                while (right > left && tmp <= nums[right])
                    right--;
                nums[left] = nums[right];
                while (left < right && tmp >= nums[left])
                    left++;
                nums[right] = nums[left];
            }
    
            nums[left] = tmp;
            return left;
    
        }

}