

class ReverseWords {

    public String reverseWords(String s) {

        StringBuilder ans = new StringBuilder();
        int len = s.length();

        int i = len - 1;
        while (i >= 0) {

            while (i >= 0 && s.charAt(i) == ' ')
                i--;

            int j = i;

            while (j >= 0 && s.charAt(j) != ' ')
                j--;

            ans.append(s.substring(j + 1, i + 1));

            if (i > j)
                ans.append(" ");

            i = j;
        }

        String res = ans.toString();
        return res.trim();
    }


}