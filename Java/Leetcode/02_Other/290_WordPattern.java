


import java.util.HashMap;
import java.util.Map;




class WordPattern {

    public boolean wordPattern(String pattern, String str) {

        String[] s = str.split(" ");

        Map<Character, String> m = new HashMap<>();
        int plen = pattern.length();
        int slen = s.length;
        if (plen != slen)
            return false;

        for (int i = 0; i < slen; i++) {

            if (!m.containsKey(pattern.charAt(i)) && !m.containsValue(s[i]))
                m.put(pattern.charAt(i), s[i]);
            else if (!m.containsKey(pattern.charAt(i)) && m.containsValue(s[i]))
                return false;
            else if (!m.get(pattern.charAt(i)).equals(s[i]))
                return false;
        }
        
        return true;

    }
}
