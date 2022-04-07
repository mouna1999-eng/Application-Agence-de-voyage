#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "allfunctions.h"






void
on_Loginbutton_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
	GtkWidget *interfacelogin=lookup_widget(objet,"interfacelogin");
	GtkWidget *interfacewelcome=lookup_widget(objet,"interfacewelcome");
	interfacelogin=create_interfacelogin();
	gtk_widget_show(interfacelogin);
	gtk_widget_destroy(interfacewelcome);
}


void
on_previewimagebutton_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_nextimagebutton_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void on_viewbutton_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *choose;
	choose = lookup_widget(objet_graphique, "welcomechoose");
	char imageurl[50],pdfurl[50];
	int k = get_catalogueinfo(gtk_combo_box_get_active_text(GTK_COMBO_BOX(choose)),imageurl,pdfurl);
	char command[50];
	sprintf(command,"xdg-open %s",pdfurl);
	system(command);
}


void
on_downloadcatalogbutton_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_returntointerfacewelcome_clicked    (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{	GtkWidget *interfacelogin=lookup_widget(objet,"interfacelogin");
	GtkWidget *interfacewelcome=lookup_widget(objet,"interfacewelcome");
	interfacewelcome=create_interfacewelcome();
	gtk_widget_show(interfacewelcome);
	gtk_widget_destroy(interfacelogin);

}



void
on_signupbutton_clicked                (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{ GtkWidget *interfacelogin=lookup_widget(objet,"interfacelogin");
  GtkWidget *interfacesignup=lookup_widget(objet,"interfacesignup");
	gtk_widget_destroy(interfacelogin);
	interfacesignup=create_interfacesignup();
	gtk_widget_show(interfacesignup);
	

}


void
on_logingbutton1_clicked               (GtkWidget       *objet,
                                        gpointer         user_data) //marceh
{ GtkWidget *interfacecustomer=lookup_widget(objet,"interfacecustomer");
  GtkWidget *interfacelogin=lookup_widget(objet,"interfacelogin");
  GtkWidget *interfaceadmin=lookup_widget(objet,"EspaceAdminHome");
  GtkWidget *interfaceagent=lookup_widget(objet,"interfaceagent");
  GtkWidget *labelerreurauthentification=lookup_widget(objet,"labelerreurauthentification");
GtkWidget *usernameentry=lookup_widget(objet,"usernameentry");
GtkWidget *passwordentry=lookup_widget(objet,"passwordentry");

authentification p;
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(usernameentry)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(passwordentry)));

if (verifauthentification0(p)==0)
			gtk_label_set_text(GTK_LABEL(labelerreurauthentification),"You are BANNED ");
		else{

				if (verifauthentification(p)==1){	instantcustomer(p) ;interfacecustomer=create_interfacecustomer();
						gtk_widget_show(interfacecustomer);
						gtk_widget_destroy(interfacelogin);

										}
				if (verifauthentification(p)==2){	
						interfaceagent=create_interfaceagent();
						instantagent(p);
						gtk_widget_show(interfaceagent);
						gtk_widget_destroy(interfacelogin);

										}
				if (verifauthentification(p)==3){	
						interfaceadmin=create_EspaceAdminHome();
						instantcustomer(p);
						gtk_widget_show(interfaceadmin);
						gtk_widget_destroy(interfacelogin);}
				else  gtk_label_set_text(GTK_LABEL(labelerreurauthentification),"Invalid information");
}

	
}


void
on_forgetpassword_clicked              (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *interfacelogin=lookup_widget(objet,"interfacelogin");
  GtkWidget *interfaceforgetpassword=lookup_widget(objet,"interfaceforgetpassword");
	gtk_widget_destroy(interfacelogin);
	interfaceforgetpassword=create_interfaceforgetpassword();
	gtk_widget_show(interfaceforgetpassword);

}





void
on_returntologinbutton_clicked         (GtkWidget       *objet,
                                        gpointer         user_data) //forgetpassword
{GtkWidget *interfacelogin=lookup_widget(objet,"interfacelogin");
  GtkWidget *interfacesignup=lookup_widget(objet,"interfacesignup");
	gtk_widget_destroy(interfacesignup);
	interfacelogin=create_interfacelogin();
	gtk_widget_show(interfacelogin);

}


void
on_returntologinbutton1_clicked        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{ GtkWidget *ouvre=lookup_widget(objet,"interfacelogin");
GtkWidget *ferme=lookup_widget(objet,"interfaceforgetpassword");
gtk_widget_destroy(ferme);
ouvre=create_interfacelogin();
gtk_widget_show(ouvre);


}






void
on_returntologin2_clicked              (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{ GtkWidget *ferme=lookup_widget(objet,"interfacesignup");
GtkWidget *ouvre=lookup_widget(objet,"interfacelogin");
gtk_widget_destroy(ferme);
ouvre=create_interfacelogin();
gtk_widget_show(ouvre);

}


void
on_confirmsignup_clicked               (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
userfirst k;
GtkWidget *interfacelogin;
interfacelogin=lookup_widget(objet,"interfacelogin");
 GtkWidget *interfacesignup;
interfacesignup=lookup_widget(objet,"interfacesignup");
 GtkWidget *nameentry;
nameentry=lookup_widget(objet,"nameentry");
GtkWidget *surnameentry;
surnameentry=lookup_widget(objet,"surnameentry");
GtkWidget *passwordentry;
passwordentry=lookup_widget(objet,"passwordentry");
GtkWidget *samepassentry;
samepassentry=lookup_widget(objet,"samepasswordentry");
GtkWidget *adresse;
adresse=lookup_widget(objet,"adresseoneentry");
GtkWidget *adressehotmailentry;
adressehotmailentry=lookup_widget(objet,"adressetwoentry");
GtkWidget *pointcomentry;
pointcomentry=lookup_widget(objet,"adressethreeentry");
GtkWidget *identry;
identry=lookup_widget(objet,"identry");
GtkWidget *numberentry;
numberentry=lookup_widget(objet,"numberentry");
GtkWidget *reponseentry=lookup_widget(objet,"questionentry");

strcpy(k.name,gtk_entry_get_text(GTK_ENTRY(nameentry)));
strcpy(k.surname,gtk_entry_get_text(GTK_ENTRY(surnameentry)));
strcpy(k.password,gtk_entry_get_text(GTK_ENTRY(passwordentry)));
strcpy(k.samepass,gtk_entry_get_text(GTK_ENTRY(samepassentry)));
strcpy(k.mailone,gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(k.hotmail,gtk_entry_get_text(GTK_ENTRY(adressehotmailentry)));
strcpy(k.dotcom,gtk_entry_get_text(GTK_ENTRY(pointcomentry)));
strcpy(k.id,gtk_entry_get_text(GTK_ENTRY(identry)));
strcpy(k.number,gtk_entry_get_text(GTK_ENTRY(numberentry)));
strcpy(k.question,gtk_entry_get_text(GTK_ENTRY(reponseentry)));

GtkWidget *labelpass;
labelpass=lookup_widget(objet,"labelpassworderreur");
GtkWidget *labelnumber;
labelnumber=lookup_widget(objet,"labelnumbererreur");
GtkWidget *labelid;
labelid=lookup_widget(objet,"labelerreurid");
GtkWidget *labeladresse=lookup_widget(objet,"labeladresseerreur");
GtkWidget *labelgeneral=lookup_widget(objet,"labelgeneralerror");

if (signupverifypassword(k)==0)
gtk_label_set_text(GTK_LABEL(labelpass),"Password not matched !");
else{	gtk_label_set_text(GTK_LABEL(labelpass),"OK");
	if (signupverifyadresse(k)==0) 
		gtk_label_set_text(GTK_LABEL(labeladresse),"Complete your adresse !");
		
	else { 	gtk_label_set_text(GTK_LABEL(labeladresse),"OK");
		if (signupexist(k)==1) gtk_label_set_text(GTK_LABEL(labeladresse),"exist");
		else {	
				gtk_label_set_text(GTK_LABEL(labeladresse),"ok !");
			if (signupverifyid(k)==0)
				gtk_label_set_text(GTK_LABEL(labelid),"id should have 8 digit !");
			else{	gtk_label_set_text(GTK_LABEL(labelid),"OK");
				if (signupverifynumber(k)==0)
					gtk_label_set_text(GTK_LABEL(labelnumber),"number should have 12 digit!");
				else{	gtk_label_set_text(GTK_LABEL(labelnumber),"OK");
					if(signupverifyall(k)==0) 					gtk_label_set_text(GTK_LABEL(labelgeneral),"Complete your Information !");
					else{gtk_label_set_text(GTK_LABEL(labelgeneral),"OK");
				signup(k);signup1(k);gtk_label_set_text(GTK_LABEL(labelgeneral),"account added");}}}}}}}





/*void
on_getpasswordbutton_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *reponse=lookup_widget(objet,"questionentry");
GtkWidget *adresse=lookup_widget(objet,"adresseentry");
GtkWidget *number=lookup_widget(objet,"numberentry");
GtkWidget *showpass=lookup_widget(objet,"passwordlabel");
userfirst p;
strcpy( p.mailone, gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(p.number, gtk_entry_get_text(GTK_ENTRY(number)));
strcpy( , gtk_entry_get_text(GTK_ENTRY(reponse)));

getpassword(p);


}*/
void
on_getpassword1button_clicked          (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *reponse=lookup_widget(objet,"questionentry");
GtkWidget *adresse;
adresse=lookup_widget(objet,"mailentry");
GtkWidget *number;
number=lookup_widget(objet,"numntry");
GtkWidget *showpass=lookup_widget(objet,"passlabel");
typepass p;char mail[30],num[30];
strcpy( p.mail, gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(p.number, gtk_entry_get_text(GTK_ENTRY(number)));
strcpy(p.reponse , gtk_entry_get_text(GTK_ENTRY(reponse)));
char str[30];
getpassword(&p);
gtk_label_set_text(GTK_LABEL(showpass),p.password);



}

void
on_customerhoteladdbutton_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)//marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacehotel");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfacehotel();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);

}


void
on_customerleasingaddbutton_clicked    (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{

GtkWidget *ouvre=lookup_widget(objet,"interfaceleasing");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfaceleasing();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);

}


void
on_customerflightadd_clicked           (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{

GtkWidget *ouvre=lookup_widget(objet,"interfaceflight");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfaceflight();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);


}


void
on_customerofferaddbutton_clicked      (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{

GtkWidget *ouvre=lookup_widget(objet,"interfaceoffer");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfaceoffer();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_customeragentbutton_clicked         (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{

GtkWidget *ouvre=lookup_widget(objet,"interfacecontactagent");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfacecontactagent();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);

}


void
on_customerchartbutton_clicked         (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{

GtkWidget *ouvre=lookup_widget(objet,"interfacemychart");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfacemychart();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_customernotificationbutton_clicked  (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{

GtkWidget *ouvre=lookup_widget(objet,"interfacewhatsnew");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfacewhatsnew();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);

}


void
on_customerhistorybutton_clicked       (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacehistory");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfacehistory();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);

}


void
on_customersettingbutton_clicked       (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacesettings");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfacesettings();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);

}


void
on_customerlogoutbutton_clicked        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
notinstantcustomer();
GtkWidget *ouvre=lookup_widget(objet,"interfacewelcome");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfacewelcome();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_customerreclamebutton_clicked       (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{

GtkWidget *ouvre=lookup_widget(objet,"interfaceclaimaservice");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomer");
ouvre=create_interfaceclaimservice();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}

void
on_bookhotelreserve_clicked            (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacehotelformulaire");
GtkWidget *ferme=lookup_widget(objet,"interfacehotel");
ouvre=create_interfacehotelformulaire();
GtkWidget *labelname=lookup_widget(objet,"hotelnameyaw");
GtkWidget *labelprix=lookup_widget(objet,"hotelpriceyaw");
char name[30],prix[30];
strcpy(name,gtk_label_get_text(GTK_LABEL(labelname)));
strcpy(prix,gtk_label_get_text(GTK_LABEL(labelprix)));
FILE *f=fopen("restempo.txt","a+");fprintf(f,"Hotel %s %s",name,prix);fclose(f);
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);



}
void
on_returnfromhotelinterfacetocustomerinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{

GtkWidget *ouvre=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfacehotel");
ouvre=create_interfacecustomer();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);

}


void
on_returnfromhotelformulairetohotelinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{

GtkWidget *ouvre=lookup_widget(objet,"interfacehotel");
GtkWidget *ferme=lookup_widget(objet,"interfacehotelformulaire");remove("restempo.txt");
ouvre=create_interfacehotel();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_confirmhotelformulaire_clicked      (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *checkin, *checkout,*title, *name, *surname,*day,*month,*year,*country,*phone,*passport,*mail,*adress,*pension,*rooms ;
	
	checkin = lookup_widget(objet, "checkin_date");
	checkout = lookup_widget(objet, "checkout_date");
	title = lookup_widget(objet, "title_combo_h");
	name = lookup_widget(objet, "name_hotelm");
	surname = lookup_widget(objet, "surname_hotelm");
	pension = lookup_widget(objet, "pension_h");
	day = lookup_widget(objet, "day_hm");
	month = lookup_widget(objet, "month_hm");
	year = lookup_widget(objet, "year_hm");
	country = lookup_widget(objet, "country_hotelm");
	phone = lookup_widget(objet, "phone_hotelm");
	passport = lookup_widget(objet, "passport_hotelm");
	mail = lookup_widget(objet, "specialrequest_hotelm");
	adress = lookup_widget(objet, "adress_hotelm");
	rooms = lookup_widget(objet, "rooms_hotel");

	hotel_info a;
	
	a.birthday.day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
	a.birthday.month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
	a.birthday.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));
	strcpy(a.title, gtk_combo_box_get_active_text(GTK_COMBO_BOX(title)));
	a.rooms = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rooms));
	strcpy(a.name, gtk_entry_get_text(GTK_ENTRY(name)));
	strcpy(a.surname, gtk_entry_get_text(GTK_ENTRY(surname)));
	strcpy(a.adress, gtk_entry_get_text(GTK_ENTRY(adress)));
	strcpy(a.checkin, gtk_label_get_text(GTK_LABEL(checkin)));
	strcpy(a.phone, gtk_entry_get_text(GTK_ENTRY(phone)));
	strcpy(a.checkout, gtk_label_get_text(GTK_LABEL(checkout)));
	strcpy(a.mail, gtk_entry_get_text(GTK_ENTRY(mail))); //special requests
	strcpy(a.country, gtk_entry_get_text(GTK_ENTRY(country)));
	strcpy(a.passport, gtk_entry_get_text(GTK_ENTRY(passport)));
	strcpy(a.pension, gtk_combo_box_get_active_text(GTK_COMBO_BOX(pension)));
	res_hotel(a);
FILE *x=fopen("instantcustomer.txt","r");char verif[50];fscanf(x,"%s",verif);fclose(x);
char prix[30];char str[100];char namer[30];char type[30];
FILE *u=fopen("reservation.txt","a+");//prix
int price;

FILE *f=fopen("restempo.txt","r");fscanf(f,"%s %s %d",type,namer,&price);fclose(f);remove("restempo.txt");

fprintf(u,"%s %s %s-%s-rooms:%d-pension:%s %s %s %s %d/%d/%d %s %s %s %s %d %s\n",type,namer,a.checkin,a.checkout,a.rooms,a.pension,a.title,a.name,a.surname,a.birthday.day,a.birthday.month,a.birthday.year,a.country,a.adress,a.phone,a.passport,price,verif);
fclose(u);
FILE *z=fopen("mychart.txt","a+");fprintf(z,"%s %s %s %d 0\n",type,namer,a.checkin,price);fclose(z);
GtkWidget *ouvre=lookup_widget(objet,"interfacehotelthankyou");
GtkWidget *ferme=lookup_widget(objet,"interfacehotelformulaire");
ouvre=create_interfacehotelthankyou();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);

}
void
on_calendar_checkin_day_selected     (GtkWidget *objet_graphique ,
                                        gpointer         user_data)
{
GtkWidget *calendar,*date_text;
	date_text = lookup_widget(objet_graphique, "checkin_date");
	calendar = lookup_widget(objet_graphique, "calendar_checkin");
	int *year,*day,*month;
	gtk_calendar_get_date(GTK_CALENDAR(calendar),&year,&month,&day);
	int var = month;
	++var;
	char str[50];
	sprintf(str,"%d/%d/%d",day,var,year);
	gtk_label_set_text(GTK_LABEL(date_text),str);
}


