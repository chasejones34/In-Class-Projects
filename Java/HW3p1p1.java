/* *****************************************************************************
 *  Name:    Chase Jones
 *  PCID:    000324186
 *  Assignment:     Set 1
 *
 *  Description:  Write a client that creates a symbol table mapping letter
 * grades to numerical scores, as in the table below, then reads from standard
 * input a list of letter grades andcomputes and prints the GPA (the average of
 * the numbers corresponding to the grades).
 *
 **************************************************************************** */

package Lab;

import edu.princeton.cs.algs4.ST;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class HW3p1p1 {
    public static void main(String[] args) {
        ST<String, Double> grades = new ST<>();
        grades.put("A+", 4.33);
        grades.put("A", 4.00);
        grades.put("A-", 3.67);
        grades.put("B+", 3.33);
        grades.put("B", 3.00);
        grades.put("B-", 2.67);
        grades.put("C+", 2.33);
        grades.put("C", 2.00);
        grades.put("C-", 1.67);
        grades.put("D", 1.00);
        grades.put("F", 0.00);

        String[] myGrades = StdIn.readAllLines();
        double average = 0.0;
        for (String eachGrade : myGrades) {
            average += grades.get(eachGrade);

        }
        average /= myGrades.length;
        StdOut.println("GPA = " + average);
    }
}
