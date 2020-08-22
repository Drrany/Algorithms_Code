
class AddBin {

    public static void main(String[] args) {
        String a = "11";
        String b = "1";
        addBinary(a, b);
    }

    public static String addBinary(String a, String b) {

        char[] num = { '0', '1', '0', '1' };
        int alen = a.length();
        int blen = b.length();

        StringBuilder ans = new StringBuilder();

        int count = 0;
        int ai = alen - 1, bi = blen - 1;

        while (ai >= 0 || bi >= 0) {
            int sum;
            if (ai < 0)
                sum = count + b.charAt(bi--) - 48;
            else if (bi < 0)
                sum = count + a.charAt(ai--) - 48;
            else
                sum = count + a.charAt(ai--) + b.charAt(bi--) - 96;

            count = sum / 2;
            ans.append(num[sum]);
        }

        if (count == 1)
            ans.append('1');

        return ans.reverse().toString();
    }

}
