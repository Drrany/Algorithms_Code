

class DiagonalTraverse {

    public static int[] findDiagonalOrder(int[][] matrix) {

        if (matrix == null || matrix.length < 1)
            return new int[0];

        int rows = matrix.length;
        int columns = matrix[0].length;

        int[] ans = new int[rows * columns];
        int i = 0;
        int sum = 0, x = 0, y = 0, flag = 1;
        while (sum < rows + columns) {
            if (flag == 1) {
                x = sum >= rows ? (rows - 1) : sum;
                y = sum - x;
                while (y < columns && x >= 0)
                    ans[i++] = matrix[x--][y++];
            } else {
                y = sum >= columns ? (columns - 1) : sum;
                x = sum - y;
                while (x < rows && y >= 0)
                    ans[i++] = matrix[x++][y--];
            }
            flag = -flag;
            sum++;
        }

        return ans;
    }

}