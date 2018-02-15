//*********************************************
//
//	Author:			Beau Shirdavani
//	Date:			2-14-2018
//	Descritption:	CS 351 - HW 02
//					read contacts list from .txt
//					convert to contacts data type in C
//
//*********************************************

//	__DATE__:is the current date

#include <stdio.h>
#include <string.h>

// date structure
struct date
{
    int d_day;
    int d_mo;
    int d_yr;
};
// contact structure, with nested date structure
struct contact
{
    char fName[15];
    char lName[15];
    struct date c_date;
};




int main()
{
   printf("\tHello, World!\n");

   // read the text file
   FILE *file;
   char f_name[15];
   char l_name[15];
   int day;
   int mo;
   int yr;
   // make array of contact structures
   struct contact c_list[100];

   file = fopen("contacts.txt", "r");
   if (file == 0){
  	printf("\tfile not found...\n");
   }

   int i = 0;
   while (fscanf(file, "%s %s %d-%d-%d", &f_name, &l_name, &day, &mo, &yr) >1){
   	// put the text file data into the array of structures
   	printf("%s %s %d %d %d\n", f_name, l_name, day, mo, yr);
   	// printf("%s %s %d %d %d\n", f_name, l_name, day, mo, yr);

   	// strcpy(c_list[i].fName, f_name);
   	// strcpy(c_list[i].lName, l_name);
   	// memcpy(c_list[i].c_date.d_day, day, 2);
   	// memcpy(c_list[i].c_date.d_mo, mo, 2);
   	// memcpy(c_list[i].c_date.d_yr, yr, 2);


   	// using loop below for each char element in the string names
   	// c_list[i].fName = f_name;
   	// c_list[i].lName = l_name;
   	c_list[i].c_date.d_day = day;
   	c_list[i].c_date.d_mo = mo;
   	c_list[i].c_date.d_yr = yr;

   	int j = 0;
   	for (j = 0; j < 15; j++){
   		c_list[i].fName[j] = f_name[j];
   		c_list[i].lName[j] = l_name[j];
   	}

   	printf("\t");
   	printf(c_list[i].fName);
   	printf("\t");
   	// printf(c_list[i].c_date.d_yr);
   	printf("\n");

   	// printf("i:");
   	// printf(i);
   	// printf("\n");

   	// increment the counter, for the next array element
   	i = i + 1;
   }
   if (! feof(file)){
   	printf("ERROR\n");
   }
   fclose(file);

	printf("Date is: ");
  	printf(__DATE__);
  	printf("\n");


  	int k = 0;
  	// for (k = 0; k < 100; k++){
  	// 	if ( (c_list[k].c_date.d_yr - 2018) > 20 ){
  	// 		printf("\t");
  	// 		printf(c_list[k].fName);
  	// 		printf("\t");
  	// 		printf(c_list[k].c_date.d_yr - 20);
  	// 		printf("\n");
  	// 	}
  	// }

   return 0;
}
