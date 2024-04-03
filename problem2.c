#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char line[250], date[11];
	int year;
    double temperature, average_18th, sum_18th, average_19th, sum_19th, average_20th, sum_20th, average_21st, sum_21st;
	
	FILE *out;
	out = fopen("GlobalTemperatures.txt", "r");
	
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
        exit(1);
    }
	
    rewind(out);

	while (fgets(line, sizeof(line), out)){
        
        sscanf(line, "%10[^,],%lf", date, &temperature); 
        sscanf(date, "%d", &year); 
        
        if (year >= 1760 && year <= 1799) {
            sum_18th += temperature;
        }
        
        else if (year >= 1800 && year <= 1899) {
            sum_19th += temperature;
        }

        else if (year >= 1900 && year <= 1999) {
            sum_20th += temperature; 
        }
        
        else if (year >= 2000 && year <= 2015) {
            sum_21st += temperature; 
        }
    }
    
    average_18th = sum_18th / ((1799 - 1760 + 1) * 12); 
    printf("Average Temperature for 18th Century: %.3lf\n", average_18th);
    
    average_19th = sum_19th / ((1899 - 1800 + 1) * 12); 
    printf("Average Temperature for 19th Century: %.3lf\n", average_19th);
    
    average_20th = sum_20th / ((1999 - 1900 + 1) * 12); 
    printf("Average Temperature for 20th Century: %.3lf\n", average_20th);
    
    average_21st = sum_21st / ((2015 - 2000 + 1) * 12); 
    printf("Average Temperature for 21st Century: %.3lf\n", average_21st);
    
	fclose(out);
	return(0);
}