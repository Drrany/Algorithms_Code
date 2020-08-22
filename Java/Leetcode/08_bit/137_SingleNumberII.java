

class SingleNumberII {
    public int singleNumber(int[] nums) {

        // 模拟不进位的三进制
        int ones = 0, twos = 0, threes = 0;
        for (int n : nums) {

            twos |= ones & n;
            ones ^= n;
            threes = ones & twos;

            ones &= ~threes;
            twos &= ~threes;

        }

        return ones;

    }
}