



import java.util.HashSet;
import java.util.List;
import java.util.Set;



class WordBreak {


    // 动态规划：dp[i]意为 以s[i]结尾的子字符串是否可以被空格拆分为一个或多个在字典中出现的单词

    public static boolean wordBreak(String s, List<String> wordDict) {

        int len = s.length();
        boolean[] dp = new boolean[len];

        Set<String> words = new HashSet<>();
        for (String string : wordDict) {
            words.add(string);
        }

        for (int i = 0; i < len; i++) {

            if (words.contains(s.substring(0, i + 1))) {
                dp[i] = true;
                continue;
            }

            for (int j = 0; j < i; j++) {

                if (dp[j] && words.contains(s.substring(j + 1, i + 1))) {
                    dp[i] = true;
                    break;
                }

            }

            if (dp[len - 1])
                return true;

        }

        return dp[len - 1];

    }

}
