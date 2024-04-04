#include <stdio.h>
#include <stdlib.h>

char *monthConvert(int month) { 
	switch (month){
		case 1:
			return "January";
        	case 2:
            	return "February";
        	case 3:
            	return "March";
        	case 4:
            	return "April";
        	case 5:
            	return "May";
        	case 6:
            	return "June";
        	case 7:
            	return "July";
        	case 8:
            	return "August";
        	case 9:
            	return "September";
        	case 10:
            	return "October";
        	case 11:
            	return "November";
        	case 12:
            	return "December";
        	default:
			return "";
    }
}

int main(void) {
char line[250], date[11], symb = 248; 
	int year, month, hottestM, hottestY, coldestM, coldestY;
      double temperature, hottestT, coldestT;
	
	FILE *out;
	out = fopen("GlobalTemperatures.txt", "r");
	
    if (out == NULL) {
      	printf("Access to 'GlobalTemperatures.txt' was unsuccessful.\n");
      	exit(1);
      }
	
      rewind(out);
    
    sscanf(line, "%10[^,],%lf", date, &temperature); 
    sscanf(date, "%d-%d", &year, &month); 
    
    hottestM = month;
    hottestY = year;
    hottestT = temperature; 
    coldestT = temperature;
    coldestM = month;
    coldestY = year;
        
	while (fgets(line, sizeof(line), out)){
		
      	sscanf(line, "%10[^,],%lf", date, &temperature); 
      	sscanf(date, "%d-%d", &year, &month); 
        
   		if (temperature >= hottestT) {
			hottestT = temperature;
			hottestY = year;
			hottestM = month;
		}
		if (temperature <= coldestT) {
			coldestT = temperature;
			coldestY = year;
			coldestM = month;
		}
}	

	char* hotMonth = monthConvert(hottestM);
	char* coldMonth = monthConvert(coldestM);
	
      printf("Hottest Month was on %s %d with an average Temp of: %.2lf%cC\n", hotMonth, hottestY, hottestT, symb);
      printf("Coldest Month was on %s %d with an average Temp of: %.2lf%cC\n", coldMonth, coldestY, coldestT, symb);

	fclose(out);
	return(0);
}



