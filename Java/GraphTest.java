/* *****************************************************************************
 *  Name:    Chase Jones
 *  PCID:    000324186
 *  Assignment:     Set 1
 *
 *  Description:
 *
 **************************************************************************** */

package Lab;

import edu.princeton.cs.algs4.Graph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class GraphTest {
    public static void main(String[] args) {
        In in = new In(args[0]);
        Graph g = new Graph(in);

        for (int i = 0; i < g.V(); i++) {
            for (int neighbors : g.adj(i)) {
                StdOut.println(i + "-" + neighbors);
            }
        }
    }
}
