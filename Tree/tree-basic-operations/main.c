#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "tree.h"

typedef struct User
{
	int Id;
	char *name;
}User;

void print_integer(void* data)
{
	int* intData = (int *)data;
	printf("%d ", *intData);
}

void print_user(void* usrPtr)
{
	User* usr = (User*)usrPtr;
	printf("%d. %s \n", usr->Id, usr->name);
}

int user_compare(void* one, void* two)
{
	User* usr1 = (User*)one;
	User* usr2 = (User*)two;
	if(usr1->Id > usr2->Id)
		return 1;
	else if(usr1->Id < usr2->Id)
		return -1;
	else
		return 0;
}

int main(void) {
	Tree* usrTree = initialize_Tree();
	usrTree->print_item = print_user;
	usrTree->node_compare = user_compare;
	printf("usrTree Initialization ===> count : %d , address : %p \n", tree_size(usrTree), usrTree->root); /* prints !!!Hello World!!! */

	printf("Is usrTree Empty ? : %d \n", is_tree_empty(usrTree));

	printf("Depth Of usrTree : %d \n", depth_of_TreeNode(usrTree->root));

	printf("Height Of usrTree : %d \n", height_of_TreeNode(usrTree, usrTree->root));

	User* usr5 = (User*)malloc(sizeof(struct User));
	usr5->Id = 5;
	usr5->name = "Mycroft";

	insert_into_tree(usrTree, usr5);

	User* usr6 = (User*)malloc(sizeof(struct User));
	usr6->Id = 6;
	usr6->name = "Sherlock";

	insert_into_tree(usrTree, usr6);

	User* usr = (User*)malloc(sizeof(struct User));
	usr->Id = 1;
	usr->name = "Andy";

	insert_into_tree(usrTree, usr);

	User* usr2 = (User*)malloc(sizeof(struct User));
	usr2->Id = 2;
	usr2->name = "Svich";

	insert_into_tree(usrTree, usr2);

	User* usr4 = (User*)malloc(sizeof(struct User));
	usr4->Id = 4;
	usr4->name = "Ginni";

	insert_into_tree(usrTree, usr4);

	User* usr3 = (User*)malloc(sizeof(struct User));
	usr3->Id = 3;
	usr3->name = "Adam";

	insert_into_tree(usrTree, usr3);


	printf("Is usrTree Empty ? : %d \n", is_tree_empty(usrTree));

	print_tree(usrTree);

	printf("Depth Of usrTree : %d \n", depth_of_TreeNode(usrTree->root));

	printf("Height Of usrTree : %d \n", height_of_TreeNode(usrTree, usrTree->root));

	return EXIT_SUCCESS;
}


