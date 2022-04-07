#include "allfunctions.h"

void add_member(MEMBER a)
{
	// add in members.txt
	FILE *f;
	f=fopen("members.txt","a");
	fprintf(f,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, a.password, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, a.nationalid, a.status);
	fclose(f);
	// add in users.txt
	FILE *f1;
	f1=fopen("users.txt","a");
	fprintf(f1,"%s %s %d 1\n",a.email,a.password,a.role);
	fclose(f1);
}

int SamePassword(char p1[], char p2[])
{
	if(strcmp(p1,p2)!=0){return 0;}
	else{return 1;}
}


int get_members_mails(char emails[50][50])
{
	FILE *f;
	f=fopen("members.txt","r");
	MEMBER a;
	int i=0;
	while(fscanf(f,"%d %s %s %s %s %d/%d/%d %s %s %d",&a.role, a.email, a.password, a.name, a.fname, &a.bdate.day, &a.bdate.month, &a.bdate.year, a.phonenumber, a.nationalid, &a.status)!=EOF)
	{
		strcpy(emails[i],a.email);
		i++;
	}
	fclose(f);
	return i;
	
}
int get_agents_mails(char emails[50][50])
{
	FILE *f;
	f=fopen("members.txt","r");
	MEMBER a;
	int i=0;
	while(fscanf(f,"%d %s %s %s %s %d/%d/%d %s %s %d",&a.role, a.email, a.password, a.name, a.fname, &a.bdate.day, &a.bdate.month, &a.bdate.year, a.phonenumber, a.nationalid, &a.status)!=EOF)
	{
		if(a.role==2)
		{
			strcpy(emails[i],a.email);
			i++;
		}
	}
	fclose(f);
	return i;
	
} 


int valid_email(char email[])
{
	int n = strlen(email);
	if(n<5){return 0;}
	int atcounter=0,ptcounter=0;
	for(int i=0;i<n;i++)
	{
		if(email[i]=='@'){++atcounter;}
		if(email[i]=='.'){++ptcounter;}
	}
	if((atcounter!=1) || (ptcounter==0 || ptcounter>2)){return 0;}
	return 1;
}

int count_members(int role)
{
	FILE *f;
	MEMBER a;
	int counter=0;
	f=fopen("members.txt","r");
	while(fscanf(f,"%d %s %s %s %s %d/%d/%d %s %s %d",&a.role, a.email, a.password, a.name, a.fname, &a.bdate.day, &a.bdate.month, &a.bdate.year, a.phonenumber, a.nationalid, &a.status)!=EOF)
	{
		if(a.role==role){++counter;}
	}
	fclose(f);
	return counter;
}

int count_clients()
{
	FILE *f;
	int counter = 0;
	f=fopen("usersappend.txt","r");
	char str[200];
	while(fgets(str,200,f)!=NULL)
	{
		++counter;
	}
	fclose(f);
	return counter;
}

//the idea: store email on login @currentuser.txt, delete on logout.

int find_current_user(MEMBER *a) // 1:user found , 0:user not found
{
	FILE *f1;
	f1=fopen("instantcustomer.txt","r");
	char ch[90];
	fscanf(f1,"%s",ch);
	fclose(f1);
	FILE *f2;
	f2 = fopen("members.txt","r");
	while(fscanf(f2,"%d %s %s %s %s %d/%d/%d %s %s %d",&a->role, a->email, a->password, a->name, a->fname, &a->bdate.day, &a->bdate.month, &a->bdate.year, a->phonenumber, a->nationalid, &a->status)!=EOF)
	{
		if(strcmp(a->email,ch)==0)
		{
			fclose(f2);
			return 1;
		}
	}
	fclose(f2);
	return 0;
	
}

int find_current_user1(userprotect1 *a) // 1:user found , 0:user not found //for change settings client
{
	FILE *f1;
	f1=fopen("instantcustomer.txt","r");
	char ch[90];
	fscanf(f1,"%s",ch);
	fclose(f1);
	FILE *f2;
	f2 = fopen("usersappend.txt","r");
	while(fscanf(f2,"%s %s %s %s %s %s %s",a->name, a->surnam, a->oldpassword, a->oldmail, a->id, a->number, a->oldanswer)!=EOF)
	{
		if(strcmp(a->oldmail,ch)==0)
		{
			fclose(f2);
			return 1;
		}
	}
	fclose(f2);
	return 0;
	
}


/*#include <time.h>
#include <stdlib.h>

srand(time(NULL));   // Initialization, should only be called once.
int r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX. */

/* Returns an integer in the range [0, n).
 *
 * Uses rand(), and so is affected-by/affects the same seed.
 */
