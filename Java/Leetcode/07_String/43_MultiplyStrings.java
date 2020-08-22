

class MultiplyStrings {

    public static void main(String[] args) {
        multiply("123", "456");
    }

    public static String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0"))
            return "0";
            
        int len1 = num1.length();
        int len2 = num2.length();

        StringBuilder ans = new StringBuilder();

        for (int i = len1 - 1; i >= 0; i--) {

            int n1 = num1.charAt(i) - '0';
            StringBuilder tmp = new StringBuilder();
            for (int j = 0; j < len1 - i - 1; j++)
                tmp.append('0');

            int count = 0;

            for (int j = len2 - 1; j >= 0; j--) {
                int n2 = num2.charAt(j) - '0';
                int sum = n1 * n2 + count;
                count = sum / 10;
                tmp.append((char) (sum % 10 + '0'));
            }
            if (count > 0)
                tmp.append((char) (count + '0'));

            int maxlen = Math.max(tmp.length(), ans.length());
            count = 0;
            StringBuilder tmpans = new StringBuilder();
            for (int j = 0; j < maxlen; j++) {
                char t = j >= tmp.length() ? '0' : tmp.charAt(j);
                char a = j >= ans.length() ? '0' : ans.charAt(j);
                int sum = count + t + a - '0' - '0';
                count = sum / 10;
                tmpans.append((char) (sum % 10 + '0'));
            }
            if (count > 0)
                tmpans.append((char) (count + '0'));

            ans = tmpans;
        }
        ans.reverse();

        return ans.toString();

    }

}