void
on_calendar_chekout_day_selected      (GtkWidget *objet_graphique ,
                                        gpointer         user_data)
{
GtkWidget *calendar,*date_text;
	date_text = lookup_widget(objet_graphique, "checkout_date");
	calendar = lookup_widget(objet_graphique, "calendar_chekout");
	int *year,*day,*month;
	gtk_calendar_get_date(GTK_CALENDAR(calendar),&year,&month,&day);
	int var = month;
	++var;
	char str[50];
	sprintf(str,"%d/%d/%d",day,var,year);
	gtk_label_set_text(GTK_LABEL(date_text),str);
}


void
on_customerlogoutfromthankyouhotel_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
notinstantcustomer();
GtkWidget *ouvre=lookup_widget(objet,"interfacewelcome");
GtkWidget *ferme=lookup_widget(objet,"interfacehotelthankyou");
ouvre=create_interfacewelcome();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_customerfromthankyouhoteltochart_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacemychart");
GtkWidget *ferme=lookup_widget(objet,"interfacehotelthankyou");
ouvre=create_interfacemychart();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_Returnfromthankyouhoteltoservices_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfacehotelthankyou");
ouvre=create_interfacecustomer();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}





void
on_customerbookleasingtoleasingformulaire_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfaceleasingformulaire");
GtkWidget *ferme=lookup_widget(objet,"interfaceleasing");
ouvre=create_interfaceleasingformulaire();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_customerreturnfromleasingtohisinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfaceleasing");
ouvre=create_interfacecustomer();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_gofromleasingformulairetothankyou_clicked(GtkWidget *objet_graphique ,
                                        gpointer         user_data)
{
GtkWidget *pickup, *dropoff,*title, *name, *surname,*day,*month,*year,*country,*phone,*passport,*mail,*adress ;
	
	pickup = lookup_widget(objet_graphique, "pickup_date");
	dropoff = lookup_widget(objet_graphique, "dropoff_date");
	title = lookup_widget(objet_graphique, "title_car");
	name = lookup_widget(objet_graphique, "name_car");
	surname = lookup_widget(objet_graphique, "surname_car");
	
	day = lookup_widget(objet_graphique, "day_car");
	month = lookup_widget(objet_graphique, "month_car");
	year = lookup_widget(objet_graphique, "year_car");
	country = lookup_widget(objet_graphique, "country_car");
	phone = lookup_widget(objet_graphique, "phone_car");
	passport = lookup_widget(objet_graphique, "passport_car");
	mail = lookup_widget(objet_graphique, "mail_car");
	adress = lookup_widget(objet_graphique, "adress_car");
	
	car_info a;
	
	a.birthday.day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
	a.birthday.month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
	a.birthday.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));
	strcpy(a.title, gtk_combo_box_get_active_text(GTK_COMBO_BOX(title)));
	
	strcpy(a.name, gtk_entry_get_text(GTK_ENTRY(name)));
	strcpy(a.surname, gtk_entry_get_text(GTK_ENTRY(surname)));
	strcpy(a.adress, gtk_entry_get_text(GTK_ENTRY(adress)));
	strcpy(a.pickup, gtk_label_get_text(GTK_LABEL(pickup)));
	strcpy(a.phone, gtk_entry_get_text(GTK_ENTRY(phone)));
	strcpy(a.dropoff, gtk_label_get_text(GTK_LABEL(dropoff)));
	strcpy(a.mail, gtk_entry_get_text(GTK_ENTRY(mail)));
	strcpy(a.country, gtk_entry_get_text(GTK_ENTRY(country)));
	strcpy(a.passport, gtk_entry_get_text(GTK_ENTRY(passport)));
	
	res_car(a);

GtkWidget *ouvre=lookup_widget(objet_graphique,"interfacehotelthankyou");
GtkWidget *ferme=lookup_widget(objet_graphique,"interfaceleasingformulaire");
ouvre=create_interfacehotelthankyou();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}

void
on_calendar_dropoff_day_selected       (GtkWidget *objet_graphique ,
                                        gpointer         user_data)
{
  GtkWidget *calendar,*date_text;
	date_text = lookup_widget(objet_graphique, "dropoff_date");
	calendar = lookup_widget(objet_graphique, "calendar_dropoff");
	int *year,*day,*month;
	gtk_calendar_get_date(GTK_CALENDAR(calendar),&year,&month,&day);
	int var = month;
	++var;
	char str[50];
	sprintf(str,"%d/%d/%d",day,var,year);
	gtk_label_set_text(GTK_LABEL(date_text),str);
}


void
on_calendar_pickup_day_selected        (GtkWidget *objet_graphique ,
                                        gpointer         user_data)
{

GtkWidget *calendar,*date_text;
	date_text = lookup_widget(objet_graphique, "pickup_date");
	calendar = lookup_widget(objet_graphique, "calendar_pickup");
	int *year,*day,*month;
	gtk_calendar_get_date(GTK_CALENDAR(calendar),&year,&month,&day);
	int var = month;
	++var;
	char str[50];
	sprintf(str,"%d/%d/%d",day,var,year);
	gtk_label_set_text(GTK_LABEL(date_text),str);
}


void
on_returnfromleasingformulairetoleasingbook_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfaceleasing");
GtkWidget *ferme=lookup_widget(objet,"interfaceleasingformulaire");
ouvre=create_interfaceleasing();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_returnfromflightinterfacetocustomerinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacecustomer");

GtkWidget *ferme=lookup_widget(objet,"interfaceflight");

ouvre=create_interfacecustomer();

gtk_widget_destroy(ferme);

gtk_widget_show(ouvre);
}


void
on_gofrominterfaceflighttoflightformulaire_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfaceflightformulaire");
GtkWidget *ferme=lookup_widget(objet,"interfaceflight");
ouvre=create_interfaceflightformulaire();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_gofromflightformulairetothankyou_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data) //marche
{

GtkWidget *from,*title,*name,*surname,*day,*month,*year,*country,*phone,*passport,*mail,*adress,*time;
	
	from = lookup_widget(objet_graphique, "flying_from");
	
	title = lookup_widget(objet_graphique, "title_fl");
	name = lookup_widget(objet_graphique, "name_fl");
	surname = lookup_widget(objet_graphique, "surname_fl");
	day = lookup_widget(objet_graphique, "day_fl");
	month = lookup_widget(objet_graphique, "month_fl");
	year = lookup_widget(objet_graphique, "year_fl");
	country = lookup_widget(objet_graphique, "country_fl");
	phone = lookup_widget(objet_graphique, "phone_fl");
	passport = lookup_widget(objet_graphique, "pass_fl");
	mail = lookup_widget(objet_graphique, "mail_fl");
	adress = lookup_widget(objet_graphique, "ad_fl");
	time = lookup_widget(objet_graphique, "time_flight");
	info a;
	
	a.birthday.day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
	a.birthday.month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
	a.birthday.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));
	strcpy(a.title, gtk_combo_box_get_active_text(GTK_COMBO_BOX(title)));
	strcpy(a.from, gtk_combo_box_get_active_text(GTK_COMBO_BOX(from)));
	
	strcpy(a.name, gtk_entry_get_text(GTK_ENTRY(name)));
	strcpy(a.surname, gtk_entry_get_text(GTK_ENTRY(surname)));
	strcpy(a.adress, gtk_entry_get_text(GTK_ENTRY(adress)));
	
	strcpy(a.phone, gtk_entry_get_text(GTK_ENTRY(phone)));
	
	strcpy(a.mail, gtk_entry_get_text(GTK_ENTRY(mail)));
	strcpy(a.country, gtk_entry_get_text(GTK_ENTRY(country)));
	strcpy(a.passport, gtk_entry_get_text(GTK_ENTRY(passport)));
	strcpy(a.time, gtk_combo_box_get_active_text(GTK_COMBO_BOX(time)));
	
	res_fl(a);
	
	
	



GtkWidget *ouvre;
GtkWidget *ferme=lookup_widget(objet_graphique,"interfaceflightformulaire");
ouvre=create_interfacehotelthankyou();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_calendar_dep_day_selected        (GtkWidget *objet_graphique ,
                                        gpointer         user_data)
{
GtkWidget *calendar,*date_text;
	date_text = lookup_widget(objet_graphique, "dep_date");
	calendar = lookup_widget(objet_graphique, "calendar_dep");
	int *year,*day,*month;
	gtk_calendar_get_date(GTK_CALENDAR(calendar),&year,&month,&day);
	int var = month;
	++var;
	char str[50];
	sprintf(str,"%d/%d/%d",day,var,year);
	gtk_label_set_text(GTK_LABEL(date_text),str);
}


void
on_calendar_ret_day_selected
                                          (GtkWidget *objet_graphique ,
                                        gpointer         user_data)
{
GtkWidget *calendar,*date_text;
	date_text = lookup_widget(objet_graphique, "ret_date");
	calendar = lookup_widget(objet_graphique, "calendar_ret");
	int *year,*day,*month;
	gtk_calendar_get_date(GTK_CALENDAR(calendar),&year,&month,&day);
	int var = month;
	++var;
	char str[50];
	sprintf(str,"%d/%d/%d",day,var,year);
	gtk_label_set_text(GTK_LABEL(date_text),str);
}



void
on_gofromflightformulairetoflighinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfaceflight");
GtkWidget *ferme=lookup_widget(objet,"interfaceflightformulaire");
ouvre=create_interfaceflight();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_returnfrominterfaceoffertocustomer_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfaceoffer");
ouvre=create_interfacecustomer();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_gofrominterfaceoffertointerfaceformulaire_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfaceofferformulaire");
GtkWidget *ferme=lookup_widget(objet,"interfaceoffer");
ouvre=create_interfaceofferformulaire();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);

}


void
on_gofrominterfaceofferformualiretooffer_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfaceoffer");
GtkWidget *ferme=lookup_widget(objet,"interfaceofferformulaire");
ouvre=create_interfaceoffer();

gtk_widget_show(ouvre);
gtk_widget_destroy(ferme);
}


void
on_gofromofferormulairetothankyou_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacehotelthankyou");

GtkWidget *ferme=lookup_widget(objet,"interfaceofferformulaire");

ouvre=create_interfacehotelthankyou();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_gofrominterfacesettingstointerfacecustomer_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfacesettings");
ouvre=create_interfacecustomer();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


