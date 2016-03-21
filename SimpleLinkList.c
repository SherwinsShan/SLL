#include "SimpleLinkList.h"
#include <stdlib.h>

//将节点n的内容初始化为{data,next} 
void Node_Init(struct node* n,SLLType data,struct node* next)
{
	n->data = data;
	n->next = next;
} 

//初始化单向链表 
SLLStatusCode SLL_Init(struct SLL* sll)
{
	sll->head = (struct node*)malloc(sizeof(struct node));//创建表头 
	//表头内容为空（可利用），表头后继指针为NULL 
	sll->head->data = SLL_NULL;
	sll->head->next = SLL_NULL;	
}


//在sll单向链表中获取指定 position位置的节点指针 
struct node* SLL_GetElemPtr(struct SLL* sll,SLLCountType position)
{
	struct node* tmpPtr = sll->head;//获得链表头 
	SLLCountType curposition = 0;
	
	//如果sll不存在，返回SLL_NULL 
	if(sll==SLL_NULL) return SLL_NULL;
	
	//前向搜索 
	while(tmpPtr!=SLL_NULL && curposition<position)
	{
		tmpPtr = tmpPtr->next;
		curposition++;	
	}
	//判断节点是否正确 
	if(tmpPtr!=SLL_NULL && curposition==position)
	{
		return tmpPtr; 
	}
	else
	{
		//不正确返回  SLL_NULL
		return SLL_NULL; 
	} 
	
} 

//返回指定数据域在链表的位置，返回0表示错误
SLLCountType SLL_GetPosition(struct SLL* sll,SLLType data)
{
	struct node* tmpPtr = SLL_NULL;
	SLLCountType count = 0;
	//检查链表和函数是否存在 
	if(sll==SLL_NULL) return 0;
	if(data==SLL_NULL) return 0;
	//遍历调用 
	for(tmpPtr = sll->head->next;tmpPtr!=SLL_NULL;tmpPtr = tmpPtr->next)
	{
		//以每个节点数据域位参数
		if(tmpPtr->data==data) break ;
		count++;
	} 
	return  count;
}

//返回单向链表sll的长度 
SLLCountType SLL_Length(struct SLL* sll)
{
	SLLCountType count = 0;
	struct node* tmpPtr =SLL_NULL;
	//如果sll不存在，返回SLL_PRM_ERROR 
	if(sll==SLL_NULL) return SLL_PRM_ERROR;
	
	//遍历计算链表长度 
	for(tmpPtr = sll->head->next;tmpPtr!=SLL_NULL;tmpPtr = tmpPtr->next)
	{
		count++;
	}
	
	return count;
}

//判断单向链表是否为空 
SLLStatusCode SLL_Empty(struct SLL* sll)
{
	//如果sll不存在，返回SLL_PRM_ERROR 
	if(sll==SLL_NULL) return SLL_PRM_ERROR;
	
	return sll->head->next==SLL_NULL;	
}

//清空链表 
SLLStatusCode SLL_Clear(struct SLL* sll)
{
	SLLType tmp;
	//如果sll不存在，返回SLL_PRM_ERROR 
	if(sll==SLL_NULL) return SLL_PRM_ERROR;
	//不断地删除第一个节点，知道链表为空 
	while(SLL_Length(sll)>0)
	{
		SLL_DeleteElem(sll,1,tmp);
	} 
	return SLL_SUCCESS;
}

//遍历每个链表节点，一节点数据域位参数，调用指定函数 visit
SLLStatusCode SLL_Traverse(struct SLL* sll,void (*visit)(SLLType t))
{
	struct node* tmpPtr = SLL_NULL;
	//检查链表和函数是否存在 
	if(sll==SLL_NULL) return SLL_PRM_ERROR;
	if(visit==SLL_NULL) return SLL_PRM_ERROR;
	//遍历调用 
	for(tmpPtr = sll->head->next;tmpPtr!=SLL_NULL;tmpPtr = tmpPtr->next)
	{
		//以每个节点数据域位参数 
		(*visit)(tmpPtr->data); 
	} 
	return  SLL_SUCCESS;
}



//返回sll单向链表中获取指定位置 position的节点的数据域 
SLLType SLL_GetElem(struct SLL* sll,SLLCountType position)
{
	struct node* tmpPtr = SLL_NULL;
	//判断链表是否存在和位置是否有效 
	if(sll==SLL_NULL || position==0 ||position>SLL_Length(sll))
		return SLL_NULL;
	else
	{
		//获取指定位置节点地址 
		tmpPtr = SLL_GetElemPtr(sll,position);
		//返回节点的数据域 
		return (SLLType)tmpPtr->data;
	}
}

//改变链表sll中指定位置的节点的数据域 
SLLStatusCode SLL_SetElem(struct SLL* sll,SLLCountType position,SLLType e)
{
	struct node* tmpPtr = SLL_NULL;
	//判断链表是否存在和位置是否有效 
	if(sll==SLL_NULL || position==0 || position>SLL_Length(sll))
		return SLL_PRM_ERROR;
	else
	{
		//获取指定位置节点地址 	 
		tmpPtr = SLL_GetElemPtr(sll,position);
		//节点数据域重新复制 
		tmpPtr->data = e;
		return SLL_SUCCESS;
	}
}


