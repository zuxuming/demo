#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "corecrt_malloc.h"
#define STACK_INIT_SIZE 1
#define STACKINCREAMENT 10 
//���� ջ
typedef struct SqStack
{
	int *base;  //ջβ
	int *top;	//ջ��
	int StackSize; //ջ�Ĵ�С
};

//��ʼ��ջ
void InitStack(struct SqStack *S)
{
	S->base= (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S->base) exit(0);
	S->top = S->base;
	S->StackSize = STACK_INIT_SIZE;
	//printf("%d\r\n", S->top);
}

//����Ԫ��eΪ�µ�ջ��Ԫ��
void PushStack(struct SqStack *S,int e)
{
	if (S->top - S->base >= S->StackSize)
	{
		S->base = (int *)realloc(S->base ,( S->StackSize + STACKINCREAMENT) * sizeof(int));
	
		if (!S->base) exit(0);
		S->top = S->base + S->StackSize;
		S->StackSize = S->StackSize + STACKINCREAMENT;
	}
	*S->top = e;
	(S->top)++;//ָ�����
}

//ȡһ��Ԫ��
int PopStack(struct SqStack *S, int *e)
{
	if (S->top != S->base) //ջ�ǿ�
	{
		(S->top)--; //ָ��ǰ��
		*e = S->top;
		//printf("PopStack:%d \r\n", *e);
		return 1;
	}
	else 
	{
		return 0;
	}
}


void main()
{
	int c = 0;
	int state = 1;
	int *op = NULL;
	struct SqStack Sq;

	InitStack(&Sq);
	//printf("ջ���ԣ�����һ�����֣�����#����β���������\r\n");
	/*do //(getchar(c) != '#')
	{
		//printf("next");
		scanf_s("%d",&c);
//		c = getchar();

		PushStack(&Sq,c);
		//printf("%d",c);
	} while (c != 101);
	*/
	printf("ջ ����\r\n");
	for (int i = 0; i < 500; i++)
	{
		PushStack(&Sq, i);
		printf("%d ", i);
	}


	printf("ջ ���\r\n");

	while (state)
	{
		state = PopStack(&Sq, &op);
		if(state)
		printf("%d ",*op);
	};
	getchar();
	getchar();
	getchar();
}


/*
int gc(int *a)
{
	int *b = 100;
	*a = b;
	printf("&b %d\r\n", &b);
	printf("a %d\r\n", a);
	printf("&a %d\r\n", &a);
}

void main()
{
	int *d = 2;
	printf("&d %d\r\n", d);
	gc(&d);
	printf("d %d\r\n",d);
	getchar();
	getchar();
	getchar();
}*/
