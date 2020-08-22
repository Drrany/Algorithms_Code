

class HappyNumber {

    public static void main(String[] args) {

        isHappy(2);

    }

    public static boolean isHappy(int n) {

        // 遇到循环就应该想到快慢指针
        
        int fast = n;
        int fn = fast;
        int slow = n;
        int sn = slow;
        int i = 0;

        while (fast != 1) {

            i++;

            fast = 0;
            while (fn != 0) {
                fast += (fn % 10) * (fn % 10);
                fn /= 10;
            }
            fn = fast;

            if (i % 2 == 0) {
                slow = 0;
                while (sn != 0) {
                    slow += (sn % 10) * (sn % 10);
                    sn /= 10;
                }
                sn = slow;
            }

            if (fast == slow)
                return false;

        }

        return true;

    }
}
