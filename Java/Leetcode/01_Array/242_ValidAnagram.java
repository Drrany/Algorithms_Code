
class ValidAnagram {

 

    public static boolean isAnagram(String s, String t) {

        if (s.length() != t.length())
            return false;

        int[] sa = new int[26];
        int[] ta = new int[26];

        int len = s.length();
        for (int i = 0; i < len; i++) {
            sa[s.charAt(i) - 97]++;
            ta[t.charAt(i) - 97]++;
        }

        for (int i = 0; i < 26; i++) {
            if (sa[i] != ta[i])
                return false;
        }
        return true;

    }

}