/*void
on_gofromcustomersettingstointerfacechangepictures_activate
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}*/
void
on_customersettingtopicturechange_clicked
                                        (GtkWidget      *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacecustomerchangepicture");
GtkWidget *ferme=lookup_widget(objet,"interfacesettings");
ouvre=create_interfacecustomerchangepicture();
gtk_widget_show(ouvre);
gtk_widget_destroy(ferme);
}

void
on_gofromcustomersettingtocustomerprotectinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacecustomerprotect");
GtkWidget *ferme=lookup_widget(objet,"interfacesettings");
ouvre=create_interfacecustomerprotect();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_gofromcustomersettingstodeleteaccountinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{

GtkWidget *ouvre=lookup_widget(objet,"interfacecustomerdeleteaccount");
GtkWidget *ferme=lookup_widget(objet,"interfacesettings");
ouvre=create_interfacecustomerdeleteaccount();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_returnfromcustomerprotecttosettings_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacesettings");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomerprotect");
ouvre=create_interfacesettings();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_gofromcustomerprotecttochangeaccount_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //changer donner de user a verifierrrrr////////////////////////// notorios problema
{
GtkWidget *ouvre=lookup_widget(objet,"interfaceaccountprotected");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomerprotect");

GtkWidget *entry=lookup_widget(objet,"namechangeentry");
GtkWidget *entrya=lookup_widget(objet,"surnamechangeentry");
GtkWidget *entryb=lookup_widget(objet,"passwordchangeentry");
GtkWidget *entryc=lookup_widget(objet,"changepasswordconfirmentry");
GtkWidget *entryd=lookup_widget(objet,"changenumberentry");
GtkWidget *entrye=lookup_widget(objet,"oldreponsechangeentry");
GtkWidget *entryf=lookup_widget(objet,"oldpassword");
GtkWidget *label1=lookup_widget(objet,"passwordchangeerror");
GtkWidget *label2=lookup_widget(objet,"generalerrorchangelabel");
char name[30],surnam[30],newpass[30],newotherpass[30],number[30],oldanswer[30],oldpassword[30];
strcpy(name,gtk_entry_get_text(GTK_ENTRY(entry)));
strcpy(surnam,gtk_entry_get_text(GTK_ENTRY(entrya)));
strcpy(newpass,gtk_entry_get_text(GTK_ENTRY(entryb)));
strcpy(newotherpass,gtk_entry_get_text(GTK_ENTRY(entryc)));
strcpy(number,gtk_entry_get_text(GTK_ENTRY(entryd)));
strcpy(oldanswer,gtk_entry_get_text(GTK_ENTRY(entrye)));
strcpy(oldpassword,gtk_entry_get_text(GTK_ENTRY(entryf)));

if (strlen(name)==0 && strlen(surnam)==0 && strlen(newpass)==0 && strlen(newotherpass)==0 && strlen(oldpassword)==0 && strlen(oldanswer)==0) gtk_label_set_text(GTK_LABEL(label1),"complete information");
else{ if ( strcmp(newpass,newotherpass)!=0) gtk_label_set_text(GTK_LABEL(label1),"password unmatched");

	else{ if (verifpassquestion(oldpassword,oldanswer)!=0) gtk_label_set_text(GTK_LABEL(label2),"invalid verification input");
		else   { 
			/*deleteoldinformation();
			 deleteoldinformationuser();
			FILE *f=fopen("usersappend.txt","a+");
			FILE *t=fopen("users.txt","a+");
				strcpy(k.name,p.name);
				strcpy(k.surnam,p.surnam);
				strcpy(k.oldpassword,p.newpass);
				strcpy(k.number,p.number);
			fprintf(f,"%s %s %s %s %s %s %s\n",k.name,k.surnam,k.oldpassword,k.oldmail,k.id,k.number,k.oldanswer);
			fprintf(t,"%s %s 1 0\n",k.oldmail,k.oldpassword);
			fclose(f);
			fclose(t); */

			// change in usersappend.txt
			userprotect1 xd;
			int lol = find_current_user1(&xd);
			FILE *k=fopen("instantcustomer.txt","r");char verif[60];fscanf(k,"%s",verif);fclose(k);
			int ligne = find_lineclientsettings("usersappend.txt",verif);
			char newline[100]="";
			strcat(newline,name);
			strcat(newline," ");
			strcat(newline,surnam);
			strcat(newline," ");
			strcat(newline,newpass);
			strcat(newline," ");
			strcat(newline,verif);
			strcat(newline," ");
			strcat(newline,xd.id);
			strcat(newline," ");
			strcat(newline,number);
			strcat(newline," ");
			strcat(newline,xd.oldanswer);
			strcat(newline,"\n");
			replace_line_infile(ligne,newline,"usersappend.txt"); // dont forget users.txt
			// change in users.txt
			int g = find_line("users.txt",verif);
			char newline1[100]="";
			strcat(newline1,verif);
			strcat(newline1," ");
			strcat(newline1,newpass);
			strcat(newline1," ");
			strcat(newline1,"1 1\n");
			replace_line_infile(g,newline1,"users.txt");
			ouvre=create_interfaceaccountprotected();
			gtk_widget_destroy(ferme);
			gtk_widget_show(ouvre); }
		}
    }

}


/*void
on_gofromdeletetointerfaceaccountdeleted_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ouvre=lookup_widget(objet,"interfacecustomerdeleteaccount");
GtkWidget *ferme=lookup_widget(objet,"interfaceaccountdeleted");
ouvre=create_interfaceaccountdeleted();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}*/

void
on_gofromdeletetointerfaceaccountdeleted1_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) // ici ou la supprime
{
GtkWidget *ouvre=lookup_widget(objet,"interfaceaccountdeleted");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomerdeleteaccount");

GtkWidget *mailverif=lookup_widget(objet,"maildeleteverify");
GtkWidget *passoneentry=lookup_widget(objet,"passwordoneverifydelete");
GtkWidget *passtwoentry=lookup_widget(objet,"passwordtwoverify");
GtkWidget *label1=lookup_widget(objet,"labelofdeletecustomer");
userprotect p;
strcpy(p.oldmail,gtk_entry_get_text(GTK_ENTRY(mailverif)));
strcpy(p.newpass,gtk_entry_get_text(GTK_ENTRY(passoneentry)));
strcpy(p.newotherpass,gtk_entry_get_text(GTK_ENTRY(passtwoentry)));
FILE *t=fopen("instantcustomer.txt","r");char verif[50];fscanf(t,"%s\n",verif);fclose(t);
if ( strlen(p.newpass)==0 && strlen(p.newotherpass)==0 && strlen(p.oldmail)==0 ) gtk_label_set_text(GTK_LABEL(label1),"complete information");	
	{if (strcmp(p.newpass,p.newotherpass)!=0 ) gtk_label_set_text(GTK_LABEL(label1),"Unmatched password");
	else { if (strcmp(p.oldmail,verif)!=0) gtk_label_set_text(GTK_LABEL(label1),"False information");
		else	{
			deleteoldinformation();
			deleteoldinformationuser();
			ouvre=create_interfaceaccountdeleted();
			gtk_widget_destroy(ferme);
			gtk_widget_show(ouvre); remove("instantcustomer.txt"); }
		}
	}

}

void
on_gofromcustomerdeleteaccounttosettings_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacesettings");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomerdeleteaccount");
					
ouvre=create_interfacesettings();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_gofrominterfaceaccountdeletedtowelcome_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) 
{
GtkWidget *ouvre=lookup_widget(objet,"interfacewelcome");
GtkWidget *ferme=lookup_widget(objet,"interfaceaccountdeleted");
ouvre=create_interfacewelcome();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_gofrominterfacepicurechangedtointerfacecustomer_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) 
{
GtkWidget *ouvre=lookup_widget(objet,"interfacepicturechanged");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomerchangepicture");
ouvre=create_interfacepicturechanged();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_returnfrompicturechangetosettings_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) 
{
GtkWidget *ouvre=lookup_widget(objet,"interfacesettings");
GtkWidget *ferme=lookup_widget(objet,"interfacecustomerchangepicture");
ouvre=create_interfacesettings();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_gofromfinishpicturetocustomerinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *ouvre=lookup_widget(objet,"interfacesettings");
GtkWidget *ferme=lookup_widget(objet,"interfacepicturechanged");
ouvre=create_interfacesettings();
gtk_widget_destroy(ferme);
gtk_widget_show(ouvre);
}


void
on_gofrominterfacefinishprotectcustomertocustomerinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) 
{
GtkWidget *ouvre=lookup_widget(objet,"interfacesettings");
GtkWidget *ferme=lookup_widget(objet,"interfaceaccountprotected");
ouvre=create_interfacesettings();
gtk_widget_show(ouvre);
gtk_widget_destroy(ferme);

}





void
on_deletenotification_clicked          (GtkWidget       *objet,
                                        gpointer         user_data) 
{
GtkWidget *rouvre=lookup_widget(objet,"interfacewhatsnew");
GtkWidget *combo=lookup_widget(objet,"comboboxchoixnotification");
char p[30];
strcpy(p,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
deletewhatsnew(p);
gtk_widget_destroy(rouvre);rouvre=create_interfacewhatsnew();gtk_widget_show(rouvre);
}


void
on_buttonviewnotification_clicked      (GtkWidget       *objet,
                                        gpointer         user_data) 
{
GtkWidget *combo=lookup_widget(objet,"comboboxchoixnotification");
FILE *t=fopen("instantcustomer.txt","r");char verif[50];fscanf(t,"%s",verif);fclose(t);
FILE *f=fopen("whatsnew.txt","a+");
char cle[30];char n[30];int e; char verifcustomer[30];
if (f!= NULL) while (fscanf(f,"%s %s %d %s\n",cle,n,&e,verifcustomer)!= EOF) if((e==0) && strcmp(verifcustomer,verif)==0) { 
gtk_combo_box_append_text(GTK_COMBO_BOX(combo),cle);}
fclose(f);
}


void
on_refreshwhatsnewbutton_clicked       (GtkWidget       *objet,
                                        gpointer         user_data) 
{
GtkWidget *tree=lookup_widget(objet,"treeviewwhatsnew");
GtkWidget *combo=lookup_widget(objet,"comboboxchoixnotification");
showtreewhatsnew(tree);
}


void
on_returnfromwhatsnewtocustomer_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfacewhatsnew");
open=create_interfacecustomer();
gtk_widget_show(open);
gtk_widget_hide(ferme);

}


void
on_returnfromhistorytocustomer_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfacehistory");
open=create_interfacecustomer();
gtk_widget_show(open);
gtk_widget_destroy(ferme);
}


void
on_modifordeletehistoryoption_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *combo=lookup_widget(objet,"combohistory");
GtkWidget *rouvre=lookup_widget(objet,"interfacehistory");
char p[30];
strcpy(p,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
deletehistory(p);
gtk_widget_destroy(rouvre);rouvre=create_interfacehistory();gtk_widget_show(rouvre);
}


void
on_refreshcomboofhistory_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *combo=lookup_widget(objet,"combohistory");
FILE *t=fopen("instantcustomer.txt","r");char verif[50];fscanf(t,"%s",verif);fclose(t);
FILE *f=fopen("history.txt","a+");

char cle[30];char n[30];int e;char d[30]; char verifcustomer[30];
if (f!= NULL) while (fscanf(f,"%s %s %s %d %s\n",cle,n,d,&e,verifcustomer)!= EOF) if((e==0) && strcmp(verif,verifcustomer)==0) { 
gtk_combo_box_append_text(GTK_COMBO_BOX(combo),n);}
fclose(f);
}


void
on_refreshtreehisotry_clicked          (GtkWidget       *objet,
                                        gpointer         user_data) //marche can be editable
{
GtkWidget *tree=lookup_widget(objet,"treehistory");
showtreehistory(tree);
}


void
on_returnfrommycharttocustomer_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfacemychart");
open=create_interfacecustomer();
gtk_widget_show(open);
gtk_widget_destroy(ferme);
}


void
on_usepromotionalcode_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"interfacemychart2");
GtkWidget *ferme=lookup_widget(objet,"interfacemychart");
open=create_interfacemychart2();
gtk_widget_show(open);
gtk_widget_destroy(ferme);
}


void
on_refreshcomboboxofchart_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *combo=lookup_widget(objet,"combochart");
FILE *f=fopen("mychart.txt","r");
char cle[30];char n[30];int e;char d[30];int p; char verifcustomer[30];
while (fscanf(f,"%s %s %s %d %d\n",cle,n,d,&p,&e)!=EOF) { 
gtk_combo_box_append_text(GTK_COMBO_BOX(combo),n);}
fclose(f);



}


void
on_Deletemychart_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *combo=lookup_widget(objet,"combochart");
GtkWidget *tree=lookup_widget(objet,"treeviewmychart");
GtkWidget *rouvre=lookup_widget(objet,"interfacemychart");
char p[30];
strcpy(p,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
deletemychart(p);
gtk_widget_destroy(rouvre);rouvre=create_interfacemychart();gtk_widget_show(rouvre);
showtreemychart(tree);
FILE *f=fopen("mychart.txt","r");

}


void
on_refreshtreeviewmychart_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *tree=lookup_widget(objet,"treeviewmychart");
GtkWidget *label=lookup_widget(objet,"totalpricelabel");
showtreemychart(tree);
int r=calculprix();
char str[50];
sprintf(str,"%d",r);
gtk_label_set_text(GTK_LABEL(label),str);

}





