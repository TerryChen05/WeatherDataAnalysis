#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char line[250], date[11];
	int year, month;
    double temperature, land_max, land_min, uncertainty1, uncertainty2, average_temp, sum_temp, average_min, sum_min, average_max, sum_max;
	
	// Accessing files
	FILE *out, *in;
	out = fopen("GlobalTemperatures.txt", "r");
	in = fopen("problem8_data.dat", "w");
	
	// Error message if unable to access source file
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
        exit(1);
    }
	
	// Resetting file pointer
    rewind(out);

	while (fgets(line, sizeof(line), out)){
        
        // Placeholders uncertainty 1 & 2 required to avoid using length modifier with assignment suppression
        sscanf(line, "%10[^,],%lf,%lf,%lf,%lf,%lf", date, &temperature, &uncertainty1, &land_max, &uncertainty2, &land_min); // Extract date "YYYY-MM-DD", temperature, land maximum temperature, and minimum temperature
        sscanf(date, "%d-%d", &year, &month); // Extract year and month from date
        
        if (month == 1) { // A new year started
                if (year > 1850 && year <= 2015) {
					average_temp = sum_temp / 12; // Calculate average for the previous year
					average_max = sum_max / 12;
					average_min = sum_min / 12;
					fprintf(in, "%d %.3lf %.3lf %.3lf\n", year - 1, average_temp, average_max, average_min);
                }
                sum_temp = 0; // Reset sum to calculate the next year 
                sum_max = 0;
                sum_min = 0;
            }
            sum_temp += temperature; // Calculate the sum for the current year
            sum_max += land_max;
            sum_min += land_min;
        }

    // Print the average temperature for the last year (2015)
    average_temp = sum_temp / 12;
	average_max = sum_max / 12;
	average_min = sum_min / 12;
    fprintf(in, "2015 %.3lf %.3lf %.3lf\n", average_temp, average_max, average_min);
        
	fclose(out);

	return(0);
}



