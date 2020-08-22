package Leetcode;

import java.util.Stack;

 class ValidParentheses {

    public static boolean isValid(String s) {

        Stack<Character> stack = new Stack<>();
        stack.push('-');
        for (Character c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[')
                stack.push(c);
            else {
                if ((stack.peek() == '(' && c == ')') || (stack.peek() == '{' && c == '}')
                        || (stack.peek() == '[' && c == ']'))
                    stack.pop();
                else
                    return false;
            }
        }

        stack.pop();
        return stack.isEmpty();
        

        

    }

}
