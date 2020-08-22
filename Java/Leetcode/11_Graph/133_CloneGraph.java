

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;



class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }

    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

class CloneGraph {
    // BFS
    public Node cloneGraph(Node node) {

        if (node == null)
            return null;

        Node[] set = new Node[101];
        set[node.val] = new Node(node.val, new ArrayList<>());
        Deque<Node> q = new LinkedList<>();
        q.offer(node);

        while (!q.isEmpty()) {

            Node tmp = q.poll();

            for (Node p : tmp.neighbors) {
                if (set[p.val] == null) {
                    q.offer(p);
                    set[p.val] = new Node(p.val, new ArrayList<>());
                }
                set[tmp.val].neighbors.add(set[p.val]);
            }

        }
        return set[node.val];
    }

    // DFS
    public Node cloneGraph2(Node node) {

        Node[] set = new Node[101];
        reCur(node, set);
        return node == null ? null : set[node.val];
    }

    public static void reCur(Node n, Node[] set) {
        if (n == null)
            return;
        if (set[n.val] == null)
            set[n.val] = new Node(n.val, new ArrayList<>());

        for (Node p : n.neighbors) {
            if (set[p.val] == null)
                reCur(p, set);
            set[n.val].neighbors.add(set[p.val]);
        }

        return;
    }
}
