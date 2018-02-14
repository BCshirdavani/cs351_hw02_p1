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
   printf("\nHello, World!\n");

   // read the text file
   FILE *ptr_file;
   char buf[50];

   ptr_file = fopen("contacts.txt", "r");
   if (!ptr_file){
   	return 1;
   }

   while (fgets(buf, 50, ptr_file) != NULL){
   	printf("%s\n", buf );
   }

   fclose(ptr_file);


   return 0;
}