//向sl链表指定位置 position的前面插入新的节点，数据域位e 
SLLStatusCode SLL_InsertElem(struct SLL* sll,SLLCountType position,SLLType e)
{
	struct node *newPtr = SLL_NULL,*tmpPtr = SLL_NULL;
	//判断链表是否存在和位置是否有效 
	if(sll==SLL_NULL || position==0 || position>SLL_Length(sll))
		return SLL_PRM_ERROR;
	else
	{
		//获取前一个节点的指针 
		tmpPtr = SLL_GetElemPtr(sll,position-1);
		//创建新的节点 
		newPtr = (struct node*)malloc(sizeof(struct node));
		if(newPtr==SLL_NULL)	return SLL_MEN_ERROR;//分配内存失败返回错误码 
		
		//初始化新节点 ，数据域为e，后继指针为上面获得指针的后继 
		Node_Init(newPtr,e,tmpPtr->next);
		//前一个节点的后继指向新节点 
		tmpPtr->next = newPtr;
		return SLL_SUCCESS;
	}
}


//往sll链表尾增加新节点，节点数据域为e 
SLLStatusCode SLL_AddElem(struct SLL* sll,SLLType e)
{
	struct node *newPtr = SLL_NULL,*tmpPtr = SLL_NULL;
	//检查sll是否存在 
	if(sll==SLL_NULL)
		return SLL_PRM_ERROR;
	else
	{
		//获取链表尾 
		tmpPtr = SLL_GetElemPtr(sll,SLL_Length(sll));
		//创建新节点 
		newPtr = (struct node*)malloc(sizeof(struct node));
		if(newPtr==SLL_NULL)	return SLL_MEN_ERROR;//分配内存失败返回错误码 
		//初始化新节点，数据域为e,后继指针为链表尾节点后继指针 
		Node_Init(newPtr,e,tmpPtr->next);
		//链表尾节点后继指针 指向新节点 
		tmpPtr->next = newPtr;
		return SLL_SUCCESS;
	}
}


//删除指定位置 position 的节点，并把节点的数据域保存在e中 
SLLStatusCode SLL_DeleteElem(struct SLL* sll,SLLCountType position,SLLType e)
{
	struct node *tmpPtr = SLL_NULL,*nextPtr = SLL_NULL;
	//判断链表是否存在和位置是否有效 
	if(sll==SLL_NULL || position==0 || position>SLL_Length(sll))
		return SLL_PRM_ERROR;
	else
	{
		//获取前一个结点指针值 
		tmpPtr = SLL_GetElemPtr(sll,position-1);
		//获取当前指定节点指针值 
		nextPtr = tmpPtr->next;
		
		//前一个节点后继指向后一个节点 
		tmpPtr->next = nextPtr->next;
		
		if(e != SLL_NULL)	e = nextPtr->data;//保存数据域 
		
		free(nextPtr);//释放节点内存 
		
		return SLL_SUCCESS;
	}
}

//删除指定数据域的节点，并把节点的数据域保存在e中 
SLLStatusCode SLL_DeleteElemC(struct SLL* sll,SLLType data,SLLType e)
{
	struct node *tmpPtr = SLL_NULL,*nextPtr = SLL_NULL;
	SLLCountType count = 0;
	//判断链表是否存在和位置是否有效 
	if(sll==SLL_NULL || data==SLL_NULL)
		return SLL_PRM_ERROR;
	else
	{
		for(tmpPtr = sll->head->next;tmpPtr!=SLL_NULL;tmpPtr = tmpPtr->next)
		{
			//以每个节点数据域位参数
			if(tmpPtr->data==data) break ;
			count++;
		}
		if(count == 0)	return SLL_ERROR;
		
		//获取前一个结点指针值 
		tmpPtr = SLL_GetElemPtr(sll,count-1);
		//获取当前指定节点指针值 
		nextPtr = tmpPtr->next;
		
		//前一个节点后继指向后一个节点 
		tmpPtr->next = nextPtr->next;
		
		if(e != SLL_NULL)	e = nextPtr->data;//保存数据域 
		
		free(nextPtr);//释放节点内存 
		
		return SLL_SUCCESS;
	}
}


//链表复制，节点结构重新构建，但是数据域共用 
SLLStatusCode	SLL_Copy(struct SLL* sou,struct SLL* tar)
{
	SLLCountType count = 0;
	struct node *tmpPtr,*tmpPtr2,*newPtr;
	//检查源链表和目标链表是否存在 
	if(sou==SLL_NULL || tar==SLL_NULL) return SLL_PRM_ERROR;
	
	//如果目标链表不为空，返回错误 
	if(SLL_Empty(tar)!=SLL_SUCCESS) return SLL_ERROR;
	
	//逐步创建新的节点，并把源链表各数据域复制到目标链表的节点的数据域中 
	for(tmpPtr = sou->head->next,tmpPtr2 = tar->head;tmpPtr!=SLL_NULL;tmpPtr = tmpPtr->next,tmpPtr2 = tmpPtr2->next)
	{
		newPtr = (struct node *)malloc(sizeof(struct node));
		Node_Init(newPtr,tmpPtr->data,SLL_NULL);
		tmpPtr2->next = newPtr;
	}
	
	return SLL_SUCCESS;
}
