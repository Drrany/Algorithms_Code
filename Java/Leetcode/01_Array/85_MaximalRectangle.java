package Leetcode;

import java.util.Stack;

class MaxRectangle {


    public int maximalRectangle(char[][] matrix) {

        if (matrix == null || matrix.length < 1 || matrix[0].length < 1)
            return 0;

        int m = matrix.length;
        int n = matrix[0].length;
        int maxarea = 0;

        for (int i = 0; i < m; i++) {

            Stack<Integer> s = new Stack<>();
            s.push(-1);
            int k = 0;
            int[] h = new int[n + 1];
            h[n] = -1;
            while (!s.isEmpty()) {

                if (k < n) {
                    while (h[k] <= i && matrix[i - h[k]][k] == '1')
                        h[k]++;
                }

                while (s.peek() != -1 && h[k] < h[s.peek()]) {
                    int area = h[s.pop()] * (k - 1 - s.peek());
                    maxarea = Math.max(area, maxarea);
                }

                if (k < n)
                    s.push(k++);
                if (s.peek() == -1)
                    break;
            }

        }

        return maxarea;

    }

}