void
on_enterpromotionalcode_clicked        (GtkWidget       *objet,
                                        gpointer         user_data) //verifier le code et faire reduction
{
GtkWidget *label=lookup_widget(objet,"verifypromotionalcodelabel");
GtkWidget *label1=lookup_widget(objet,"totalreductionlabel");
GtkWidget *entry=lookup_widget(objet,"promotionalcodeverifyentry");
promotion p;
strcpy(p.promoentry,gtk_entry_get_text(GTK_ENTRY(entry)));
GtkWidget *tri=lookup_widget(objet,"treeviewchart2");
int r=calculprix();char str[50];showtreemychart(tri);

if (verifpromotionalcode(&p)==1) 
{
	r=((r*70)/100);
	gtk_label_set_text(GTK_LABEL(label),"Verified code");
	int line = find_line("promotionalcodes.txt", p.promoentry);
	char newline[100]="";
	FILE *f=fopen("instantcustomer.txt","r");char verifcustomer[50];fscanf(f,"%s\n",verifcustomer);fclose(f);
	strcat(newline, p.promoentry);
	strcat(newline," ");
	strcat(newline, verifcustomer);
	strcat(newline," ");
	strcat(newline,"1\n");
	replace_line_infile(line, newline, "promotionalcodes.txt");

					

				


}
else gtk_label_set_text(GTK_LABEL(label),"Code doesnt Exist !");


sprintf(str,"%d",r);

gtk_label_set_text(GTK_LABEL(label1),str);
}

void
on_finishchart2_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)  //fonctionreservation vider le panier
{
GtkWidget *open=lookup_widget(objet,"interfacechartfinale");
GtkWidget *ferme=lookup_widget(objet,"interfacemychart2");
open=create_interfacechartfinale();
gtk_widget_show(open);
gtk_widget_destroy(ferme);
}


void
on_returnfromchart2tochart1_clicked    (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *open=lookup_widget(objet,"interfacemychart");
GtkWidget *ferme=lookup_widget(objet,"interfacemychart2");
open=create_interfacemychart();
gtk_widget_show(open);
gtk_widget_destroy(ferme);
}


void
on_finishbookingchartfinale_clicked    (GtkWidget       *objet,
                                        gpointer         user_data) //marche
{
GtkWidget *open=lookup_widget(objet,"interfacewelcome");
GtkWidget *ferme=lookup_widget(objet,"interfacechartfinale");
open=create_interfacewelcome();
gtk_widget_show(open);
gtk_widget_destroy(ferme);
}


void
on_finishagentcontactedah_clicked      (GtkWidget       *objet,
                                        gpointer         user_data){

GtkWidget *open=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfaceagentcontacted");
open=create_interfacecustomer();
gtk_widget_show(open);
gtk_widget_destroy(ferme);
}

void
on_returnfromcustomerclaimstointerfacecustomer_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data){
GtkWidget *open=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfaceclaimservice");
open=create_interfacecustomer();
gtk_widget_show(open);
gtk_widget_destroy(ferme);
}
void
on_interfaceclaimservice_show          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *combo2=lookup_widget(objet,"comboclaimserviceselectfromhistor");
FILE *t=fopen("instantcustomer.txt","r");char verif[50];fscanf(t,"%s",verif);fclose(t);
FILE *f=fopen("history.txt","r");
char type[30],nom[30],d[30];int e;char verifcustomer[30];
if (f!= NULL) while (fscanf(f,"%s %s %s %d %s\n",type,nom,d,&e,verifcustomer)!= EOF) if((e==0) && strcmp(verif,verifcustomer)==0) { 
gtk_combo_box_append_text(GTK_COMBO_BOX(combo2),nom);}
fclose(f);
}

void
on_envoyclaimstoagent_clicked          (GtkWidget       *objet,
                                        gpointer         user_data) 
{
GtkWidget *combo1=lookup_widget(objet,"comboclaimtypeservice");
GtkWidget *combo2=lookup_widget(objet,"comboclaimserviceselectfromhistor");
GtkWidget *entry1=lookup_widget(objet,"claimdescriptionentry");
FILE *t=fopen("instantcustomer.txt","r");char verif[50];fscanf(t,"%s",verif);fclose(t);
FILE *c=fopen("claims.txt","a+");
char str[60];strcpy(str,gtk_entry_get_text(GTK_ENTRY(entry1)));
char n[30];char k[30];
strcpy(k,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1)));
strcpy(n,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo2)));
fprintf(c,"%s %s %s %s\n",k,n,str,verif);fclose(c);
GtkWidget *open=lookup_widget(objet,"interfaceserviceclaimed");
GtkWidget *ferme=lookup_widget(objet,"interfaceclaimservice");
open=create_interfaceserviceclaimed();
gtk_widget_show(open);
gtk_widget_destroy(ferme);
}
void
on_returnfromcustomercontacttocutomerinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data){

GtkWidget *open=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfacecontactagent");
open=create_interfacecustomer();
gtk_widget_show(open);
gtk_widget_destroy(ferme);
}

void
on_customeraddcontactagent_clicked     (GtkWidget       *objet,
                                        gpointer         user_data){
GtkWidget *open=lookup_widget(objet,"interfaceagentcontacted");
GtkWidget *ferme=lookup_widget(objet,"interfacecontactagent");

GtkWidget *combo=lookup_widget(objet,"comboboxchooseservicecontactagent");
GtkWidget *spinfromday=lookup_widget(objet,"spinfromday1");
GtkWidget *spinfrommonth=lookup_widget(objet,"spinfrommonth1");
GtkWidget *spinfromyear=lookup_widget(objet,"spinfromyear1");
GtkWidget *spintoday=lookup_widget(objet,"spintoday1");
GtkWidget *spintomonth=lookup_widget(objet,"spintomonth1");
GtkWidget *spintoyear=lookup_widget(objet,"spintoyear1");
GtkWidget *entrytitle=lookup_widget(objet,"titleservice1");
GtkWidget *entryyaw=lookup_widget(objet,"titleservice2");
FILE *t=fopen("instantcustomer.txt","r");char verif[50];fscanf(t,"%s",verif);fclose(t);
char combovalue[30];strcpy(combovalue,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
char title[20];strcpy(title,gtk_entry_get_text(GTK_ENTRY(entrytitle)));
char description[150];strcpy(description,gtk_entry_get_text(GTK_ENTRY(entryyaw)));

int  sfd=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON (spinfromday));
int  sfm=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON (spinfrommonth));
int  sfy=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON (spinfromyear));
int  std=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON (spintoday));
int  stm=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON (spintomonth));
int  sty=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON (spintoyear));
FILE *f=fopen("contactagent.txt","a+");


fprintf(f,"%s %s %d/%d/%d %d/%d/%d %s\n",combovalue,description,sfd,sfm,sfy,std,stm,sty,verif);
fclose(f);

open=create_interfaceagentcontacted();
gtk_widget_show(open);
gtk_widget_destroy(ferme);

}

void
on_gofromfinishcustomerclaimtocustomerinterface_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data){
GtkWidget *open=lookup_widget(objet,"interfacecustomer");
GtkWidget *ferme=lookup_widget(objet,"interfaceserviceclaimed");
open=create_interfacecustomer();
gtk_widget_show(open);
gtk_widget_destroy(ferme);

}
void
on_interfacecontactagent_show          (GtkWidget       *objet,
                                        gpointer         user_data) //nefaitrien
{


}
/////////////////////////////////////////////////////////////////////////////interface ya_agent//////////////

void
on_hotelsloul_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1=lookup_widget(objet,"interfaceagent");
GtkWidget *win2=lookup_widget(objet,"window_hotels");
win2=create_window_hotels();gtk_widget_show(win2);gtk_widget_destroy(win1);
}


void
on_gofrominterfaceagenttorequests_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *ouvre=lookup_widget(objet,"window_demands");
GtkWidget *ferme=lookup_widget(objet,"interfaceagent");
ouvre=create_window_demands();gtk_widget_show(ouvre);gtk_widget_destroy(ferme);
}


void
on_leasingloul_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1=lookup_widget(objet,"interfaceagent");
GtkWidget *win2=lookup_widget(objet,"window_name_of_leasing");


 win2=create_window_name_of_leasing();gtk_widget_show(win2);gtk_widget_destroy(win1);
}


void
on_offreoftthedays_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1=lookup_widget(objet,"interfaceagent");
GtkWidget *win2=lookup_widget(objet,"window_offre_of_the_days"); win2=create_window_offre_of_the_days();gtk_widget_show(win2);gtk_widget_destroy(win1);
}


void
on_gofrominterfaceagenttoeditcontent_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1=lookup_widget(objet,"interfaceagent");
GtkWidget *win2=lookup_widget(objet,"window_hotels"); win2=create_window_hotels();gtk_widget_show(win2);gtk_widget_destroy(win1);
}


void
on_agentsettings_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ferme=lookup_widget(objet,"interfaceagent");
GtkWidget *ouvre=lookup_widget(objet,"window_remove"); ouvre=create_window_remove();gtk_widget_show(ouvre);gtk_widget_destroy(ferme);
}


void
on_gofrominterfaceagenttointerfaceeditflight_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"window_flight");
GtkWidget *ferme=lookup_widget(objet,"interfaceagent");
open=create_window_flight();gtk_widget_show(open);gtk_widget_destroy(ferme);
}


void
on_logoutfromagent_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *welcome,*flight;
	flight=lookup_widget(objet,"window_flight");
	gtk_widget_destroy(flight);
	welcome=create_interfacewelcome();
	gtk_widget_show(welcome);
	remove("instantcustomer.txt");

}


void
on_gofrominterfaceagenthoteltoagentflight_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *hotels,*flight,*leasing,*offer;
	hotels = lookup_widget(objet,"window_hotels");
	flight = lookup_widget(objet,"window_flight");
	leasing = lookup_widget(objet,"window_name_of_leasing");
	offer = lookup_widget(objet,"window_offre_of_the_days");
	gtk_widget_destroy(hotels);
	gtk_widget_destroy(flight);
	gtk_widget_destroy(leasing);
	flight=create_window_flight();
	gtk_widget_show(flight);
}


void
on_fenetre_leasing_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *hotels,*flight,*leasing,*offer;
	hotels = lookup_widget(objet,"window_hotels");
	flight = lookup_widget(objet,"window_flight");
	leasing = lookup_widget(objet,"window_name_of_leasing");
	offer = lookup_widget(objet,"window_offre_of_the_days");
	gtk_widget_destroy(hotels);
	gtk_widget_destroy(flight);
	gtk_widget_destroy(leasing);
	leasing=create_window_name_of_leasing();
	gtk_widget_show(leasing);
}


void
on_fenetre_offre_of_the_day_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *hotels,*flight,*leasing,*offer;
	hotels = lookup_widget(objet,"window_hotels");
	flight = lookup_widget(objet,"window_flight");
	leasing = lookup_widget(objet,"window_name_of_leasing");
	offer = lookup_widget(objet,"window_offre_of_the_days");
	gtk_widget_destroy(hotels);
	gtk_widget_destroy(flight);
	gtk_widget_destroy(leasing);
	offer=create_window_offre_of_the_days();
	gtk_widget_show(offer);
}


void
on_gofrominterfaceagenthoteltointerfaceagent_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"interfaceagent");
GtkWidget *ferme=lookup_widget(objet,"window_hotels");
open=create_interfaceagent();gtk_widget_show(open);gtk_widget_destroy(ferme);
}


void
on_gofrominterfacehotelstosettings_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"window_remove");
GtkWidget *ferme=lookup_widget(objet,"window_hotels");
open=create_window_remove();gtk_widget_show(open);gtk_widget_destroy(ferme);
}


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewmembers=lookup_widget(objet,"treeviewmembers");
afficher(treeviewmembers);
}


void
on_delet_hotel_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input=lookup_widget(objet,"entry164");
GtkWidget *win1=lookup_widget(objet,"window_hotels");
GtkWidget *treeview1 ;
char name_hotel[100];

strcpy(name_hotel,gtk_entry_get_text(GTK_ENTRY(input)));

suprimer(name_hotel);


gtk_widget_destroy(win1); win1=create_window_hotels();gtk_widget_show(win1);

treeview1=lookup_widget(win1,"treeviewmembers");
afficher(treeview1);
}


void
on_saved_hotels_to_treeview_add_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *inputname;
	GtkWidget *inputdescription;
        GtkWidget *inputprice;
	inputname=lookup_widget(objet, "entry156");
	inputdescription=lookup_widget(objet,"entry157");
        inputprice=lookup_widget(objet,"entry158");
	char  *prices=gtk_entry_get_text(GTK_ENTRY(inputprice));
	char *name=gtk_entry_get_text(GTK_ENTRY(inputname));
	char *descib=gtk_entry_get_text(GTK_ENTRY(inputdescription));
	
	ajouter(name,prices,descib);
  // jcp 

GtkWidget *win1=lookup_widget(objet,"window_hotels");
gtk_widget_destroy(win1); win1=create_window_hotels();gtk_widget_show(win1);
GtkWidget *treeview1 ;
treeview1=lookup_widget(win1,"treeviewmembers");
afficher(treeview1);
}


void
on_logout0_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1=lookup_widget(objet,"window_hotels");
GtkWidget *win2=lookup_widget(objet,"interfaceagent");
 win2=create_interfaceagent();gtk_widget_show(win2);gtk_widget_destroy(win1);
}


void
on_afficher2_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewmembers=lookup_widget(objet,"treeview_offer_of_the_day");
afficher2(treeviewmembers);
}


