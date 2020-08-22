package Leetcode;

class RotateImage{

    public static void swap(int[][] arr, int row1, int column1, int row2, int column2) {
        int tmp = arr[row1][column1];
        arr[row1][column1] = arr[row2][column2];
        arr[row2][column2] = tmp;
    }

    public void rotate(int[][] matrix) {

        int row = matrix.length;

        for (int i = 0; i < row / 2; i++) {// 先上下翻转数组
            for (int j = 0; j < row; j++)
                swap(matrix, i, j, row - i - 1, j);
        }

        for (int i = 0; i < row; i++) {// 再按正对角线交换对应元素
            for (int j = i; j < row; j++)
                swap(matrix, i, j, j, i);
        }

    }

    public void rotate2(int[][] matrix) {

        int row = matrix.length;

        for (int i = 0; i < row / 2; i++) {

            int start = i;
            int end = row - 1 - i;

            for (int j = start; j < end; j++) {

                int tmp = matrix[i][j];
                matrix[i][j] = matrix[row - j - 1][i];
                matrix[row - j - 1][i] = matrix[row - i - 1][row - j - 1];
                matrix[row - i - 1][row - j - 1] = matrix[j][row - 1 - i];
                matrix[j][row - 1 - i] = tmp;

            }

        }

    }

}