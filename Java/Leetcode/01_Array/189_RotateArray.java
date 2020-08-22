
import java.util.Arrays;


class RotateArray {

    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4, 5, 6, 7 };
        rotate(nums, 3);
        System.out.println(Arrays.toString(nums));
    }

    public static void rotate(int[] nums, int k) {

        int len = nums.length;
        k %= len;//

        reVerse(nums, 0, len);
        reVerse(nums, 0, k);
        reVerse(nums, k, len);
    }

    public static void reVerse(int[] nums, int i, int j) {

        for (int k = 0; k < (j - i) / 2; k++) {
            int tmp = nums[k + i];
            nums[k + i] = nums[j - k - 1];
            nums[j - k - 1] = tmp;
        }

    }

}
