

class CountandSay {

    public String countAndSay(int n) {

        return reCur(n);
    }

    public static String reCur(int n) {
        if (n == 1)
            return "1";

        String tmp = reCur(n - 1);
        char[] arr = tmp.toCharArray();
        int len = arr.length;

        StringBuilder tmpans = new StringBuilder();
        
        int i = 0;
        while (i < len) {
            int m = i;
            while (i < len - 1 && arr[i] == arr[i + 1])
                i++;
            int sum = i + 1 - m;
            tmpans.append(sum).append(arr[i++]);
        }
        return tmpans.toString();
    }
}
