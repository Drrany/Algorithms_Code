

class PalindromeNum {

    public boolean isPalindrome(int x) {

        int rex = 0;
        int copyx = x;

        while (x > 0) {
            rex = rex * 10 + x % 10;
            x /= 10;
        }
        
        if (rex == copyx)
            return true;

        return false;

    }

}