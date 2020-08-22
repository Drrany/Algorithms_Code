
import java.util.List;

class KeysandRooms {

    
    static boolean[] visited;

    // 841.
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {

        int len = rooms.size();
        visited = new boolean[len];
        reCur(rooms, 0);

        for (boolean b : visited) {
            if (!b)
                return false;
        }

        return true;

    }

    public static void reCur(List<List<Integer>> rooms, int i) {

        visited[i] = true;
        List<Integer> tmp = rooms.get(i);
        for (Integer n : tmp) {
            if (!visited[n])
                reCur(rooms, n);
        }

        return;

    }

}