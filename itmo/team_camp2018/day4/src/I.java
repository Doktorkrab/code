import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class I {

    public static class Point {
        public long x, y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            Point point = (Point) o;
            return x == point.x &&
                    y == point.y;
        }

        public long dist(Point p) {
            return new Vector(this, p).len();
        }
    }

    public static class Vector {
        public long x, y;

        public Vector(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public Vector(Point A, Point B) {
            this(A.x - B.x, A.y - B.y);
        }

        @SuppressWarnings("SuspiciousNameCombination")
        public Vector rotate90() {
            return new Vector(-y, x);
        }

        public long len() {
            return x * x + y * y;
        }
    }

    public static class Line {
        public long a, b, c;

        public Line(Point A, Point B) {
            Vector AB = new Vector(A, B).rotate90();
            this.a = AB.x;
            this.b = AB.y;
            this.c = -a * A.x - b * A.y;
        }

        public long getDist(Point p) {
            return a * p.x + b * p.y + c;
        }
    }

    public Random rnd = new Random(230239566);

    public static final int BOUND = (int) (1e9 + 1);
    public int[] color;

    public Point rndPoint() {
        return new Point(rnd.nextInt(BOUND), rnd.nextInt(BOUND));
    }


    public boolean can(List<Point> points) {
        int cnt = 0;
        for (int k = 0; k < 10000; k++) {
            Point A = rndPoint();
            Point B = rndPoint();
            Line l = new Line(A, B);
            boolean[][] was = new boolean[2][2];
            boolean valid = true;
            for (int i = 0; i < points.size(); i++) {
                long dist = l.getDist(points.get(i));
                if (dist > 0)
                    was[color[i]][0] = true;
                else if (dist < 0)
                    was[color[i]][1] = true;
                else
                    valid = false;
            }
            if (was[0][0] && was[0][1])
                valid = false;
            if (was[1][0] && was[1][1])
                valid = false;
            if (was[0][0] && was[1][0])
                valid = false;
            if (was[0][1] && was[1][1])
                valid = false;
            if (valid) {
                cnt++;
            }
        }
        return cnt > 900 - points.size() * 30;
    }

    public void solve() throws IOException {
        int n = nextInt();
        List<Point> points = new ArrayList<>(n);
        color = new int[n];
        for (int i = 0; i < n; i++) {
            Point rndP;
            while (true) {
                rndP = rndPoint();
                points.add(rndP);
                color[i] = 0;
                if (!can(points)) {
                    points.remove(points.size() - 1);
                    continue;
                }
                color[i] = 1;
                if (!can(points)) {
                    points.remove(points.size() - 1);
                    continue;
                }
                color[i] = 0;
                break;
            }
            out.print(points.get(i).x);
            out.print(' ');
            out.println(points.get(i).y);
            out.flush();
            if ("white".equals(nextToken()))
                color[i] = 1;
        }
        while (true) {
            Point A = rndPoint();
            Point B = rndPoint();
            Line l = new Line(A, B);
            boolean[][] was = new boolean[2][2];
            boolean valid = true;
            for (int i = 0; i < n; i++) {
                long dist = l.getDist(points.get(i));
                if (dist > 0)
                    was[color[i]][0] = true;
                else if (dist < 0)
                    was[color[i]][1] = true;
                else
                    valid = false;
            }
            if (was[0][0] && was[0][1])
                valid = false;
            if (was[1][0] && was[1][1])
                valid = false;
            if (was[0][0] && was[1][0])
                valid = false;
            if (was[0][1] && was[1][1])
                valid = false;
            if (valid) {
                out.print(A.x);
                out.print(' ');
                out.print(A.y);
                out.print(' ');
                out.print(B.x);
                out.print(' ');
                out.println(B.y);
                break;
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
        new I().run();
    }

}