void
on_logout11_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1=lookup_widget(objet,"window_offre_of_the_days");
GtkWidget *win2=lookup_widget(objet,"interfaceagent");
win2=create_interfaceagent();gtk_widget_show(win2);gtk_widget_destroy(win1);
}


void
on_gofromofferofthedeayagenttocustomerdemands_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"interfaceagent");
GtkWidget *ferme=lookup_widget(objet,"interface_hotels");
open=create_interfaceagent();gtk_widget_show(open);gtk_widget_destroy(ferme);
}


void
on_gofrominterfaceoffertointerfaceagent_enter
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"interfaceagent");
GtkWidget *ferme=lookup_widget(objet,"interface_hotels");
open=create_interfaceagent();gtk_widget_show(open);gtk_widget_destroy(ferme);
}


void
on_gofrominterfaceoffertointerfacesettings_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"window_remove");
GtkWidget *ferme=lookup_widget(objet,"interface_offre_of_the_days");
open=create_window_remove();gtk_widget_show(open);gtk_widget_destroy(ferme);
}


void
on_buttonHotels_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *hotels,*flight,*leasing,*offer;
	hotels = lookup_widget(objet,"window_hotels");
	flight = lookup_widget(objet,"window_flight");
	leasing = lookup_widget(objet,"window_name_of_leasing");
	offer = lookup_widget(objet,"window_offre_of_the_days");
	gtk_widget_destroy(hotels);
	gtk_widget_destroy(flight);
	gtk_widget_destroy(leasing);
	hotels=create_window_hotels();
	gtk_widget_show(hotels);
}


void
on_buttonLeasing_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1=lookup_widget(objet,"window_offre_of_the_days");
GtkWidget *win2=lookup_widget(objet,"window_name_of_leasing");


 win2=create_window_name_of_leasing();gtk_widget_show(win2);gtk_widget_destroy(win1);
}


void
on_ya_delet_offre_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input=lookup_widget(objet,"entry165");
GtkWidget *win1=lookup_widget(objet,"window_offre_of_the_days");
GtkWidget *treeview1 ;
char name_offre[100];

strcpy(name_offre,gtk_entry_get_text(GTK_ENTRY(input)));

suprimer2(name_offre);


gtk_widget_destroy(win1); win1=create_window_offre_of_the_days();gtk_widget_show(win1);

treeview1=lookup_widget(win1,"treeview_offre_of_the_day");
afficher2(treeview1);
}


void
on_saved_to_text_offre_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
     GtkWidget *inputvalid_until;
	GtkWidget *inputname_of_the_offre;
        GtkWidget *inputdescriptions;
	inputvalid_until=lookup_widget(objet, "entry159");
	inputname_of_the_offre=lookup_widget(objet,"entry160");
        inputdescriptions=lookup_widget(objet,"entry161");
	char  *until=gtk_entry_get_text(GTK_ENTRY(inputvalid_until));
	char *name=gtk_entry_get_text(GTK_ENTRY(inputname_of_the_offre));
	char *descib=gtk_entry_get_text(GTK_ENTRY(inputdescriptions));
	
	ajouter2(until,name,descib);


GtkWidget *win1=lookup_widget(objet,"window_offre_of_the_days");
gtk_widget_destroy(win1); win1=create_window_offre_of_the_days();gtk_widget_show(win1);

GtkWidget *treeview1 ;
treeview1=lookup_widget(win1,"treeview_offre_of_the_day");
afficher2(treeview1);
}


void
on_logout20_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1=lookup_widget(objet,"window_name_of_leasing");
GtkWidget *win2=lookup_widget(objet,"interfaceagent");
 win2=create_interfaceagent();gtk_widget_show(win2);gtk_widget_destroy(win1);

}


void
on_buttonhotels_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1=lookup_widget(objet,"window_name_of_leasing");
GtkWidget *win2=lookup_widget(objet,"window_hotels");
win2=create_window_hotels();gtk_widget_show(win2);gtk_widget_destroy(win1);
}


void
on_button_offree_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *win1=lookup_widget(objet,"window_name_of_leasing");
GtkWidget *win2=lookup_widget(objet,"window_offre_of_the_days");
 win2=create_window_offre_of_the_days();gtk_widget_show(win2);gtk_widget_destroy(win1);
}


void
on_gofrominterfaceleasingtoflight_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"window_flight");
GtkWidget *ferme=lookup_widget(objet,"window_name_of_leasing");
open=create_window_flight();gtk_widget_show(open);gtk_widget_destroy(ferme);
}


void
on_gofrominterfaceagentleasingtointerfacecustomerdemands_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"window_name_of_leasing");
GtkWidget *ferme=lookup_widget(objet,"interfaceagent");
open=create_window_flight();gtk_widget_show(open);gtk_widget_destroy(ferme);
}


void
on_gofrominterfaceleasingagentointerfaceagent_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"interfaceagent");
GtkWidget *ferme=lookup_widget(objet,"window_name_of_leasing");
open=create_window_name_of_leasing();gtk_widget_show(open);gtk_widget_destroy(ferme);
}


void
on_gofrominterfaceleasingtointerfaceagentsettings_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *open=lookup_widget(objet,"interfaceagent");
GtkWidget *ferme=lookup_widget(objet,"window_name_of_leasing");
open=create_interfaceagent();gtk_widget_show(open);gtk_widget_destroy(ferme);
}


void
on_ya_delet_car_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input=lookup_widget(objet,"entry166");
GtkWidget *win1=lookup_widget(objet,"window_name_of_leasing");
GtkWidget *treeview1 ;
char name_car[100];
strcpy(name_car,gtk_entry_get_text(GTK_ENTRY(input)));
suprimer3(name_car);
gtk_widget_destroy(win1); win1=create_window_name_of_leasing();gtk_widget_show(win1);
treeview1=lookup_widget(win1,"treeview2");
afficher3(treeview1);
}


void
on_afficher3_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2=lookup_widget(objet,"treeview2");
afficher3(treeview2);
}

void
on_saved3_to_users3_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *inputname;
	GtkWidget *inputdescription;
        GtkWidget *inputprice;
	inputname=lookup_widget(objet, "entry60");
	inputdescription=lookup_widget(objet,"entry162");
        inputprice=lookup_widget(objet,"entry163");
	char  *prices=gtk_entry_get_text(GTK_ENTRY(inputprice));
	char *name=gtk_entry_get_text(GTK_ENTRY(inputname));
	char *descib=gtk_entry_get_text(GTK_ENTRY(inputdescription));
	
	ajouter3(name,prices,descib);

GtkWidget *win1=lookup_widget(objet,"window_name_of_leasing");
gtk_widget_destroy(win1); win1=create_window_name_of_leasing();gtk_widget_show(win1);

GtkWidget *treeview1 ;
treeview1=lookup_widget(win1,"treeview2");
afficher3(treeview1);
}














void
on_precedhotelyaw_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *labelname=lookup_widget(objet,"hotelnameyaw");
GtkWidget *labeldescription=lookup_widget(objet,"hoteldescriptionyaw");
GtkWidget *labelprice=lookup_widget(objet,"hotelpriceyaw");

}


void
on_nexthotelyaw_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *labelname=lookup_widget(objet,"hotelnameyaw");
GtkWidget *labeldescription=lookup_widget(objet,"hoteldescriptionyaw");
GtkWidget *labelprice=lookup_widget(objet,"hotelpriceyaw");
nexthoteladd();
FILE *f=fopen("hotelsxp.txt","r");
char name[30];char description[30];int price;
if(fscanf(f,"%s %s %d\n",name,description,&price)!=EOF)
gtk_label_set_text(GTK_LABEL(labelname),name);
gtk_label_set_text(GTK_LABEL(labeldescription),description);
char str[30];sprintf(str,"%d",price);
gtk_label_set_text(GTK_LABEL(labelprice),str);
fclose(f);
nexthoteldelete(name);
}



void
on_leasenext_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *labelname=lookup_widget(objet,"leasenameyaw");
GtkWidget *labeldescription=lookup_widget(objet,"leasedescriptionyaw");
GtkWidget *labelprice=lookup_widget(objet,"leasepriceyaw");
nextleaseadd();
FILE *f=fopen("users3xp.txt","r");
char name[30];char description[30];int price;
if(fscanf(f,"%s %d %s\n",name,&price,description)!=EOF)
gtk_label_set_text(GTK_LABEL(labelname),name);
gtk_label_set_text(GTK_LABEL(labeldescription),description);
char str[30];sprintf(str,"%d",price);
gtk_label_set_text(GTK_LABEL(labelprice),str);
fclose(f);
nextleasedelete(name);

}


void
on_nextofferyaw_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *labelname=lookup_widget(objet,"offernameyaw");
GtkWidget *labeldescription=lookup_widget(objet,"offerdescriptionyaw");
GtkWidget *labelprice=lookup_widget(objet,"offerpriceyaw");
nextofferadd();
FILE *f=fopen("users2xp.txt","r");
char name[30];char description[30];int price;
if(fscanf(f,"%s %s %d\n",name,description,&price)!=EOF)
gtk_label_set_text(GTK_LABEL(labelname),name);
gtk_label_set_text(GTK_LABEL(labeldescription),description);
char str[30];sprintf(str,"%d",price);
gtk_label_set_text(GTK_LABEL(labelprice),str);
fclose(f);
nextofferdelete(name);
}




// espace admin:




void on_LogoutAdmin_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	notinstantcustomer();
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinSettings);
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinDeleteMembers);
	gtk_widget_destroy(WinPromotionalCode);
	// go authen
	GtkWidget *winlogin;
	winlogin = create_interfacelogin();
	gtk_widget_show(winlogin);
	
}



void on_Home_clicked(GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinSettings);
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinDeleteMembers);
	gtk_widget_destroy(WinPromotionalCode);
	WinHome = create_EspaceAdminHome();
	gtk_widget_show(WinHome);
	// no need to make the counting here, already coded in the show window singal.
}


void on_Claims_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinSettings);
	gtk_widget_destroy(WinDeleteMembers);
	gtk_widget_destroy(WinPromotionalCode);
	WinClaims = create_EspaceAdminClaims();
	gtk_widget_show(WinClaims);
}



void on_PromotionalCode_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	gtk_widget_destroy(WinPromotionalCode);	
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinSettings);
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinDeleteMembers);
	WinPromotionalCode = create_EspaceAdminPromotionalCode();
	gtk_widget_show(WinPromotionalCode);
}


void on_Statistical_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinSettings);
	gtk_widget_destroy(WinDeleteMembers);
	gtk_widget_destroy(WinPromotionalCode);
	WinStatistical = create_EspaceAdminStatistical();
	gtk_widget_show(WinStatistical);
}


void on_AddMembers_clicked(GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinUploadCV,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinUploadCV = lookup_widget(objet_graphique, "windowuploadcv"); // destory upload cv window so it wont recreate everytime.
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinUploadCV);
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinSettings);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinDeleteMembers);
	gtk_widget_destroy(WinPromotionalCode);		
	WinAddMembers = create_EspaceAdminAddmemberInfo();
	gtk_widget_show(WinAddMembers);
}



void on_DeleteMembers_clicked(GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	gtk_widget_destroy(WinSettings);
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinDeleteMembers);
	gtk_widget_destroy(WinPromotionalCode);
	WinDeleteMembers = create_EspaceAdminDeletemembersInfo();
	gtk_widget_show(WinDeleteMembers);
	
	/* GtkWidget *selectagent;
	selectagent = lookup_widget(objet_graphique, "DeleteMembersChoose");
	char list[50][10];
	int n;
	n = mails(list);
	for(int i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(selectagent),_(list[i]));
	} */
	
}


void on_Settings_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinDeleteMembers);
	gtk_widget_destroy(WinPromotionalCode);
	gtk_widget_destroy(WinSettings);
	WinSettings = create_EspaceAdminSettings();
	gtk_widget_show(WinSettings);
	
}


void
on_ClaimsDone_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ClaimsDelete_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void on_ClaimsAnswer_clicked  (GtkWidget     *objet_graphique,      gpointer user_data)
{
	//msgsend
	GtkWidget *text,*claim;
	text = lookup_widget(objet_graphique, "ClaimsAnswerText");
	claim = lookup_widget(objet_graphique, "ClaimsChoose");
	char msg[100]="claim ";
	strcat(msg, gtk_entry_get_text(GTK_ENTRY(text))); // sans espace
	strcat(msg," 0 ");
	strcat(msg, gtk_combo_box_get_active_text(GTK_COMBO_BOX(claim)));
	send_msg(msg);
	// claim delete
	int k = find_line2("claims.txt", gtk_combo_box_get_active_text(GTK_COMBO_BOX(claim)));
	delete_line_infile(k,"claims.txt");
	// reset
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinSettings);
	gtk_widget_destroy(WinDeleteMembers);
	gtk_widget_destroy(WinPromotionalCode);
	WinClaims = create_EspaceAdminClaims();
	gtk_widget_show(WinClaims);
}


