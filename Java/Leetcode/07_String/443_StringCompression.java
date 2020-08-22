


class StringCompression {

    public static void main(String[] args) {
        char[] chars = { 'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c' };
        compress(chars);
    }

    public static int compress(char[] chars) {

        int len = chars.length;
        int slow = 0, fast = 0;

        int count = 0;
        while (fast < len) {

            chars[slow] = chars[fast];
            count = 0;

            while (fast < len && chars[fast] == chars[slow]) {
                count++;
                fast++;
            }

            if (count != 1) {
                for (char c : String.valueOf(count).toCharArray())
                    chars[++slow] = c;
            }
            slow++;
        }

        return slow;

    }

}