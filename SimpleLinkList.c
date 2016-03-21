#include "SimpleLinkList.h"
#include <stdlib.h>

//���ڵ�n�����ݳ�ʼ��Ϊ{data,next} 
void Node_Init(struct node* n,SLLType data,struct node* next)
{
	n->data = data;
	n->next = next;
} 

//��ʼ���������� 
SLLStatusCode SLL_Init(struct SLL* sll)
{
	sll->head = (struct node*)malloc(sizeof(struct node));//������ͷ 
	//��ͷ����Ϊ�գ������ã�����ͷ���ָ��ΪNULL 
	sll->head->data = SLL_NULL;
	sll->head->next = SLL_NULL;	
}


//��sll���������л�ȡָ�� positionλ�õĽڵ�ָ�� 
struct node* SLL_GetElemPtr(struct SLL* sll,SLLCountType position)
{
	struct node* tmpPtr = sll->head;//�������ͷ 
	SLLCountType curposition = 0;
	
	//���sll�����ڣ�����SLL_NULL 
	if(sll==SLL_NULL) return SLL_NULL;
	
	//ǰ������ 
	while(tmpPtr!=SLL_NULL && curposition<position)
	{
		tmpPtr = tmpPtr->next;
		curposition++;	
	}
	//�жϽڵ��Ƿ���ȷ 
	if(tmpPtr!=SLL_NULL && curposition==position)
	{
		return tmpPtr; 
	}
	else
	{
		//����ȷ����  SLL_NULL
		return SLL_NULL; 
	} 
	
} 

//����ָ���������������λ�ã�����0��ʾ����
SLLCountType SLL_GetPosition(struct SLL* sll,SLLType data)
{
	struct node* tmpPtr = SLL_NULL;
	SLLCountType count = 0;
	//�������ͺ����Ƿ���� 
	if(sll==SLL_NULL) return 0;
	if(data==SLL_NULL) return 0;
	//�������� 
	for(tmpPtr = sll->head->next;tmpPtr!=SLL_NULL;tmpPtr = tmpPtr->next)
	{
		//��ÿ���ڵ�������λ����
		if(tmpPtr->data==data) break ;
		count++;
	} 
	return  count;
}

//���ص�������sll�ĳ��� 
SLLCountType SLL_Length(struct SLL* sll)
{
	SLLCountType count = 0;
	struct node* tmpPtr =SLL_NULL;
	//���sll�����ڣ�����SLL_PRM_ERROR 
	if(sll==SLL_NULL) return SLL_PRM_ERROR;
	
	//�������������� 
	for(tmpPtr = sll->head->next;tmpPtr!=SLL_NULL;tmpPtr = tmpPtr->next)
	{
		count++;
	}
	
	return count;
}

//�жϵ��������Ƿ�Ϊ�� 
SLLStatusCode SLL_Empty(struct SLL* sll)
{
	//���sll�����ڣ�����SLL_PRM_ERROR 
	if(sll==SLL_NULL) return SLL_PRM_ERROR;
	
	return sll->head->next==SLL_NULL;	
}

//������� 
SLLStatusCode SLL_Clear(struct SLL* sll)
{
	SLLType tmp;
	//���sll�����ڣ�����SLL_PRM_ERROR 
	if(sll==SLL_NULL) return SLL_PRM_ERROR;
	//���ϵ�ɾ����һ���ڵ㣬֪������Ϊ�� 
	while(SLL_Length(sll)>0)
	{
		SLL_DeleteElem(sll,1,tmp);
	} 
	return SLL_SUCCESS;
}

//����ÿ������ڵ㣬һ�ڵ�������λ����������ָ������ visit
SLLStatusCode SLL_Traverse(struct SLL* sll,void (*visit)(SLLType t))
{
	struct node* tmpPtr = SLL_NULL;
	//�������ͺ����Ƿ���� 
	if(sll==SLL_NULL) return SLL_PRM_ERROR;
	if(visit==SLL_NULL) return SLL_PRM_ERROR;
	//�������� 
	for(tmpPtr = sll->head->next;tmpPtr!=SLL_NULL;tmpPtr = tmpPtr->next)
	{
		//��ÿ���ڵ�������λ���� 
		(*visit)(tmpPtr->data); 
	} 
	return  SLL_SUCCESS;
}



//����sll���������л�ȡָ��λ�� position�Ľڵ�������� 
SLLType SLL_GetElem(struct SLL* sll,SLLCountType position)
{
	struct node* tmpPtr = SLL_NULL;
	//�ж������Ƿ���ں�λ���Ƿ���Ч 
	if(sll==SLL_NULL || position==0 ||position>SLL_Length(sll))
		return SLL_NULL;
	else
	{
		//��ȡָ��λ�ýڵ��ַ 
		tmpPtr = SLL_GetElemPtr(sll,position);
		//���ؽڵ�������� 
		return (SLLType)tmpPtr->data;
	}
}

//�ı�����sll��ָ��λ�õĽڵ�������� 
SLLStatusCode SLL_SetElem(struct SLL* sll,SLLCountType position,SLLType e)
{
	struct node* tmpPtr = SLL_NULL;
	//�ж������Ƿ���ں�λ���Ƿ���Ч 
	if(sll==SLL_NULL || position==0 || position>SLL_Length(sll))
		return SLL_PRM_ERROR;
	else
	{
		//��ȡָ��λ�ýڵ��ַ 	 
		tmpPtr = SLL_GetElemPtr(sll,position);
		//�ڵ����������¸��� 
		tmpPtr->data = e;
		return SLL_SUCCESS;
	}
}


