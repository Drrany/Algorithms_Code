package Leetcode;

import java.util.Arrays;

class  UniquePaths {

    public static void main(String[] args) {
        int n = uniquePaths2(4, 5);
        System.out.println(n);
    }

    public static int uniquePaths(int m, int n) {

        int[][] dp = new int[m][n];

        for (int i = 0; i < m; i++)
            dp[i][n - 1] = 1;
        for (int i = 0; i < n; i++)
            dp[m - 1][i] = 1;

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];

    }
    
    public static int uniquePaths2(int m, int n) {

        int[] cur = new int[n];
        Arrays.fill(cur,1);
        for (int i = 1; i < m;i++){
            for (int j = 1; j < n; j++){
                cur[j] += cur[j-1] ;
            }
        }
        return cur[n-1]; 
    }


}