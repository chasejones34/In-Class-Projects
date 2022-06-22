/* *****************************************************************************
 *  Name:    Chase Jones
 *  PCID:    000324186
 *  Assignment:     Set 1
 *
 *  Description:Implement quicksort with a cutoff to insertion sort for
 *  subarrays with less than M elements, and empirically determine the value of
 *  M for which quicksort runs fastest in your computing environment to sort
 *  random arrays of N doubles, for N = 10^3, 10^4, 10^5, and 10^6. Plot average
 *  running times for M from 0 to 30 for each value of M. Note: You need to add a
 *  three-argument sort() method to ALGORITHM 2.2 for sorting subarrays such
 *  that the call Insertion.sort(a, lo, hi) sorts the subarray a[lo..hi].
 *
 **************************************************************************** */

package Lab;

import edu.princeton.cs.algs4.Insertion;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.Stopwatch;

public class QuickSortCutoff {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int iterations = Integer.parseInt(args[1]);
        doExperiment(n, iterations);
    }

    private static void doExperiment(int n, int iterations) {
        double averageTime = 0.0;
        for (int M = 1; M <= 30; M++) {
            for (int iter = 0; iter < iterations; iter++) {
                //generate aray
                Comparable[] a = genRandArray(n);
                //start stopwatch
                Stopwatch timer = new Stopwatch();
                //sort
                sort(a, M);
                //collect elapsed time
                averageTime += timer.elapsedTime();
            }
            //average elapsed time
            averageTime /= iterations;
            //display
            StdOut.printf("%d\t%d\t%.6f\n", n, M, averageTime);
        }
    }

    public static void sort(Comparable[] a, int cutoff) {

        sort(a, 0, a.length - 1, cutoff);
    }

    public static void sort(Comparable[] a, int lo, int hi, int cutoff) {
        if (hi <= lo + cutoff) {
            Insertion.sort(a, lo, hi);
            return;
        }
        int j = partition(a, lo, hi);
        sort(a, lo, j - 1, cutoff);
        sort(a, j + 1, hi, cutoff);
    }

    private static int partition(Comparable[] a, int lo, int hi) {
        int i = lo;
        int j = hi + 1;
        Comparable v = a[lo];
        while (true) {

            // find item on lo to swap
            while (less(a[++i], v)) {
                if (i == hi) break;
            }

            // find item on hi to swap
            while (less(v, a[--j])) {
                if (j == lo) break;      // redundant since a[lo] acts as sentinel
            }

            // check if pointers cross
            if (i >= j) break;

            exch(a, i, j);
        }

        // put partitioning item v at a[j]
        exch(a, lo, j);

        // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
        return j;
    }

    /***************************************************************************
     *  Helper sorting functions.
     ***************************************************************************/

    // is v < w ?
    private static boolean less(Comparable v, Comparable w) {
        if (v == w) return false;   // optimization when reference equals
        return v.compareTo(w) < 0;
    }

    // exchange a[i] and a[j]
    private static void exch(Object[] a, int i, int j) {
        Object swap = a[i];
        a[i] = a[j];
        a[j] = swap;
    }

    private static Comparable[] genRandArray(int n) {
        Comparable[] array = new Comparable[n];
        for (int i = 0; i < n; i++) {
            array[i] = StdRandom.uniform();
        }
        return array;
    }
}
