#include <stdio.h>
#include "SimpleLinkList.h"

void pt(SLLType t)
{
	printf("trave:%s\n",t) ;
} 

char k[] = "hello";
char q[] = "world";
int main(void)
{
	struct SLL mysll;
	int a;
	SLLType e;
	SLL_Init(&mysll);

	if(SLL_Empty(&mysll)==SLL_SUCCESS) printf("sll empty,length:%d\n\n",SLL_Length(&mysll));
	
	
	SLL_AddElem(&mysll,(SLLType)q);
	SLL_AddElem(&mysll,(SLLType)k);
	
	SLL_InsertElem(&mysll,1,(SLLType)"sll");
	
	if(SLL_Empty(&mysll)==SLL_SUCCESS) printf("sll empty,length:%d\n\n",SLL_Length(&mysll));
	
	SLL_Traverse(&mysll,pt);

	printf("get1:%s\n",SLL_GetElem(&mysll,1));
	printf("get2:%s\n\n\n",SLL_GetElem(&mysll,2));
	
	printf("hello is in :%d\n\n\n",SLL_GetPosition(&mysll,(SLLType)k));
	
	
	
	SLL_DeleteElemC(&mysll,(SLLType)k,e);
	
	SLL_DeleteElem(&mysll,1,e);
	
	SLL_Traverse(&mysll,pt);
	
	SLL_Clear(&mysll);

	
	return 0; 
} 

