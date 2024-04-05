#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char line[250], date[11];
	int year, month;
    double temperature, land_max, land_min, uncertainty1, uncertainty2, average_temp, sum_temp, average_min, sum_min, average_max, sum_max;
	
	FILE *out, *in;
	out = fopen("GlobalTemperatures.txt", "r");
	in = fopen("problem8_data.dat", "w");
	
    if (out == NULL) {
        printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
        exit(1);
    }
	
    rewind(out);

	while (fgets(line, sizeof(line), out)){
        
        sscanf(line, "%10[^,],%lf,%lf,%lf,%lf,%lf", date, &temperature, &uncertainty1, &land_max, &uncertainty2, &land_min); 
        sscanf(date, "%d-%d", &year, &month); 
        
        if (month == 1) { 
                if (year > 1850 && year <= 2015) {
					average_temp = sum_temp / 12; 
					average_max = sum_max / 12;
					average_min = sum_min / 12;
					fprintf(in, "%d %.3lf %.3lf %.3lf\n", year - 1, average_temp, average_max, average_min);
                }
                sum_temp = 0;
                sum_max = 0;
                sum_min = 0;
            }
            sum_temp += temperature; 
            sum_max += land_max;
            sum_min += land_min;
        }
    
    average_temp = sum_temp / 12;
	average_max = sum_max / 12;
	average_min = sum_min / 12;
    fprintf(in, "2015 %.3lf %.3lf %.3lf\n", average_temp, average_max, average_min);
        
    
    

    
	fclose(out);
	return(0);
}

