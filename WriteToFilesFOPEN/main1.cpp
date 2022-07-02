#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;

   printf("Enter num: ");
   scanf("%d\n",&num);

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("test.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }


   fprintf(fptr,"%d\n",num);
   fclose(fptr);

   return 0;
}
