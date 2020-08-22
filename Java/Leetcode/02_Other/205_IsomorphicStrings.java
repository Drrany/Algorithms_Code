class Isomorphic {

    public boolean isIsomorphic(String s, String t) {

        int slen = s.length();

        // 使用数组来代替Map
        int[] sm = new int[128];
        int[] tm = new int[128];

        for (int i = 0; i < slen; i++) {

            if (sm[s.charAt(i)] != tm[t.charAt(i)])
                return false;

            if (sm[s.charAt(i)] == 0) {
                sm[s.charAt(i)] = i+1;
                tm[t.charAt(i)] = i+1;
            }

        }

        return true;

    }

}