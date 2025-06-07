import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        Star from;
        Star to;
        double distance;

        Edge(Star from, Star to, double distance) {
            this.from = from;
            this.to = to;
            this.distance = distance;
        }

        @Override
        public int compareTo(Edge other) {
            return Double.compare(this.distance, other.distance);
        }
    }

    static class Star {
        double x;
        double y;

        Star(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public double getDistance(Star other) {
            return Math.sqrt(Math.pow(this.x-other.x, 2) + Math.pow(this.y-other.y, 2));
        }
    }

    static HashMap<Star, Star> parent = new HashMap<>();

    static Star find(Star star) {
        if (parent.get(star).equals(star)) {
            return star;
        }

        parent.put(star, find(parent.get(star)));
        return find(parent.get(star));
    }

    static boolean union(Star a, Star b) {
        Star rootA = find(a);
        Star rootB = find(b);

        if (rootA.equals(rootB)) {
            return false;
        }

        parent.put(rootB, rootA);
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        ArrayList<Star> stars = new ArrayList<>();
        for (int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            double x = Double.parseDouble(st.nextToken());
            double y = Double.parseDouble(st.nextToken());

            stars.add(new Star(x, y));
        }

        ArrayList<Edge> edges = new ArrayList<>();
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                Star from = stars.get(i);
                Star to = stars.get(j);
                double distance = from.getDistance(to);

                edges.add(new Edge(from, to, distance));
            }
        }

        for (Star star : stars) {
            parent.put(star, star);
        }

        Collections.sort(edges);

        double tot = 0;
        int cnt = 0;

        for (Edge edge : edges) {
            Star from = edge.from;
            Star to = edge.to;

            if (union(from, to)) {
                tot += edge.distance;
                cnt++;
            }

            if (cnt == n-1) break;
        }

        System.out.printf("%.2f", tot);

        br.close();
    }

}
