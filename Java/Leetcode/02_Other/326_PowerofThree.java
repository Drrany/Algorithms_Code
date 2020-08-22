

class PowerofThree {

    public boolean isPowerOfThree(int n) {

        if (n == 1)
            return true;

        while (n != 0) {
            if (n == 3 || n == 1)
                return true;

            if (n % 3 == 0) {
                if (n % 27 == 0)
                    n /= 27;
                if (n % 9 == 0)
                    n /= 9;
                if (n % 3 == 0)
                    n /= 3;
            } else
                break;
        }

        return false;
    }

}