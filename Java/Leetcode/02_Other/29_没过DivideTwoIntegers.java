


class DivideTwoInt {

    public static void main(String[] args) {
        int d = divide(2, -3);
        System.out.println(d);
        System.out.println(-2147483648 / -3);
    }

    public static int divide(int dividend, int divisor) {

        int flag = 1;
        int quo = 0;

        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            flag = -1;

        dividend = Math.min(dividend, -dividend);
        divisor = Math.min(divisor, -divisor);

        if (divisor == -1) {
            if (flag == 1 && dividend == -2147483648)
                return 2147483647;
            return dividend * (-flag);
        }

        int inidiv = divisor;
        while (dividend <= divisor * 2) {
            divisor += divisor;
            quo += 2;
        }

        int sub = quo == 0 ? dividend : (dividend - divisor);
        while (sub <= inidiv) {
            if ((flag == 1 && quo == 2147483646) || (flag == -1) && quo == 2147483647)
                return 2147483647;
            sub -= inidiv;
            quo++;
        }

        // if (dividend > divisor)
        // return 0;

        // while (dividend <= divisor) {
        // if ((flag == 1 && quo == 2147483646) || (flag == -1) && quo == 2147483647)
        // return 2147483647;
        // dividend -= divisor;
        // quo++;
        // }

        return quo * flag;
    }

}
