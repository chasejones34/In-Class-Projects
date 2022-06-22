/* *****************************************************************************
 *  Name:    Chase Jones
 *  PCID:    000324186
 *  Assignment:     Set 1
 *
 *  Description: The indegree of a vertex in a digraph is the number of directed
 *  edges that point to that vertex. The outdegree of a vertex in a digraph is
 *  the number of directed edges that emanate from that vertex. No vertex is
 *  reachable from a vertex of outdegree 0, which is called a sink; a vertex of
 *  indegree 0, which is called a source, is not reachable from an other vertex.
 *  A digraph where self-loops are allowed and every vertex has outdegree
 *  is called a map (a function from the set of integers from 0 to V–1 onto
 *  itself). Write a program Degrees.java that implements the following API:
 *
 *
 **************************************************************************** */

package Lab;

import edu.princeton.cs.algs4.Bag;
import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class Degrees {
    int[] inDegrees;
    int[] outDegrees;
    Bag<Integer> sources;
    Bag<Integer> sinks;
    boolean mapornah = true;

    public Degrees(Digraph digraph) {
        inDegrees = new int[digraph.V()];
        outDegrees = new int[digraph.V()];
        for (int v = 0; v < digraph.V(); v++) {
            for (int s : digraph.adj(v)) {
                outDegrees[v]++;
                inDegrees[s]++;
            }
        }
        for (int v = 0; v < digraph.V(); v++) {
            if (outDegrees[v] == 0) {
                sinks.add(v);
            }
            if (inDegrees[v] == 0) {
                sources.add(v);
            }
            if (outDegrees[v] != 1) {
                mapornah = false;
            }

        }
    }

    public int outDegrees(int v) {
        return outDegrees[v];
    }

    public int inDegrees(int v) {
        return inDegrees[v];
    }

    public

    public static void main(String[] args) {
        In in = new In(args[0]);
        Digraph myGraph = new Digraph(in);

        Degrees degs = new Degrees(myGraph);
        StdOut.println("Degrees");
        for (int v = 0; v < myGraph.V(); v++) {
            StdOut.println(
                    "Vertex: " + v + ", in=" + degs.inDegrees(v) + ", out =" + degs
                            .outDegrees(v));

        }

    }


}
