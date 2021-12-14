#ifndef STOCK_H_
#define STOCK_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct Date{
int jour;
int mois;
int annee;
}date;
typedef struct Stock{
char type[20];//0:
char nom_produit[20];
char lieu[20];
char fournisseur[50];
int quantite;
char unite[20];//0:Kg 1:piece
date date_fabrication;
date date_expiration;
char reference[20];
}stock;
void Ajouter_stock(stock s);
void Afficher_stock(GtkWidget *liste,char file[20]);
void dell_stock(char nom_produit[20]);
void reptre_de_stock();
void recherche_stock(char nom_produit[20]);
void modifier(char nom_produit[20], stock x);


#endif