void
on_ClaimsAnswerSend_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void on_AddMembersAdd_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *role,*name,*fname,*email,*nationalid,*phonenumber,*password,*cpassword,*day,*month,*year,*PasswordCheck;
	PasswordCheck = lookup_widget(objet_graphique, "AddMembersWrongPassword");
	role = lookup_widget(objet_graphique, "AddMembersRole");
	name = lookup_widget(objet_graphique, "AddMembersName");
	fname = lookup_widget(objet_graphique, "AddMembersFName");
	day = lookup_widget(objet_graphique, "AddMembersBirthDay");
	month = lookup_widget(objet_graphique, "AddMembersBirthMonth");
	year = lookup_widget(objet_graphique, "AddMembersBirthYear");
	password = lookup_widget(objet_graphique, "AddMembersPassword");
	cpassword = lookup_widget(objet_graphique, "AddMembersCPassword");
	phonenumber = lookup_widget(objet_graphique, "AddMembersPhone");
	nationalid = lookup_widget(objet_graphique, "AddMembersNationalID");
	email = lookup_widget(objet_graphique, "AddMembersEmail");
	// add_member(MEMBER a);
	MEMBER m;
	if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)),"Admin")==0)
	{
		m.role=3;
	}
	else
	{
		m.role=2;
	}
	m.bdate.day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
	m.bdate.month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
	m.bdate.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));
	strcpy(m.name, gtk_entry_get_text(GTK_ENTRY(name)));
	strcpy(m.fname, gtk_entry_get_text(GTK_ENTRY(fname)));
	strcpy(m.password, gtk_entry_get_text(GTK_ENTRY(password)));
	strcpy(m.phonenumber, gtk_entry_get_text(GTK_ENTRY(phonenumber)));
	strcpy(m.nationalid, gtk_entry_get_text(GTK_ENTRY(nationalid)));
	strcpy(m.email, gtk_entry_get_text(GTK_ENTRY(email)));
	m.status = 1; // account activated by default
	int flag=0;
	char errortext[100]="";
	if(strcmp(m.password,"")==0 || strlen(m.password)<2)
	{
		flag=1;
		strcat(errortext,"Invalid password\n");
	}
	if(strcmp(gtk_entry_get_text(GTK_ENTRY(cpassword)),"")==0 || strcmp(m.password,gtk_entry_get_text(GTK_ENTRY(cpassword)))!=0)
	{
		flag=1;
		strcat(errortext,"Wrong password Repetition\n");
	}
	if(valid_email(m.email)!=1)
	{
		flag=1;
		strcat(errortext,"Invalid Email\n");
	}
	if(valid_nb(m.phonenumber,11)!=1 || strcmp(m.phonenumber,"")==0)
	{
		flag=1;
		strcat(errortext,"Invalid Phone Number\n");
	}
	if(valid_nb(m.nationalid,8)!=1 || strcmp(m.nationalid,"")==0)
	{
		flag=1;
		strcat(errortext,"Invalid National ID\n");
	}
	if(strcmp(m.name,"")==0 || strcmp(m.fname,"")==0 || strlen(m.name)<2 || strlen(m.fname)<2)
	{
		flag=1;
		strcat(errortext,"Invalid Name/FamilyName\n");
	}
	
	if(flag==1)
	{
		gtk_label_set_text(GTK_LABEL(PasswordCheck),errortext);
	}
	else
	{
		add_member(m);
		gtk_label_set_text(GTK_LABEL(PasswordCheck),"Added Successfully!");
	}
	
}



void on_AddMembersUploadCV_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *WinUpload;
	WinUpload = create_windowuploadcv();
	gtk_widget_show(WinUpload);
}



void on_DeleteMembersDesactivate_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *selectagent;
	selectagent = lookup_widget(objet_graphique, "DeleteMembersChoose");
	MEMBER a;
	char email[50];
	strcpy(email,gtk_combo_box_get_active_text(GTK_COMBO_BOX(selectagent)));
	int linenumber = find_member_by_email(&a,email);
	char newlinetext[200];
	int desactivate = 0;
	sprintf(newlinetext,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, a.password, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, a.nationalid, desactivate);
	replace_line_infile(linenumber, newlinetext, "members.txt");
	// change status info display:
	GtkWidget *status;
	status = lookup_widget(objet_graphique, "DeleteMembersStatus");
	gtk_label_set_text(GTK_LABEL(status),"Desactivated");
	int h = find_line9("users.txt",a.email);
	char ln[500]="";
	strcat(ln,a.email);
	strcat(ln," ");
	strcat(ln,a.password);
	strcat(ln," ");
	char t[50];
	sprintf(t,"%d",a.role);
	strcat(ln,t);
	strcat(ln," 0\n");
	replace_line_infile(h,ln,"users.txt");
}


void on_AddMembersUploadCancel_clicked   (GtkWidget     *objet_graphique,      gpointer user_data)  
{
	GtkWidget *upload;
	upload = lookup_widget(objet_graphique, "windowuploadcv");
	gtk_widget_destroy(upload);
}


void on_AddMembersUploadOpen_clicked  (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *filechooser;
	filechooser = lookup_widget(objet_graphique, "windowuploadcv");
	char str[100];
	strcpy(str,gtk_file_chooser_get_uri(GTK_FILE_CHOOSER(filechooser)));
	//strcpy(url,g_file_get_uri(gtk_file_chooser_get_file(GTK_FILE_CHOOSER(filechooser))));
	int n = strlen(str),j=0;
	char url[n-7];
	for(int i = 7;i<n;i++)
	{
		url[j]=str[i];
		++j;
	}
	strcat(url,"\0");
	char command[100];
	sprintf(command, "cp %s cv", url); // linux command
	system(command);
	gtk_widget_destroy(filechooser);
	// show addmember window , choose url label , add url there(before destroymaybe)
	// on add clicked , take url from label , and add it to member.url
	// go to every fscanf & fprintf and add member.url
	// default url to 0
}



void on_DeleteMembersActivate_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *selectagent;
	selectagent = lookup_widget(objet_graphique, "DeleteMembersChoose");
	MEMBER a;
	char email[50];
	strcpy(email,gtk_combo_box_get_active_text(GTK_COMBO_BOX(selectagent)));
	int linenumber = find_member_by_email(&a,email);
	char newlinetext[200];
	int activate = 1;
	sprintf(newlinetext,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, a.password, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, a.nationalid, activate);
	replace_line_infile(linenumber, newlinetext, "members.txt");
	// change status info display:
	GtkWidget *status;
	status = lookup_widget(objet_graphique, "DeleteMembersStatus");
	gtk_label_set_text(GTK_LABEL(status),"Activated");
	int h = find_line9("users.txt",a.email);
	char ln[500]="";
	strcat(ln,a.email);
	strcat(ln," ");
	strcat(ln,a.password);
	strcat(ln," ");
	char t[50];
	sprintf(t,"%d",a.role);
	strcat(ln,t);
	strcat(ln," 1\n");
	replace_line_infile(h,ln,"users.txt");
}



void on_EspaceAdminHome_show (GtkWidget     *objet_graphique,      gpointer user_data)
{
	// General info:
	GtkWidget *admincounter,*agentcounter,*totaltext,*clientcounter;
	clientcounter = lookup_widget(objet_graphique, "HomeCustomersNumber");
	admincounter = lookup_widget(objet_graphique, "HomeAdminsNumber");
	agentcounter = lookup_widget(objet_graphique, "HomeAgentsNumber");
	totaltext = lookup_widget(objet_graphique, "HomeTotalNumber");
	char nclient[5],nadmin[5],nagent[5],total[5];
	int sum=(count_members(3)+count_members(2)+count_clients());
	sprintf(nadmin,"%d",count_members(3));
	sprintf(nagent,"%d",count_members(2));
	sprintf(nclient,"%d",count_clients());
	sprintf(total,"%d",sum);
	gtk_label_set_text(GTK_LABEL(admincounter),nadmin);
	gtk_label_set_text(GTK_LABEL(agentcounter),nagent);
	gtk_label_set_text(GTK_LABEL(clientcounter),nclient);
	gtk_label_set_text(GTK_LABEL(totaltext),total);
	// User Info:
	GtkWidget *fullname,*email,*phonenumber,*birthdate; //*password;
	fullname = lookup_widget(objet_graphique, "HomeConnectedAs");
	email = lookup_widget(objet_graphique, "HomeEmail");
	phonenumber = lookup_widget(objet_graphique, "HomePhoneNumber");
	birthdate = lookup_widget(objet_graphique, "HomeBirthDate");
	// password = lookup_widget(objet_graphique, "HomePassword");
	MEMBER a;
	int k;
	k=find_current_user(&a);
	char nom[100],str[50];
	strcpy(nom,a.name);
	strcat(nom," ");
	strcat(nom,a.fname);
	sprintf(str,"%d/%d/%d",a.bdate.day,a.bdate.month,a.bdate.year);
	gtk_label_set_text(GTK_LABEL(fullname),nom);
	gtk_label_set_text(GTK_LABEL(email),a.email);
	gtk_label_set_text(GTK_LABEL(phonenumber),a.phonenumber);
	gtk_label_set_text(GTK_LABEL(birthdate),str);
	// gtk_label_set_text(GTK_LABEL(password),a.password); on button show.
	
}


void on_HomePasswordShow_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *password;
	MEMBER m;
	find_current_user(&m);
	password = lookup_widget(objet_graphique, "HomePassword");
	gtk_label_set_text(GTK_LABEL(password),m.password);
		
}



void on_PCGenerateCode_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *codetext;
	codetext = lookup_widget(objet_graphique, "PCCode");
	char code[50];
	generate_promotionalcode(code);
	gtk_label_set_text(GTK_LABEL(codetext),code);
	
}



void on_PCAdd_clicked  (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *generatedcode,*codetext,*codecheck,*selectcode;
	generatedcode = lookup_widget(objet_graphique, "PCCode");
	codetext = lookup_widget(objet_graphique, "PCCodeText");
	codecheck = lookup_widget(objet_graphique, "PCCodeCheck");
	selectcode = lookup_widget(objet_graphique, "PCChooseCode");
	char code[50];
	sprintf(code,"%s NOTSENT 0\n",gtk_label_get_text(GTK_LABEL(generatedcode)));
	if(IsCodeUnique(code)==0 && strcmp(gtk_label_get_text(GTK_LABEL(generatedcode)),"Code Added Successfully!")!=0 && strcmp(gtk_label_get_text(GTK_LABEL(generatedcode)),"Invalid Code or Code Exist!")!=0 && strcmp(gtk_label_get_text(GTK_LABEL(generatedcode)),"**********")!=0){
		add_code_to_database(code);
		gtk_combo_box_append_text(GTK_COMBO_BOX(selectcode),gtk_label_get_text(GTK_LABEL(generatedcode))); // append code into selectcode combobox.
		char text[300]="";
		display_text_from_file(text,"promotionalcodes.txt");
		gtk_label_set_text(GTK_LABEL(codetext),text);
		gtk_label_set_text(GTK_LABEL(generatedcode),"Code Added Successfully!");
	}
	else
	{
		gtk_label_set_text(GTK_LABEL(codecheck),"Invalid Code or Code Exist!");
	}
}


void on_PCSend_clicked  (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *client,*code,*msgtext;
	client = lookup_widget(objet_graphique, "PCChooseClient");
	code = lookup_widget(objet_graphique, "PCChooseCode");
	msgtext = lookup_widget(objet_graphique, "PCMessageText");
	char msg[300]="";
	strcat(msg,"code ");
	strcat(msg, gtk_entry_get_text(GTK_ENTRY(msgtext)));
	strcat(msg,"_");
	strcat(msg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(code)));
	strcat(msg," 0 ");
	strcat(msg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(client)));
	send_msg(msg);
	int n = find_line("promotionalcodes.txt", gtk_combo_box_get_active_text(GTK_COMBO_BOX(code)));
	char str[50];
	sprintf(str, "%s %s 0\n", gtk_combo_box_get_active_text(GTK_COMBO_BOX(code)), gtk_combo_box_get_active_text(GTK_COMBO_BOX(client)));
	replace_line_infile(n, str, "promotionalcodes.txt");
	// sent successfully
	GtkWidget *error;
	error = lookup_widget(objet_graphique, "PCError");
	gtk_label_set_text(GTK_LABEL(error),"Message Sent Successfully!");
	// reset
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	gtk_widget_destroy(WinPromotionalCode);	
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinSettings);
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinDeleteMembers);
	WinPromotionalCode = create_EspaceAdminPromotionalCode();
	gtk_widget_show(WinPromotionalCode);

}



void on_EspaceAdminPromotionalCode_show (GtkWidget     *objet_graphique,      gpointer user_data)
{
	// display codes in database
	GtkWidget *text;
	text = lookup_widget(objet_graphique, "PCCodeText");
	char str[300]="";
	display_text_from_file(str,"promotionalcodes.txt");
	gtk_label_set_text(GTK_LABEL(text),str);
	// append codes in comboboxes
	GtkWidget *selectcode,*selectclient;
	selectcode = lookup_widget(objet_graphique, "PCChooseCode");
	selectclient = lookup_widget(objet_graphique, "PCChooseClient");
	char codes[50][50]; // clients[50][50];
	int n=get_promotionalcodes(codes); //r=get_members_mails(clients); get clients mails , same as for members, just diff struct format.	
	for(int i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(selectcode),codes[i]);
		// gtk_combo_box_append_text(GTK_COMBO_BOX(selectagent),clients[i]);
	}
	// append client into combobox
	char clients[50][50];
	int k = get_clients_mail(clients);
	for(int i=0;i<k;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(selectclient),clients[i]);
	}
	
	
}



void on_EspaceAdminDeletemembersInfo_show (GtkWidget     *objet_graphique,      gpointer user_data)
{
	// append emails in select member combobox
	GtkWidget *selectagent;
	selectagent = lookup_widget(objet_graphique, "DeleteMembersChoose");
	char list[50][50];
	int n;
	n = get_members_mails(list);
	MEMBER a;
	int k = find_current_user(&a);
	for(int i=0;i<n;i++)
	{
		if(strcmp(list[i],a.email)!=0) //skip the current user email.
		{
			gtk_combo_box_append_text(GTK_COMBO_BOX(selectagent),list[i]);
		}	
	} 
	// append options in select option combobox
	GtkWidget *option;
	option = lookup_widget(objet_graphique, "DeleteMembersOption");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"FullName");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"BirthDate");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"NationalID");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"PhoneNumber");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"Email");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"Password");
	
}


