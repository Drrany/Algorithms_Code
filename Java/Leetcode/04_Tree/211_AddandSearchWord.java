

class TrieNode {
    TrieNode next[];
    boolean isEnd;

    TrieNode() {
        next = new TrieNode[26];
    }
}

class WordDictionary {

    TrieNode root;

    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {

        TrieNode p = root;
        for (char c : word.toCharArray()) {
            if (p.next[c - 'a'] == null) {
                p.next[c - 'a'] = new TrieNode();
            }
            p = p.next[c - 'a'];
        }
        p.isEnd = true;
    }

    /**
     * Returns if the word is in the data structure. A word could contain the dot
     * character '.' to represent any one letter.
     */
    public boolean search(String word) {

        TrieNode p = root;
        return reCurSearch(word, p, 0);

    }

    public static boolean reCurSearch(String word, TrieNode p, int i) {
        if (i >= word.length())
            return p.isEnd;

        int c = word.charAt(i);
        if (c != '.') {
            if (p.next[c - 'a'] == null)
                return false;
            p = p.next[c - 'a'];
            return reCurSearch(word, p, i + 1);
        } else {
            for (TrieNode n : p.next) {
                if (n != null&&reCurSearch(word, n, i + 1))
                    return true;
            }
            return false;
        }

    }

}
