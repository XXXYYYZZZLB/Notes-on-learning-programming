//栈和队列


//------------栈(先进后出)
//--顺序栈 
//定义-顺序存储 
#define MaxSize 10
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

//初始化
void InitStack(SqStack &S){
	S.top=-1;	//初始化栈顶指针 
				//此种方式是，栈顶指针指向栈顶元素
				//还有一种方式是指向（将要成为的）栈顶元素 
} 

//判空
bool StackEmpty(SqStack S){
	if(S.top==-1) 
		return true;
	else
		return false;
}

//进栈
bool Push(SqStack &S,Elempty x){
	if(S.top==MaxSize-1)
		return false;
	S.top++;
	S.data[S.top]=x;
	return true;
} 

//出栈操作
bool Pop(SqStack &S,Elempty &x){
	if(S.top==-1)
		return false;
	x=S.data[S.top];
	S.top--;
	return true;
} 

//读栈顶元素
 bool GetTop(SqStack S,ElemType &x){
 	if(S.top==-1)
 		return false;
 	x=S.data[S.top];
 	return true;
} 

//--共享栈

#define MaxSize 10
typedef struct{
	ElemType data[MaxSize];
	int top0;
	int top1; 
}ShStack;

//初始化
//两端面对面的栈 这样:"||||oooo-> oo <-oo|||||"  
//栈满的条件: "top0+1=top1" 
void InitStack(ShStack &S){
	S.top0=-1;
	S.top1=MaxSize;	
}

//--链栈
//	头插法建立单链表 = 进栈
// 	对头节点的后删 = 出栈
typedef struct Linknode{
	ElemType data;
	struct Linknode *next;
} *LiStack;



 
 






