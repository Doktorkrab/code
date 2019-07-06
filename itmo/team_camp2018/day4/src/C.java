import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class C {

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] cntM = new int[m + 1];
        int[] cntN = new int[n + 1];
        int k = nextInt();
        for (int i = 0; i < k; i++) {
            int a = nextInt();
            int b = nextInt();
            cntN[a]++;
            cntM[b]++;
        }
        for (int i = 0; i <= n; i++) {
            if(cntN[i]>1){
                out.print("NO");
                return;
            }
        }
        for (int i = 0; i <= m; i++) {
            if(cntM[i]>1){
                out.print("NO");
                return;
            }
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
        new C().run();
    }

}
