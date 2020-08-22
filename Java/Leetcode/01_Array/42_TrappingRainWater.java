package Leetcode;

class TrapWater {

    public static void main(String[] args) {
        int[] height = { 4,2,3 };
        int n = trap1(height);
        System.out.println(n);
    }

    public static int trap(int[] height) {//动态规划

        int capacity = 0;
        int len = height.length;
        int[][] max_LR = new int[len][2];

        int i = 0;
        while (i++ < len - 2) {// 两端不用考虑，因为不会有水

            max_LR[i][0] = Math.max(height[i - 1], max_LR[i - 1][0]);
            max_LR[len - i - 1][1] = Math.max(height[len - i], max_LR[len - i][1]);

        }

        for (int j = 1; j < max_LR.length - 1; j++) {
            int minheight = Math.min(max_LR[j][0], max_LR[j][1]);
            if (minheight > height[j])
                capacity += (minheight - height[j]);
        }

        return capacity;
    }

    public static int trap1(int[] height) {//动态规划+双指针

        int capacity = 0;
        int len = height.length;
        int maxLf = 0, maxRg = 0;//分别代表当前元素左边最高墙和右边最高墙高度
        int left = 1, right = len - 2;//左右指针

        while (left <= right) {

            if (height[left - 1] < height[right + 1]) {//此时maxLf一定小于maxRg，因此只用计算maxLf

                maxLf = Math.max(height[left - 1], maxLf);
                if (maxLf > height[left])
                    capacity += (maxLf - height[left]);
                left++;

            } else {

                maxRg = Math.max(height[right + 1], maxRg);
                if (maxRg > height[right])
                    capacity += (maxRg - height[right]);
                right--;

            }
        }

        return capacity;
    }

}