

class Search2DMatrixII {

    public boolean searchMatrix2(int[][] matrix, int target) {

        if (matrix == null || matrix.length < 1 || matrix[0].length < 1)
            return false;

        int rows = matrix.length;
        int columns = matrix[0].length;
        if (matrix[0][0] > target || matrix[rows - 1][columns - 1] < target)
            return false;

        int r = 0, c = columns - 1;
        while (r >= 0 && r < rows && c >= 0 && c < columns) {
            int t = matrix[r][c];

            if (t == target)
                return true;
            if (t < target)
                r++;
            else
                c--;

        }
        return false;

    }

    public boolean searchMatrix(int[][] matrix, int target) {

        if (matrix == null || matrix.length < 1 || matrix[0].length < 1)
            return false;

        int rows = matrix.length;
        int columns = matrix[0].length;
        if (matrix[0][0] > target || matrix[rows - 1][columns - 1] < target)
            return false;

        int upr = 0;
        int downr = rows - 1;
        while (matrix[upr][columns - 1] < target)
            upr++;
        while (matrix[downr][0] > target)
            downr--;

        int leftc = 0;
        int rightc = columns - 1;
        while (matrix[rows - 1][leftc] < target)
            leftc++;
        while (matrix[0][rightc] > target)
            rightc--;

        for (int i = upr; i <= downr; i++) {
            for (int j = leftc; j <= rightc; j++) {
                if (matrix[i][j] == target)
                    return true;
            }
        }

        return false;

    }

}