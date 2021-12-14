#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "stock.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"

char a[20]="laitier";
char b[20]="piéce";
stock x;
void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(a,"laitier");
	}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(a,"Céreal");
	}
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(a,"sucré");
	}
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(a,"Boissons");
	}
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(a,"Legumes");
	}
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(a,"Fruits");
	}
}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(a,"grass");
	}
}


void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(a,"Viandes");
	}
}


void
on_radiobutton9_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(a,"Poissons");
	}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	strcpy(b,"Piéce");
}





void
on_button2quitter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit() ; 
}


void
on_button1ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
stock x;
GtkWidget *nom_produit=lookup_widget(GTK_WIDGET(button),"nom_produit");
GtkWidget *lieu=lookup_widget(GTK_WIDGET(button),"lieu");
GtkWidget *fournisseur=lookup_widget(GTK_WIDGET(button),"fournisseur");
GtkWidget *quantite=lookup_widget(GTK_WIDGET(button),"quantite");
GtkWidget *reference=lookup_widget(GTK_WIDGET(button),"reference");
GtkWidget *jrf=lookup_widget(GTK_WIDGET(button),"jrf");
GtkWidget *msf=lookup_widget(GTK_WIDGET(button),"msf");
GtkWidget *anf=lookup_widget(GTK_WIDGET(button),"anf");
GtkWidget *jre=lookup_widget(GTK_WIDGET(button),"jre");
GtkWidget *mse=lookup_widget(GTK_WIDGET(button),"mse");
GtkWidget *ane=lookup_widget(GTK_WIDGET(button),"ane");


if((strcmp((gtk_entry_get_text(GTK_ENTRY(nom_produit))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(lieu))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(fournisseur))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(reference))),"")==0))
{ 
g_print("non");
GtkWidget *dialog2;
dialog2=create_dialog2() ;
gtk_widget_show(dialog2) ;

}

else{

strcpy(x.nom_produit,gtk_entry_get_text(GTK_ENTRY(nom_produit)));
strcpy(x.lieu,gtk_entry_get_text(GTK_ENTRY(lieu)));
strcpy(x.fournisseur,gtk_entry_get_text(GTK_ENTRY(fournisseur)));
strcpy(x.reference,gtk_entry_get_text(GTK_ENTRY(reference)));

x.quantite=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
x.date_fabrication.jour= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jrf));
x.date_fabrication.mois= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(msf));
x.date_fabrication.annee= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anf));
x.date_expiration.jour= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jre));
x.date_expiration.mois= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mse));
x.date_expiration.annee= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ane));

strcpy(x.type,a);
strcpy(x.unite,b);



GtkWidget *dialog1;
dialog1=create_dialog1() ;
gtk_widget_show(dialog1) ;

Ajouter_stock(x);}
strcpy(a,"laitier");
strcpy(b,"piéce");
}


void
on_closebutton1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog1=lookup_widget(GTK_WIDGET(button),("dialog1"));

gtk_widget_destroy(dialog1);
}


void
on_closebutton2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2=lookup_widget(GTK_WIDGET(button),("dialog2"));

gtk_widget_destroy(dialog2);
}


void
on_button3afficher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
stock x;
GtkWidget *window1;
GtkWidget *afficher_stock;
GtkWidget *treeviewstock;
  window1=lookup_widget(objet,"window1");
  gtk_widget_destroy(window1);
  afficher_stock=lookup_widget(objet,"afficher_stock");
  afficher_stock=create_afficher_stock();
  gtk_widget_show(afficher_stock);
treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
Afficher_stock(treeviewstock,"stock.txt");
}


void
on_treeviewgestionstock_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

gchar *str_data1;
gchar *str_data2;
gchar *str_data3;

gchar *str_data5;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter   iter;
  if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))
  {

 gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 1, &str_data1, -1);
 gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 2, &str_data2, -1);
 gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &str_data3, -1);
 gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 6, &str_data5, -1);
  }

strcpy(x.nom_produit,str_data1);
strcpy(x.lieu,str_data2); 
strcpy(x.fournisseur,str_data3);
strcpy(x.reference,str_data5);

}


void
on_button1modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
//GtkWidget *label=lookup_widget(GTK_WIDGET(button),"label16");
//gtk_label_set_text(GTK_LABEL(label),v.test);
//Sdell_stock(x.nom_produit);
/*****Na3mlo Actualiser lil liste **************/

GtkWidget *afficher_stock=lookup_widget(GTK_WIDGET(button),"afficher_stock");

GtkWidget *window1;
window1=lookup_widget(GTK_WIDGET(button),("window1"));

gtk_widget_destroy(afficher_stock);
window1=create_window1();
gtk_widget_show(window1);

GtkWidget *nom_produit=lookup_widget(window1,"nom_produit");
GtkWidget *lieu=lookup_widget(window1,"lieu");
GtkWidget *fournisseur=lookup_widget(window1,"fournisseur");

GtkWidget *reference=lookup_widget(window1,"reference");
gtk_entry_set_text(GTK_LABEL(nom_produit),x.nom_produit);
gtk_entry_set_text(GTK_LABEL(lieu),x.lieu);
gtk_entry_set_text(GTK_LABEL(fournisseur),x.fournisseur);
gtk_entry_set_text(GTK_LABEL(reference),x.reference);


}


void
on_button2supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
//GtkWidget *label=lookup_widget(GTK_WIDGET(button),"label16");
//gtk_label_set_text(GTK_LABEL(label),v.test);
dell_stock(x.nom_produit);
/*****Na3mlo Actualiser lil liste **************/

