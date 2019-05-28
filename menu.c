//fonctions globales
	void choix(int *choix){
			printf("\n\tChoix : ");	scanf("%d",choix);
			
	}
	void quitter(){
		printf("\n\tAu Revoir.\n");
		exit(0);
	}
void login_menu(Client *p_Client){
		
	do{
		
    printf("             ___________________________________________\n");
	printf("            |                    Home                   |\n");     
	printf("            |-------------------------------------------|\n");
	printf("            |  1)  Login.                               |\n");
	printf("            |  2)  Nouveau client.                      |\n");
	printf("            |  3)  Exit.                                |\n");
	printf("            |___________________________________________|\n");
		choix(&c);
		switch(c){
			case 1:
				logged=sign_in(p_Client);
				break;
			case 2:
				logged=sign_up(p_Client);
				break;
			case 3:
				quitter(0);
				break;
			default:
				printf("Choix invalide.\n");		
		}
	}while(logged!=1);
}
void menu_achat(Client *p_Client,Pile* p_Pizza){
do{
	
	clear_screen(0);
	printf("\n#============================ %s %s ( ID :  %d )============================#\n",p_Client->nom_client,p_Client->prenom_client,p_Client->num_client);
	puts(" 1)	Commander une Pizza.");
	puts(" 2)	Voir mon panier.");
	puts(" 3)	Voir mes commandes.");
	puts(" 4)	consulter votre compte.");
	puts(" 5)	log out.");
	puts(" 0)	Clear.");
	
		choix(&c);
		switch(c){
			case 1:
				qte_total=commander_Pizza(p_Client,p_Pizza);				
					system("pause");
				if(qte_total==0)	menu_achat(p_Client,p_Pizza);
				else{
					if(p_Client->compte < prix_total){
						puts("Solde insuffisant! : ");
						puts("Vos pizzas sont dans votre panier, veuillez les consulter apres la Recharge de votre compte!");
						sleep(1);
						menu_achat(p_Client,p_Pizza);
					}
					else{
						achat_pizzas(p_Client,p_Pizza);
						menu_achat(p_Client,p_Pizza);
					}
					
				}	
				break;
			case 2:
				
				if(p_Pizza->sommet!=NULL)	 affiche_panier(p_Pizza);
				else	printf("Votre panier est vide.\n");	
				system("pause");
				break;
			case 3:
				voir_commandes(p_Client);
				break;	
			case 4:
				client_menu(p_Client);
				system("pause");
				break;
			case 5:	
				printf("%s %s (%d) Logging out ...\n",p_Client->prenom_client,p_Client->nom_client,p_Client->num_client);
				libere_client(p_Client); 
				sleep(1);
				main();
				break;
			case 0:
				system("cls");
				menu_achat(p_Client,p_Pizza);

			
		}
	}while(c!=5);
}
