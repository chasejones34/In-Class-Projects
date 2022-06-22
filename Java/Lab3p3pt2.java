/* *****************************************************************************
 *  Name:    Chase Jones
 *  PCID:    00032486
 *  Assignment:     Set 1
 *
 *  Description:  Write a program that computes the percentage of red nodes in a
 *  given red-black BST. Test your program by running at least 100 trials of the
 *  experiment of inserting N random keys into an initially empty tree, for
 *  N = 10^4, 10^5, and 10^6,and formulate an hypothesis.
 *
 **************************************************************************** */

package Lab;

import edu.princeton.cs.algs4.StdRandom;

public class Lab3p3pt2 {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int maxIter = Integer.parseInt(args[1]);

        int countTotal;

        for (int iter = 1; iter <= maxIter; iter++) {
            RedBlackBST<Double, Double> myBST = new RedBlackBST<>();
            for (int i = 1; i <= N; i++) {
                double x = StdRandom.uniform();
                myBST.put(x, x);

            }
            for (Double key : myBST.keys()) {
                //count red and black links
                if ()
            }
        }
    }
}
