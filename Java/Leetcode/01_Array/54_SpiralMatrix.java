package Leetcode;

import java.util.ArrayList;
import java.util.List;

class SprialMatrix{

    public List<Integer> spiralOrder(int[][] matrix) {

        List<Integer> ans = new ArrayList<>();
        if (matrix.length < 1)
            return ans;

        int rows = matrix.length - 1;
        int columns = matrix[0].length - 1;
        int r = 0, c = 0;

        while (true) {

            for (int i = c; i <= columns; i++)//读上边界元素
                ans.add(matrix[r][i]);
            if (++r > rows)//读完上边界＋1
                break;

            for (int i = r; i <= rows; i++)//读右边界元素
                ans.add(matrix[i][columns]);
            if (--columns < c)//读完右边界-1
                break;

            for (int i = columns; i >= c; i--)//读下边界元素
                ans.add(matrix[rows][i]);
            if (--rows < r)//读完下边界+1
                break;

            for (int i = rows; i >= r; i--)//读左边界元素
                ans.add(matrix[i][c]);
            if (++c > columns)//读完左边界+1
                break;

        }

        return ans;

    }

}