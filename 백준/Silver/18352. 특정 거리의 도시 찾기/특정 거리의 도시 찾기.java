import java.io.*;
import java.util.*;

public class Main {

    static class Pair {
        int dst,nde;

        public Pair(int dst, int nde) {
            this.dst = dst;
            this.nde = nde;
        }
    }

    static class Edge {
        int to, weight;

        public Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static int n,m,k,x;
    static List<Edge>[] graph;
    static int[] dist;

    static void dijkstra() {
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(p -> p.dst)); // {dist, node}
        pq.add(new Pair(0, x));
        dist[x] = 0;

        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            if (p.dst != dist[p.nde]) continue;

            for (Edge e : graph[p.nde]) {
                int nxtNode = e.to;
                int nxtDist = e.weight;

                if (dist[nxtNode] > dist[p.nde] + nxtDist) {
                    dist[nxtNode] = dist[p.nde] + nxtDist;
                    pq.add(new Pair(dist[nxtNode], nxtNode));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n+1];
        for (int i=1;i<=n;++i) graph[i] = new ArrayList<>();
        dist = new int[n+1];

        for (int i=0;i<m;++i) {
            st = new StringTokenizer(br.readLine());

            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            graph[s].add(new Edge(e, 1));
        }

        Arrays.fill(dist, Integer.MAX_VALUE);
        dijkstra();

        List<Integer> order = new ArrayList<>();

        for (int i=1;i<=n;++i) {
            if (dist[i] == k) {
                order.add(i);
            }
        }

        if (order.isEmpty()) System.out.println(-1);
        else {
            Collections.sort(order);

            for (int o : order) {
                System.out.println(o);
            }
        }
    }
}