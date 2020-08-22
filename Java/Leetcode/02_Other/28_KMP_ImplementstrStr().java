

import java.util.Arrays;

class KMP1 {

    public static void main(String[] args) {
        String needle = "issip";
        String haystack = "mississippi";
        int n = strStr(haystack, needle);
        System.out.println(n);
    }

    public static void computeNext(String needle, int[] next, int len) {

        /*
         * 已知 next[0……i-1]，如何计算 next[i]，即模式串 [0,i-1] 的对称程度：
         *      若 next[i-1] = 0，表示模式串 [0,i-2] 的对称程度为0，只需将模式串第 i-1 个字符与第 1 个字符进行比较。它的对称程度最多也就是1
         *      若 next[i-1] = 1，只需将模式串第 i-1 个字符与第 2 个字符进行比较，因为前面的是 next[i-1]=1，说明前面的字符已经和第一个相等了，不需要重复比较
         *      若 next[i-1] = n，只需将模式串第 i-1 个字符与第 n+1 个字符进行比较，
         *                              若相等，当前字符的对称程度为n+1
         *                              若不相等，可能存在子对称，寻找子对称，子对称程度一定小于n+1
         */

        // next[0] = -1,next[1] = 0,这两个是固定的，所以从i=2开始
        // j表示 next[i-1]，此处 j=next[2-1]=0
        int i = 2, j = 0;

        // 方法1.
        // for (; i < nlen; i++) {

        //     // needle.charAt(i-1) != needle.charAt(j)表示当前字符不能继承前一个字符的对称程度
        //     // j > 0 表示可能存在子对称
        //     while (j > 0 && needle.charAt(i - 1) != needle.charAt(j))
        //         // 递归寻找子对称，若一直找不到，最终 j = 0(因为为了防止下一步j越界，此时还没有将next[0]赋为-1，当next数组计算完后再赋值)，跳出循环
        //         j = next[j];

        //     // 若匹配，当前字符对称程度等于(子)对称程度+1
        //     if (needle.charAt(i - 1) == needle.charAt(j))
        //         next[i] = j + 1;
        //     // 否则，当前字符对称程度为0
        //     else
        //         next[i] = 0;

        //     // 更新j，等于前一个i的对称程度
        //     j = next[i];
        // }
        // next[0]=-1;

        //方法2. 简化版
        next[0] = -1;
        while (i < len) {
            // j 为 -1 时，表示不存在子对称了，赋值为 0，进行下一个 i 的计算
            // 或者 needle.charAt(i-1) == needle.charAt(j)，表示当前对称可以继承，next[i]=j+1
            if (j == -1 || needle.charAt(i - 1) == needle.charAt(j)) {
                j++;
                next[i++] = j;
            }
            // 否则递归寻找子对称
            else
                j = next[j];
        }

    }
    
    public static void computeNextval(String needle, int[] nextval, int len) {

        int i = 2, j = 0;

        nextval[0] = -1;
        while (i < len) {
            if (j == -1 || needle.charAt(i - 1) == needle.charAt(j)) {
                j++;
                nextval[i] = j;
                // 如果要跳转的位置的字符等于该字符，则不必再跳转，因为肯定也不等
                if (needle.charAt(i) == needle.charAt(j))
                    nextval[i] = nextval[j];
                i++;
            }
            else
                j = nextval[j];
        }

    }

    public static int strStr(String haystack, String needle) {

        int hlen = haystack.length();
        int nlen = needle.length();
        if (nlen == 0)
            return 0;

        int[] next = new int[nlen];
        
        computeNext(needle, next, nlen);
        // next[i] 表示模式串[0,i-1]的对称程度，规定next[0]=-1，原因看1.
        // 若needle[i]与haystack当前位置k不匹配：
        //                      1.若 next[i] = -1，说明 i = 0，即模式串第一个元素与主串不等，只能令模式串和主串整体右移，haystack的k位置对应的是needle第一个元素的左边，所以 i = -1
        //                      2.若 next[i] = 0，说明模式串第i个元素之前的串完全不对称，只能从第一个元素重新开始配对，因此 i = 0
        //                      3.若 next[i] = n，说明模式串第i个元素之前的串前n个元素和后n个元素相等，即前n个元素可以不用重新配对，i = n
  
        
        System.out.println(Arrays.toString(next));

        int i = 0, j = 0;
        while (i < hlen && j < nlen) {

            // j = -1 表示第一个元素就和主串当前元素不等，需要整体后移
            // haystack.charAt(i) == needle.charAt(j) 表示当前元素匹配，整体后移
            if (j == -1 || haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
            } else
                j = next[j];

        }

        if (j >= nlen)
            return i - j;
        else
            return -1;

    }

}
