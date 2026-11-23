package day3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DijkstraNaive {

    public static void main(String[] args) throws IOException {
//        System.setOut(new PrintStream(Files.newOutputStream(Paths.get("dijkstra.out"),
//                StandardOpenOption.WRITE, StandardOpenOption.TRUNCATE_EXISTING,
//                StandardOpenOption.CREATE)));
        GraphWeighted g = GraphWeighted.load("graphweighted.txt");
        System.err.println("dijkstranaive");

        int[] result = dijkstra(g, 0);

        // print output
        for (int i : result) {
            System.out.println(Integer.toString(i));
        }
    }

    public static int[] dijkstra(GraphWeighted g, int s) {
        boolean[] isInX = new boolean[g.N];
        isInX[s] = true;
        int[] a = new int[g.N];
        Arrays.fill(a, Integer.MAX_VALUE);
        a[s] = 0;

        while (true) {
            int wopt = -1, costopt = Integer.MAX_VALUE;
            for (int v = 0; v < g.N; v++) {
                ArrayList<Integer> neigborsOfV = g.edges.get(v);
                for (int j = 0; j < neigborsOfV.size(); j++) {
                    final int w = neigborsOfV.get(j);
                    if (isInX[v] && !isInX[w] && a[v] + g.costs.get(v).get(j) < costopt) {
                        wopt = w;
                        costopt = a[v] + g.costs.get(v).get(j);
                    }
                }
            }
            if(costopt == Integer.MAX_VALUE)
                break;
            isInX[wopt] = true;
            a[wopt] = costopt;
        }

        return a;
    }
}

class GraphWeighted {

// ------------------------- G R A P H   I T S E L F --------------------------  
    int N, E;                                    // # of nodes,  # of edges
    ArrayList< ArrayList<Integer>> edges;       // linked list representation
    ArrayList< ArrayList<Integer>> costs;       // linked list representation

// ------------------------- C O N S T R U C T O R ----------------------------  
// creates a graph with n nodes and no edges (so called empty graph) 
    public GraphWeighted(int n) {
        N = n;
        edges = new ArrayList<>();
        costs = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
            costs.add(new ArrayList<>());
        }
    }

// ------------------------- A D D   E D G E  ---------------------------------
// mainly for input reading  
    void addedge(int a, int b, int c) {
        edges.get(a).add(b);
        edges.get(b).add(a);
        costs.get(a).add(c);
        costs.get(b).add(c);
        E++;
    }

// ----------------------------------------------------------------------------
//                              P R I N T
//                     useful for debug purposes 
    void print() {
        for (int node = 0; node < N; node++) {
            System.out.printf("%2d__", node);
            for (int j = 0; j < edges.get(node).size(); j++) {
                System.out.printf(" %2d[%2d]", edges.get(node).get(j), costs.get(node).get(j));
            }
            System.out.printf("\n");
        }
        System.out.printf("-------------------- \n");
    }

// ------------------------- A D D   E D G E  ---------------------------------
// mainly for input reading  
    void addedge(int a, int b) {
        edges.get(a).add(b);
        edges.get(b).add(a);
        E++;
    }

// ----------------------------------------------------------------------------
//                          L O A D E R
// ----------------------------------------------------------------------------
    static GraphWeighted load(String fileName) {
        try {
            BufferedReader br;
            if (fileName == null || fileName.isEmpty()) {
                br = new BufferedReader(new InputStreamReader(System.in));
            } else {
                br = new BufferedReader(new FileReader(fileName));
            }

            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.valueOf(st.nextToken()); // # of nodes
            int m = Integer.valueOf(st.nextToken()); // # of edges

            GraphWeighted g = new GraphWeighted(n);

            int n1, n2, cost;
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                n1 = Integer.valueOf(st.nextToken());
                n2 = Integer.valueOf(st.nextToken());
                cost = Integer.valueOf(st.nextToken());
                g.addedge(n1, n2, cost);
            }

            br.close();

            return g;
        } catch (IOException eee) {
            System.out.printf(" Excepcion in graph read.\n");
            return null;
        }
    }

// ----------------------------------------------------------------------------
//           D E B U G       U T I L I T I E S
// ----------------------------------------------------------------------------
    public static <T> void list(ArrayList<T> a) {
        for (T x : a) {
            System.out.printf(" %s", x);
        }
        System.out.printf("\n-------------------\n");
    }

    public static void list(int[] a) {
        for (int x : a) {
            System.out.printf(" %s", x);
        }
        System.out.printf("\n-------------------\n");
    }

    public static void list(boolean[] a) {
        for (boolean x : a) {
            System.out.printf(" %d", x ? 1 : 0);
        }
        System.out.printf("\n-------------------\n");
    }

}
