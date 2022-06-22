/* *****************************************************************************
 *  Name:    Chase Jones
 *  PCID:    00032186
 *  Assignment:     Set 1
 *
 *  Description:  The eccentricity of a vertex v is the length of the shortest
 *  path from that vertex to the furthest vertex from v.  The diameter of a
 *  graph is the maximum eccentricity of any vertex.  The radius of a graph is
 *  the smallest eccentricity of any vertex.  A center is a vertex whose
 *  eccentricity is the radius.  Implement the following API and create a test
 *  client that reads a graph from the input stream named as a command-line
 *  argument.  Find the diameter, radius, and all centers of the data in
 *  mediumG.txt.
 *
 **************************************************************************** */

package Lab;

import edu.princeton.cs.algs4.BreadthFirstPaths;
import edu.princeton.cs.algs4.CC;
import edu.princeton.cs.algs4.Graph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

import java.util.LinkedList;
import java.util.List;

public class GraphProperties {
    private int[] eccentricity;
    private int radius;
    private int diameter;
    private List<Integer> centers;

    public GraphProperties(Graph g) {
        eccentricity = new int[g.V()];
        diameter = 0;
        radius = g.V() - 1;
        centers = new LinkedList<Integer>();

        CC cc = new CC(g);
        if (cc.count() != 1) {
            throw new IllegalArgumentException("Graph not connected");
        }

        for (int v = 0; v < g.V(); v++) {
            BreadthFirstPaths bfs = new BreadthFirstPaths(g, v);

            for (int w = 0; w < g.V(); w++) {
                if (bfs.distTo(w) > eccentricity[v]) {
                    eccentricity[v] = bfs.distTo(w);
                }
            }
            if (eccentricity[v] > diameter) {
                diameter = eccentricity[v];
            }
            if (eccentricity[v] < radius) {
                radius = eccentricity[v];
            }
        }
        for (int v = 0; v < g.V(); v++) {
            if (eccentricity[v] == radius) {
                centers.add(v);
            }
        }
    }

    public int diameter() {
        return diameter;
    }

    public int radius() {
        return radius;
    }

    public int eccentricity(int v) {
        return eccentricity[v];
    }

    public List<Integer> center() {
        return centers;
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        Graph myGraph = new Graph(in);

        GraphProperties props = new GraphProperties(myGraph);

        StdOut.println("Eccentricities: ");
        for (int v = 0; v < myGraph.V(); v++) {
            StdOut.println("Vertex: " + v + ", Eccentricity=" + props.eccentricity(v));

        }
        StdOut.println("Diameter: " + props.diameter());
        StdOut.println("Radius: " + props.radius());
        StdOut.print("Center:");
        for (int v : props.center()) {
            StdOut.print(" " + v);
        }
    }
}
