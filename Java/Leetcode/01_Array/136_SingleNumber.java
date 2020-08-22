
import java.util.Arrays;

class SingleNumber {

    // 方法一，先排序
    public int singleNumber(int[] nums) {

        Arrays.sort(nums);
        int len = nums.length;
        for (int i = 0; i < len - 1; i += 2) {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }

        return nums[len - 1];

    }

    // 方法二，异或，异或具有交换律
    public int singleNumber2(int[] nums) {

        int single = nums[0];
        for (int i = 1; i < nums.length; i++)
            single ^= nums[i];

        return single;

    }

}