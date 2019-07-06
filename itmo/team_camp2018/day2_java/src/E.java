import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

import static java.lang.System.out;

public class E {

    public int n, m;
    public Pair[] a;

    public static class Node {
        public int l, r, max;
        public Node leftNode, rightNode;

        public Node(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }

    public Node build(int l, int r) {
        Node res = new Node(l, r);
        if (l == r) {
            return res;
        } else {
            int m = (l + r) / 2;
            res.leftNode = build(l, m);
            res.rightNode = build(m + 1, r);
            return res;
        }
    }

    public void set(Node root, int ind, int val) {
        if (ind < root.l || ind > root.r)
            return;
        if (root.l == root.r) {
            root.max = Math.max(root.max, val);
            return;
        }
        set(root.leftNode, ind, val);
        set(root.rightNode, ind, val);
        root.max = Math.max(root.leftNode.max, root.rightNode.max);
    }

    public int query(Node root, int l, int r) {
        if (r < root.l || l > root.r)
            return -1;
        if (l <= root.l && root.r <= r) {
            return root.max;
        }
        return Math.max(query(root.leftNode, l, r), query(root.rightNode, l, r));
    }

    public static class Pair implements Comparable<Pair> {
        public int val, ind;

        public Pair(int val, int ind) {
            this.val = val;
            this.ind = ind;
        }

        @Override
        public int compareTo(Pair pair) {
            if (val != pair.val)
                return Integer.compare(val, pair.val);
            else
                return Integer.compare(ind, pair.ind);
        }
    }

    public void solve() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        a = new Pair[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Pair(sc.nextInt(), i);
        }
        Pair[] aCopy = Arrays.copyOf(a, n);
        Arrays.sort(a);
        int[] posByInd = new int[n];
        Map<Integer, Integer> l = new HashMap<>((int) 4e6, 1f);
        for (int i = 0; i < n; i++) {
            posByInd[a[i].ind] = i + 1;
            if (!l.containsKey(a[i].val)) {
                l.put(a[i].val, i + 1);
            }
        }
        Node[] dp = new Node[m + 1];
        for (int i = 0; i < m + 1; i++) {
            dp[i] = build(0, n + 3);
        }
        for (int i = 0; i < n; i++) {
            for (int m = 0; m <= this.m; m++) {
                int val = posByInd[i];
                int realVal = aCopy[i].val;
                set(dp[m], val, query(dp[m], 0, l.get(realVal) - 1) + 1);
                if (m != 0) {
                    int max = query(dp[m - 1], l.get(realVal), val - 1);
                    max = Math.max(max, query(dp[m - 1], val + 1, n + 3));
                    set(dp[m], val, max + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m + 1; i++) {
            ans = Math.max(ans, dp[i].max);
        }
        out.println(ans);
    }

    FastScanner sc;
    PrintWriter out;

    void run()throws IOException{
        sc=new FastScanner(System.in);
        out=new PrintWriter(System.out);
        solve();
        sc.close();;
        out.close();
    }

    static class FastScanner extends BufferedReader {
        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }


        static boolean isWhiteSpace(int c) {
            return c >= 0 && c <= 32;
        }

        public int nextInt() throws IOException {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int ret = 0;
            while (c >= 0 && !isWhiteSpace(c)) {
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c
                            + " found");
                }
                ret = ret * 10 + c - '0';
                c = read();
            }
            return ret * sgn;
        }


        public String readLine() {
            try {
                return super.readLine();
            } catch (IOException e) {
                return null;
            }
        }

    }

    public static void main(String[] args) throws IOException {
        new E().run();
    }

}
