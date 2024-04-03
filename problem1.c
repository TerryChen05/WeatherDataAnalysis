#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    FILE *in, *out;
    char *source_file = "GlobalTemperatures.csv", *destination_file = "GlobalTemperatures.txt", line[250], date[11], ch;
    int year, month;
    double temperature, average, sum;
    
    in = fopen(source_file, "r");
    out = fopen(destination_file, "w+"); // Opens to read and write
    
    // Error message if unable to access source file
    if (in == NULL) {
        printf("Access to '%s' unsuccessful.\n", source_file);
        exit(1);
    }
	
	// Copy-Pasting data from source file to destination file 
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }
    fclose(in);

	// Resetting file pointer
    rewind(out);

     while (fgets(line, sizeof(line), out)) {
        
        // Divide the line to extract date and temperature
        if (sscanf(line, "%10[^,],%lf", date, &temperature) == 2) {
            
            // Extract the year from the date
            sscanf(date, "%d-%d", &year, &month);
            if (month == 1) { // A new year started
                if (year > 1760 && year <= 2015) {
					average = sum / 12; // Calculate average for the previous year
					printf("Year: %d, Average Temperature: %.3lf\n", year - 1, average);
                }
                sum = 0; // Reset sum to calculate the next year 
            }
            sum += temperature; // Calculate the sum for the current year
        }
    }

    // Print the average temperature for the last year (2015)
    average = sum / 12;
    printf("Year: 2015, Average Temperature: %.3lf\n", average);
    
    
    fclose(out);

}