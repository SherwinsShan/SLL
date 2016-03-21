#ifndef SIMPLELINKLIST
#define SIMPLELINKLIST

/*************************
@name:		SimpleLinkList
@date:		2016.3.21
@author:	akitomato
@version:	1.0(beta)
@README:	范式单向链表
**************************/


//返回码 
#define SLL_MEN_ERROR	-2/*内存错误*/
#define SLL_PRM_ERROR	-1/*参数错误*/
#define SLL_NULL		0
#define SLL_ERROR		0
#define SLL_SUCCESS		1

//定义单向链表数据域类型 

typedef void*			SLLType;
typedef unsigned int	SLLCountType;//定义单向链表原始个数数据类型 
typedef int				SLLStatusCode;//定义返回码类型 

//链表节点结构体 
struct node
{
	SLLType 	data;//数据域		
	struct node* next; //指向下一个节点的指针 
};
//链表结构体 
struct SLL
{
	 struct node* head; //指向链表头指针 	
};

void 			Node_Init(struct node* n,SLLType data,struct node* next); //初始化链表节点 
SLLStatusCode	SLL_Init(struct SLL* sll);	//初始化链表 
struct node* 	SLL_GetElemPtr(struct SLL* sll,SLLCountType position);//获取链表节点指针 
SLLCountType 	SLL_Length(struct SLL* sll); //获取链表长度 
SLLStatusCode 	SLL_Empty(struct SLL* sll);//判断链表是否为空 
SLLStatusCode	SLL_Clear(struct SLL* sll);//清理链表 
SLLStatusCode	SLL_Traverse(struct SLL* sll,void (*visit)(SLLType t));//遍历每个链表节点，一节点数据域位参数，调用指定函数 
SLLType			SLL_GetElem(struct SLL* sll,SLLCountType position);//获取指定位置的节点数据域 
SLLStatusCode	SLL_SetElem(struct SLL* sll,SLLCountType position,SLLType e);//设置指定位置的节点数据域 
SLLStatusCode	SLL_InsertElem(struct SLL* sll,SLLCountType position,SLLType e);//往指定位置的节点前面插入节点 
SLLStatusCode	SLL_AddElem(struct SLL* sll,SLLType e);//往链表尾添加节点 
SLLStatusCode	SLL_DeleteElem(struct SLL* sll,SLLCountType position,SLLType e);//删除指定位置的节点 
SLLStatusCode	SLL_Copy(struct SLL* sou,struct SLL* tar);//链表复制
SLLCountType	SLL_GetPosition(struct SLL* sll,SLLType data);//寻找指定数据域的位置
SLLStatusCode	SLL_DeleteElemC(struct SLL* sll,SLLType data,SLLType e);//直接删除指定数据域的节点
#endif

