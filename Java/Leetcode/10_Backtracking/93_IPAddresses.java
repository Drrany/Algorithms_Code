

import java.util.ArrayList;
import java.util.List;



class IPAddress {

    public static void main(String[] args) {
        restoreIpAddresses("010010");
    }

    public static List<String> restoreIpAddresses(String s) {

        List<String> ans = new ArrayList<>();
        int len = s.length();
        if (len < 4 || len > 12)
            return ans;

        reCur(0, 0, s, len, ans, new String());
        return ans;
    }

    public static void reCur(int th, int n, String s, int len, List<String> ans, String path) {

        if (th == 3) {
            int num = Integer.valueOf(s.substring(n, len));
            if (num <= 255 && !(s.charAt(n) == '0' && len - n > 1)) {
                path += String.valueOf(num);
                System.out.println(path);
                ans.add(path);
            }
            return;
        }

        for (int i = 1; i < 4 && len - n > i; i++) {

            if ((4 - th) * 3 < len - n)
                return;

            if (s.charAt(n) == '0' && i > 1)
                return;

            int num = Integer.valueOf(s.substring(n, n + i));

            if (num <= 255) {
                path += String.valueOf(num) + ".";
                reCur(th + 1, n + i, s, len, ans, path);
                path = path.substring(0, path.length() - i - 1);
            }
        }

        return;

    }
}