/*int randint(int n) {
  int RAND_MAX,end;
  if ((n - 1) == RAND_MAX) {
    return rand();
  } else {
    // Supporting larger values for n would requires an even more
    // elaborate implementation that combines multiple calls to rand()
    assert (n <= RAND_MAX);

    // Chop off all of the values that would cause skew...
    int end = RAND_MAX / n; // truncate skew
    assert (end > 0);
    end *= n;

    // ... and ignore results from rand() that fall above that limit.
    // (Worst case the loop condition should succeed 50% of the time,
    // so we can expect to bail out of this loop pretty quickly.)
    int r;
    while ((r = rand()) >= end);

    return r % n;
  }
} */


void generate_promotionalcode(char code[])
{
	srand(time(NULL));
	int r1 = rand() % 20,r2 = rand() % 20,r3 = rand() % 20,r4 = rand() % 20;
	char ch[50];
	sprintf(ch,"%d%dtunivisit%d%d",r1,r2,r3,r4);
	strcpy(code,ch);
}

void add_code_to_database(char code[]) // attention : there is a limit , if passed app crashes. maybe cuz of display text size or label size.
{
	FILE *f;
	f=fopen("promotionalcodes.txt","a");
	fputs(code,f);
	fclose(f);
}

void display_text_from_file(char text[], char file[])
{
	FILE *f;
	f=fopen(file,"r");
	char ch[100];
	while(fgets(ch,100,f)!=NULL)
	{
		strcat(text,ch);
		//strcat(text,"\n");
	}
	fclose(f);
}


int IsCodeUnique(char code[])
{
	FILE *f;
	f=fopen("promotionalcodes.txt","r");
	char ch[50];
	int flag=0;
	while(fscanf(f,"%s",ch)!=EOF)
	{
		if(strcmp(code,ch)==0){flag = 1;}
	}
	fclose(f);
	return flag; // 1: code exist so non unique , 0: code dosnt exist
}


int get_promotionalcodes(char codes[50][50])
{
	FILE *f;
	int i=0;
	f=fopen("promotionalcodes.txt","r");
	char ch1[50],ch2[50],ch0[50];
	while(fscanf(f,"%s %s %s",ch0,ch1,ch2)!=EOF)
	{
		if(strcmp(ch1,"NOTSENT")==0 && strcmp(ch2,"0")==0)
		{
			strcpy(codes[i],ch0);
			++i;
		}
	}
	fclose(f);
	return i;
}

int find_member_by_email(MEMBER *a, char ch[]) // returns member line in database, 0: if member dosnt exist
{
	FILE *f2;
	int line=0;
	f2 = fopen("members.txt","r");
	while(fscanf(f2,"%d %s %s %s %s %d/%d/%d %s %s %d",&a->role, a->email, a->password, a->name, a->fname, &a->bdate.day, &a->bdate.month, &a->bdate.year, a->phonenumber, a->nationalid, &a->status)!=EOF)
	{
		++line;
		if(strcmp(a->email,ch)==0)
		{
			fclose(f2);
			return line;
		}
	}
	fclose(f2);
	return 0;
	
}


void replace_line_infile(int line, char newline[], char filename[])
{
	FILE *f;
	FILE *ft;	
	int counter=0;
	char buffer[200];
	f=fopen(filename,"r");
	ft=fopen("tempo.txt","w");
	while ((fgets(buffer, 200, f)) != NULL)
	{
		counter++;
		if(counter==line)
		{
			fputs(newline, ft);
		}
		else
		{
			fputs(buffer, ft);
		}
	}
	fclose(f);
	fclose(ft);
	remove(filename);
	rename("tempo.txt",filename);
}


void delete_line_infile(int line, char filename[])
{
	FILE *f;
	FILE *ft;	
	int counter=0;
	char buffer[200];
	f=fopen(filename,"r");
	ft=fopen("tempo.txt","w");
	while ((fgets(buffer, 200, f)) != NULL)
	{
		counter++;
		if(counter==line)
		{
			counter++; // skip the line
		}
		else
		{
			fputs(buffer, ft);
		}
	}
	fclose(f);
	fclose(ft);
	remove(filename);
	rename("tempo.txt",filename);
}

int valid_nb(char nb[], int len)
{
	int n=strlen(nb);
	if(n!=len){return 0;}
	for(int i=0;i<n;i++)
	{
		if(isdigit(nb[i])==0)
		{
			return 0;
		}
	}
	return 1;
}

int valid_fullname(char name[])
{
	int n = strlen(name);
	if(n<5){return 0;}
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(isdigit(name[i])!=0){return 0;}
		if(name[i]==' '){flag=1;}
	}
	return flag;
}


