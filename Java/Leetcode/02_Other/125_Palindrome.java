
class Palindrome {

    public static boolean isPalindrome(String s) {

        int len = s.length();
        int left = 0, right = len - 1;

        while (left < right) {

            while (left < right && !((s.charAt(left) >= 'a' && s.charAt(left) <= 'z')
                    || (s.charAt(left) >= 'A' && s.charAt(left) <= 'Z')
                    || (s.charAt(left) >= '0' && s.charAt(left) <= '9')))
                left++;
            while (left < right && !((s.charAt(right) >= 'a' && s.charAt(right) <= 'z')
                    || (s.charAt(right) >= 'A' && s.charAt(right) <= 'Z')
                    || (s.charAt(right) >= '0' && s.charAt(right) <= '9')))
                right--;
            if (left < right && (Math.abs((s.charAt(left) - s.charAt(right))) != 0)
                    && !s.substring(left, left + 1).equalsIgnoreCase(s.substring(right, right + 1)))
                return false;
            left++;
            right--;

        }

        return true;

    }

}