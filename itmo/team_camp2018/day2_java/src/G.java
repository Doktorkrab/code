import java.io.*;
import java.util.*;

public class G {

    public static final int INF = (int) 2e9;

    public static class Vertex implements Comparable<Vertex> {
        public int v, cost;

        public boolean change, up;

        public Vertex(int v, int cost) {
            this.v = v;
            this.cost = cost;
        }

        public Vertex(int v, int cost, boolean change) {
            this.v = v;
            this.cost = cost;
            this.change = change;
        }

        public Vertex(int v, int cost, boolean change, boolean up) {
            this.v = v;
            this.cost = cost;
            this.change = change;
            this.up = up;
        }

        @Override
        public int hashCode() {
            return v;
        }

        @Override
        public boolean equals(Object o) {
            Vertex ver = (Vertex) o;
            return ver.v == v && change == ver.change;
        }

        @Override
        public int compareTo(Vertex v) {
            if (cost != v.cost)
                return Integer.compare(cost, v.cost);
            else
                return Boolean.compare(change, v.change);
        }
    }

    public static class Edge {
        public int from, to, w;

        public Edge(int from, int to, int w) {
            this.from = from;
            this.to = to;
            this.w = w;
        }
    }

    public int n, m;
    public List<List<Edge>> g;
    public int[] h;

    public void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        g = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }
        h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = nextInt();
        }
        for (int i = 0; i < m; i++) {
            int from = nextInt() - 1;
            int to = nextInt() - 1;
            int w = nextInt();
            g.get(from).add(new Edge(from, to, w));
            g.get(to).add(new Edge(to, from, w));
        }
        Queue<Vertex> q = new PriorityQueue<>(2 * n);
        Set<Vertex> found = new HashSet<>((int) 1e6, 1f);
        Map<Vertex, Integer> dist = new HashMap<>((int) 1e6f);
        Vertex start = new Vertex(0, 0, false);
        q.add(start);
        dist.put(start, 0);
        while (!q.isEmpty()) {
            Vertex v = q.poll();
            if (found.contains(v))
                continue;
            found.add(v);
            for (int i = 0; i < g.get(v.v).size(); i++) {
                Edge e = g.get(v.v).get(i);
                Vertex newW = new Vertex(e.to, dist.get(v) + e.w, v.change, v.up);
                if (h[e.to] > h[v.v] && v.change) {
                    continue;
                }
                if (h[e.to] < h[v.v] && !v.up) {
                    continue;
                }
                if (h[e.to] < h[v.v]) {
                    newW.change = true;
                } else if (h[e.to] > h[v.v]) {
                    newW.up = true;
                }
                if (dist.get(v) + e.w < dist.getOrDefault(newW, INF)) {
                    dist.put(newW, dist.get(v) + e.w);
                    q.add(newW);
                }
            }
        }
        Vertex end = new Vertex(n - 1, -1, true);
        if (!dist.containsKey(end))
            out.println(-1);
        else
            out.println(dist.get(end));
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

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new G().run();
    }

}