int valid_bdate(char bdate[])
{
	int n = strlen(bdate);
	if(n<8 || n>10){return 0;}
	int slashcounter=0;
	for(int i=0;i<n;i++)
	{
		if(bdate[i]=='/'){++slashcounter;}
		if(isdigit(bdate[i])==0){return 0;}
	}
	if(slashcounter!=2){return 0;}
	return 1;
}

int valid_password(char password[])
{
	int n=strlen(password);
	if(n<4){return 0;}
	int nb=0,car=0;
	for(int i=0;i<n;i++)
	{
		if(isdigit(password[i])==0){++car;}
		if(isdigit(password[i])!=0){++nb;}
	}
	if(car==0 || nb==0){return 0;}
	return 1;
}

void send_msg(char msg[])
{
	FILE *f;
	f=fopen("whatsnew.txt","a");
	fprintf(f,"%s\n",msg);
	fclose(f);
} 


int get_clients_mail(char clients[50][50])
{
	FILE *f;
	f=fopen("usersappend.txt","r");
	CLIENT a;
	int i=0;
	while(fscanf(f,"%s %s %s %s %s %s %s",a.name,a.surname,a.password,a.email,a.id,a.number,a.question)!=EOF)
	{
		strcpy(clients[i],a.email);
		++i;		
	}
	fclose(f);
	return i;
}



int find_line(char file[], char searchword[])
{
	FILE *f;
	int line=0;
	f=fopen(file, "r");
	char str1[50],str2[50],str3[50];
	while(fscanf(f,"%s %s %s",str1,str2,str3))
	{
		++line;
		if(strcmp(str1,searchword)==0 || strcmp(str2,searchword)==0 || strcmp(str3,searchword)==0)
		{
			fclose(f);
			return line;
		}
	}
	fclose(f);
	return 0;
}

int find_lineclientsettings(char file[], char searchword[])
{
	FILE *f;
	int line=0;
	f=fopen(file, "r");
	char str1[50],str2[50],str3[50],str4[50],str5[50],str6[50],str7[50];
	while(fscanf(f,"%s %s %s %s %s %s %s",str1,str2,str3,str4,str5,str6,str7))
	{
		++line;
		if(strcmp(str1,searchword)==0 || strcmp(str2,searchword)==0 || strcmp(str3,searchword)==0 || strcmp(str4,searchword)==0 || strcmp(str5,searchword)==0 || strcmp(str6,searchword)==0 || strcmp(str7,searchword)==0)
		{
			fclose(f);
			return line;
		}
	}
	fclose(f);
	return 0;
}



int find_line9(char file[], char searchword[])
{
	FILE *f;
	int line=0;
	f=fopen(file, "r");
	char str1[50],str2[50],str3[50],str4[50];
	while(fscanf(f,"%s %s %s %s",str1,str2,str3,str4))
	{
		++line;
		if(strcmp(str1,searchword)==0 || strcmp(str2,searchword)==0 || strcmp(str3,searchword)==0 || strcmp(str4,searchword)==0)
		{
			fclose(f);
			return line;
		}
	}
	fclose(f);
	return 0;
}

int find_line2(char file[], char searchword[])
{
	FILE *f;
	int line=0;
	f=fopen(file, "r");
	char str1[50],str2[50],str3[50],str4[50];
	while(fscanf(f,"%s %s %s %s",str1,str2,str3,str4))
	{
		++line;
		if(strcmp(str1,searchword)==0 || strcmp(str2,searchword)==0 || strcmp(str3,searchword)==0 || strcmp(str4,searchword)==0)
		{
			fclose(f);
			return line;
		}
	}
	fclose(f);
	return 0;
}



int get_claims(char claims[100][100])
{
	FILE *f;
	f=fopen("claims.txt","r");
	int i = 0;
	char ch1[100],ch2[100],ch3[100],ch4[100];
	while(fscanf(f,"%s %s %s %s",ch1,ch2,ch3,ch4)!=EOF)
	{
		strcpy(claims[i],ch4);
		++i;
	}
	fclose(f);
	return i;
}

/*void fix_text(char text[])
{
	//FILE *f;
	//f=fopen("temptext1.txt","a+");
	//fputs(text,f);
	//fclose(f); 
	char command[100];
	sprintf(command,"%s tr " " - > temptext2.txt",text);
	system(command);
	FILE *f2;
	f2=fopen("temptext2.txt","r");
	char str[100];
	fgets(str,100,f2);
	strcpy(text,str);
	fclose(f2);
} */







// whatsnew.c :

/*enum 
{
NEW,
CONTENU,
COLUMNS
}; */

