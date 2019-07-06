import java.io.*;
import java.util.*;

public class G {
    public int n, k;
    public String s;

    public void gen() {

    }

    public void solve() throws IOException {
        n = nextInt();
        k = nextInt();
        s = nextToken();
        gen();
        Queue<String> q = new ArrayDeque<>(n);
        q.add("");
        while (true) {
            String cur = q.poll();
            if (!s.contains(cur)) {
                out.print(cur);
                return;
            }
            for (int i = 0; i < k; i++) {
                q.add(cur + (char) ('a' + i));
            }
        }
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public void run() {
        try {
            br = new BufferedReader(new FileReader("g.in"));
            out = new PrintWriter("g.out");

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
