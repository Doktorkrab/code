import java.io.*;
import java.util.*;

public class H {

    public int n, m;
    public int time = 0;
    public int[] up, tin;
    public boolean[] used;

    public static class Edge {
        public int to;
        public boolean bridge;
        public Edge rev;

        public Edge(int to, boolean bridge) {
            this.to = to;
            this.bridge = bridge;
        }
    }

    public List<List<Edge>> g;

    public void dfs(int v, int p) {
        up[v] = tin[v] = time++;
        used[v] = true;
        for (int i = 0; i < g.get(v).size(); i++) {
            Edge e = g.get(v).get(i);
            int u = e.to;
            if (u == p)
                continue;
            if (used[u]) {
                up[v] = Math.min(up[v], tin[u]);
            } else {
                dfs(u, v);
                up[v] = Math.min(up[v], up[u]);
            }
            if (up[u] > tin[v]) {
                e.bridge = true;
                e.rev.bridge = true;
            }
        }
    }

    int cnt = 0;

    public void dfs2(int v) {
        used[v] = true;
        for (int i = 0; i < g.get(v).size(); i++) {
            Edge e = g.get(v).get(i);
            int u = e.to;
            if (!used[u] && !e.bridge) {
                dfs2(u);
            }
            if (e.bridge)
                cnt++;
        }
    }

    public void solve() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        g = new ArrayList<>(n);
        used = new boolean[n];
        tin = new int[n];
        up = new int[n];
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;
            Edge eFrom = new Edge(to, false);
            Edge eTo = new Edge(from, false);
            eFrom.rev = eTo;
            eTo.rev = eFrom;
            g.get(from).add(eFrom);
            g.get(to).add(eTo);
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i, -1);
            }
        }
        Arrays.fill(used, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                cnt = 0;
                dfs2(i);
                if (cnt <= 1)
                    ans++;
            }
        }
        out.print(ans);
    }

    FastScanner sc;
    StringTokenizer in;
    PrintWriter out;

    static class FastScanner extends BufferedReader {
        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }


        public int read() {
            try {
                int ret = super.read();
                return ret;
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

        static boolean isWhiteSpace(int c) {
            return c >= 0 && c <= 32;
        }

        public int nextInt() {
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

        public long nextLong() {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long ret = 0;
            while (c >= 0 && !isWhiteSpace(c)) {
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c + " found");
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

    public void run() {
        try {
            sc = new FastScanner(new FileInputStream("system.in"));
            out = new PrintWriter("system.out");

            solve();

            sc.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] args) throws IOException {
        new H().run();
    }

}
