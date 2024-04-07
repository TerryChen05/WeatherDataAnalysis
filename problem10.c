#include <stdio.h>
#include <stdlib.h>


int main (void) {
	char line[250], date[11];
	double temperature, uncertainty;
	int year;
	FILE *in, *out;

	out = fopen("GlobalTemperatures.txt", "r");
    in = fopen("prob10.dat", "w");
    
    if (out == NULL) {
        printf("Access to Data unsuccessful.\n");
        exit(1);
    }

	rewind(out);

	while (fgets(line, sizeof(line), out)){
		
        sscanf(line, "%10[^,],%lf,%lf", date, &temperature, &uncertainty); 
        sscanf(date, "%d", &year); 
        if (year >= 2000 && year <= 2014) {
			fprintf(in, "%s\t%lf\t%lf\n", date, temperature, uncertainty);
		}
	}	
	fclose(in);
	fclose(out);
	
	return 0;
}
