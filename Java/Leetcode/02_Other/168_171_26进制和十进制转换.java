

class Baseconversion {

    public static void main(String[] args) {
        String s = convertToTitle(28);
        System.out.println(s);
    }

    public static String convertToTitle(int n) {

        StringBuilder ans = new StringBuilder();

        while (n != 0) {
            n--;
            ans.insert(0, String.valueOf((char) (n % 26 + 65)));
            n /= 26;
        }

        return ans.toString();

    }

    public static int tenTotwo(int n) {

        int ans = 0;
        int i = 1;
        while (n != 0) {
            ans += (n % 2) * i;
            n /= 2;
            i *= 10;
        }

        return ans;

    }

    public int titleToNumber(String s) {

        char[] nums = s.toCharArray();
        int ans = 0;
        for (char c : nums) {
            int m = c - 'A' + 1;
            ans = ans * 26 + m;
        }

        return ans;

    }
}
