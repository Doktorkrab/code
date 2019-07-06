import com.sun.org.apache.xpath.internal.operations.Mod;

import java.io.*;
import java.util.*;

public class D {

    public long n;

    public static final long MOD = (long) (1e9 + 7);

    public long[] a;

    public static class Node {
        public long l, r, sum;

        public Node leftNode, rightNode;

        public Node(long l, long r) {
            this.l = l;
            this.r = r;
        }
    }

    public Node build(long l, long r) {
        Node res = new Node(l, r);
        if (l != r) {
            long m = (l + r) / 2;
            res.leftNode = build(l, m);
            res.rightNode = build(m + 1, r);
        }
        return res;
    }

    public void add(Node root, long ind, long val) {
        if (ind < root.l || ind > root.r)
            return;
        if (root.l == root.r) {
            root.sum += val;
            root.sum %= MOD;
            return;
        }
        add(root.leftNode, ind, val);
        add(root.rightNode, ind, val);
        root.sum = root.leftNode.sum + root.rightNode.sum;
        root.sum %= MOD;
    }

    public long query(Node root, long l, long r) {
        if (r < root.l || l > root.r)
            return 0;
        if (root.l >= l && root.r <= r)
            return root.sum;
        return query(root.leftNode, l, r) + query(root.rightNode, l, r);
    }

    public static final long MAX_VAL = (long) 2e5;

    public void solve() throws IOException {
        n = nextInt();
        a = new long[(int) n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Node root = build(0, MAX_VAL);
        long ans = 0;
        long sum = 0;
        long prevSum = 0;
        for (int i = 0; i < n; i++) {
            add(root, a[i], 1);
            add(root, a[i], query(root, 0, a[i] - 1));
            prevSum = sum;
            sum += root.sum;
            sum %= MOD;
            ans += sum * (i + 1) - prevSum;
            ans %= MOD;
        }
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public long nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new D().run();
    }

}
