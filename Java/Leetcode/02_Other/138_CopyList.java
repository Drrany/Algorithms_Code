import java.util.HashMap;
import java.util.Map;

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class CopyList {

    public Node copyRandomList(Node head) {

        Map<Node, Node> set = new HashMap<>();

        Node tmp = head;
        while (tmp != null) {
            set.put(tmp, new Node(tmp.val));
            tmp = tmp.next;
        }

        tmp = head;
        Node p = null;
        while (tmp != null) {
            p = set.get(tmp);
            p.next = set.get(tmp.next);
            p.random = set.get(tmp.random);
            tmp = tmp.next;
        }

        return set.get(head);

    }

}