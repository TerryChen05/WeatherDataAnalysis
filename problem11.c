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
  FILE *out, *in, *finalIn;

  in = fopen(source_file, "r");
  out = fopen(destination_file, "w+"); 

  while ((ch = fgetc(in)) != EOF) {
    fputc(ch, out);
  }
  fclose(in);

  finalIn = fopen("problem11.txt", "w");

  if (out == NULL) {
    printf("Access to 'GlobalTemperatures.txt' unsuccessful.\n");
    exit(1);
  }

  rewind(out);
  fprintf(finalIn, "#Year AverageLandTemp AverageLandOceanTemp\n");
  while (fgets(line, sizeof(line), out)) {

    sscanf(line, "%10[^,],%lf,%lf,%lf,%lf,%lf,%lf,%lf, %lf", date, &temperature,
           &uncertainty1, &land_max, &uncertainty2, &land_min, &land_minUnc,
           &avgLandOceanTemp,
           &avgLandOceanUnc); 
    sscanf(date, "%d-%d", &year, &month); 
    if (month == 1) {                     
      if (year > 1850 && year <= 2015) {
        average = sum / 12;
        finalLandOceanAvg = sumOcean / 12;
        fprintf(finalIn, "%d %.3lf %.3lf\n", year - 1, average,
                finalLandOceanAvg);
      }
      sum = 0;
      sumOcean = 0;
    }
    sumOcean += avgLandOceanTemp;
    sum += temperature;
  }

  finalLandOceanAvg = sumOcean / 12;
  average = sum / 12;
  fprintf(finalIn, "2015 %.3lf %.3lf\n", average, finalLandOceanAvg);

  fclose(out);
  return (0);
}
