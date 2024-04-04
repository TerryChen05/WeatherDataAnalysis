#include <stdio.h>

int main()
{
    FILE *file;
    FILE *dataF;
    int years[1000];
    double temp[1000];
    

    file = fopen ("problem1.txt", "r");
    dataF = fopen ("DATA.txt", "w");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    
    return 0;
}
