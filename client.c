//Declarations:
	struct Adresse{
		char *ville,*rue;
		int bat,apt;
	};
	
	struct Client{
		int num_client;
		char *nom_client,*prenom_client;
		char *tel;
		char *mot_passe;
		float compte;
		Adresse *adr_client;
	};
//Fonctions:
	//Nouveau client:
	Client* nouveau_client(Client *nouveau){
			nouveau->nom_client = (char*)	malloc(30*sizeof(char));
			nouveau->prenom_client = (char*)	malloc(30*sizeof(char));
			nouveau->tel = (char*) malloc(20*sizeof(char));
			nouveau->adr_client = (Adresse *) malloc(sizeof(Adresse));
			nouveau->adr_client->ville = (char *) malloc(15*sizeof(char));
			nouveau->adr_client->rue = (char *) malloc(20*sizeof(char));
			nouveau->mot_passe = (char *) malloc(20*sizeof(char));
			return nouveau;
	}
	void copier_data(Client *p_Client,int num,char* nom,char* prenom,char* ville,char* rue,int bat,int apt,char* tel,float compte,char* mdpasse){
		strcpy(p_Client->nom_client,nom);
	    strcpy(p_Client->prenom_client,prenom);
	    strcpy(p_Client->adr_client->ville,ville);
	    strcpy(p_Client->adr_client->rue,rue);
	    strcpy(p_Client->tel,tel);
	    strcpy(p_Client->mot_passe,mdpasse);
	    p_Client->num_client=num;
	    p_Client->compte=compte;
	    p_Client->adr_client->bat=bat;
	    p_Client->adr_client->apt=apt;
	}
	
	// Login:
	int  sign_in(Client *p_Client){
		char mot_tmp[20];int id;
		FILE *f_Client;
		do{
			clear_screen(1);
			printf("ID :");	scanf("%d",&id);
			printf("Mot de passe :");	scanf("%s",mot_tmp);
			printf("\n 1) Log In.\n 0) Retour au menu.\n ");
				choix(&c);
			switch(c){
				case 1:
					f_Client = fopen("Client.txt","r+");
					while(!feof(f_Client)){
			    		fscanf(f_Client,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%s\t%f\t%s\n",&num,nom,prenom,nom_ville,nom_rue,&num_bat,&num_apt,num_tel,&num_compte,mot_passe);
						if(id==num && !(strcmp(mot_tmp,mot_passe))){
							p_Client=nouveau_client(p_Client);
							copier_data(p_Client,num,nom,prenom,nom_ville,nom_rue,num_bat,num_apt,num_tel,num_compte,mot_passe);
							fclose(f_Client);
							return 1;
						}
					}
					printf("ID ou Mot passe sont incorrect!\n");
					break;
				case 0:
					break;
				default:
					printf("Choix eronne!\n");			
			}	
		}while(c!=0);
		return 0;
		
	}

	int get_last_client_id(){
		FILE *f_Client;
		int i=0,taille;	char c;
		if((f_Client=fopen("Client.txt","r+")) != NULL){
			fseek(f_Client,0,SEEK_END);
			if((ftell(f_Client))==0)	return 0;
				//else
			taille=ftell(f_Client);
			for(i=3;taille!=0;i++){
				fseek(f_Client,-i,SEEK_END);
				taille=ftell(f_Client);
				if((c=getc(f_Client))=='\n')
					{
						
						printf("char : %c\n",c);
						break;
					}
			}
			fscanf(f_Client,"%d",&num);
			return num;
		}
		
	}
	int sign_up(Client *p_Client){
			num=get_last_client_id()+1;
			printf("Nom : \n");	scanf("%s",&nom);
			printf("Prenom : ");	scanf("%s",&prenom);
			printf("Adresse :\n\tVille : ");	scanf("%s",nom_ville);
			printf("\tRue : ");	scanf("%s",nom_rue);
			printf("\tNum batiment : ");	scanf("%d",&num_bat);
			printf("\tNum appartement : ");	scanf("%d",&num_apt);
			printf("Tel: ");	scanf("%s",num_tel);
			printf("Compte: ");	scanf("%f",&num_compte);
			printf("Mot de passe(<20): ");	scanf("%s",mot_passe);
			
		FILE *f_Client = fopen("Client.txt","a");	
	    if(f_Client!=NULL){
	    	p_Client = nouveau_client(p_Client);
	    	fprintf(f_Client,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%s\t%f\t%s\n",num,nom,prenom,nom_ville,nom_rue,num_bat,num_apt,num_tel,num_compte,mot_passe);
			copier_data(p_Client,num,nom,prenom,nom_ville,nom_rue,num_bat,num_apt,num_tel,num_compte,mot_passe);
			fclose(f_Client);
	    	return 1;
		}else{	
			printf("Impossible d'ouvrir le fichier\nYou're not Logged In");
			return 0;
		}	
	}
	void client_menu(Client* p_Client){
		do{system("cls");
		char conf;
		puts("Vos informations:	");
		
			printf(" ID:\t%d\n\t2) Nom:\t%s\n\t3) Prenom:\t%s\n\t4) Ville:\t%s\n\t5) Rue:\t%s\n\t6) Num de batiment:\t%d\n\t7) Num d\'appartement:\t%d\n\t8) Num de tel:\t%s\n\t9) Solde de compte:\t%.2f(DH)\n\t10) Mot de passe:\t%s\n\n 1) Sauvegarder\n0) Retour au menu.\n"
					,num,nom,prenom,nom_ville,nom_rue,num_bat,num_apt,num_tel,num_compte,mot_passe); 
			puts("\n\tChoisir et Modifier...");
		
			choix(&c);
			switch(c){
				case 2:	printf(" Nom :");	scanf("%s",nom);	break;
				case 3:	printf(" Prenom :");	scanf("%s",prenom);	break;	
				case 4:	printf(" Ville :");	scanf("%s",nom_ville);	break;
				case 5:	printf(" Rue :");	scanf("%s",nom_rue);	break;
				case 6:	printf(" Num de Batiment :");	scanf("%d",&num_bat);	break;
				case 7:	printf(" Num d\'appartement :");	scanf("%d",&num_apt);	break;
				case 8:	printf(" Tel :");	scanf("%s",num_tel);	break;
				case 9:	printf(" Solde de compte :");	scanf("%f",&num_compte);	break;
				case 10:	printf(" Mot de passe :");	scanf("%s",mot_passe);	break;
				case 1:
					do{
						printf("Voulez vous sauvegarder (y/n)? ");	
						scanf("%c",&conf);
						if(conf=='y'){
							copier_data(p_Client,num,nom,prenom,nom_ville,nom_rue,num_bat,num_apt,num_tel,num_compte,mot_passe);
							save_client_data(p_Client);
							printf("Saved\n");
							system("pause");
							break;
						}
					}while(conf!='y' && conf!='n');
					
					break;
				case 0:
					break;	
				default: puts("Choix invalide.");
			}
		}while(c!=0);
	}
	void save_client_data(Client* p_Client){
		int num,bat,apt;
		char nom[30],prenom[30],tel[20],ville[15],rue[20],mdpasse[20];
		float compte;
		FILE * f_Client=fopen("Client.txt","r+");
		FILE * f_Client_nv=fopen("nouveau.txt","w");
		while(!feof(f_Client)){
			fscanf(f_Client,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%s\t%f\t%s\n",&num,nom,prenom,ville,rue,&bat,&apt,tel,&compte,mdpasse);
		    if(num!=p_Client->num_client)
		    	fprintf(f_Client_nv,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%s\t%f\t%s\n",num,nom,prenom,ville,rue,&bat,&apt,tel,&compte,mdpasse);
			else
				fprintf(f_Client_nv,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%s\t%f\t%s\n",p_Client->num_client,p_Client->nom_client,p_Client->prenom_client,p_Client->adr_client->ville,p_Client->adr_client->rue,p_Client->adr_client->bat,p_Client->adr_client->apt,p_Client->tel,p_Client->compte,p_Client->mot_passe);
		}

		fclose(f_Client);
		fclose(f_Client_nv);
		remove("Client.txt");
		rename("nouveau.txt","Client.txt");
		system("pause");
	}	
	void libere_client(Client* p_Client){
		free(p_Client->nom_client);
		free(p_Client->prenom_client);
		free(p_Client->tel);
		free(p_Client->adr_client);
		free(p_Client->adr_client->ville);
		free(p_Client->adr_client->rue);
		free(p_Client->mot_passe);
	}
