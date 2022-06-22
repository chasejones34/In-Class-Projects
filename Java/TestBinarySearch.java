/* *****************************************************************************
 *  Name:    Chase Jones
 *  PCID:    000324186
 *  Assignment:  Lab 10
 *
 *  Description: Write a test client for BinarySearchST that tests the
 *  implementations of min(), max(), floor(), ceiling(), select(), rank(),
 *  deleteMin(), deleteMax(), and keys() that are given in the text.
 *
 **************************************************************************** */

package Lab;

import edu.princeton.cs.algs4.BinarySearchST;
import edu.princeton.cs.algs4.StdOut;

public class TestBinarySearch {
    public static void main(String[] args) {
        //Build Symbol Table

        BinarySearchST<Double, String> st = new BinarySearchST<Double, String>();

        //populate Symbol Table

        st.put(62.69, "The_Weekend");
        st.put(61.46, "Drake");
        st.put(57.31, "Justin Beiber");
        st.put(55.74, "J Balvin");
        st.put(54.39, "Dua Lipa");
        st.put(51.88, "Cardi B");
        st.put(50.77, "Ed Sheeran");
        st.put(49.93, "Ariana Grande");
        st.put(49.35, "Marshmello");
        st.put(48.38, "Khalid");

        //Demonstrates all the comperable induced methods, display/exlain results

        StdOut.println(
                "Least Ammount of Plays: " + st.min() + " million. Artist: " + st.get(st.min()));
        StdOut.println(
                "Most Ammount of Plays: " + st.max() + " million. Artist: " + st.get(st.max()));
        StdOut.println("Closest to reaching 50 million plays: " + st.floor(50.00) + st
                .get(st.floor(50.00)));
        StdOut.println("Most recently surpassing 50 million plays: " + st.ceiling(50.00) + st
                .get(st.ceiling(50.00)));
        StdOut.println("Artist with the 3rd most plays: " + st.select(3) + st.get(st.select(3)));
        StdOut.println("Ammount of artists with plays less than Ed Sheeran: " + st.rank(50.77));
        StdOut.println("Plays count between 50 and 60 million: " + st.keys(50.00, 60.00));
        StdOut.println("After deleting the top artist, the list of listens now looks like: ");
        st.deleteMax();
        for (double plays : st.keys()) {
            StdOut.println(plays);
        }

        //Adding the top artist back
        st.put(62.69, "The_Weekend");

        StdOut.println("After deleting the bottom artist, the list of listens now looks like: ");
        st.deleteMin();
        for (double plays : st.keys()) {
            StdOut.println(plays);
        }
    }
}
