#include "suprimer4.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>







void suprimer4(char ref[])
{

	char REF[100];
	char DEPART[100];
	char ARRIVER[100];
	char DATEALLER[100];
	char DATERETOUR[100];
	char PRICES[100];

FILE *u=fopen("users4.txt","r");
FILE *t=fopen("tamp.txt","a+");
if (u!=NULL)
{
while(fscanf(u,"%s %s %s %s %s %s\n",REF,DEPART,ARRIVER,DATEALLER,DATERETOUR,PRICES)!=EOF)
{
if (strcmp(REF,ref)!=0)
{
fprintf(t,"%s %s %s %s %s %s \n",REF,DEPART,ARRIVER,DATEALLER,DATERETOUR,PRICES);
}
}
}
fclose(u);
fclose(t);
remove("users4.txt");
rename("tamp.txt","users4.txt");
}
