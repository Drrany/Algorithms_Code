
class CompareVersion {

    public static int compareVersion(String version1, String version2) {

        int sum1 = 0;
        int sum2 = 0;

        int count = 3;

        StringBuilder tmp = new StringBuilder();
        for (char c : version1.toCharArray()) {

            if (c != '.') {
                tmp.append(c);
            } else {
                sum1 += Integer.valueOf(tmp.toString()) * Math.pow(10, count);
                tmp = new StringBuilder();
                count--;
                continue;
            }

        }
        sum1 += Integer.valueOf(tmp.toString()) * Math.pow(10, count);

        count = 3;
        tmp = new StringBuilder();
        for (char c : version2.toCharArray()) {

            if (c != '.') {
                tmp.append(c);
            } else {
                sum2 += Integer.valueOf(tmp.toString()) * Math.pow(10, count);
                tmp = new StringBuilder();
                count--;
                continue;
            }
        }
        sum2 += Integer.valueOf(tmp.toString()) * Math.pow(10, count);

        if (sum1 > sum2)
            return 1;
        else if (sum2 > sum1)
            return -1;
        else
            return 0;

    }

}