/*
void showtreewhatsnew( GtkWidget *liste){
FILE *t=fopen("instantcustomer.txt","r");char verif[30];fscanf(t,"%s",verif);fclose(t);
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;
char new[30];
char contenu[30];
int e;
char verifcustomer[30];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" new", renderer, "text",NEW, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" contenu", renderer, "text",CONTENU, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING);
f = fopen("whatsnew.txt","r");

if(f==NULL) return;
else 
	{
f = fopen("whatsnew.txt", "a+");
	while(fscanf(f,"%s %s %d %s\n",new,contenu,&e,verifcustomer)!=EOF) if((e==0) && strcmp(verif,verifcustomer)==0)//non souhaite =1
				{
gtk_list_store_append(store, &iter);
gtk_list_store_set (store,&iter, NEW, new, CONTENU , contenu, -1);  }
		fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
	 }
}
} */


void deletewhatsnew(char p[])
{
FILE *f=fopen("instantcustomer.txt","r");char verifcustomer[50];fscanf(f,"%s\n",verifcustomer);fclose(f);
 char type[30];
 char nom[30];
 char date[30]; int prix; int b;char customer[30];
FILE *u=fopen("whatsnew.txt","r");
FILE *t=fopen("whatsnewtempo.txt","a+");
if (u!=NULL)
{
while(fscanf(u,"%s %s %d %s\n",type,nom,&b,customer)!=EOF)
{
if (strcmp(type,p)!=0 || strcmp(customer,verifcustomer)!=0)
{
fprintf(t,"%s %s %d %s\n",type,nom,b,customer);
}
}
}
fclose(u);
fclose(t);
remove("whatsnew.txt");
rename("whatsnewtempo.txt","whatsnew.txt");
}

