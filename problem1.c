#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    FILE *in, *out;
    char *source_file = "GlobalTemperatures.csv", *destination_file = "GlobalTemperatures.txt", line[250], date[11], ch;
    int year, month;
    double temperature, average, sum;
    
    in = fopen(source_file, "r");
    out = fopen(destination_file, "w+"); 
    
    if (in == NULL) {
        printf("Access to '%s' unsuccessful.\n", source_file);
        exit(1);
    }
	
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }
    fclose(in);

    rewind(out);

     while (fgets(line, sizeof(line), out)) {
        
        if (sscanf(line, "%10[^,],%lf", date, &temperature) == 2) {
            
            sscanf(date, "%d-%d", &year, &month);
            if (month == 1) { 
                if (year > 1760 && year <= 2015) {
					average = sum / 12; 
					printf("Year: %d, Average Temperature: %.3lf\n", year - 1, average);
                }
                sum = 0; 
            }
            sum += temperature;
        }
    }

    average = sum / 12;
    printf("Year: 2015, Average Temperature: %.3lf\n", average);
    
    
    fclose(out);

}