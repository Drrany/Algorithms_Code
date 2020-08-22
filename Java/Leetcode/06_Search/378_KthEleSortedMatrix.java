

class KthEleSortedMatrix {

    public static int kthSmallest(int[][] matrix, int k) {

        int rows = matrix.length;
        int columns = matrix[0].length;

        int left = matrix[0][0];
        int right = matrix[rows - 1][columns - 1];

        while (left < right) {

            int mid = (left + right) / 2;
            int count = findCount(matrix, mid, rows, columns);
            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }

        return right;

    }

    public static int findCount(int[][] matrix, int mid, int rows, int columns) {
        int i = rows - 1;
        int j = 0;
        int count = 0;
        while (i >= 0 && j < columns) {
            if (matrix[i][j] <= mid) {
                count += i + 1;
                j++;
            } else
                i--;
        }
        return count;

    }

}