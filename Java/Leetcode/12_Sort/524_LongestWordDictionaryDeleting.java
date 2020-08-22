

import java.util.Collections;
import java.util.Comparator;

class LongestWordDictionaryDeleting {

    public String findLongestWord(String s, List<String> d) {

        Comparator<String> com = new Comparator<String>() {

            @Override
            public int compare(String o1, String o2) {
                if (o1.length() != o2.length())
                    return -Integer.compare(o1.length(), o2.length());
                else
                    return o1.compareTo(o2);
            }

        };
        
        Collections.sort(d, com);

        for (String t : d) {
            if (isSub(s, t))
                return t;
        }

        return "";

    }

    public static boolean isSub(String s, String t) {

        int slen = s.length();
        int tlen = t.length();
        if (slen < tlen)
            return false;

        int i = 0, j = 0;
        while (i < slen && j < tlen) {
            if (s.charAt(i) == t.charAt(j))
                j++;
            i++;
        }

        if (j >= tlen)
            return true;
        else
            return false;

    }

}