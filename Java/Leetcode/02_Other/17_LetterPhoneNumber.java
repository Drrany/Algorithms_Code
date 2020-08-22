

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;



class LetterNumber {

    // 方法一：利用队列先进先出的特点
    public List<String> letterCombinations(String digits) {

        LinkedList<String> ans = new LinkedList<>();
        if (digits.isEmpty())
            return ans;

        ans.add("");
        String[] tab = new String[] { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        for (int i = 0; i < digits.length(); i++) {
            int index = Character.getNumericValue(digits.charAt(i)) - 2;
            int len = ans.size();

            for (int j = 0; j < len; j++) {

                String tmp = ans.remove();
                for (int k = 0; k < tab[index].length(); k++) {
                    ans.add(tmp + tab[index].charAt(k));
                }
            }
        }

        return ans;
    }

    // 方法二：逐一配对，效率高
    public List<String> letterCombinations2(String digits) {

        List<String> ans = new ArrayList<>();
        String[] tab = new String[8];
        tab[0] = "abc";
        tab[1] = "def";
        tab[2] = "ghi";
        tab[3] = "jkl";
        tab[4] = "mno";
        tab[5] = "pqrs";
        tab[6] = "tuv";
        tab[7] = "wxyz";

        List<StringBuilder> t = new ArrayList<>();

        for (int i = 0; i < digits.length(); i++) {

            int index = digits.charAt(i) - 50;

            if (i == 0) {
                for (int j = 0; j < tab[index].length(); j++) {
                    StringBuilder tmp = new StringBuilder();
                    tmp.append(tab[index].charAt(j));
                    t.add(tmp);
                }
            } else {

                int len = t.size();

                for (int j = 0; j < len; j++) {

                    for (int k = 1; k < tab[index].length(); k++) {
                        StringBuilder tmp = new StringBuilder();
                        tmp.append(t.get(j)).append(tab[index].charAt(k));
                        t.add(tmp);
                    }
                    t.get(j).append(tab[index].charAt(0));
                }

            }
        }

        for (StringBuilder sBuilder : t) {
            ans.add(sBuilder.toString());
        }

        return ans;

    }

}
