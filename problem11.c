#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *source_file = "GlobalTemperatures.csv",
       *destination_file = "GlobalTemperatures.txt", ch;
  char line[250], date[11];
  int year, month;
  double temperature, land_max, land_min, uncertainty1, uncertainty2,
      average_temp, sum_temp, average_min, sum_min, average_max, sum_max,
      avgLandOceanTemp, avgLandOceanUnc;
  double sumOcean, sumOceanLandTemp, finalLandOceanAvg, land_minUnc;
  double average, sum;
  // Accessing files
  FILE *out, *in, *finalIn;

  in = fopen(source_file, "r"); // Opens file to read
  out = fopen(destination_file, "w+"); // Opens to read and write

  // Copy and paste the data in the csv to txt
  while ((ch = fgetc(in)) != EOF) {
    fputc(ch, out);
  }
  fclose(in);

  // Open a new file to write
  finalIn = fopen("problem11.txt", "w");

  // Error message if unable to access source file
  if (out == NULL) {
    printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
    exit(1);
  }

  // Resetting file pointer
  rewind(out);
  fprintf(finalIn, "#Year AverageLandTemp AverageLandOceanTemp\n");
  while (fgets(line, sizeof(line), out)) {

    // Placeholders uncertainty 1 & 2 required to avoid using length modifier
    // with assignment suppression
    // Extracts all the values within the csv file
    sscanf(line, "%10[^,],%lf,%lf,%lf,%lf,%lf,%lf,%lf, %lf", date, &temperature,
           &uncertainty1, &land_max, &uncertainty2, &land_min, &land_minUnc,
           &avgLandOceanTemp,
           &avgLandOceanUnc); 
    sscanf(date, "%d-%d", &year, &month); // Extract year and month from date
    if (month == 1) {                     // A new year started
      if (year > 1850 && year <= 2015) {
        average = sum / 12;
        finalLandOceanAvg = sumOcean / 12;
        fprintf(finalIn, "%d %.3lf %.3lf\n", year - 1, average,
                finalLandOceanAvg);
      }
      // Reset sum values
      sum = 0;
      sumOcean = 0;
    }
    // Add the temperatures to the sum
    sumOcean += avgLandOceanTemp;
    sum += temperature;
  }

  // Print the average temperature for the last year (2015)
  finalLandOceanAvg = sumOcean / 12;
  average = sum / 12;
  fprintf(finalIn, "2015 %.3lf %.3lf\n", average, finalLandOceanAvg);

  // Close the file
  fclose(out);
  return (0);
}

