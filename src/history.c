#include "history.h"


enum 
{
TYPE,
NOM,
DATE,

COLUMNS
};
void showtreehistory(GtkWidget *liste){
char verifcustomer[30];
FILE *t=fopen("instantcustomer.txt","r");
fscanf(t,"%s",verifcustomer);fclose(t);
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;
char type[30];
char nom[30];
char date [30];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" type", renderer, "text",TYPE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f = fopen("history.txt","r");
char v[30];int e;
if(f==NULL) return;
else 
	{
f = fopen("history.txt", "a+");
	while(fscanf(f,"%s %s %s %d %s\n",type,nom,date,&e,v)!=EOF) if ((e==0) && strcmp(verifcustomer,v)==0)
				{
gtk_list_store_append(store, &iter);
gtk_list_store_set (store,&iter, TYPE, type, NOM , nom, DATE, date, -1);  }
		fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
	 }
}
}




/*void deletehistory(char p[]){
FILE *f=fopen("instantcustomer.txt","r");char verifcustomer[30];fscanf(f,"%s\n",verifcustomer);fclose(f);
 char type[30];
 char nom[30];
 char date[30]; int prix; int b;char customer[30];
FILE *u=fopen("history.txt","r");
FILE *t=fopen("historytempo.txt","a+");
if (u!=NULL)
{
while(fscanf(u,"%s %s %s %d %s\n",type,nom,date,&b,customer)!=EOF)
{
if (strcmp(nom,p)!=0 || strcmp(customer,verifcustomer)!=0)
{
fprintf(t,"%s %s %s %d %s\n",type,nom,date,b,customer);
}
}
}
fclose(u);
fclose(t);
remove("history.txt");
rename("historytempo.txt","history.txt");


} */
