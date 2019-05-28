#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
#include "client.c"
#include "pizza.c"
#include "menu.c"
#include "pile.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void init_program(Pile * P){
	P->sommet=NULL;
	P->taille=0;
	qte_total=0;
	prix_total=0; 
	logged=0;
}	
int main(int argc, char *argv[]) {
	system("cls");
	init_program(&Pizzas);
	login_menu(&C);
	menu_achat(&C,&Pizzas);
	return 0;
}
