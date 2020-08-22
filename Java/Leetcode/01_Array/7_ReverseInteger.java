
class ReverseInt {

    public static void main(String[] args) {
        int t = reverse(Integer.MIN_VALUE - 8);
        System.out.println(t);
    }

    public static int reverse(int x) {

        int ans = 0;

        while (x != 0) {

            int mod = x % 10;
            x /= 10;
            if (ans > (Integer.MAX_VALUE / 10 - mod / 10) || ans < (Integer.MIN_VALUE / 10 - mod / 10))
                return 0;
            ans = mod + ans * 10;

        }

        return ans;

    }
}