

class Matrix {

    public int[][] updateMatrix(int[][] matrix) {

        int rows = matrix.length;
        int columns = matrix[0].length;
        int[][] dp = new int[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                dp[i][j] = matrix[i][j] == 0 ? 0 : Integer.MAX_VALUE - 1;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (i >= 1)
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);
                if (j >= 1)
                    dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + 1);
            }
        }

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = columns - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dp[i][j] = Math.min(dp[i][j], dp[i + 1][j] + 1);
                if (j < columns - 1)
                    dp[i][j] = Math.min(dp[i][j], dp[i][j + 1] + 1);
            }
        }

        return dp;

    }

}