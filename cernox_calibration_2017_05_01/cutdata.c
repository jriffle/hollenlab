#include <stdio.h>

#define N 200 //integer spacing for data line selection
#define old_data_set "calibration.asc" //file to pull the data from
#define new_data_set "partialdata.asc" //new file to write to

int main()
{
  int n;
  int lines, ch, count = 0;
  
  remove(new_data_set);//remove last updated file so appending doesn't continue
  
  char str[25];
  FILE *fnew = fopen(new_data_set, "a+");//open new file to write to
  FILE *fold = fopen(old_data_set, "r");//point the file to read

  if (N%2 == 0) {
    n = N + 1;
  } else {
    n = N;
  }    

  do {
    ch = fgetc(fold);
    if(ch == '\n') {
      lines++;
    }
  } while (ch != EOF);//count the number of lines in the old file

  if (ch != '\n' && lines != 0) {
    lines++;
  } 

  printf("\nOld file %s: %d lines.\n", old_data_set, lines);
  rewind(fold);

  int i = 2;
  for (i; i < lines; i++) { 
    fgets(str, 25, fold);//read the file string by string
    if (i%n == 1) {
      fprintf(fnew, "%s", str);//print every Nth line to the new file
      count++;    
    }
  }
  printf("New file %s: %d lines.\n\n", new_data_set, count);
  return 0;
}   
