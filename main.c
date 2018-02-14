//*********************************************
//
//	Author:			Beau Shirdavani
//	Date:			2-14-2018
//	Descritption:	CS 351 - HW 02
//					read contacts list from .txt
//					convert to contacts data type in C
//
//*********************************************

#include <stdio.h>

int main()
{
   printf("\tHello, World!\n");

   // read the text file
   FILE *file;
   char f_name[24];
   char l_name[24];
   int day;
   int mo;
   int yr;

   file = fopen("contacts.txt", "r");
   if (file == 0){
  	printf("\tfile not found...\n");
   }

   while (fscanf(file, "%s %s %d-%d-%d", &f_name, &l_name, &day, &mo, &yr) >1){
   	printf("%s %s %d %d %d\n", f_name, l_name, day, mo, yr);
   }
   if (! feof(file)){
   	printf("ERROR\n");
   }
   fclose(file);

   return 0;
}
