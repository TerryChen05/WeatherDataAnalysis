#include <stdio.h>

int main()
{
    // Varaible declarations
    FILE *file;
    FILE *dataF;
    int years[1000];
    double temp[1000];
    
    // Open the file and read it
    // Open the file and write to it
    file = fopen ("problem1.txt", "r");
    dataF = fopen ("problem7_data.dat", "w");
    
    // Tries to open the file and if it cannot be opened then an error will show up
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    // Scans for all the years and temperatures and stores them in an array
    fprintf(dataF,"Years\t19th\t20th\n");
    for (int i = 0; i < 500; i++){
        fscanf(file, "%d %lf", &years[i], &temp[i]);
    }
    // Takes 19th and 20th century temperatures and outputs it
    for (int i = 0; i < 200; i++){
        if (years[i] >= 1799 && years[i] <= 1899) {
            fprintf(dataF, "%d %lf %lf\n", i-39, temp[i], temp[i + 100]);
        } 
    }
    return 0;
}

