
class VersionControl {
    boolean isBadVersion(int version) {
        return true;
    }
}

class FirstBad extends VersionControl {
    public int firstBadVersion(int n) {

        int i = 1, j = n;
        while (i < j) {
            // int mid = (i + j) / 2;当i和j都很大时会溢出
            // int mid = i + (j - i) / 2;当j很大，i很很小的负数时会溢出
            int mid = (i + j) >>> 1;
            // i + j 在发生整型溢出以后，会变成负数，此时如果除以 2 ，mid 是一个负数，但是经过无符号右移，可以得到在不溢出的情况下正确的结果。

            if (isBadVersion(mid))
                j = mid;
            else
                i = mid + 1;
        }

        return i;

    }
}
