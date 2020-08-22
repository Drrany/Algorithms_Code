

class MaximalSquare {

    public int maximalSquare(char[][] matrix) {

        int maxlen = 0;
        if (matrix == null || matrix.length < 1)
            return maxlen;

        int rows = matrix.length;
        int columns = matrix[0].length;

        int[][] dp = new int[rows + 1][columns + 1];

        for (int i = 1; i < rows + 1; i++) {
            for (int j = 1; j < columns + 1; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    maxlen = Math.max(maxlen, dp[i][j]);
                }
            }
        }

        return maxlen*maxlen;
    }

}