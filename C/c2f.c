#include <stdio.h>

/* print Celsius-Fahrenheit table
    for Celsius = 0, 20, ..., 300 */
main()
{
    int f, c;
    int lower, upper, step;
    

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    f = lower;
    printf("%10s%10s\n", "Celsius", "Fahrenheit");
    for(c = lower; c <= upper; c = c + step) {
        f = (c*9)/5 +32;
        printf("%10d%10d\n", c, f);
        
    }
}