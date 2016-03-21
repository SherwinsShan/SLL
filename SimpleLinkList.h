#ifndef SIMPLELINKLIST
#define SIMPLELINKLIST

/*************************
@name:		SimpleLinkList
@date:		2016.3.21
@author:	akitomato
@version:	1.0(beta)
@README:	��ʽ��������
**************************/


//������ 
#define SLL_MEN_ERROR	-2/*�ڴ����*/
#define SLL_PRM_ERROR	-1/*��������*/
#define SLL_NULL		0
#define SLL_ERROR		0
#define SLL_SUCCESS		1

//���嵥���������������� 

typedef void*			SLLType;
typedef unsigned int	SLLCountType;//���嵥������ԭʼ������������ 
typedef int				SLLStatusCode;//���巵�������� 

//����ڵ�ṹ�� 
struct node
{
	SLLType 	data;//������		
	struct node* next; //ָ����һ���ڵ��ָ�� 
};
//����ṹ�� 
struct SLL
{
	 struct node* head; //ָ������ͷָ�� 	
};

void 			Node_Init(struct node* n,SLLType data,struct node* next); //��ʼ������ڵ� 
SLLStatusCode	SLL_Init(struct SLL* sll);	//��ʼ������ 
struct node* 	SLL_GetElemPtr(struct SLL* sll,SLLCountType position);//��ȡ����ڵ�ָ�� 
SLLCountType 	SLL_Length(struct SLL* sll); //��ȡ������ 
SLLStatusCode 	SLL_Empty(struct SLL* sll);//�ж������Ƿ�Ϊ�� 
SLLStatusCode	SLL_Clear(struct SLL* sll);//�������� 
SLLStatusCode	SLL_Traverse(struct SLL* sll,void (*visit)(SLLType t));//����ÿ������ڵ㣬һ�ڵ�������λ����������ָ������ 
SLLType			SLL_GetElem(struct SLL* sll,SLLCountType position);//��ȡָ��λ�õĽڵ������� 
SLLStatusCode	SLL_SetElem(struct SLL* sll,SLLCountType position,SLLType e);//����ָ��λ�õĽڵ������� 
SLLStatusCode	SLL_InsertElem(struct SLL* sll,SLLCountType position,SLLType e);//��ָ��λ�õĽڵ�ǰ�����ڵ� 
SLLStatusCode	SLL_AddElem(struct SLL* sll,SLLType e);//������β��ӽڵ� 
SLLStatusCode	SLL_DeleteElem(struct SLL* sll,SLLCountType position,SLLType e);//ɾ��ָ��λ�õĽڵ� 
SLLStatusCode	SLL_Copy(struct SLL* sou,struct SLL* tar);//������
SLLCountType	SLL_GetPosition(struct SLL* sll,SLLType data);//Ѱ��ָ���������λ��
SLLStatusCode	SLL_DeleteElemC(struct SLL* sll,SLLType data,SLLType e);//ֱ��ɾ��ָ��������Ľڵ�
#endif

