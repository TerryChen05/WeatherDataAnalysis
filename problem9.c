#include <stdio.h>
#include <stdlib.h>

int main (void) {

	char line[250], date[11];
	double avgTemp, avgUnc, maxTemp, maxUnc, minTemp;
	int year, month;
	int count = 0;
	
	FILE *in, *out;

	out = fopen("GlobalTemperatures.txt", "r");
    in = fopen("prob9.dat", "w");
    
    if (out == NULL) {
        printf("Access to Data unsuccessful.\n");
        exit(1);
    }

	rewind(out);
	
	double centuryAvg = 0, centuryMin = 0, centuryMax = 0;
	
	while (fgets(line, sizeof(line), out)){
		if ((year == 1849 && month == 12) || (year == 1999 && month == 12) || (year == 1899 && month == 12)){
			count = 1;
			centuryAvg = 0;
			centuryMin = 0;
			centuryMax = 0;
		}
			
        sscanf(line, "%10[^,],%lf,%lf,%lf,%lf,%lf", date, &avgTemp, &avgUnc, &maxTemp, &maxUnc, &minTemp); 
        sscanf(date, "%d-%d", &year, &month); 

        centuryAvg += avgTemp;
        centuryMin += minTemp;
        centuryMax += maxTemp;

        if((year == 1899 && month == 12) || (year == 1999 && month == 12) || (year == 2015 && month == 12)) {

			centuryAvg = centuryAvg/count;
	        centuryMin = centuryMin/count;
			centuryMax = centuryMax/count;
			if (year == 1899)
				fprintf(in, "19th\t");
			else if (year == 1999)
				fprintf(in, "20th\t");
			else if (year == 2015)
				fprintf(in, "21st\t");
			fprintf(in, "%lf\t%lf\t%lf\n", centuryAvg, centuryMax, centuryMin);
		}
		count++;
	}	
	
	fclose(in);
	fclose(out);

	return 0;
}