//��sl����ָ��λ�� position��ǰ������µĽڵ㣬������λe 
SLLStatusCode SLL_InsertElem(struct SLL* sll,SLLCountType position,SLLType e)
{
	struct node *newPtr = SLL_NULL,*tmpPtr = SLL_NULL;
	//�ж������Ƿ���ں�λ���Ƿ���Ч 
	if(sll==SLL_NULL || position==0 || position>SLL_Length(sll))
		return SLL_PRM_ERROR;
	else
	{
		//��ȡǰһ���ڵ��ָ�� 
		tmpPtr = SLL_GetElemPtr(sll,position-1);
		//�����µĽڵ� 
		newPtr = (struct node*)malloc(sizeof(struct node));
		if(newPtr==SLL_NULL)	return SLL_MEN_ERROR;//�����ڴ�ʧ�ܷ��ش����� 
		
		//��ʼ���½ڵ� ��������Ϊe�����ָ��Ϊ������ָ��ĺ�� 
		Node_Init(newPtr,e,tmpPtr->next);
		//ǰһ���ڵ�ĺ��ָ���½ڵ� 
		tmpPtr->next = newPtr;
		return SLL_SUCCESS;
	}
}


//��sll����β�����½ڵ㣬�ڵ�������Ϊe 
SLLStatusCode SLL_AddElem(struct SLL* sll,SLLType e)
{
	struct node *newPtr = SLL_NULL,*tmpPtr = SLL_NULL;
	//���sll�Ƿ���� 
	if(sll==SLL_NULL)
		return SLL_PRM_ERROR;
	else
	{
		//��ȡ����β 
		tmpPtr = SLL_GetElemPtr(sll,SLL_Length(sll));
		//�����½ڵ� 
		newPtr = (struct node*)malloc(sizeof(struct node));
		if(newPtr==SLL_NULL)	return SLL_MEN_ERROR;//�����ڴ�ʧ�ܷ��ش����� 
		//��ʼ���½ڵ㣬������Ϊe,���ָ��Ϊ����β�ڵ���ָ�� 
		Node_Init(newPtr,e,tmpPtr->next);
		//����β�ڵ���ָ�� ָ���½ڵ� 
		tmpPtr->next = newPtr;
		return SLL_SUCCESS;
	}
}


//ɾ��ָ��λ�� position �Ľڵ㣬���ѽڵ�������򱣴���e�� 
SLLStatusCode SLL_DeleteElem(struct SLL* sll,SLLCountType position,SLLType e)
{
	struct node *tmpPtr = SLL_NULL,*nextPtr = SLL_NULL;
	//�ж������Ƿ���ں�λ���Ƿ���Ч 
	if(sll==SLL_NULL || position==0 || position>SLL_Length(sll))
		return SLL_PRM_ERROR;
	else
	{
		//��ȡǰһ�����ָ��ֵ 
		tmpPtr = SLL_GetElemPtr(sll,position-1);
		//��ȡ��ǰָ���ڵ�ָ��ֵ 
		nextPtr = tmpPtr->next;
		
		//ǰһ���ڵ���ָ���һ���ڵ� 
		tmpPtr->next = nextPtr->next;
		
		if(e != SLL_NULL)	e = nextPtr->data;//���������� 
		
		free(nextPtr);//�ͷŽڵ��ڴ� 
		
		return SLL_SUCCESS;
	}
}

//ɾ��ָ��������Ľڵ㣬���ѽڵ�������򱣴���e�� 
SLLStatusCode SLL_DeleteElemC(struct SLL* sll,SLLType data,SLLType e)
{
	struct node *tmpPtr = SLL_NULL,*nextPtr = SLL_NULL;
	SLLCountType count = 0;
	//�ж������Ƿ���ں�λ���Ƿ���Ч 
	if(sll==SLL_NULL || data==SLL_NULL)
		return SLL_PRM_ERROR;
	else
	{
		for(tmpPtr = sll->head->next;tmpPtr!=SLL_NULL;tmpPtr = tmpPtr->next)
		{
			//��ÿ���ڵ�������λ����
			if(tmpPtr->data==data) break ;
			count++;
		}
		if(count == 0)	return SLL_ERROR;
		
		//��ȡǰһ�����ָ��ֵ 
		tmpPtr = SLL_GetElemPtr(sll,count-1);
		//��ȡ��ǰָ���ڵ�ָ��ֵ 
		nextPtr = tmpPtr->next;
		
		//ǰһ���ڵ���ָ���һ���ڵ� 
		tmpPtr->next = nextPtr->next;
		
		if(e != SLL_NULL)	e = nextPtr->data;//���������� 
		
		free(nextPtr);//�ͷŽڵ��ڴ� 
		
		return SLL_SUCCESS;
	}
}


//�����ƣ��ڵ�ṹ���¹����������������� 
SLLStatusCode	SLL_Copy(struct SLL* sou,struct SLL* tar)
{
	SLLCountType count = 0;
	struct node *tmpPtr,*tmpPtr2,*newPtr;
	//���Դ�����Ŀ�������Ƿ���� 
	if(sou==SLL_NULL || tar==SLL_NULL) return SLL_PRM_ERROR;
	
	//���Ŀ������Ϊ�գ����ش��� 
	if(SLL_Empty(tar)!=SLL_SUCCESS) return SLL_ERROR;
	
	//�𲽴����µĽڵ㣬����Դ������������Ƶ�Ŀ������Ľڵ���������� 
	for(tmpPtr = sou->head->next,tmpPtr2 = tar->head;tmpPtr!=SLL_NULL;tmpPtr = tmpPtr->next,tmpPtr2 = tmpPtr2->next)
	{
		newPtr = (struct node *)malloc(sizeof(struct node));
		Node_Init(newPtr,tmpPtr->data,SLL_NULL);
		tmpPtr2->next = newPtr;
	}
	
	return SLL_SUCCESS;
}
