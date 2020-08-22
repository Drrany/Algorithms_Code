

class SingleNumberIII {

    public static int[] singleNumber(int[] nums) {

        int[] ans = new int[2];
        int sum = 0;

        // 求出所有数的异或，最后得到只出现一次的两个元素的异或
        for (int i : nums)
            sum ^= i;

        // 求出这两个元素最低的不同位，通过与补码的与操作获得
        int mask = sum & (-sum);

        for (int i : nums) {
            int t = i & mask;
            if (t != 0)
                ans[0] ^= i;
            else
                ans[1] ^= i;
        }

        return ans;

    }

}