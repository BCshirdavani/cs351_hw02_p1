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
   	
   	printf("%s %s %d %d %d\n", f_name, l_name, day, mo, yr);

   	// put the text file data into the array of structures
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
   	printf("\n\tyear: %d",c_list[i].c_date.d_yr);
   	printf("\n");

   	printf("loop: %d" , i);
   	printf("\n");
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

  	// filter and print ages
  	int k = 0;
  	for (k = 0; k < 15; k++){
  		if ( ((c_list[k].c_date.d_yr) != NULL) && ((2018 - (c_list[k].c_date.d_yr) ) > 17) && ((2018 - (c_list[k].c_date.d_yr) ) < 25)){
  			printf("\t");
  			printf("name: %s", c_list[k].fName);
  			printf("\t\t");
  			printf("age: %d", (2018 - (c_list[k].c_date.d_yr)));
  			printf("\n");
  		}
  	}

   return 0;
}
