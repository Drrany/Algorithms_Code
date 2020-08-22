import java.util.HashMap;
import java.util.Map;

class Node {
    public int key, val;
    public Node next, prev;

    public Node(int k, int v) {
        key = k;
        val = v;
    }
}

class DoubleList {
    private Node head, tail;
    private int size;

    public DoubleList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.next = tail;
        tail.prev = head;
        size = 0;
    }

    public void addFirst(Node x) {
        x.next = head.next;
        x.prev = head;
        x.next.prev = x;
        head.next = x;
        size++;
    }

    public void remove(Node x) {
        x.next.prev = x.prev;
        x.prev.next = x.next;
        size--;
    }

    public Node removeLast() {
        if (tail.prev == head)
            return null;

        Node res = tail.prev;
        remove(res);
        return res;
    }

    public int getSize() {
        return size;
    }

}

class LRUCache {
    /**
     * Your LRUCache object will be instantiated and called as such: LRUCache obj =
     * new LRUCache(capacity); int param_1 = obj.get(key); obj.put(key,value);
     */

    private Map<Integer, Node> m;
    private DoubleList cache;
    private int capacity;

    public LRUCache(int capacity) {
        m = new HashMap<>();
        cache = new DoubleList();
        this.capacity = capacity;
    }

    public int get(int key) {

        int res = -1;
        if (m.containsKey(key)) {
            res = m.get(key).val;
            put(key, res);
        }

        return res;

    }

    public void put(int key, int value) {

        Node a = new Node(key, value);

        if (m.containsKey(key)) {
            cache.remove(m.get(key));
            cache.addFirst(a);
            m.put(key, a);
        } else {
            if (capacity == cache.getSize())
                m.remove(cache.removeLast().key);

            cache.addFirst(a);
            m.put(key, a);
        }
        

    }
}

