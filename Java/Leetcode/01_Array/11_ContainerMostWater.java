
class Solution {
    public int maxArea(int[] height) {

        int capacity = 0;
        int i = 0, j = height.length - 1;
        while (i != j) {

            int tmp = (j - i) * Math.min(height[j], height[i]);
            if (tmp > capacity)
                capacity = tmp;
            if (height[i] < height[j])
                i++;
            else
                j--;

        }

        return capacity;

    }
}