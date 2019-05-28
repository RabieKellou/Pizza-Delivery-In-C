	
	
//Empilement:
int empiler_pizza(Pile *P, int id_pizza,char *nom_pizza,float prix_pizza,int qte){
	Pizza* nouveauPizza = (Pizza *) malloc(sizeof(Pizza));
	if(nouveauPizza==NULL)	  return -1;
	nouveauPizza->nom_pizza = (char *) malloc(40*sizeof(char));
	if(nouveauPizza->nom_pizza==NULL)	return -1;
	//affectation
		nouveauPizza->id_pizza = id_pizza;
		nouveauPizza->prix = prix_pizza;
		nouveauPizza->qte = qte;
		strcpy(nouveauPizza->nom_pizza,nom_pizza);
		
		qte_total += nouveauPizza->qte;
		prix_total += (nouveauPizza->prix * nouveauPizza->qte);
		nouveauPizza->suivant = P->sommet;
		P->sommet = nouveauPizza;
		
	P->taille++;
	return 0;
}
//Depilement:
int depiler_pizza(Pile *P){
	Pizza *supp_pizza;
	if(P->taille==0)
		return -1;
	supp_pizza = P->sommet;
	printf("%s %.2f(DH) id = %d a ete supprimee sur votre panier.\n",supp_pizza->nom_pizza,supp_pizza->prix,supp_pizza->id_pizza);
	
	qte_total -= supp_pizza->qte;
	prix_total -= (supp_pizza->prix * supp_pizza->qte);
	
	P->sommet = P->sommet->suivant;
	free(supp_pizza->nom_pizza);
	free(supp_pizza);	
	P->taille--;
	return 0;
}

//Affichafge de panier
void affiche_panier(Pile *P){
	int i;
	struct Pizza* courant = P->sommet;
	printf("Voila votre panier:\n");
	puts("ID    | \tNom Pizza \t | \t Prix \t\t|  Quantite	");
	while(courant != NULL){
		printf("\n%d)\t%s\t\t  %.2f (DH)\t   %d \n",courant->id_pizza,courant->nom_pizza,courant->prix,courant->qte);
		courant = courant->suivant;
	}
	puts("==============================================================");
	printf("Total :				\t %.2f (DH)\t  %d\n",prix_total,qte_total);
	puts("==============================================================");
	printf("\n\t 1)Commander\n\t 0)Retour au menu\n");
	do{
		choix(&c);
		switch(c){
			case 1:
				achat_pizzas(&C,P);
				break;
			case 0: break;	
			default:
				printf("Choix invalide\n");
		}
	}while(c!=0);
}
