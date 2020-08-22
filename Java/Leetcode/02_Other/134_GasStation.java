

class GasStation {

    public static int canCompleteCircuit(int[] gas, int[] cost) {

        int len = gas.length;
        int index = 0;
        int sub = 0;

        int sum = 0;
        for (int i = 0; i < len; i++) {
            sub += gas[i] - cost[i];
            if (sum < 0) {
                sum = gas[i] - cost[i];
                index = i;
            } else
                sum += gas[i] - cost[i];
        }

        return sub >= 0 ? index : -1;
    }

}