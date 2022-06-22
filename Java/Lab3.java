/* *****************************************************************************
 *  Name:    Chase Jones
 *  PCID:    000324186
 *  Assignment:     Lab3
 *
 *  Description:  Prints 'Hello, World' to the terminal window.
 *                By tradition, this is everyone's first program.
 *                Prof. Brian Kernighan initiated this tradition in 1974.
 *
 **************************************************************************** */

package Lab;

public class Lab3 {
    public static void main(String[] args) {


    }

    public static int count(int[] a) {
        int n = a.length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        if (a[i] + a[j] + a[k] + a[l] == 0) {
                            count++;
                        }
                    }
                }
            }
            return count;
        }
    }
}
