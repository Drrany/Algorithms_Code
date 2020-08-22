
class PowerofTwo {

    public boolean isPowerOfTwo(int n) {

        return n > 0 && ((n & (n - 1)) == 0);

    }

    public boolean isPowerOfTwo2(int n) {

        while (n != 0 ) {
            if (n == 2 || n == 1)
                return true;
            if (n % 2 != 0)
                return false;
            n /= 2;
        }

        return false;

    }

}