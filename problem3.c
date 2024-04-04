#include <stdio.h>
#include <stdlib.h>


int main(void) {
    FILE *out;
    char line[250], date[11], symb=248;
    int year, month;
    double temperature, total_years, jan_sum, feb_sum, mar_sum, apr_sum, may_sum, jun_sum, jul_sum, aug_sum, sep_sum, oct_sum, nov_sum, dec_sum ;
   
    out = fopen("GlobalTemperatures.txt", "r"); // Opens to read and write
   
    // Error message if unable to access source file
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
        exit(1);
    }


    // Resetting file pointer & variables
    rewind(out);
    temperature = 0;


    while (fgets(line, sizeof(line), out)) {
       
        // Divide the line to extract date and temperature
        if (sscanf(line, "%10[^,],%lf", date, &temperature) == 2) {
           
            // Extract the year from the date
            sscanf(date, "%d-%d", &year, &month);
           
            if (year >= 1900 && year <= 2015) {
                if (month == 1) { // January
                    jan_sum += temperature;
                } else if (month == 2) { // February
                    feb_sum += temperature;
                } else if (month == 3) {
                    mar_sum += temperature;
                } else if (month == 4) {
                    apr_sum += temperature;
                } else if (month == 5) {
                    may_sum += temperature;
                } else if (month == 6) {
                    jun_sum += temperature;
                } else if (month == 7) {
                    jul_sum += temperature;
                } else if (month == 8) {
                    aug_sum += temperature;
                } else if (month == 9) {
                    sep_sum += temperature;
                } else if (month == 10) {
                    oct_sum += temperature;
                } else if (month == 11) {
                    nov_sum += temperature;
                } else if (month == 12) {
                    dec_sum += temperature;
                }
               
            }
        }
    }


    total_years = (2015-1900+1);


    printf("The January Average is: %.3lf%cC\n", jan_sum/total_years, symb);
    printf("The February Average is: %.3lf%cC\n", feb_sum/total_years, symb);
    printf("The March Average is: %.3lf%cC\n", mar_sum/total_years, symb);
    printf("The April Average is: %.3lf%cC\n", apr_sum/total_years, symb);
    printf("The May Average is: %.3lf%cC\n", may_sum/total_years, symb);
    printf("The June Average is: %.3lf%cC\n", jun_sum/total_years, symb);
    printf("The July Average is: %.3lf%cC\n", jul_sum/total_years, symb);
    printf("The August Average is: %.3lf%cC\n", aug_sum/total_years, symb);
    printf("The September Average is: %.3lf%cC\n", sep_sum/total_years, symb);
    printf("The October Average is: %.3lf%cC\n", oct_sum/total_years, symb);
    printf("The November Average is: %.3lf%cC\n", nov_sum/total_years, symb);
    printf("The December Average is: %.3lf%cC\n", dec_sum/total_years, symb);


    fclose(out);
   
    return(0);
}

