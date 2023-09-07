#include<stdio.h>
#include "postfix.h"

#include "merge.h"
#include "stack.h"

int main()
{ int n,ret;
char expression[30]= "2 3 1 * + 9 -";
int result;
Stack s1;
   do
   {
   	printf("\nenter 1: For merge sort \nenter 2:for insertion sort \n enter 3 for postfix evaluation \nenter 0:for exit");
   	scanf("%d",&n);
   	
   	switch(n)
   	{ case 1:
	   mergesort();
   	         break;
   	  
   	  case 2:init(&s1);
	        push(&s1,50);
			printf("%d",pop(&s1));
   	        break;
		case 3:   
     result= evaluate(expression);  
printf("Result= %d\n", result);
break;  
   	  case 0:break;
   	  default: printf("\n\nInvalid go home\n\n");
	   }
   }while(n);
   return 0;
}