
import java.util.Arrays;

class MoveZeroes {

    public static void moveZeroes(int[] nums) {

        int slow = 0, fast = 0;
        while (fast < nums.length) {
            if (nums[fast] != 0)
                nums[slow++] = nums[fast];
            fast++;
        }
        Arrays.fill(nums, slow, fast, 0);
    }
}
