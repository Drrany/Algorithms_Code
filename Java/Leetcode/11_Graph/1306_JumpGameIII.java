


class JumpGameIII {

    public boolean canReach(int[] arr, int start) {

        return reCur(arr, start, new boolean[arr.length]);

    }

    public static boolean reCur(int[] arr, int now, boolean[] visited) {

        if (now < 0 || now >= arr.length || visited[now])
            return false;

        if (arr[now] == 0)
            return true;
        visited[now] = true;

        return reCur(arr, now - arr[now], visited) || reCur(arr, now + arr[now], visited);

    }
    
}