#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 10          // data size
#define FREQ_SIZE 1000   // upper bound for values
 
// input: 
//    user enters 10 non-negative integers
// output: 
//    report how many times each unique value occured,
//    display values and occurence times in ascending order
 
int main() {
   
   int inputArray[SIZE] = { 0 };
   int frequency[FREQ_SIZE + 1] = { 0 };
   int diffNums[SIZE] = { 0 };
   int num, counter = 0;
 
   // report what the program does
   printf("Please enter 10 non-negative integers (1 at a time).\n");
 
   // ask to enter 10 numbers 
   printf("Number must be from 0 to 1000.");
 
   while(counter < SIZE){
      // ask to enter the following number
      printf("\n\nEnter %d number: ", counter+1);
      if((scanf("%d", &num) == 1) && (getchar() == '\n')){
         if ((num >= 0) && (num <=FREQ_SIZE)){
            inputArray[counter++] = num;
            // report that number entered successfully
            printf("Number %d entered successfully.");
         } else {
            // report that value exceeds bounds and has to belong to [0; FREQ-SIZE]
            printf("Invalid number(exceeds bounds)! Please enter number from 0 to %d.", FREQ_SIZE);
         }
      } else {
         // report invalid input, ask to enter whole non-negative number again
         printf("Invalid input! Please enter whole non-integer number.");
         while(getchar() != '\n');
      }
   }
   
   // report that data has been entered correctly
   printf("\n\nAll data entered. Results:\n");
   
   // proceeding to computations...
   
   for(int i=0; i<SIZE; i++){
        frequency[ inputArray[i] ]++;
   }
 
   int flag;
   int diffNumsCounter = 0;
 
   for(int i=0; i<SIZE; i++){
      flag=1;
      for(int j=0; j<i; j++){
         if(inputArray[i] == inputArray[j]){
            flag=0;
         }        
      }       
      if(flag){
         diffNums[diffNumsCounter] = inputArray[i];
         diffNumsCounter++;
      }
   }
 
   int temp;
 
   for(int j=0; j<diffNumsCounter-1; j++){
      for(int i=0; i<diffNumsCounter-j-1; i++){
         if(diffNums[i] > diffNums[i+1]){
            temp = diffNums[i];
            diffNums[i] = diffNums[i+1];
            diffNums[i+1] = temp;
         }
      }
   }
 
   // report that results will be reported
   printf("Number          Frequency\n");

   for(int i=0; i<diffNumsCounter; i++){
      if( frequency[ diffNums[i] ] != 0 ){

         // report the value of diffNums[i] and the value of frequency[diffNums[i]]
         if (diffNums[i]<10) {
            printf("     %d ................ %d\n", diffNums[i], frequency[diffNums[i]]);
         } else if (diffNums[i]<100) {
            printf("    %d ................ %d\n", diffNums[i], frequency[diffNums[i]]);
         } else if (diffNums[i]<1000) {
            printf("   %d ................ %d\n", diffNums[i], frequency[diffNums[i]]);
         } else {
            printf("  %d ................ %d\n", diffNums[i], frequency[diffNums[i]]);
         }}
      }

   getchar();
   return 0;
}