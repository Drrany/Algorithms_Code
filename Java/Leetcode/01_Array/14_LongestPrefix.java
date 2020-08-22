package Leetcode;

class longestCommonPre {

    public String longestCommonPrefix(String[] strs) {

        int len = strs.length;
        if (len < 1)
            return "";

        int ans = strs[0].length();
        int i = 1;
        while (ans != 0 && i < len) {
            int tmp = 0;
            for (int j = 0; j < strs[i].length() && j < ans; j++) {
                if (strs[0].charAt(j) != strs[i].charAt(j))
                    break;
                tmp++;
            }
            ans = Math.min(ans, tmp);
            i++;
        }

        return strs[0].substring(0, ans);

    }

}
