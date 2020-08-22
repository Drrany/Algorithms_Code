

class MinFallingPathSum {

    public int minFallingPathSum(int[][] A) {

        if (A == null || A.length < 1)
            return 0;
        int rows = A.length;
        int columns = A[0].length;

        int[][] dp = new int[2][columns];
        for (int i = 0; i < columns; i++)
            dp[0][i] = A[rows - 1][i];
        int flag = 0;

        for (int i = rows - 2; i >= 0; i--) {

            for (int j = 0; j < columns; j++) {
                int left = j > 0 ? dp[flag][j - 1] : Integer.MAX_VALUE;
                int mid = dp[flag][j];
                int right = j < columns - 1 ? dp[flag][j + 1] : Integer.MAX_VALUE;
                dp[(flag + 1) % 2][j] = Math.min(mid, Math.min(left, right)) + A[i][j];
            }
            flag = (flag + 1) % 2;
        }

        int min = dp[flag][0];
        for (int i = 0; i < columns; i++)
            min = Math.min(min, dp[flag][i]);

        return min;
    }

}