GtkWidget *afficher_stock=lookup_widget(GTK_WIDGET(button),"afficher_stock");
GtkWidget *treeviewstock;

treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
Afficher_stock(treeviewstock,"stock.txt");
gtk_widget_show(treeviewstock);

}


void
on_button3retour_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4, *afficher_stock;
window4=lookup_widget(GTK_WIDGET(button),("window4"));
afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
gtk_widget_destroy(afficher_stock);
window4=create_window4();
gtk_widget_show(window4);
}




void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	strcpy(b,"Kg");
}


void
on_button2retour2_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_stock, *window2,*treeviewstock;
window2=lookup_widget(GTK_WIDGET(button),("window2"));
afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
gtk_widget_destroy(window2);
afficher_stock=create_afficher_stock();
gtk_widget_show(afficher_stock);
treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
Afficher_stock(treeviewstock,"stock.txt");
}


void
on_button3repture_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
stock x;
reptre_de_stock();
GtkWidget *window2;
GtkWidget *afficher_stock;
GtkWidget *treeviewstock;
  afficher_stock=lookup_widget(objet,"afficher_stock");
  gtk_widget_destroy(afficher_stock);
  window2=lookup_widget(objet,"window2");
  window2=create_window2();
  gtk_widget_show(window2);
treeviewstock=lookup_widget(window2,"treeview1");
Afficher_stock(treeviewstock,"repture_stock.txt");
remove("repture_stock.txt");
}


void
on_button1login_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttongotoajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1, *window4;
	window1=lookup_widget(GTK_WIDGET(button),("window1"));
	window4=lookup_widget(GTK_WIDGET(button),("window4"));
	gtk_widget_destroy(window4);
	window1=create_window1();
	gtk_widget_show(window1);
}


void
on_buttongotomodifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *afficher_stock, *window4,*treeviewstock;
	window4=lookup_widget(GTK_WIDGET(button),("window4"));
	afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
	gtk_widget_destroy(window4);
	afficher_stock=create_afficher_stock();
	gtk_widget_show(afficher_stock);
	treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
	Afficher_stock(treeviewstock,"stock.txt");
}


void
on_buttongotoafficher_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *afficher_stock, *window4,*treeviewstock;
	window4=lookup_widget(GTK_WIDGET(button),("window4"));
	afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
	gtk_widget_destroy(window4);
	afficher_stock=create_afficher_stock();
	gtk_widget_show(afficher_stock);
	treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
	Afficher_stock(treeviewstock,"stock.txt");
}


void
on_buttongotosupprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *afficher_stock, *window4,*treeviewstock;
	window4=lookup_widget(GTK_WIDGET(button),("window4"));
	afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
	gtk_widget_destroy(window4);
	afficher_stock=create_afficher_stock();
	gtk_widget_show(afficher_stock);
	treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
	Afficher_stock(treeviewstock,"stock.txt");
}





void
on_button1recherche_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	char recherche1[19];
	GtkWidget *afficher_stock, *recherche,*treeviewstock;
	afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
	recherche=lookup_widget(GTK_WIDGET(button),("entry1recherche"));
	strcpy(recherche1,gtk_entry_get_text(GTK_ENTRY(recherche)));
	recherche_stock(recherche1);
	treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
	Afficher_stock(treeviewstock,"recherche_stock.txt");
	remove("recherche_stock.txt");
}


void
on_button1modif_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
stock x;
GtkWidget *nom_produit=lookup_widget(GTK_WIDGET(button),"nom_produit");
GtkWidget *lieu=lookup_widget(GTK_WIDGET(button),"lieu");
GtkWidget *fournisseur=lookup_widget(GTK_WIDGET(button),"fournisseur");
GtkWidget *quantite=lookup_widget(GTK_WIDGET(button),"quantite");
GtkWidget *reference=lookup_widget(GTK_WIDGET(button),"reference");
GtkWidget *jrf=lookup_widget(GTK_WIDGET(button),"jrf");
GtkWidget *msf=lookup_widget(GTK_WIDGET(button),"msf");
GtkWidget *anf=lookup_widget(GTK_WIDGET(button),"anf");
GtkWidget *jre=lookup_widget(GTK_WIDGET(button),"jre");
GtkWidget *mse=lookup_widget(GTK_WIDGET(button),"mse");
GtkWidget *ane=lookup_widget(GTK_WIDGET(button),"ane");


if((strcmp((gtk_entry_get_text(GTK_ENTRY(nom_produit))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(lieu))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(fournisseur))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(reference))),"")==0))
{ 
g_print("non");
GtkWidget *dialog2;
dialog2=create_dialog2() ;
gtk_widget_show(dialog2) ;

}

else{

strcpy(x.nom_produit,gtk_entry_get_text(GTK_ENTRY(nom_produit)));
strcpy(x.lieu,gtk_entry_get_text(GTK_ENTRY(lieu)));
strcpy(x.fournisseur,gtk_entry_get_text(GTK_ENTRY(fournisseur)));
strcpy(x.reference,gtk_entry_get_text(GTK_ENTRY(reference)));

x.quantite=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
x.date_fabrication.jour= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jrf));
x.date_fabrication.mois= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(msf));
x.date_fabrication.annee= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anf));
x.date_expiration.jour= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jre));
x.date_expiration.mois= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mse));
x.date_expiration.annee= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ane));

strcpy(x.type,a);
strcpy(x.unite,b);


GtkWidget *dialog1;
dialog1=create_dialog1() ;
gtk_widget_show(dialog1) ;



		modifier(x.nom_produit, x);
}

strcpy(a,"laitier");
strcpy(b,"piéce");


}


