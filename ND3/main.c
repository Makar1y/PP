#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void format(char *input, char *output, const int buffer_size) {
   if (input != NULL) {
      int j = 0;

      for (int i = 0; i < buffer_size; ++i) {
         if (i > 0 && input[i-1] == '\0') return;

         if (input[i] == ' ') {
            char pre_char = 2;
            char after_char = 3;

            for (int k = i - 1; k >= 0; --k) {
               if (input[k] != ' ') {
                  pre_char = input[k];
                  break;
               }
            }

            for (int k = i + 1; k < buffer_size; ++k) {
               if (input[k] != ' ') {
                  after_char = input[k];
                  break; 
               }
            }

            if (pre_char == after_char) continue;
         }

         output[j] = input[i];
         ++j;
      }
   }
}


int main(int argc, char **argv) {
   if (argc < 3){
      printf("Program usage: program_name input_file output_file");
      return 0;
   }

   // Input file opening
   FILE *input = fopen(argv[1], "r");
   if(input == NULL) {
      perror(argv[1]);
      return 1;
   }

   // Output file opening
   FILE *output = fopen(argv[2], "w");
   if(output == NULL) {
      perror(argv[2]);
      fclose(input);
      return 1;
   }

   char *buffer_in;
   char *buffer_out;
   buffer_in = malloc(BUFFER_SIZE * sizeof(char));
   buffer_out = malloc(BUFFER_SIZE * sizeof(char));


   while (fgets(buffer_in, BUFFER_SIZE, input) != NULL) {
      format(buffer_in, buffer_out, BUFFER_SIZE);
      fprintf(output, "%s", buffer_out);
   }


   free(buffer_in);
   free(buffer_out);
   fclose(input);
   fclose(output);

   printf("Text successfully formatted and transferred from %s to %s", argv[1], argv[2]);
   return 0;
}