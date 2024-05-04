#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char line[250], date[11];
	int year;
    double temperature, average_18th, sum_18th, average_19th, sum_19th, average_20th, sum_20th, average_21st, sum_21st;
	
	// Accessing file
	FILE *out;
	out = fopen("GlobalTemperatures.txt", "r");
	
	// Error message if unable to access source file
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
        exit(1);
    }
	
	// Resetting file pointer
    rewind(out);

	// Loop that gathers sum of each century
	while (fgets(line, sizeof(line), out)){
        
        sscanf(line, "%10[^,],%lf", date, &temperature); // Extract date "YYYY-MM-DD" and temperature
        sscanf(date, "%d", &year); // Extract year from date
        
        if (year >= 1760 && year <= 1799) {
            sum_18th += temperature; // Calculate the sum for the current century
        }
        
        else if (year >= 1800 && year <= 1899) {
            sum_19th += temperature; // Calculate the sum for the current year
        }
        
        else if (year >= 1900 && year <= 1999) {
            sum_20th += temperature; // Calculate the sum for the current year
        }
        
        else if (year >= 2000 && year <= 2015) {
            sum_21st += temperature; // Calculate the sum for the current year
        }
    }
    
    // Displaying data
    average_18th = sum_18th / ((1799 - 1760 + 1) * 12); // Calculate average for the century
    printf("Average Temperature for 18th Century: %.3lf\n", average_18th);
    
    average_19th = sum_19th / ((1899 - 1800 + 1) * 12); // Calculate average for the century
    printf("Average Temperature for 19th Century: %.3lf\n", average_19th);
    
    average_20th = sum_20th / ((1999 - 1900 + 1) * 12); // Calculate average for the century
    printf("Average Temperature for 20th Century: %.3lf\n", average_20th);
    
    average_21st = sum_21st / ((2015 - 2000 + 1) * 12); // Calculate average for the century
    printf("Average Temperature for 21st Century: %.3lf\n", average_21st);
    
	fclose(out);
	return(0);
}