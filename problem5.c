 #include <stdio.h>
 #include <stdlib.h>
 
 
 int main(void) {

	char line[20];
	int year, coldYear, hotYear;
	double temp, coldTemp, hotTemp;

	//open file
	FILE *out;
	out = fopen("problem1.txt", "r");
	
    if (fgets(line, sizeof(line), out) == NULL) {
        printf("File is empty.\n");
        exit(1);
    }
	
    rewind(out);
    
	//read first data
    sscanf(line, "%d %lf", &year, &temp);
    coldYear = year;
    hotYear = year; 
    coldTemp = temp;
    hotTemp = temp;
    
	//determine hottest and coldest years
	while (fgets(line, sizeof(line), out)){
		
        sscanf(line, "%d %lf", &year, &temp); 
        if (temp > hotTemp) {
			hotYear = year;
			hotTemp = temp;
		}
		if (temp < coldTemp) {
			coldYear = year;
			coldTemp = temp;
		}
	}	

	//prints final answer
	printf("The coldest year was %d\n", coldYear);
	printf("The hottest year was %d", hotYear);

	fclose(out);
	
	return(0);
}
