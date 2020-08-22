package Leetcode;

class SpiralTwo {

    public static void main(String[] args) {
        generateMatrix(3);
    }

    public static int[][] generateMatrix(int n) {

        if (n == 0)
            return null;

        int r = 0, c = 0;
        int rows = n - 1, columns = n - 1;
        int[][] ans = new int[n][n];
        int num = 0;
        n *= n;

        while (num < n) {

            for (int i = c; i <= columns && num < n; i++) {
                ans[r][i] = ++num;
            }
            r++;

            for (int i = r; i <= rows && num < n; i++) {
                ans[i][columns] = ++num;
            }
            columns--;

            for (int i = columns; i >= c && num < n; i--) {
                ans[rows][i] = ++num;
            }
            rows--;

            for (int i = rows; i >= r && num < n; i--) {
                ans[i][c] = ++num;
            }
            c++;

        }

        return ans;

    }

}
