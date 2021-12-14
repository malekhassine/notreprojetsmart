#include "stock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

enum{
TYPE,
NOM_PRODUIT,
LIEU,
FOURNISSEUR,
QUANTITE,
UNITE,
REFERENCE,
DATE_FABRICATION,
DATE_EXPIRATION,
COLUMNS
};

void Ajouter_stock(stock s)
{
	FILE *f;
	f=fopen("stock.txt","a+");
	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %s %d %s %d %d %d %d %d %d %s\n",s.type,s.nom_produit,s.lieu,s.fournisseur,s.quantite,s.unite,s.date_fabrication.jour,s.date_fabrication.mois,s.date_fabrication.annee,s.date_expiration.jour,s.date_expiration.mois,s.date_expiration.annee,s.reference);
		fclose(f);
	}
} 

void Afficher_stock(GtkWidget *liste,char file[20])
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  stock s;
  char r1[20];
  char r2[20];
  char r3[20];
  char r4[20];
  char r5[20];
  char r6[20];
  char dt_date_fabrication[40];
  char dt_date_expiration[40];
       store=NULL;
  
           FILE*f;
     store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
   if(store==NULL)
   {

          renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes(" Nom Produit",renderer,"text",NOM_PRODUIT, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes(" Lieu",renderer,"text",LIEU, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes(" Fournisseur",renderer,"text",FOURNISSEUR, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes(" Qunatité",renderer,"text",QUANTITE, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("Unité",renderer,"text",UNITE, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new();
     
          column = gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",REFERENCE, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("date de fabrication",renderer,"text",DATE_FABRICATION, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("date d'expiration",renderer,"text",DATE_EXPIRATION, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   }

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f= fopen(file,"r");
if(f==NULL){return;}
else{
	while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d %d %s\n",s.type,s.nom_produit,s.lieu,s.fournisseur,&s.quantite,s.unite,&s.date_fabrication.jour,&s.date_fabrication.mois,&s.date_fabrication.annee,&s.date_expiration.jour,&s.date_expiration.mois,&s.date_expiration.annee,s.reference)!=EOF)
	{
		strcpy(dt_date_fabrication,"");
		strcpy(dt_date_expiration,"");

		sprintf(r1,"%d",s.date_fabrication.jour);
		sprintf(r2,"%d",s.date_fabrication.mois);
		sprintf(r3,"%d",s.date_fabrication.annee);
		strcat(strcat(strcat(strcat(strcat(dt_date_fabrication,r1),"/"),r2),"/"),r3);

		sprintf(r4,"%d",s.date_expiration.jour);
		sprintf(r5,"%d",s.date_expiration.mois);
		sprintf(r6,"%d",s.date_expiration.annee);
		strcat(strcat(strcat(strcat(strcat(dt_date_expiration,r4),"/"),r5),"/"),r6);

		gtk_list_store_append (store, &iter);
		gtk_list_store_set(store,&iter,TYPE,s.type,NOM_PRODUIT,s.nom_produit,LIEU,s.lieu,FOURNISSEUR,s.fournisseur,QUANTITE,s.quantite,UNITE,s.unite,REFERENCE,s.reference,DATE_FABRICATION,dt_date_fabrication,DATE_EXPIRATION,dt_date_expiration,-1); 
       }
              fclose(f);
       gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
       g_object_unref (store);
	}
    
}



/*********Supp stock***************/
void dell_stock(char nom_produit[20])
{
	stock s;
	FILE *f,*ftmp;
	f=fopen("stock.txt","r");
	ftmp=fopen("tmp.txt","a+");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d %d %s\n",s.type,s.nom_produit,s.lieu,s.fournisseur,&s.quantite,s.unite,&s.date_fabrication.jour,&s.date_fabrication.mois,&s.date_fabrication.annee,&s.date_expiration.jour,&s.date_expiration.mois,&s.date_expiration.annee,s.reference)!=EOF)
		{
			if(strcmp(s.nom_produit,nom_produit)!=0)
				fprintf(ftmp,"%s %s %s %s %d %s %d %d %d %d %d %d %s\n",s.type,s.nom_produit,s.lieu,s.fournisseur,s.quantite,s.unite,s.date_fabrication.jour,s.date_fabrication.mois,s.date_fabrication.annee,s.date_expiration.jour,s.date_expiration.mois,s.date_expiration.annee,s.reference);
			
		}
	}
	fclose(f);
	fclose(ftmp);
	remove("stock.txt");
	rename("tmp.txt","stock.txt");
}
void reptre_de_stock()
{
	stock s;
	FILE *f,*ftmp;
	f=fopen("stock.txt","r");
	ftmp=fopen("repture_stock.txt","a+");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d %d %s\n",s.type,s.nom_produit,s.lieu,s.fournisseur,&s.quantite,s.unite,&s.date_fabrication.jour,&s.date_fabrication.mois,&s.date_fabrication.annee,&s.date_expiration.jour,&s.date_expiration.mois,&s.date_expiration.annee,s.reference)!=EOF)
		{
			if(s.quantite==0)
				fprintf(ftmp,"%s %s %s %s %d %s %d %d %d %d %d %d %s\n",s.type,s.nom_produit,s.lieu,s.fournisseur,s.quantite,s.unite,s.date_fabrication.jour,s.date_fabrication.mois,s.date_fabrication.annee,s.date_expiration.jour,s.date_expiration.mois,s.date_expiration.annee,s.reference);
			
		}
	}
	fclose(f);
	fclose(ftmp);
}
void recherche_stock(char nom_produit[20])
{
	stock s;
	FILE *f,*ftmp;
	f=fopen("stock.txt","r");
	ftmp=fopen("recherche_stock.txt","a+");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d %d %s\n",s.type,s.nom_produit,s.lieu,s.fournisseur,&s.quantite,s.unite,&s.date_fabrication.jour,&s.date_fabrication.mois,&s.date_fabrication.annee,&s.date_expiration.jour,&s.date_expiration.mois,&s.date_expiration.annee,s.reference)!=EOF)
		{
			if(strcmp(s.nom_produit,nom_produit)==0)
				fprintf(ftmp,"%s %s %s %s %d %s %d %d %d %d %d %d %s\n",s.type,s.nom_produit,s.lieu,s.fournisseur,s.quantite,s.unite,s.date_fabrication.jour,s.date_fabrication.mois,s.date_fabrication.annee,s.date_expiration.jour,s.date_expiration.mois,s.date_expiration.annee,s.reference);
			
		}
	}
	fclose(f);
	fclose(ftmp);

}


void modifier(char nom_produit[20], stock x)
     {
        
	stock s;
	FILE *f,*ftmp;
	f=fopen("stock.txt","r");
	ftmp=fopen("tmp2.txt","a+");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d %d %s\n",s.type,s.nom_produit,s.lieu,s.fournisseur,&s.quantite,s.unite,&s.date_fabrication.jour,&s.date_fabrication.mois,&s.date_fabrication.annee,&s.date_expiration.jour,&s.date_expiration.mois,&s.date_expiration.annee,s.reference)!=EOF)
		{
			if(strcmp(s.nom_produit,nom_produit)==0)
				fprintf(ftmp,"%s %s %s %s %d %s %d %d %d %d %d %d %s\n",x.type,x.nom_produit,x.lieu,x.fournisseur,x.quantite,x.unite,x.date_fabrication.jour,x.date_fabrication.mois,x.date_fabrication.annee,x.date_expiration.jour,x.date_expiration.mois,x.date_expiration.annee,x.reference);
			
		}
	}
	fclose(f);
	fclose(ftmp);
	remove("stock.txt");
	rename("tmp2.txt","stock.txt");
      }






