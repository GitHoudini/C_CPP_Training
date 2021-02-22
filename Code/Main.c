/*
 ============================================================================
 Name        : TestCode
 Author      : Vitor V.
 Version     :
 Copyright   : 
 Description : Code for Gupy test
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Nódulo com dado em numero inteiro e endereço do próximo da lista
struct node {
	int data;
	struct node* next;
};

void print_list(struct node *root) {
	struct node *listWatch;
	listWatch = root;

	printf ("%d ",listWatch->data);
	while (listWatch->next != NULL){
		listWatch = listWatch->next;
		printf ("%d ",listWatch->data);
	}
	
	printf ("\n");
}

void put_number(struct node *root, int numData) {
	struct node *newMember;
	newMember = root;

	//Caminha pela lista
	if (newMember != 0){
		while (newMember->next != 0){
			newMember = newMember->next;
		}
	}

	//Cria espaço e adiciona dado no final da fila
	newMember->next = (struct node*)malloc(sizeof(struct node));
	newMember = newMember->next;
	newMember->data = numData;
	newMember->next = 0;

	//Imprime lista
	print_list (root);
}

void get_number(struct node *root, int pos) {
	struct node *listWatch;
	int aux;
	listWatch = root;
	if (pos > 1){
		for (aux=1; aux<pos; aux++){
			listWatch = listWatch->next;
		}
	}
	printf ("%d\n",listWatch->data);
}

void remove_number(struct node *root, int data) {

}

void last_number(struct node *root) {

}

int main(int argc, char *argv[]) {
	char input[201];

	//Inicio da lista
	struct node *root;
	root = (struct node*)malloc(sizeof(struct node));
	root->data = 2147483647;
	root->next = 0;

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}
		
		//Quebra do prompt do usuario em comando e numero inteiro
		char *cmdStr;
		char *cmdNum;
		int dado;
		cmdStr = strtok (input," ,.;-");
		cmdNum = strtok(NULL," ,.;-");
		dado = strtol (cmdNum,NULL,10);

		if (strncmp(cmdStr, "put", 3) == 0) {			
			//Caso seja o primeiro dado, senao, corre pela lista
			if (root->data == 2147483647){
				root->data = dado;
				print_list(root);
			}
			else {
				put_number(root, dado);
			}
		}

		if (strncmp(cmdStr, "get", 3) == 0) {
			get_number(root,dado);
		}

		if (strncmp(cmdStr, "list", 4) == 0) {
			if (root->data == 2147483647){
				printf("Lista vazia\n");
			} else {
				print_list(root);	
			}
		}

		if (strncmp(cmdStr, "remove", 6) == 0) {
			remove_number(root,dado);
			print_list(root);
		}

		if (strncmp(cmdStr, "clear", 5) == 0) {
			root->data = 2147483647;
			root->next = 0;
		}

		if (strncmp(cmdStr, "first", 5) == 0) {
			if (root->data == 2147483647){
				printf("Lista vazia\n");
			} else {
				printf("%d\n",root->data);	
			}
		}

		if (strncmp(cmdStr, "last", 4) == 0) {
			last_number(root);
		}

		if (strncmp(cmdStr, "exit", 4) == 0) {
			printf("Leaving. Good bye.\n");
		}

	}

	return EXIT_SUCCESS;
}