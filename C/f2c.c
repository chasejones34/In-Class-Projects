#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
main()
{
    int fahr, celsius;
    int lower, upper, step;
    

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    printf("%10s%10s\n", "Fahrenheit", "Celsius");
    for(fahr = lower; fahr <= upper; fahr = fahr + step) {
        celsius = 5 * (fahr-32) / 9;
        printf("%10d%10d\n", fahr, celsius);
        
    }
}