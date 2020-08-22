

class PermutationinString {

    public static boolean checkInclusion(String s1, String s2) {

        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 > len2)
            return false;

        int[] pat1 = new int[26];
        int[] pat2 = new int[26];

        for (char c : s1.toCharArray())
            pat1[c - 'a']++;

        int len = 0, i = 0;
        while (i < len2) {
            while (i < len2 && len < len1) {
                pat2[s2.charAt(i) - 'a']++;
                i++;
                len++;
            }
            if (len == len1) {
                boolean tmp = true;
                for (int j = 0; j < 26; j++) {
                    if (pat1[j] != pat2[j]) {
                        tmp = false;
                        break;
                    }
                }
                if (tmp)
                    return tmp;
                pat2[s2.charAt(i - len) - 'a']--;
                len--;
            }
        }

        return false;
    }

}