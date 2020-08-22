
class SearchSqrt {

    public static void main(String[] args) {
        int n = mySqrt(2147395599);
        System.out.println(n);
    }

    public static int mySqrt(int x) {

        long left = 0, right = (x / 2) + 1;

        while (left <= right) {
            long mid = (left + right) / 2;
            long sum = mid * mid;
            if (sum == x)
                return (int)mid;
            else if (sum < x)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return (int)left - 1;

    }

}