void on_EspaceAdminStatistical_show  (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *selectagent;
	selectagent = lookup_widget(objet_graphique, "StatisticalsAgent");
	char list[50][50];
	int n;
	n = get_agents_mails(list);
	for(int i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(selectagent),list[i]);
	} 
}


void
on_DeleteMembersShowCV_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void on_PCDelete_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	// delete code from database
	GtkWidget *delete,*chosencode;
	chosencode = lookup_widget(objet_graphique, "PCChooseCode");
	delete = lookup_widget(objet_graphique, "PCDelete");
	char code[50][50];
	int n=get_promotionalcodes(code),line;
	for(int i=0;i<n;i++)
	{
		if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(chosencode)),code[i])==0)
		{
			line = ++i;
			break;
		}
	}
	delete_line_infile(line, "promotionalcodes.txt");
	//display codes in database
	GtkWidget *text;
	text = lookup_widget(objet_graphique, "PCCodeText");
	char str[300]="";
	display_text_from_file(str,"promotionalcodes.txt");
	gtk_label_set_text(GTK_LABEL(text),str);
	// reset interface -> removes code from comboboxes
	GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
	WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
	WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
	WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
	WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
	WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
	WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
	WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
	gtk_widget_destroy(WinPromotionalCode);	
	gtk_widget_destroy(WinHome);
	gtk_widget_destroy(WinClaims);
	gtk_widget_destroy(WinStatistical);
	gtk_widget_destroy(WinAddMembers);
	gtk_widget_destroy(WinSettings);
	gtk_widget_destroy(WinDeleteMembers);
	WinPromotionalCode = create_EspaceAdminPromotionalCode();
	gtk_widget_show(WinPromotionalCode);
}



void on_DeleteMembersShow_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *password,*selectedmember;
	password = lookup_widget(objet_graphique, "DeleteMembersPassword");
	selectedmember = lookup_widget(objet_graphique, "DeleteMembersChoose");
	char memberemail[50];
	strcpy(memberemail,gtk_combo_box_get_active_text(GTK_COMBO_BOX(selectedmember)));
	MEMBER a;
	int n = find_member_by_email(&a,memberemail);
	gtk_label_set_text(GTK_LABEL(password),a.password);
	
}


void on_DeleteMembersApply_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *member,*option,*new,*pass,*cpass,*error;
	error = lookup_widget(objet_graphique, "DeleteMembersError");
	char errortext[100]="";
	int flag=0;
	member = lookup_widget(objet_graphique, "DeleteMembersChoose");
	option = lookup_widget(objet_graphique, "DeleteMembersOption");
	new = lookup_widget(objet_graphique, "DeleteMembersNew");
	/*text1 = lookup_widget(objet_graphique , "DeleteMembersText1");
	text2 = lookup_widget(objet_graphique , "DeleteMembersText2");
	text3 = lookup_widget(objet_graphique , "DeleteMembersText3"); */
	pass = lookup_widget(objet_graphique, "DeleteMemebersPassword");
	cpass = lookup_widget(objet_graphique, "DeleteMembersCPassword");
	MEMBER a;
	char email[50];
	strcpy(email, gtk_combo_box_get_active_text(GTK_COMBO_BOX(member)));
	int n = find_member_by_email(&a,email);
	char chosenoption[50];
	char str[100];
	char changed[100];
	int var,j=0,h=0;
	char name[50],fname[50],day[10],month[10],year[10];
	strcpy(changed,gtk_entry_get_text(GTK_ENTRY(new)));
	int len=strlen(changed);
	strcpy(chosenoption, gtk_combo_box_get_active_text(GTK_COMBO_BOX(option)));
	if(strcmp(gtk_entry_get_text(GTK_ENTRY(pass)),gtk_entry_get_text(GTK_ENTRY(cpass)))==0 && strcmp(gtk_entry_get_text(GTK_ENTRY(pass)),a.password)==0) // password repeat check and correct password check
	{
		if(strcmp(chosenoption,"FullName")==0)
		{
			if(valid_fullname(changed)==1)
			{
				sprintf(str,"%d %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, a.password, changed  , a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, a.nationalid, a.status);
				replace_line_infile(n, str, "members.txt");
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new FullName\n");
			}
		}
		if(strcmp(chosenoption,"Password")==0)
		{
			if(valid_password(changed)==1)
			{
				sprintf(str,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, changed, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, a.nationalid, a.status);
				replace_line_infile(n, str, "members.txt");
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new password\n");
			}
		}
		if(strcmp(chosenoption,"Email")==0)
		{
			if(valid_email(changed)==1)
			{
				sprintf(str,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, changed, a.password, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, a.nationalid, a.status);
				replace_line_infile(n, str, "members.txt");
				replace_line_infile(1, changed, "currentuser.txt"); // replaces the current user email also.
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new email\n");
			}
		}
		if(strcmp(chosenoption,"PhoneNumber")==0)
		{
			if(valid_nb(changed,11)==1)
			{
				sprintf(str,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, a.password, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, changed, a.nationalid, a.status);
				replace_line_infile(n, str, "members.txt");
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new phone number\n");
			}
		}
		if(strcmp(chosenoption,"NationalID")==0)
		{
			if(valid_nb(changed,8)==1)
			{
				sprintf(str,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, a.password, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, changed, a.status);
				replace_line_infile(n, str, "members.txt");
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new national ID\n");
			}
		}
		if(strcmp(chosenoption,"BirthDate")==0)
		{
			if(valid_bdate(changed)==1)
			{
				sprintf(str,"%d %s %s %s %s %s %s %s %d\n",a.role, a.email, a.password, a.name, a.fname, changed, a.phonenumber, a.nationalid, a.status);
				replace_line_infile(n, str, "members.txt");
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new birth date\n");
			}
		}

	}
	else // password check.
	{
		flag=1;
		if(strcmp(gtk_entry_get_text(GTK_ENTRY(pass)),a.password)!=0){strcat(errortext,"-Wrong Password\n");}
		if(strcmp(gtk_entry_get_text(GTK_ENTRY(pass)),gtk_entry_get_text(GTK_ENTRY(cpass)))!=0){strcat(errortext,"-Wrong Password Repition\n");}
	}
	if(flag==1) // error display if an error exists
	{
		gtk_label_set_text(GTK_LABEL(error),errortext);	
	}
	else
	{
		// RESET
		GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
		WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
		WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
		WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
		WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
		WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
		WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
		WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
		gtk_widget_destroy(WinHome);
		gtk_widget_destroy(WinClaims);
		gtk_widget_destroy(WinStatistical);
		gtk_widget_destroy(WinSettings);
		gtk_widget_destroy(WinAddMembers);
		gtk_widget_destroy(WinDeleteMembers);
		gtk_widget_destroy(WinPromotionalCode);
		WinSettings = create_EspaceAdminSettings();
		gtk_widget_show(WinSettings);
	}
}



void on_DeleteMembersChoose_changed (GtkWidget     *objet_graphique,      gpointer user_data)
{
	// member selection
	GtkWidget *selectmember;
	selectmember = lookup_widget(objet_graphique, "DeleteMembersChoose");
	char memberemail[50];
	strcpy(memberemail, gtk_combo_box_get_active_text(GTK_COMBO_BOX(selectmember)));
	MEMBER a;
	int n = find_member_by_email(&a, memberemail);
	// member info display
	GtkWidget *name,*email,*phonenumber,*bdate,*nationalid,*status,*role,*pass;
	role = lookup_widget(objet_graphique, "DeleteMembersRole");
	name = lookup_widget(objet_graphique, "DeleteMembersName");
	email = lookup_widget(objet_graphique, "DeleteMembersEmail");
	phonenumber = lookup_widget(objet_graphique, "DeleteMembersPhoneNumber");
	bdate = lookup_widget(objet_graphique, "DeleteMembersBirthDate");
	nationalid = lookup_widget(objet_graphique, "DeleteMembersNationalID");
	status = lookup_widget(objet_graphique, "DeleteMembersStatus");
	pass = lookup_widget(objet_graphique, "DeleteMembersPassword");
	gtk_label_set_text(GTK_LABEL(pass),"*******");
	char str[100];
	sprintf(str,"%s %s",a.name,a.fname);	
	gtk_label_set_text(GTK_LABEL(name),str);
	gtk_label_set_text(GTK_LABEL(email),a.email);
	gtk_label_set_text(GTK_LABEL(phonenumber),a.phonenumber);
	char dt[50];
	sprintf(dt,"%d/%d/%d", a.bdate.day, a.bdate.month, a.bdate.year);
	gtk_label_set_text(GTK_LABEL(bdate),dt);
	gtk_label_set_text(GTK_LABEL(nationalid),a.nationalid);
	char stat[50];
	if(a.status==1)
	{
		strcpy(stat,"Activated");
	}
	else
	{
		strcpy(stat, "Desactivated");
	}
	gtk_label_set_text(GTK_LABEL(status),stat);
	char rl[10];
	if(a.role==2){strcpy(rl,"Agent");}
	else{strcpy(rl,"Admin");}
	gtk_label_set_text(GTK_LABEL(role),rl);
	
	
}






void on_SettingsApply_clicked (GtkWidget     *objet_graphique,      gpointer user_data)

{
	GtkWidget **option,*new,*pass,*cpass,*error;
	error = lookup_widget(objet_graphique, "SettingsError");
	char errortext[100]="";
	int flag=0;
	option = lookup_widget(objet_graphique, "SettingsChooseMod");
	new = lookup_widget(objet_graphique, "SettingsNewInfo");
	/*text1 = lookup_widget(objet_graphique , "DeleteMembersText1");
	text2 = lookup_widget(objet_graphique , "DeleteMembersText2");
	text3 = lookup_widget(objet_graphique , "DeleteMembersText3"); */
	pass = lookup_widget(objet_graphique, "SettingsPassword");
	cpass = lookup_widget(objet_graphique, "SettingsCPassword");
	MEMBER m;
	int k = find_current_user(&m);
	MEMBER a;
	int n = find_member_by_email(&a, m.email);
	char chosenoption[50];
	char str[100];
	char changed[100];
	int var,j=0,h=0;
	char name[50],fname[50],day[10],month[10],year[10];
	strcpy(changed,gtk_entry_get_text(GTK_ENTRY(new)));
	int len=strlen(changed);
	strcpy(chosenoption, gtk_combo_box_get_active_text(GTK_COMBO_BOX(option)));
	if(strcmp(gtk_entry_get_text(GTK_ENTRY(pass)),gtk_entry_get_text(GTK_ENTRY(cpass)))==0 && strcmp(gtk_entry_get_text(GTK_ENTRY(pass)),a.password)==0) // password repeat check and correct password check
	{
		if(strcmp(chosenoption,"FullName")==0)
		{
			if(valid_fullname(changed)==1)
			{
				sprintf(str,"%d %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, a.password, changed  , a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, a.nationalid, a.status);
				replace_line_infile(n, str, "members.txt");
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new FullName\n");
			}
		}
		if(strcmp(chosenoption,"Password")==0)
		{
			if(valid_password(changed)==1)
			{
				sprintf(str,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, changed, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, a.nationalid, a.status);
				replace_line_infile(n, str, "members.txt");
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new password\n");
			}
		}
		if(strcmp(chosenoption,"Email")==0)
		{
			if(valid_email(changed)==1)
			{
				sprintf(str,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, changed, a.password, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, a.nationalid, a.status);
				replace_line_infile(n, str, "members.txt");
				replace_line_infile(1, changed, "currentuser.txt"); // replaces the current user email also.
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new email\n");
			}
		}
		if(strcmp(chosenoption,"PhoneNumber")==0)
		{
			if(valid_nb(changed,11)==1)
			{
				sprintf(str,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, a.password, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, changed, a.nationalid, a.status);
				replace_line_infile(n, str, "members.txt");
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new phone number\n");
			}
		}
		if(strcmp(chosenoption,"NationalID")==0)
		{
			if(valid_nb(changed,8)==1)
			{
				sprintf(str,"%d %s %s %s %s %d/%d/%d %s %s %d\n",a.role, a.email, a.password, a.name, a.fname, a.bdate.day, a.bdate.month, a.bdate.year, a.phonenumber, changed, a.status);
				replace_line_infile(n, str, "members.txt");
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new national ID\n");
			}
		}
		if(strcmp(chosenoption,"BirthDate")==0)
		{
			if(valid_bdate(changed)==1)
			{
				sprintf(str,"%d %s %s %s %s %s %s %s %d\n",a.role, a.email, a.password, a.name, a.fname, changed, a.phonenumber, a.nationalid, a.status);
				replace_line_infile(n, str, "members.txt");
			}
			else
			{
				flag=1;
				strcat(errortext,"-Invalid new birth date\n");
			}
		}

	}
	else // password check.
	{
		flag=1;
		if(strcmp(gtk_entry_get_text(GTK_ENTRY(pass)),a.password)!=0){strcat(errortext,"-Wrong Password\n");}
		if(strcmp(gtk_entry_get_text(GTK_ENTRY(pass)),gtk_entry_get_text(GTK_ENTRY(cpass)))!=0){strcat(errortext,"-Wrong Password Repition\n");}
	}
	if(flag==1) // error display if an error exists
	{
		gtk_label_set_text(GTK_LABEL(error),errortext);	
	}
	else
	{
		// RESET
		GtkWidget *WinHome,*WinClaims,*WinStatistical,*WinAddMembers,*WinDeleteMembers,*WinPromotionalCode,*WinSettings;
		WinHome = lookup_widget(objet_graphique, "EspaceAdminHome");
		WinClaims = lookup_widget(objet_graphique, "EspaceAdminClaims");
		WinStatistical = lookup_widget(objet_graphique, "EspaceAdminStatistical");
		WinAddMembers = lookup_widget(objet_graphique, "EspaceAdminAddmemberInfo");
		WinDeleteMembers = lookup_widget(objet_graphique, "EspaceAdminDeletemembersInfo");
		WinPromotionalCode = lookup_widget(objet_graphique, "EspaceAdminPromotionalCode");
		WinSettings = lookup_widget(objet_graphique, "EspaceAdminSettings");
		gtk_widget_destroy(WinHome);
		gtk_widget_destroy(WinClaims);
		gtk_widget_destroy(WinStatistical);
		gtk_widget_destroy(WinSettings);
		gtk_widget_destroy(WinAddMembers);
		gtk_widget_destroy(WinDeleteMembers);
		gtk_widget_destroy(WinPromotionalCode);
		WinSettings = create_EspaceAdminSettings();
		gtk_widget_show(WinSettings);
	}
}


void on_EspaceAdminSettings_show (GtkWidget     *objet_graphique,      gpointer user_data)
{
	// current user selection
	MEMBER m;
	int k = find_current_user(&m);
	MEMBER a;
	int n = find_member_by_email(&a, m.email);
	// member info display
	GtkWidget *name,*email,*phonenumber,*bdate,*nationalid,*status,*role;
	role = lookup_widget(objet_graphique, "SettingsRole");
	name = lookup_widget(objet_graphique, "SettingsName");
	email = lookup_widget(objet_graphique, "SettingsEmail");
	phonenumber = lookup_widget(objet_graphique, "SettingsPhoneNumber");
	bdate = lookup_widget(objet_graphique, "SettingsBirthDate");
	nationalid = lookup_widget(objet_graphique, "SettingsNationalID");
	status = lookup_widget(objet_graphique, "SettingsStatus");
	// password is done in show button
	char str[100];
	sprintf(str,"%s %s",a.name,a.fname);	
	gtk_label_set_text(GTK_LABEL(name),str);
	gtk_label_set_text(GTK_LABEL(email),a.email);
	gtk_label_set_text(GTK_LABEL(phonenumber),a.phonenumber);
	char dt[50];
	sprintf(dt,"%d/%d/%d", a.bdate.day, a.bdate.month, a.bdate.year);
	gtk_label_set_text(GTK_LABEL(bdate),dt);
	gtk_label_set_text(GTK_LABEL(nationalid),a.nationalid);
	char stat[50];
	if(a.status==1)
	{
		strcpy(stat,"Activated");
	}
	else
	{
		strcpy(stat, "Desactivated");
	}
	gtk_label_set_text(GTK_LABEL(status),stat);
	char rl[10];
	if(a.role==2){strcpy(rl,"Agent");}
	else{strcpy(rl,"Admin");}
	gtk_label_set_text(GTK_LABEL(role),rl);
	// append options in select option combobox
	GtkWidget *option;
	option = lookup_widget(objet_graphique, "SettingsChooseMod");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"FullName");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"BirthDate");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"NationalID");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"PhoneNumber");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"Email");
	gtk_combo_box_append_text(GTK_COMBO_BOX(option),"Password");
}