void deletereservation(char p[])
{
char a[50],b[50],c[500],d[50],e[50],f[50],g[50],h[50],j[50],k[50],l[50],m[50],n[50];
FILE *u=fopen("reservation.txt","r");
FILE *t=fopen("reservationtempo.txt","a+");
if (u!=NULL)
{
while(fscanf(u,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",a,b,c,d,e,f,g,h,j,k,l,m,n)!=EOF)
{
if (strcmp(n,p)!=0)
{
fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",a,b,c,d,e,f,g,h,j,k,l,m,n);
}
}
}
fclose(u);
fclose(t);
remove("reservation.txt");
rename("reservationtempo.txt","reservation.txt");
}

// verifuathentification.c:

int verifauthentification(authentification p)
{
FILE *f =fopen("users.txt","r");
char username[50];
char password[30];
int role;
int b;
if (f!=NULL)
	{	while (fscanf(f,"%s %s %d %d \n",username,password,&role,&b)!=EOF)
			{	if(strcmp(username,p.username)==0 && strcmp(password,p.password)==0){	return role;
				}
				

			}

	}


fclose(f);


}
int verifauthentification0(authentification p)
{
FILE *f =fopen("users.txt","r");
char username[50];
char password[30];
int role;
int b;
int r=1 ;
if (f!=NULL)
	{	while (fscanf(f,"%s %s %d %d \n",username,password,&role,&b)!=EOF)
			{
				if(strcmp(username,p.username)==0 && strcmp(password,p.password)==0 && b==0) r=0;
				

			}

	}
return r;


fclose(f);}
void instantcustomer( authentification p){
FILE *f=fopen("instantcustomer.txt","a+");
fprintf(f,"%s",p.username);
fclose(f);}
void notinstantcustomer(){
remove("instantcustomer.txt");
}
void instantagent( authentification p){
FILE *f=fopen("instantagent.txt","a+");
fprintf(f,"%s",p.username);
fclose(f);
}

// suprimer3.c:
void suprimer3(char name_car[])
{
 char NAME[100];
 char PRICE[100];
 char DESCRIPTION[100];
FILE *u=fopen("users3.txt","r");
FILE *t=fopen("tamp.txt","a+");
if (u!=NULL)
{
while(fscanf(u,"%s %s %s \n",NAME,PRICE,DESCRIPTION)!=EOF)
{
if (strcmp(NAME,name_car)!=0)
{
fprintf(t,"%s %s %s \n",NAME,PRICE,DESCRIPTION);
}
}
}
fclose(u);
fclose(t);
remove("users3.txt");
rename("tamp.txt","users3.txt");
}
  
// suprimer2.c:
void suprimer2(char name_offre[])
{
 char UNTIL[100];
 char NAME[100];
 char DESCRIPTION[100];
FILE *u=fopen("users2.txt","r");
FILE *t=fopen("tamp.txt","a+");
if (u!=NULL)
{
while(fscanf(u,"%s %s %s \n",UNTIL,NAME,DESCRIPTION)!=EOF)
{
if (strcmp(NAME,name_offre)!=0)
{
fprintf(t,"%s %s %s \n",UNTIL,NAME,DESCRIPTION);
}
}
}
fclose(u);
fclose(t);
remove("users2.txt");
rename("tamp.txt","users2.txt");
}
  
// surpimer.c:
void suprimer(char name_hotel[])
{
 char NAME[100];
 char PRICE[100];
 char DESCRIPTION[100];
FILE *u=fopen("hotels.txt","r");
FILE *t=fopen("tamp.txt","a+");
if (u!=NULL)
{
while(fscanf(u,"%s %s %s \n",NAME,PRICE,DESCRIPTION)!=EOF)
{
if (strcmp(NAME,name_hotel)!=0)
{
fprintf(t,"%s %s %s \n",NAME,PRICE,DESCRIPTION);
}
}
}
fclose(u);
fclose(t);
remove("hotels.txt");
rename("tamp.txt","hotels.txt");
}
  
// singup.c :
void signup( userfirst p)
{
FILE *f=fopen("usersappend.txt","a+");
fprintf(f,"%s %s %s %s@%s.%s %s %s %s \n",p.name,p.surname,p.password,p.mailone,p.hotmail,p.dotcom,p.id,p.number,p.question);
fclose(f);


}
void signup1( userfirst p){
FILE *f=fopen("users.txt","a+");
int r=1;
int b=1;
fprintf(f,"%s@%s.%s %s %d %d \n ",p.mailone,p.hotmail,p.dotcom,p.password,r,b);
fclose(f);



}

int signupverifypassword( userfirst p)
{
int i=0;
if (strlen(p.password)!=0 && strcmp(p.password,p.samepass)==0) i=1;
return i;
}

int signupverifyadresse(userfirst p)
{
int i=0;
if (strlen(p.mailone)!=0 && strlen(p.hotmail)!=0 && strlen(p.dotcom)!=0 ) i=1;
return i;
}

int signupverifynumber(userfirst p)
{ int i=0;
if (strlen(p.number)==11) i=1;
return i;}

int signupverifyid(userfirst p)
{
int i=0;
if(strlen(p.id)==8) i=1;
return i;}
int signupverifyall (userfirst p )
{
int i=0;
if ( strlen(p.name)!=0 && strlen(p.surname)!=0 && strlen(p.question)!=0 )
i=1;
return i;
}


int signupexist( userfirst p ) 
{
char adresse[30];
char one[30];
char two[30];
char password[30];
char adressetot[60];
userfirst k ;
/*strcat(adressetot,p.mailone);strcat(adressetot,"@");strcat(adressetot,p.hotmail);strcat(adressetot,".");strcat(adressetot,p.dotcom);*/
int l;int e;l=0;
FILE *f=fopen("users.txt","r");
FILE *t=fopen("usersverify.txt","a+");fprintf(t,"%s@%s.%s",p.mailone,p.hotmail,p.dotcom);fclose(t);
FILE *d=fopen("usersverify.txt","r");fscanf(d,"%s\n",adressetot);fclose(d); remove("usersverify.txt");
while(fscanf(f,"%s\n",k.mailone)!=EOF)
				{if ( strcmp (k.mailone,adressetot) == 0 ) 
								{ l=1 ;}

				}

fclose(f); return l;
}

// protectcustomer.c:

int verifpassquestion(char str2[], char str5[]) 
{FILE *f=fopen("usersappend.txt","r");
int i=0;
char name[30],surname[30],mdp[30],mail[30],question[30];
int id,number;
while (fscanf(f,"%s %s %s %s %s %s %s\n",name,surname,mdp,mail,id,number,question)!=EOF) if (strcmp(str2,mdp)==0 && strcmp(str5,question)==0) i=1;
fclose(f);
return i;
}
void getoldinformation( userprotect *p){
FILE *t=fopen("instantcustomer.txt","r");char verif[50];fscanf(t,"%s\n",verif);fclose(t);
FILE *f=fopen("usersappend.txt","r");
char name[30],surname[30],mdp[30],mail[30],question[30];
char id[30],number[30];
while (fscanf(f,"%s %s %s %s %s %s %s\n",name,surname,mdp,mail,id,number,question)!=EOF)
	if (strcmp(mail,verif)==0) {strcpy(p->name,name);strcpy(p->surnam,surname);strcpy(p->oldpassword,mdp);strcpy(p->oldmail,mail);strcpy(p->id,id);strcpy(p->number,number);strcpy(p->oldanswer,question);}
fclose(f);
}
void deleteoldinformation()
{
FILE *k=fopen("instantcustomer.txt","r");char verif[50];fscanf(k,"%s\n",verif);fclose(k);
FILE *f=fopen("usersappend.txt","r");
FILE *temp=fopen("usersappendtempo.txt","a+");

char name[30],surname[30],mdp[30],mail[30],question[30];
char id[30],number[30];
while (fscanf(f,"%s %s %s %s %s %s %s\n",name,surname,mdp,mail,id,number,question)!=EOF)
{
if (strcmp(mail,verif)!=0)
{
fprintf(temp,"%s %s %s %s %s %s %s\n",name,surname,mdp,mail,id,number,question);
}
}

fclose(f);
fclose(temp);
remove("usersappend.txt");
rename("usersappendtempo.txt","usersappend.txt");
}
void deleteoldinformationuser()
{
FILE *k=fopen("instantcustomer.txt","r");char verif[50];fscanf(k,"%s\n",verif);fclose(k);
FILE *f=fopen("users.txt","r");
FILE *temp=fopen("userstempo.txt","a+");

char mdp[30],mail[30];
int r,b;
while (fscanf(f,"%s %s %d %d\n",mail,mdp,&r,&b)!=EOF)
{
if (strcmp(mail,verif)!=0)
{
fprintf(temp,"%s %s %d %d\n",mail,mdp,r,b);
}
}

fclose(f);
fclose(temp);
remove("users.txt");
rename("userstempo.txt","users.txt");
}

// next.c:

void nexthoteladd(){
FILE *f= fopen("hotels.txt","r"); char name[30];char description[30];int price;
FILE *t=fopen("hotelsxp.txt","a+");
while ( fscanf(f,"%s %s %d\n",name,description,&price)!=EOF) fprintf(t,"%s %s %d\n",name,description,price);
fclose(f);fclose(t);
}


void nexthoteldelete(char p[]){

char NAME[100];
 int PRICE;
 char DESCRIPTION[100];
FILE *u=fopen("hotelsxp.txt","r");
FILE *d=fopen("hotelsxptemp.txt","a+");

while(fscanf(u,"%s %s %d \n",NAME,DESCRIPTION,&PRICE)!=EOF) if (strcmp(NAME,p)!=0) fprintf(d,"%s %s %d \n",NAME,DESCRIPTION,PRICE);

fclose(u);
fclose(d);
remove("hotelsxp.txt");
rename("hotelsxptemp.txt","hotelsxp.txt");
}
nextleaseadd(char p[]){
FILE *f= fopen("users3.txt","r"); char name[30];char description[30];int price;
FILE *t=fopen("users3xp.txt","a+");
while ( fscanf(f,"%s %d %s\n",name,&price,description)!=EOF) fprintf(t,"%s %d %s\n",name,price,description);
fclose(f);fclose(t);
}

void nextleasedelete(char p[]){

char NAME[100];
 int PRICE;
 char DESCRIPTION[100];
FILE *u=fopen("users3xp.txt","r");
FILE *d=fopen("users3xptemp.txt","a+");
while(fscanf(u,"%s %d %s\n",NAME,&PRICE,DESCRIPTION)!=EOF) if (strcmp(NAME,p)!=0) fprintf(d,"%s %d %s \n",NAME,PRICE,DESCRIPTION);

fclose(u);
fclose(d);
remove("users3xp.txt");
rename("users3xptemp.txt","users3xp.txt");
}

void nextofferadd(){
FILE *f= fopen("users2.txt","r"); char name[30];char description[30];int price;
FILE *t=fopen("users2xp.txt","a+");
while ( fscanf(f,"%s %s %d\n",name,description,&price)!=EOF) fprintf(t,"%s %s %d\n",name,description,price);
fclose(f);fclose(t);
}
void nextofferdelete(char p[]){
char NAME[100];
 int PRICE;
 char DESCRIPTION[100];
FILE *u=fopen("users3xp.txt","r");
FILE *d=fopen("users3xptemp.txt","a+");
while(fscanf(u,"%s %s %d\n",NAME,DESCRIPTION,&PRICE)!=EOF) if (strcmp(NAME,p)!=0) fprintf(d,"%s %s %d \n",NAME,DESCRIPTION,PRICE);
fclose(u);
fclose(d);
remove("users3xp.txt");
rename("users3xptemp.txt","users3xp.txt");

}

// mychart.c:
/*enum 
{
TYPE,
NOM,
DATE, // changed to DATEE (conflicting with typedef DATE;)
PRICE,
COLUMNS
}; */

/*
void showtreemychart(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;
char type[30];
char nom[30];
char date [30];
int price;
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
column=gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATEE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" price", renderer, "text",PRICE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
f = fopen("mychart.txt","r");
int e;
if(f==NULL) return;
else 
	{
f = fopen("mychart.txt", "a+");
	while(fscanf(f,"%s %s %s %d %d\n",type,nom,date,&price,&e)!=EOF)
				{
gtk_list_store_append(store, &iter);
gtk_list_store_set (store,&iter, TYPE, type, NOM , nom, DATEE, date, PRICE, price , -1);  }
		fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
	 }
}
} */




void deletemychart(char p[]){
 char type[30];
 char nom[30];
 char date[30]; int prix; int b;
FILE *u=fopen("mychart.txt","r");
FILE *t=fopen("mycharttempo.txt","a+");
if (u!=NULL)
{
while(fscanf(u,"%s %s %s %d %d\n",type,nom,date,&prix,&b)!=EOF)
{
if (strcmp(nom,p)!=0)
{
fprintf(t,"%s %s %s %d %d\n",type,nom,date,prix,b);
}
}
}
fclose(u);
fclose(t);
remove("mychart.txt");
rename("mycharttempo.txt","mychart.txt");

}
void deletemyreservation(char p[]){
FILE *x=fopen("instantcustomer.txt","r");char verif[50];fscanf(x,"%s\n",verif);fclose(x);
char a[50],b[50],c[500],d[50],e[50],f[50],g[50],h[50],j[50],k[50],l[50],m[50],n[50];
FILE *u=fopen("reservation.txt","r");
FILE *t=fopen("reservationtempo.txt","a+");
if (u!=NULL)
{
while(fscanf(u,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",a,b,c,d,e,f,g,h,j,k,l,m,n)!=EOF)
{
if (strcmp(n,verif)!=0 || strcmp(b,p)!=0)
{
fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",a,b,c,d,e,f,g,h,j,k,l,m,n);
}
}
}
fclose(u);
fclose(t);
remove("reservation.txt");
rename("reservationtempo.txt","reservation.txt");

}


int calculprix(){
FILE *f; int e;int price;char type[30];char nom[30];char date[30];
f = fopen("mychart.txt", "r");
int p=0;
while(fscanf(f,"%s %s %s %d %d\n",type,nom,date,&price,&e)!=EOF)
p+=price;
fclose(f);
return p;

}


int verifpromotionalcode ( promotion *p ){
int i;
i=0;
FILE *f=fopen("instantcustomer.txt","r");char verifcustomer[50];fscanf(f,"%s\n",verifcustomer);fclose(f);
FILE *t=fopen("promotionalcodes.txt","r");char codepromotional[30];int b;char adresse[30];
while(fscanf(t,"%s %s %d \n",codepromotional,adresse,&b)!=EOF) if(strcmp(codepromotional,p->promoentry)==0 && strcmp(adresse,verifcustomer)==0 && (b==0)) i=1;
fclose(t);
return i;
}

// history.c:

/*enum 
{
TYPE,
NOM,
DATE, changed to DATEE cuz of conflicting typedef DATE;

COLUMNS
}; */

/*
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
column=gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATEE, NULL);
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
gtk_list_store_set (store,&iter, TYPE, type, NOM , nom, DATEE, date, -1);  }
		fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
	 }
}
} */




void deletehistory(char p[]){
FILE *f=fopen("instantcustomer.txt","r");char verifcustomer[50];fscanf(f,"%s\n",verifcustomer);fclose(f);
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


}

// getpassword.c:

void getpassword(typepass *p){
FILE *f=fopen("usersappend.txt","r");
char nom[20];
char prenom[20];
char motdepass[20];
char sonmail[20] ;
char identity[10];
char numero[10];
char reponse[20]; 
if (f!=NULL)
strcpy(p->password,"Invalid_information");
	{	while (fscanf(f,"%s %s %s %s %s %s %s\n",nom,prenom,motdepass,sonmail,identity,numero,reponse)!=EOF)
			{	if(strcmp(sonmail,p->mail)==0 && strcmp(numero,p->number)==0 && strcmp(reponse,p->reponse)==0){	strcpy(p->password,motdepass);
				
				}
				
				

			}

	}


fclose(f);}

// ajouter3.c:

void ajouter3(char name[],char prises[],char descib[]){

FILE *f;
f=fopen("users3.txt","a+");
if(f!=NULL){

fprintf(f,"%s %s %s \n",name,prises,descib);
fclose(f);}
}

// ajouter2.c:

void ajouter2(char until[],char name[],char descib[]){

FILE *f;
f=fopen("users2.txt","a+");
if(f!=NULL){

fprintf(f,"%s %s %s \n",until,name,descib);
fclose(f);}
}

// ajouter.c:
void ajouter(char name[],char prises[],char descib[]){

FILE *f;
f=fopen("hotels.txt","a+");
if(f!=NULL){

fprintf(f,"%s %s %s \n",name,prises,descib);
fclose(f);}
}

// afficher3.c:

/*enum
{	NAME,
	PRICE,
	DESCRIPTION,
	COLUMNS
}; */

/*
void afficher3 (GtkWidget * liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char name[100];char price[100];char description[100];
store=NULL;
FILE *f ;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{ renderer=gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("name",renderer,"text",NAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("price",renderer,"text",PRICE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("description",renderer,"text",DESCRIPTION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING); 
f=fopen("users3.txt","r");
if(f==NULL) return;
else{ f=fopen("users3.txt","a+");while(fscanf(f,"%s %s %s",name,price,&description)!=EOF)
{gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NAME,name,PRICE,price,DESCRIPTION,description,-1);
}fclose(f); 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}} */

// afficher2.c:

/*enum
{	UNTIL,
	NAME,
	DESCRIPTION,
	COLUMNS
}; */
/*
void afficher2 (GtkWidget * liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char until[100];char name[100];char description[100];
store=NULL;
FILE *f ;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{ renderer=gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("until",renderer,"text",UNTIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("name",renderer,"text",NAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("description",renderer,"text",DESCRIPTION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING); 
f=fopen("users2.txt","r");
if(f==NULL) return;
else{ f=fopen("users2.txt","a+");while(fscanf(f,"%s %s %s",until,name,&description)!=EOF)
{gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,UNTIL,until,NAME,name,DESCRIPTION,description,-1);
}fclose(f); 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}} */

// afficher.c:

/*enum
{	NAME,
	PRICE,
	DESCRIPTION,
	COLUMNS
}; */

/*
void afficher (GtkWidget * liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char name[100];char price[100];char description[100];
store=NULL;
FILE *f ;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{ renderer=gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("name",renderer,"text",NAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("price",renderer,"text",PRICE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("description",renderer,"text",DESCRIPTION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING); 
f=fopen("hotels.txt","r");
if(f==NULL) return;
else{ f=fopen("hotels.txt","a+");while(fscanf(f,"%s %s %s",name,price,&description)!=EOF)
{gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NAME,name,PRICE,price,DESCRIPTION,description,-1);
}fclose(f); 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}} */





// image/catalogue functions:


int get_catalogueinfo(char cataloguename[], char imageurl[], char pdfurl[]) // returns 1:found , 0:notfound
{
	FILE *f;
	f=fopen("catalogue.txt","r");
	char name[50],str1[50],str2[50];
	while(fscanf(f,"%s %s %s",name,str1,str2)!=EOF)
	{
		if(strcmp(cataloguename,name)==0)
		{
			strcpy(imageurl,str1);
			strcpy(pdfurl,str2);
			fclose(f);
			return 1;
		}
	}
	fclose(f);
	return 0;
}

int get_cataloguesnames(char list[50][50])
{
	FILE *f;
	f=fopen("catalogue.txt","r");
	int p=0;
	char name[50],imageurl[50],pdfurl[50];
	while(fscanf(f,"%s %s %s",name,imageurl,pdfurl)!=EOF)
	{
		strcpy(list[p],name);
		++p;
	}
	fclose(f);
	return p;
}


void res_hotel(hotel_info a)
{
	FILE *f;
	f=fopen("reservation_hotel.txt","a+");
	fprintf(f,"%s %s %d  %s %s %s %s %d/%d/%d %s %s %s %s %s\n",a.checkin,a.checkout,a.rooms,a.pension,a.title,a.name,a.surname,a.birthday.day,a.birthday.month, a.birthday.year,a.country,a.adress,a.phone,a.passport,a.mail);
	

	fclose(f);	
}


void res_car(car_info a)
{
	FILE *f;
	f=fopen("reservation_car.txt","a+");
	fprintf(f,"%s %s %s %s %s %d/%d/%d %s %s %s %s %s\n",a.dropoff,a.pickup,a.title,a.name,a.surname,a.birthday.day,a.birthday.month, a.birthday.year,a.country,a.adress,a.phone,a.passport,a.mail);
	

	fclose(f);	
}


void res_fl(info a)
	{
	FILE *f;
	f=fopen("reservation_flight.txt","a+");
 	
	fprintf(f,"%s %s %s %s %d/%d/%d %s %s %s %s %s %s\n",a.from,a.title,a.name,a.surname,a.birthday.day,a.birthday.month,a.birthday.year,a.country,a.phone,a.passport,a.mail,a.adress,a.time);
	
	fclose(f);
	}



int get_flight_airport(char air[200][200])
{
	FILE *f;
	f=fopen("users4.txt","r");
	int i=0;
	char str[200],str1[200],str2[200],str3[200],str4[200],str5[200],str6[200];
	while(fscanf(f,"%s %s %s %s %s %s",str1,str2,str3,str4,str5,str6)!=EOF)
	{
		sprintf(str,"%s %s %s %s %s %s",str1,str2,str3,str4,str5,str6);
		strcpy(air[i],str);
		i++;
	}
	fclose(f);
	return i;
	 
}





