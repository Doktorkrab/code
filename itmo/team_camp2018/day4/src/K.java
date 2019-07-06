import java.io.*;
import java.util.*;

public class K {

    public int[] dI = {1, -1, 0, 0};
    public int[] dJ = {0, 0, 1, -1};

    public int[][] map;

    public static class State {
        public int i, j, x, y;

        public State(int i, int j, int x, int y) {
            this.i = i;
            this.j = j;
            this.x = x;
            this.y = y;
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int startI = nextInt();
        int startJ = nextInt();
        map = new int[n + 2][m + 2];
        boolean used[][] = new boolean[n + 2][m + 2];
        int x = nextInt();
        int y = nextInt();
        for (int i = 1; i <= n; i++) {
            String tmp = br.readLine();
            for (int j = 1; j <= m; j++) {
                if (tmp.charAt(j - 1) == '.')
                    map[i][j] = 1;
            }
        }
        Queue<State> q = new ArrayDeque<>(n * m);
        q.add(new State(startI, startJ, x, y));
        used[startI][startJ] = true;
        int ans = 0;
        while (!q.isEmpty()) {
            State v = q.poll();
            ans++;
            for (int i = 0; i < dI.length; i++) {
                int newI = v.i + dI[i];
                int newJ = v.j + dJ[i];
                if (map[newI][newJ] == 1) {
                    if (i == 2 && v.y == 0)
                        continue;
                    if (i == 3 && v.x == 0)
                        continue;
                    if (!used[newI][newJ]) {
                        int newX = v.x;
                        int newY = v.y;
                        if (i == 2) {
                            newY--;
                        } else if (i == 3) {
                            newX--;
                        }
                        used[newI][newJ] = true;
                        q.add(new State(newI, newJ, newX, newY));
                    }
                }
            }
        }
//        for (int i = 0; i < n + 2; i++) {
//            out.println(Arrays.toString(used[i]));
//        }
        out.print(ans);
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
        new K().run();
    }

}
