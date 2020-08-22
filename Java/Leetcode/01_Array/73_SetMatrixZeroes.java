package Leetcode;

class SetZeros {

    public void setZeroes(int[][] matrix) {

        int m = matrix.length;
        int n = matrix[0].length;
        boolean row_flag = false;
        boolean column_flag = false;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == 0) {
                    if (i == 0)
                        row_flag = true;
                    if (j == 0)
                        column_flag = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }

            }
        }

        for (int i = 1; i < m; i++) {

            for (int j = 1; j < n; j++) {

                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

            }
        }

        for (int i = 0; i < n && row_flag; i++)
            matrix[0][i] = 0;
        for (int i = 0; i < m && column_flag; i++)
            matrix[i][0] = 0;

        return;

    }

}
