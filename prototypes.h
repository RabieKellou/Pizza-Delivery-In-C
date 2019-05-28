//Declaration des variables globales pour :
	
	//Adresse
		typedef struct Adresse Adresse;
		 int num,num_bat,num_apt;
		 float num_compte;
	//Client
		char nom[30],prenom[30],nom_ville[15],nom_rue[20],num_tel[20],mot_passe[20];
		typedef struct Client Client;
		Client C;
	
	
	//Pizza:
		typedef struct Pizza Pizza;

	//Programme
		int c,qte_total,logged;
		float prix_total;
	//pile 
		typedef struct Pile{
				Pizza * sommet;
				int taille;
			}Pile;
			
		Pile Pizzas;	

	//pile:
	int	empiler_pizza(Pile*,int,char*,float,int);
	void affiche_panier(Pile *);
//############################################################################################################################	
	
//Prototypes :
	//Client:
		Client * nouveau_client(Client *);
		void copier_data(Client *,int,char*,char* ,char* ,char* ,int ,int ,char* ,float ,char* );
		int sign_in(Client*);
		int sign_up(Client*);
		void client_menu(Client*);
		void save_client_data(Client*);
		int get_last_client_id();
	//Pizza:
		
		int commander_Pizza(Client*,Pile *);
	// Commande
		void voir_commandes(Client* );	
	//Programme:
		void clear_screen(int s){
			sleep(s);
			system("cls");
		}
		void choix(int *);
		void login_menu(Client *);
		void menu_achat(Client *,Pile *);
		void init_program(Pile *);
