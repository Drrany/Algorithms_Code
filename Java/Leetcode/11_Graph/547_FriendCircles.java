
class FriendCircles {

    public static void main(String[] args) {
        int[][] M = { { 1, 0, 0, 1 }, { 0, 1, 1, 0 }, { 0, 1, 1, 1 }, { 1, 0, 1, 1 } };
        // int[][] M = { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } };
        int n = findCircleNum(M);
        System.out.println(n);
    }

    // 方法一：dfs

    static boolean[] visited;
    static int count;

    public static int findCircleNum(int[][] M) {

        int rows = M.length;
        int columns = M[0].length;
        count = rows;

        visited = new boolean[rows];
        for (int i = 0; i < rows; i++) {
            if (!visited[i]) {
                visited[i] = true;
                reCur(M, i, rows, columns);
            }
        }

        return count;

    }

    public static void reCur(int[][] M, int i, int rows, int columns) {

        for (int j = 0; j < columns; j++) {

            if (j != i && M[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                count--;
                reCur(M, j, rows, columns);
            }

        }

        return;

    }

    // 方法二：并查集

    public static int findCircleNum2(int[][] M) {

        int rows = M.length;
        UF uf = new UF(rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < i; j++) {// 对称矩阵
                if (M[i][j] == 1)
                    uf.union(i, j);
            }
        }

        return uf.getCount();
    }

}

class UF {

    private int count;// 连通分量
    private int[] parents;// 父结点
    private int[] size;// 记录每个节点的子节点数

    public UF(int n) {
        count = n;
        parents = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            size[i] = 1;
        }
    }

    private int findRoot(int x) {
        while (parents[x] != x) {
            x = parents[x];
        }
        return x;
    }

    public boolean isConnected(int p, int q) {
        return findRoot(p) == findRoot(q);
    }

    public void union(int p, int q) {
        if (isConnected(p, q))
            return;

        int rootp = findRoot(p);
        int rootq = findRoot(q);
        if (size[rootp] > size[rootq]) {
            parents[rootq] = rootp;
            size[rootp] += size[rootq];
        } else {
            parents[rootp] = rootq;
            size[rootq] += size[rootp];
        }
        count--;
    }

    public int getCount() {
        return count;
    }

}