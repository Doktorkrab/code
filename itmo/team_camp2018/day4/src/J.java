import java.io.*;
import java.util.*;

public class J {


    public static class Pair {
        public int from, to, id;

        public Pair(int from, int to, int id) {
            this.from = from;
            this.to = to;
            this.id = id;
        }
    }

    public List<List<Integer>> g, newG;
    public int n;
    public int[] sender;
    public List<Pair> pairs;
    public int[] tin, tout, prev;
    public int time = 0;

    public void dfs(int v, int p) {
        tin[v] = time++;
        prev[v] = p;
        for (int i = 0; i < g.get(v).size(); i++) {
            int u = g.get(v).get(i);
            if (u != p)
                dfs(u, v);
        }
        tout[v] = time++;
    }

    public boolean isPred(int v, int u) {
        return tin[u] > tin[v] && tin[u] < tout[v];
    }

    public boolean[] visited;

    public void travel(int v, int u) {
        int cur = v;
        while (cur != u && !isPred(cur, u)) {
            visited[cur] = true;
            cur = prev[cur];
            visited[cur] = true;
        }
        while (u != cur) {
            visited[u] = true;
            u = prev[u];
        }
        visited[u] = true;
        visited[v] = true;
    }

    public int[] color;

    public void cycle(int v) {
        color[v] = 1;
        for (int i = 0; i < newG.get(v).size(); i++) {
            int u = newG.get(v).get(i);
            if (color[u] == 0) {
                cycle(u);
            } else if (color[u] == 1) {
                out.print("NO");
                out.close();
                System.exit(0);
            }
        }
        color[v] = 2;
    }

    public void solve() throws IOException {
        n = nextInt();
        g = new ArrayList<>(n);
        tin = new int[n];
        tout = new int[n];
        prev = new int[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }
        for (int i = 0; i < n - 1; i++) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            g.get(a).add(b);
            g.get(b).add(a);
        }
        int s = nextInt();
        sender = new int[n + 1];
        for (int i = 0; i < s; i++) {
            int num = nextInt() - 1;
            int id = nextInt();
            sender[id] = num;
        }
        int k = nextInt();
        pairs = new ArrayList<>(n);
        newG = new ArrayList<>(k);
        for (int i = 0; i < k; i++) {
            newG.add(new ArrayList<>());
        }
        for (int i = 0; i < k; i++) {
            int num = nextInt() - 1;
            int id = nextInt();
            pairs.add(new Pair(sender[id], num, i));
        }
        dfs(0, -1);
        for (int i = 0; i < pairs.size(); i++) {
            Pair p = pairs.get(i);
            Arrays.fill(visited, false);
            travel(p.from, p.to);
            visited[p.from] = false;
            visited[p.to] = false;
            for (int j = 0; j < pairs.size(); j++) {
                if (i == j)
                    continue;
                Pair cur = pairs.get(j);
                if (visited[cur.from]) {
                    newG.get(cur.id).add(p.id);
                }
                if (visited[cur.to]) {
                    newG.get(p.id).add(cur.id);
                }
            }
        }
        color = new int[k];
        if (k > 0)
            cycle(0);
        out.print("YES");
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public void run() {
        try {
            br = new BufferedReader(new FileReader("j.in"));
            out = new PrintWriter("j.out");

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
        new J().run();
    }

}
