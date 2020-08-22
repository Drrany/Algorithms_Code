
class TrieNode {
    boolean isEnd;
    TrieNode[] next;

    TrieNode() {
        next = new TrieNode[26];
    }
}

class Trie {

    TrieNode root;

    public static void main(String[] args) {
        Trie trie = new Trie();

        trie.insert("apple");
        trie.search("apple"); // 返回 true
        trie.search("app"); // 返回 false
        trie.startsWith("app"); // 返回 true
        trie.insert("app");
        trie.search("app"); // 返回 true
    }

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {

        TrieNode p = root;

        for (char c : word.toCharArray()) {

            if (p.next[c - 'a'] == null) {
                TrieNode t = new TrieNode();
                p.next[c - 'a'] = t;
            }
            p = p.next[c - 'a'];
        }
        p.isEnd = true;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {

        TrieNode p = root;

        for (char c : word.toCharArray()) {
            if (p.next[c - 'a'] == null)
                return false;
            p = p.next[c - 'a'];
        }
        if (p.isEnd)
            return true;

        return false;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {

        TrieNode p = root;

        for (char c : prefix.toCharArray()) {
            if (p.next[c - 'a'] == null)
                return false;
            p = p.next[c - 'a'];
        }
        return true;

    }
}