import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Template {

    public int[] alph = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    public List<Long> ansL = new ArrayList<>();

    public int ans = 0;
    int a, b;

    public boolean check(long x) {
        if (x == 1)
            return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    public void gen(long cur) {
        if (!check(cur))
            return;
        if (cur >= a && cur <= b) {
            ans++;
            ansL.add(cur);
        }
        if (cur > b)
            return;
        for (int i = 0; i < alph.length; i++) {
            if (cur == 0 && i == 0)
                i++;
            gen(cur * 10L + alph[i]);
        }
    }

    public void solve() throws IOException {
        a = nextInt();
        b = nextInt();
        gen(0);
        out.println(ans);
        Collections.sort(ansL);
        for (long x : ansL)
            out.println(x);
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
        new Template().run();
    }

}
