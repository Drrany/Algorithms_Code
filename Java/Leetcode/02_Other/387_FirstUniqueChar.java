


class FirstChar {

    public int firstUniqChar(String s) {

        int[] times = new int[26];

        for (char c : s.toCharArray()) {
            times[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (times[s.charAt(i) - 'a'] == 1)
                return i;
        }
        
        return -1;
    }

}