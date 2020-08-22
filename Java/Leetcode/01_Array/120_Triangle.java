package Leetcode;

import java.util.List;

class Triangle {

    public int minimumTotal(List<List<Integer>> triangle) {

        int rows = triangle.size();
        int[] dp = new int[rows + 1];

        for (int i = rows - 1; i >= 0; i--) {

            for (int j = 0; j <= i; j++) {
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
            }

        }
        
        return dp[0];

    }

}
