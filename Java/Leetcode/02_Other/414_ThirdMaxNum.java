

class ThirdMaxNum {

    public static void main(String[] args) {
        int[] nums = { -2147483648, -2147483648, -2147483648, -2147483648, 1, 1, 1 };
        thirdMax(nums);
    }

    public static int thirdMax(int[] nums) {

        int[] max = new int[3];

        max[0] = Integer.MIN_VALUE;
        max[1] = Integer.MIN_VALUE;
        max[2] = Integer.MIN_VALUE;

        int flag0 = 0, flag1 = 0, flag2 = 0;

        for (int i : nums) {

            if (i > max[0] || (i == max[0] && flag0 == 0)) {
                max[2] = max[1];
                max[1] = max[0];
                max[0] = i;
                flag0++;
                flag1++;
                flag2++;
            } else if (i == max[0])
                continue;
            else if (i > max[1] || (i == max[1] && flag1 == 1)) {
                max[2] = max[1];
                max[1] = i;
                flag1++;
                flag2++;
            } else if (i == max[1])
                continue;
            else if (i > max[2] || (i == max[2] && flag2 == 2)) {
                max[2] = i;
                flag2++;
            }

        }

        if (flag2 < 3)
            return max[0];

        return max[2];

    }

}