void on_SettingsShow_clicked (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *pass;
	pass=lookup_widget(objet_graphique, "SettingsPasswordText");
	MEMBER m;
	int k = find_current_user(&m);
	gtk_label_set_text(GTK_LABEL(pass),m.password);
}


void on_EspaceAdminClaims_show (GtkWidget     *objet_graphique,      gpointer user_data)
{
	// list
	
	GtkWidget *tree;
	tree=lookup_widget(objet_graphique, "ClaimsTree");
	show_claimstree(tree);
	// append claims into choose comboxbox
	GtkWidget *choose;
	choose = lookup_widget(objet_graphique, "ClaimsChoose");
	char claims[100][100];
	int n = get_claims(claims);
	for(int i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(choose),claims[i]);
	}
	
}





// les fonctions de tree: (DONT TOUCH):





void
on_window_remove_show                  (GtkWidget       *objet,
                                        gpointer         user_data) // show treeandcombo
{
GtkWidget *tree=lookup_widget(objet,"treeviewofcontactagent");
GtkWidget *combo=lookup_widget(objet,"combotoclientrespond");
treeviewofcontact(tree);
FILE *f=fopen("contactagent.txt","r"); char title[30];char description[150];char email[30];char datedebut[30],datefin[30];
while(fscanf(f,"%s %s %s %s %s\n",title,description,datedebut,datefin,email)!=EOF) 
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),email);
fclose(f);
}


void
on_respondtoclientsbutton_clicked      (GtkWidget       *objet,
                                        gpointer         user_data) // get two entryr and then send them
{
GtkWidget *titleentry=lookup_widget(objet,"titrerespondentry");
GtkWidget *descriptionentry=lookup_widget(objet,"descriptiontocliententry");
GtkWidget *comboentry=lookup_widget(objet,"combotoclientrespond");
char envoititle[30];char envoidescription[30]; char envoimail[30];
strcpy(envoititle,gtk_entry_get_text(GTK_WIDGET(titleentry)));
strcpy(envoidescription,gtk_entry_get_text(GTK_WIDGET(descriptionentry)));
strcpy(envoimail,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboentry)));

FILE *f=fopen("whatsnew.txt","a"); fprintf(f,"%s %s %s\n",envoititle,envoidescription,envoimail);fclose(f);
}


void
on_returnfromwindowremoveakacontacttointerfaceagent_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data) // return
{
GtkWidget *ouvre=lookup_widget(objet,"interfaceagent");
GtkWidget *ferme=lookup_widget(objet,"window_remove");
ouvre=create_interfaceagent();
gtk_widget_show(ouvre);gtk_widget_destroy(ferme);
}


void on_interfacewelcome_show (GtkWidget     *objet_graphique,      gpointer user_data)
{
	// append catalogue names:
	GtkWidget *choose;
	choose = lookup_widget(objet_graphique, "welcomechoose");
	char list[50][50];
	int n = get_cataloguesnames(list);
	for(int i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(choose),list[i]);	
	}
	// welcome image display:
	GtkWidget *welcomeimagebox;
	welcomeimagebox = lookup_widget(objet_graphique, "catalogimage");
	gtk_image_set_from_file(welcomeimagebox,"Welcome.gif");
	


}


void on_welcomechoose_changed (GtkWidget     *objet_graphique,      gpointer user_data)
{
	GtkWidget *choose,*image;
	choose = lookup_widget(objet_graphique, "welcomechoose");
	image = lookup_widget(objet_graphique, "catalogimage");
	char imageurl[50],pdfurl[50];
	int k = get_catalogueinfo(gtk_combo_box_get_active_text(GTK_COMBO_BOX(choose)),imageurl,pdfurl);
	gtk_image_set_from_file(image,imageurl); // displays imageurl into imagebox
	

	
}








void
on_delete_flight_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input=lookup_widget(objet,"entry_del_fl");
GtkWidget *win1=lookup_widget(objet,"window_flight");
GtkWidget *treeview1 ;
char ref[100];

strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));

suprimer4(ref);


gtk_widget_destroy(win1); win1=create_window_flight();gtk_widget_show(win1);

treeview1=lookup_widget(win1,"treeview3");
afficher4(treeview1);
}


void
on_show_flights_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewmembers=lookup_widget(objet,"treeview3");
afficher4(treeviewmembers);
}


void
on_fenetre_hotrels_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}








void
on_add_flight_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *inputref;
	GtkWidget *inputdepart;
        GtkWidget *inputreturn;
        GtkWidget *inputdateDepart;
	GtkWidget *inputDate_ariver;
        GtkWidget *inputprice ;
	inputref=lookup_widget(objet, "ref_flight");
	inputdepart=lookup_widget(objet,"departing_add");
        inputreturn=lookup_widget(objet,"returning_add");
        inputdateDepart=lookup_widget(objet, "departing_date_add");
	inputDate_ariver=lookup_widget(objet,"returning_date_add");
        inputprice=lookup_widget(objet,"flight_price_add");
	char *ref=gtk_entry_get_text(GTK_ENTRY(inputref));
	char *depart=gtk_entry_get_text(GTK_ENTRY(inputdepart));
	char *arriver=gtk_entry_get_text(GTK_ENTRY(inputreturn));
        char *date_aller=gtk_entry_get_text(GTK_ENTRY(inputdateDepart));
	char *date_arriver=gtk_entry_get_text(GTK_ENTRY(inputDate_ariver));
	char *price=gtk_entry_get_text(GTK_ENTRY(inputprice));	


	ajouter4(ref,depart,arriver,date_aller,date_arriver,price);
	GtkWidget *win1=lookup_widget(objet,"window_flight");
gtk_widget_destroy(win1); win1=create_window_flight();gtk_widget_show(win1);
GtkWidget *treeview1 ;
treeview1=lookup_widget(win1,"treeview3");
afficher4(treeview1);




}




void
on_interfaceflight_show                (GtkWidget       *objet,
                                        gpointer         user_data)
{
///home/maher/Desktop/asba
///home/maher/Desktop/asba

//treeviewofflighting
GtkWidget *treeviewmembers=lookup_widget(objet,"treeviewofflighting");
afficher4(treeviewmembers);
}


void
on_interfaceflightformulaire_show      (GtkWidget *objet_graphique ,
                                        gpointer         user_data)
{
GtkWidget *dep_airport,*ret_airport;
	char air[200][200];
	int n = get_flight_airport(air);
	dep_airport=lookup_widget(objet_graphique,"flying_from");
	
	for(int i=0;i<n;i++)
	{
	gtk_combo_box_append_text(GTK_COMBO_BOX(dep_airport),air[i]);
	

}
}


void
on_window_demands_show                 (GtkWidget       *widget,
                                        gpointer         user_data)
{GtkWidget *combo=lookup_widget(widget,"comboreturntocustomecontact");
GtkWidget *tree=lookup_widget(widget,"treeviewreturncontactagent");
showtreeofdemands(tree);
//fonctionshowtreereservationtaoumlreservationtxt
char a[30],b[30],c[500],d[30],e[30],f[30],g[30],h[30],j[30],k[30],l[30],m[30],n[30];
FILE *w=fopen("reservation.txt","r");
while (fscanf(w,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",a,b,c,d,e,f,g,h,j,k,l,m,n)!=EOF)
gtk_combo_box_append_text(GTK_COMBO_BOX(combo),n);
fclose(w);
}


void
on_Returnfromdemandakaremovetointerfaceagent_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ouvre=lookup_widget(objet,"interfaceagent");
GtkWidget *ferme=lookup_widget(objet,"window_demands");
ouvre=create_interfaceagent();gtk_widget_show(ouvre);gtk_widget_destroy(ferme);
}


void
on_acceptreservation_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *combo=lookup_widget(objet,"comboreturntocustomecontact");
char customer[60];strcpy(customer,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
FILE *w=fopen("whatsnew.txt","a+");fprintf(w,"Res your-reservation-is-done-please-come-to-our-agent-to-pay-your-bills-free 0 %s\n",customer);fclose(w);

char a[30],b[30],c[500],d[30],e[30],f[30],g[30],h[30],j[30],k[30],l[30],m[30],n[30];
FILE *r=fopen("reservation.txt","r");FILE *s=fopen("history.txt","a+");
while (fscanf(r,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",a,b,c,d,e,f,g,h,j,k,l,m,n)!=EOF) 
{deletereservation(customer);
fprintf(s,"%s %s %s 0 %s\n",a,b,c,n);}
fclose(r);fclose(s);

GtkWidget *ferme=lookup_widget(objet,"window_demands");gtk_widget_destroy(ferme);
GtkWidget *open=create_window_demands();gtk_widget_show(open);

//Delete
//fonctioncreatehistory
}


void
on_refusereservation_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *combo=lookup_widget(objet,"comboreturntocustomecontact");
char customer[60];strcpy(customer,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
FILE *w=fopen("whatsnew.txt","a+");fprintf(w,"Reservation your-reservation-is-refused-please-contact-our-agent 0 %s\n",customer);fclose(w);
deletereservation(customer);

GtkWidget *ferme=lookup_widget(objet,"window_demands");gtk_widget_destroy(ferme);
GtkWidget *open=create_window_demands();gtk_widget_show(open);
//fonctiondeleteligne
}


void
on_gofromhotelagentinterfacetocustomersdemands_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ouvre=lookup_widget(objet,"window_demands");
GtkWidget *ferme=lookup_widget(objet,"window_hotels");
ouvre=create_window_demands();
gtk_widget_show(ouvre);gtk_widget_destroy(ferme);
}


void
on_gofromfligjhtinterfacetocustomersdemands_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ouvre=lookup_widget(objet,"window_demands");
GtkWidget *ferme=lookup_widget(objet,"window_flight");
ouvre=create_window_demands();
gtk_widget_show(ouvre);gtk_widget_destroy(ferme);
}

