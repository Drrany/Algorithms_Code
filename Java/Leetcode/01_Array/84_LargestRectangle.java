package Leetcode;

import java.util.Stack;

class Rectangle {

    public int largestRectangleArea(int[] heights) {

        int len = heights.length;
        int maxarea = 0;
        if (len < 1)    return maxarea;

        Stack<Integer> s = new Stack<>();
        s.add(-1);
        int i = 0;
        s.add(i);

        while (s.peek() != -1) {

            if (i < len) {

                while (s.peek() != -1 && heights[i] < heights[s.peek()]) {
                    int area = heights[s.pop()] * (i - 1 - s.peek());
                    maxarea = Math.max(area, maxarea);
                }
                s.add(i++);
            }

            else {
                int area = heights[s.pop()] * (i - 1 - s.peek());
                maxarea = Math.max(area, maxarea);
            }

        }

        return maxarea;

    }

}
