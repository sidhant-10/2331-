#include<stdio.h>
#include "postfixevaluation.h"
#include "utils.h"
#include "merge.h"
#include "stack.h"
#include "filesort.h"
#include "match.h"
#include "dijkstra.h"
#include "infixtopostfix.h"
#include "binarytree.h"
#include "quicksort.h"
#include <stdlib.h>
int main()
{ Node* root = NULL;

    int choice, data;
	 int n,ret,c;
char expression[30];
 char inputfile[100];
    char outputFile[100];
int result;
char postfix[30];
int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
int m, value;
    Node* root = NULL;
Stack s1;
   do
   {
   	printf("\nenter 1: For merge sort \nenter 2:for add \nenter 3:for insertion sort \nenter 4 for postfix evaluation \n\nenter 0:for exit");
	printf("\nenter 5:bracketmatching \nenter 6:shortest path algo\nenter 7:binary tree \n8:infix to postfixevauluation\n9:quicksort\n10:bracketmatching");
   	scanf("%d",&n);
   	
   	switch(n){
   	 case 1:
	   file_sort();
   	       break;  
   	  case 2:ret=add(5,10);
		 printf("%d",ret);
   	        break;
   	  case 3:init(&s1);
	        push(&s1,50);
			printf("%d",pop(&s1));
   	        break;
		case 4:   printf("enter postfix expression");
scanf("%s",expression);
      result= evaluate(expression);  
	  
        printf("Result= %d\n", result);
         break; 


		case 5:printf("Bracket matching, enter expression");
        
		scanf("%s",expression);

         if (isMatchingBrackets(expression)) {
              printf("Brackets are balanced!\n");
               } else {
                      printf("Brackets are not balanced!\n");
                              }
        break;
		 case 6: printf("Shortest path");
		  
    int src = 0; // Specify the source vertex.

    dijkstra(graph, src);
		break;
		
	 case 7:do{
		 printf("\nBinary Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                // Clean up and exit
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
	 }
	 while(choice!=5);
	 free(root);
	
	 case 8: printf(" enter Infix expression");
        
		scanf("%s",expression);
		infixToPostfix(expression, postfix);
		
	   result= evaluate(postfix);  
	  
        printf("Result= %d\n", result);
         break; 
case 9:
 printf("Enter the input file name: ");
                scanf("%s", inputfile);
                printf("Enter the output file name: ");
                scanf("%s", outputFile);
                sortAndSaveWordFrequency(inputfile, outputFile);
                printf("Word frequency sorted and saved.\n");
	 
	 break;
case 10: printf("Enter an expression: ");
                scanf("%s", expression);
                if (areBracketsBalanced(expression)) {
                    printf("Brackets are balanced.\n");
                } else {
                    printf("Brackets are not balanced.\n");
                }
case 0: printf("exiting menu");break;
   	  default: printf("\n\nInvalid text\n\n");
	   }
	  
   }while(n);
   return 0;
}

