package Leetcode;

class SearchinMatrix {

    // 二维映射成一维，二分查找
    public boolean searchMatrix2(int[][] matrix, int target) {

        if (matrix.length < 1 || matrix[0].length < 1)
            return false;

        int m = matrix.length;
        int n = matrix[0].length;

        int start = 0, end = m * n - 1;
        while (start <= end) {

            int mid = (start + end) / 2;
            int x = mid / n;
            int y = mid % n;
            if (matrix[x][y] < target)
                start = mid + 1;
            else if (matrix[x][y] > target)
                end = mid - 1;
            else
                return true;

        }

        return false;

    }

    public boolean searchMatrix(int[][] matrix, int target) {

        if (matrix.length < 1 || matrix[0].length < 1)
            return false;

        int m = matrix.length;
        int n = matrix[0].length;

        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;

        int mi = 0;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
                mi = i;
        }

        for (int i = 0; i < n; i++) {
            if (matrix[mi][i] == target)
                return true;
        }

        return false;

    }

    

}
