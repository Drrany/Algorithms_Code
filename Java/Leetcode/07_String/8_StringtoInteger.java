
class Solution {

    public static void main(String[] args) {

        System.out.println(myAtoi("-91283472332"));

    }

    public static int myAtoi(String str) {

        str = str.trim();
        int len = str.length();
        if (len < 1)
            return 0;

        int i = 0;
        int flag = 1;
        int ans = 0;

        if (str.charAt(i) == '+')
            i++;
        else if (str.charAt(i) == '-') {
            i++;
            flag = -1;
        }

        while (i < len && str.charAt(i) <= '9' && str.charAt(i) >= '0') {
            if (flag > 0 && ((ans > Integer.MAX_VALUE / 10)
                    || ((ans == Integer.MAX_VALUE / 10) && (str.charAt(i) - '0') > 7)))
                return Integer.MAX_VALUE;
            if (flag < 0 && ((ans > Integer.MAX_VALUE / 10)
                    || ((ans == Integer.MAX_VALUE / 10) && (str.charAt(i) - '0') > 8)))
                return Integer.MIN_VALUE;

            ans = ans * 10 + str.charAt(i) - '0';
            i++;
        }

        return flag * ans;

    }

}
