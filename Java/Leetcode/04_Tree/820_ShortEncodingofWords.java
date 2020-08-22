
import java.util.Arrays;

class ShortEncodingofWords {
    // 方法1：字典树（前缀树）
    public int minimumLengthEncoding2(String[] words) {

        Trie t = new Trie();
        int count = 0;
        Arrays.sort(words, (o1, o2) -> -Integer.compare(o1.length(), o2.length()));
        for (String word : words) {
            count += t.insert(word);
        }

        return count;

    }

    // 方法2：暴力
    public int minimumLengthEncoding(String[] words) {

        int len = words.length;

        for (int i = 0; i < len; i++) {
            String s = words[i];
            words[i] = new StringBuilder(s).reverse().toString();
        }

        Arrays.sort(words);
        int count = 0;
        for (int i = 0; i < len - 1; i++) {
            String cur = words[i];
            String nex = words[i + 1];
            for (int j = 0; j < cur.length(); j++) {
                if (cur.charAt(j) != nex.charAt(j)) {
                    count += cur.length() + 1;
                    break;
                }
            }
        }

        count += words[len - 1].length() + 1;
        return count;

    }

}

class Trie {

    TrieNode root;

    Trie() {
        root = new TrieNode();
    }

    int insert(String word) {

        TrieNode p = root;
        boolean isNew = false;
        for (int i = word.length() - 1; i >= 0; i--) {
            int n = word.charAt(i) - 'a';
            if (p.child[n] == null) {
                isNew = true;
                p.child[n] = new TrieNode();
            }
            p = p.child[n];
        }

        return isNew ? word.length() + 1 : 0;

    }

}

class TrieNode {

    TrieNode[] child = new TrieNode[26];

    TrieNode() {
    }

}