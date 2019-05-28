

//Declarations:
	struct Pizza{
		int id_pizza;
		char *nom_pizza;
		float prix;
		int qte;
		Pizza* suivant;
	};

//Fonctions:

	int commander_Pizza(Client* p_Client,Pile* p_Pizza){
		int idPizza,qte_pizza;
		char nomPizza[30];
		float prix_pizza;
		FILE *f_Pizza;
		do{	
			f_Pizza = fopen("Pizza.txt","r+");
			printf("ID\t|   Nom Pizaa		|\t Prix\n");
			while(!(feof(f_Pizza))){
				fscanf(f_Pizza,"%d,%[^\n,],%f\n",&idPizza,nomPizza,&prix_pizza);
					printf("\n%d)\t   %s\t  %.2f (DH)\n",idPizza,nomPizza,prix_pizza);
			}
			puts("===========================================================");
			puts("-1)	cree votre pizza.\n");
			puts("99)	Commander.\n");
			puts("0)	Retour au Menu.");
			int next_id=idPizza;
		
		
			printf("\n########	Quantite: %d \t Prix Total : %.2f (DH)	########\n",qte_total,prix_total);
			choix(&c);
			switch(c){
				case -1:
					next_id++;
					printf("Nom pizza: ");
					gets(nomPizza);
					gets(nomPizza);
					printf("Prix de pizza: ");	scanf("%f",&prix_pizza);
					printf("Quantite commandee : ");	scanf("%d",&qte_pizza);
					printf("%s\n",nomPizza);
					f_Pizza = fopen("Pizza.txt","a+");
					fprintf(f_Pizza,"%d,%s,%f\n",next_id,nomPizza,prix_pizza);
					if(qte_pizza!=0)
						if(empiler_pizza(p_Pizza,idPizza,nomPizza,prix_pizza,qte_pizza)!=-1)
							printf("Ajout de %s au panier...\n",nomPizza);
					fclose(f_Pizza);
					break;
				case 99:
					return qte_total;
					break;	
				case 0: break;
				
				default:	
					rewind(f_Pizza);
					while(!feof(f_Pizza)){
						fscanf(f_Pizza,"%d,%[^,],%f\n",&idPizza,nomPizza,&prix_pizza);
						if(c==idPizza){
							printf("Quantite commandee : ");	scanf("%d",&qte_pizza);
							if(qte_pizza!=0) 
								if(empiler_pizza(p_Pizza,idPizza,nomPizza,prix_pizza,qte_pizza)!=-1)
									printf("Ajout de %s au panier...\n",nomPizza);	
							break;
						}
					}
					if(c!=idPizza)
				        printf("Choix Eronne!\n");
			}
			sleep(2);
			system("cls");
			
		}while(c!=0);
		fclose(f_Pizza);
		menu_achat(&C,&Pizzas);
	    return;
	}
	void liberer_pizza(Pile* p_Pizza){
		while(p_Pizza->sommet!=NULL){
			free(p_Pizza->sommet->nom_pizza);
			free(p_Pizza->sommet);
			p_Pizza->sommet=p_Pizza->sommet->suivant;
		}
		
	}
	void achat_pizzas(Client* p_Client,Pile* p_Pizza){
		p_Client->compte -=prix_total;
		num_compte=p_Client->compte;
		FILE * f_Commande=fopen("Commande.txt","a+");
		Pizza *temp = p_Pizza->sommet;
		while(temp!=NULL){
			fprintf(f_Commande,"%d,%d,%d\n",p_Client->num_client,temp->id_pizza,temp->qte);
			temp=temp->suivant;
			
		}
		fclose(f_Commande);
		liberer_pizza(p_Pizza);
		save_client_data(p_Client);
		puts("Merci pour votre achat.");
		printf("Solde de votre compte est : %.2f\n",p_Client->compte);
		system("pause");
	}
	
	void voir_commandes(Client* p_Client){
		int num_clt,clt_pizza,qte,qte_T=0,idPizza;	float prix_U,prix_T=0;
		char nomPizza[30];
		printf("===================== %s %s =====================\n",p_Client->nom_client,p_Client->prenom_client);
		puts("-------------------------------------------------------");
		FILE *f_commande = fopen("Commande.txt","r+");
		FILE *f_Pizza = fopen("Pizza.txt","r+");
		printf("ID\t|   Nom Pizza		|\t Prix\n");
		puts("-------------------------------------------------------");
		while(!feof(f_commande)){
			fscanf(f_commande,"%d,%d,%d\n",&num_clt,&clt_pizza,&qte);
			if(num_clt==p_Client->num_client){
				rewind(f_Pizza);
				while(!(feof(f_Pizza))){
					fscanf(f_Pizza,"%d,%[^\n,],%f\n",&idPizza,nomPizza,&prix_U);
					if(clt_pizza==idPizza)
						{
							prix_T += (qte * prix_U);
							qte_T += qte;
							printf("\n%d)\t   %s\t  %.2f (DH)\n",idPizza,nomPizza,prix_U);
						}
				}
			}
		}
		printf("\n########	Quantite: %d \t Prix Total : %.2f (DH)	########\n",qte_T,prix_T);
		system("pause");
	}
	
	
