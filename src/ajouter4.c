#include"ajouter4.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ajouter4(char ref[],char depart[],char arriver[],char date_aller[],char date_arriver[],char price[])
{

FILE *f;
f=fopen("users4.txt","a+");
if(f!=NULL){

fprintf(f,"%s %s %s %s %s %s\n",ref,depart,arriver,date_aller,date_arriver,price);
fclose(f);}
}
