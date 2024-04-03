#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(void) {

    FILE *out;

    char line[250], date[11], symb=248;
    int year, month;
    double temperature, total_years, jan_sum, feb_sum, mar_sum, apr_sum, may_sum, jun_sum, jul_sum, aug_sum, sep_sum, oct_sum, nov_sum, dec_sum ;
   
    out = fopen("GlobalTemperatures.txt", "r"); 
   
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
        exit(1);
    }

    rewind(out);


    fclose(out);

    return 0;


}