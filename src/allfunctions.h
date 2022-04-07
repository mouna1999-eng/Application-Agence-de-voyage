#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// I dont need it for now , maybe for Agent Online Hours counter #include <time.h>

typedef GtkWidget;
typedef GtkCellRenderer;
typedef GtkTreeViewColumn;
typedef GtkTreeIter;
typedef GtkListStore;

typedef struct
{
	int day;
	int month;
	int year;
} DATE;

typedef struct 
{
	int role; // 3:admin 2:agent
	char email[200];
	char password[50];
	char name[50];
	char fname[50];
	DATE bdate;
	char phonenumber[50];
	char nationalid[50];
	// int demandsdone;
	int status; // 1:Activated 0:Desactivated
	// int hours online; int demands done; int performance; or just calculate it when needed, m.demands/m.hours, default to 0 in declaration so u wont have to change every member declaration in code.
			
} MEMBER;


void add_member(MEMBER a);
int SamePassword(char p1[], char p2[]);
void desactivate_member_by_email(char email[]);
int get_members_mails(char emails[50][50]);
int get_agents_mails(char emails[50][50]);

int valid_email(char email[]); // checks for @ . and len >4
int valid_nb(char nb[], int len); // check a valid phonenumber/nationalid (only numbers) , len(nb) ==  len , 1:True , 0:False
int valid_fullname(char name[]); // checks for space, only characters, and len >5.
int valid_bdate(char bdate[]); // checks the existing of a 3x/ and 8 =< len =< 10
int valid_password(char password[]); // checks for nmbers only, len >3, checks for existing of both numbers and characters.

int count_members(int role);
int count_clients();

int find_current_user(MEMBER *a); // returns 1:user found , 0:user not found

void generate_promotionalcode(char code[]);
void add_code_to_database(char code[]);
void display_text_from_file(char text[],char file[]); // only works for promotionalcodes.txt because I didnt use fgets, I used format fscanf (fgets didnt work for some reasons)
int IsCodeUnique(char code[]);
int get_promotionalcodes(char codes[50][50]);
int find_member_by_email(MEMBER *a, char ch[]);
void replace_line_infile(int line, char newline[], char filename[]);
void delete_line_infile(int line, char filename[]);
int find_line9(char file[], char searchword[]);
int find_lineclientsettings(char file[], char searchword[]);
// CLAIMS
int get_claims(char claims[100][100]);


/*enum
{
	SERVICENAME,
	SERVICETYPE,
	DESCRIPTION,
	FROM,
	COLUMNS
}; */
/*
enum
{	
	NAME,
	PRICE,
	DESCRIPTION,
	UNTIL,
	SERVICENAME,
	SERVICETYPE,
	FROM,
	TYPE,
	NOM,
	DATEE, // check typedef conflicationF
	NEW,
	CONTENU,
	COLUMNS
}; */






// PC
void send_msg(char msg[]);
int get_clients_mail(char clients[50][50]);
int find_line(char file[], char searchword[]);




typedef struct
{
	char name[50];
	char surname[50];
	char password[50];
	char email[50];
	char id[50];
	char number[50];
	char question[50];
	
} CLIENT;




//void fix_text(char text[]);


// tools maher:

/*typedef struct
{
	int day;
	int month;
	int year;
} DATEE; */





// whatsnew.h:

// void showtreewhatsnew(GtkWidget *liste); 
void deletewhatsnew(char p[]);

// verifauthentificiation.h:

typedef struct
{
char username[30];
char password[30];
}authentification;


int verifauthentification(authentification p);
int verifauthentification0(authentification p);
void instantcustomer( authentification p);
void notinstantcustomer();
void instantagent( authentification p);

// suprimer3.h:
void suprimer3(char name_car[]);

// suprimer2.h:
void suprimer2(char name_offre[]);

// surpimer.h:
void suprimer(char name_hotel[]);

// singup.h:
typedef struct
{
char name[20];
char surname[20];
char password[20];
char samepass[20];
char mailone[20];
char hotmail[20];
char dotcom[20];
char id[20];
char number[20];
char question[20];
} userfirst;

void signup( userfirst p );
void signup1( userfirst p);
int signupverifypassword(userfirst p);
int signupverifyadresse(userfirst p);
int signupverifyid(userfirst p);
int signupverifynumber(userfirst p);
int signupverifyall (userfirst p);
int signupexist( userfirst p );

// protectcutomer.h:
typedef struct {
char name[30];char surnam[30];char newpass[30],newotherpass[30],oldpassword[30],oldanswer[30],newnumber[11];char oldmail[30];
char number[30],id[30];

}userprotect;

typedef struct
{
	char name[30],surnam[30],oldpassword[30],oldmail[30],id[30],number[30],oldanswer[30];

}userprotect1;

int find_current_user1(userprotect1 *a); // for change client settings

int verifpassquestion(char str2[],char str5[] ) ;
void getoldinformation( userprotect *p);
void deleteoldinformation();
void deleteoldinformationuser();

// next.h:

void nexthoteladd();
void nexthoteldelete(char p[]);
void nextleaseadd();
void nextleasedelete(char p[]);
void nextofferadd();
void nextofferdelete(char p[]);

// mychart.h:
typedef struct{
char promoentry[30];
int promonum;
}promotion;

//void showtreemychart(GtkWidget *liste);
void deletemychart(char p[]);
int calculprix();
int verifpromotionalcode ( promotion *p );
void deletemyreservation(char p[]);

// history.h:

// void showtreehistory(GtkWidget *liste); 
void deletehistory(char p[]);

// getpassword.h:

typedef struct
{
char mail[30];
char number[30];
char reponse[30];
char password[30]
}typepass;
//na9sa il reponse
void getpassword(typepass *p );
void showtreepassword(GtkWidget *liste,char ad[],char nu[]);

// ajouter3.h:

void ajouter3(char name[],char prises[],char descib[]);

// ajouter2.h:

void ajouter2(char until[],char name[],char descib[]);

// ajouter.h:

void ajouter(char name[],char prises[],char descib[]);

void deletereservation(char p[]);


// image/catalogue functions:

int get_catalogueinfo(char cataloguename[50], char imageurl[50], char pdfurl[50]); // returns 1:found , 0:notfound
int get_cataloguesnames(char list[50][50]); // returns catalogues number available


// fncts integration maher/yassin:





typedef struct 
{
	char from[500];
	/*char to[50];*/
	char name[50];
	char surname[50];
	/*char departing[50];*/
	/*char returning[50];*/
	DATE birthday;
	char phone[50];
	char passport[50];
        char title[50];
	char adress[50];
	char country[50];
	char mail[50];
	/*char day[50];
	char month[50];
	char year[50];*/
	char time[50];
			
} info;



typedef struct 
{
	int rooms;
	int nights;
	char pension[50];
	char checkin[50];
	char checkout[50];
	char name[50];
	char surname[50];
	DATE birthday;
	char phone[50];
	char passport[50];
        char title[50];
	char adress[50];
	char country[50];
	char mail[50];
	char day[50];
	char month[50];
	char year[50];
			
} hotel_info;


typedef struct 
{
	
	
	char pickup[50];
	char dropoff[50];
	char name[50];
	char surname[50];
	DATE birthday;
	char phone[50];
	char passport[50];
        char title[50];
	char adress[50];
	char country[50];
	char mail[50];
	char day[50];
	char month[50];
	char year[50];
			
} car_info;



void res_fl(info a);
void res_car(car_info a);
void res_hotel(hotel_info a);
int get_flight_airport(char air[200][200]);






