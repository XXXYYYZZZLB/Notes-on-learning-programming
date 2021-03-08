//栈和队列

 
//------------队列(先进先出)
//--顺序队列 (循环队列)
//定义-顺序存储 
#define MaxSize 10
typedef struct{
	ElemType data[MaxSize];
	int front,rear;
	//队头指针指向对头元素
	//队尾指针指向队尾的下一个元素 
}SqQueue;

//初始化 
void InitQueue(SqQueue &Q){
	Q.front=0;
	Q.rear=0;
} 

//判空
bool QueueEmpty(SqQueue Q){
	if(Q.rear==Q.front)
		return true;
	else
		return false;
} 

//入队
bool EnQueue(SqQueue &Q,Elempty x){
	if((Q.rear+1)%MaxSize==Q.front)//满 
		return false;
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;//重点 :循环队列 
	return true; 
} 

//队列满的条件:队尾指针的下一个位置是队头
//即：(Q.rear+1)%MaxSize==Q.front
//就需要牺牲一个储存单元 

//出队 
bool EdQueue(SqQueue &Q,ElemType &x){
	if(Q.front==Q.rear)//空 
		return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true;
} 

//获得对头元素
bool GetHead(SqQueue Q,ElemType &x){
	if(Q.rear==Q.front)
		return false;
	x=Q.data[Q.front];
	return true;
} 

//判断队列已满/已空
//方案1：
//		(浪费一个空间)以上  
//方案2：
//		(不能浪费空间)设置一个size 
//		空 size=0，rear=front
//		满 size=MaxSize，rear=front 
//方案3：
//		(不能浪费空间)设置一个tag标志，来标志最近一次操作 
//		满只能是通过插入 
//		空只能是删除 


//其他出题方法：
//队尾不是指向下一个元素
//初始化时， 让队尾指针指向最后一个 
//判空：(Q.rear+1)%MaxSize==Q.front



//--链队列 (循环队列)
//带头结点 
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next; 
}LinkNode; 
 
typedef struct{
	LinkNode *front,*rear;//队列的队头和队尾指针 
}LinkQueue;

void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode))
	Q.front->next=NULL; 
}

//入队 
void EnQueue(LinkQueue &Q,Elempty x){
	LinkNode *s=(LinkNode)malloc(sizeof(LinkNode));
	s->data=x;
	s.next=NULL;
	Q.rear->next=s;	//插入 
	Q.rear=s;		//修改表尾指针 
} 

//出队 
//画图就懂了 
void DeQueue(LinkQueue &Q,Elempty &x){
	if(Q.front==Q.rear)
		return false; 
	LinkNode *p=Q.front->next;
	x=p->data;				//返回队头元素 
	Q.front->next=p->next;	 
	if(Q.rear==p)			//如果是最后一个结点出队 
		Q.rear=Q.front;		//修改rear指针 
	free(p);
	return true;
} 

//不存在队满，除非内存满了 



	 	 






