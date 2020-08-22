


class Permutationk {

    static boolean[] flag;
    static int k;
    static String ans;
    static int[] factorial;// 阶乘数组

    public String getPermutation(int n, int k) {

        flag = new boolean[n + 1];
        ans = new String();
        factorial = new int[n + 1];
        factorial[0] = 1;
        this.k = k;

        for (int i = 1; i <= n; i++)
            factorial[i] = i * factorial[i - 1];

        reCur(new StringBuilder(), n);

        return ans;

    }

    public static void reCur(StringBuilder path, int n) {

        if (path.length() == n) {
            k--;
            if (k == 0)
                ans = path.toString();
        }

        for (int i = 1; i <= n && k > 0; i++) {
            if (!flag[i]) {
                if (factorial[n - path.length() - 1] < k) {
                    k -= factorial[n - path.length() - 1];
                    continue;
                }

                flag[i] = true;
                reCur(path.append(i), n);
                flag[i] = false;
                path.deleteCharAt(path.length() - 1);
            }
        }

    }

}
