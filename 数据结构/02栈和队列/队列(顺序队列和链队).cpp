//ջ�Ͷ���

 
//------------����(�Ƚ��ȳ�)
//--˳����� (ѭ������)
//����-˳��洢 
#define MaxSize 10
typedef struct{
	ElemType data[MaxSize];
	int front,rear;
	//��ͷָ��ָ���ͷԪ��
	//��βָ��ָ���β����һ��Ԫ�� 
}SqQueue;

//��ʼ�� 
void InitQueue(SqQueue &Q){
	Q.front=0;
	Q.rear=0;
} 

//�п�
bool QueueEmpty(SqQueue Q){
	if(Q.rear==Q.front)
		return true;
	else
		return false;
} 

//���
bool EnQueue(SqQueue &Q,Elempty x){
	if((Q.rear+1)%MaxSize==Q.front)//�� 
		return false;
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;//�ص� :ѭ������ 
	return true; 
} 

//������������:��βָ�����һ��λ���Ƕ�ͷ
//����(Q.rear+1)%MaxSize==Q.front
//����Ҫ����һ�����浥Ԫ 

//���� 
bool EdQueue(SqQueue &Q,ElemType &x){
	if(Q.front==Q.rear)//�� 
		return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true;
} 

//��ö�ͷԪ��
bool GetHead(SqQueue Q,ElemType &x){
	if(Q.rear==Q.front)
		return false;
	x=Q.data[Q.front];
	return true;
} 

//�ж϶�������/�ѿ�
//����1��
//		(�˷�һ���ռ�)����  
//����2��
//		(�����˷ѿռ�)����һ��size 
//		�� size=0��rear=front
//		�� size=MaxSize��rear=front 
//����3��
//		(�����˷ѿռ�)����һ��tag��־������־���һ�β��� 
//		��ֻ����ͨ������ 
//		��ֻ����ɾ�� 


//�������ⷽ����
//��β����ָ����һ��Ԫ��
//��ʼ��ʱ�� �ö�βָ��ָ�����һ�� 
//�пգ�(Q.rear+1)%MaxSize==Q.front



//--������ (ѭ������)
//��ͷ��� 
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next; 
}LinkNode; 
 
typedef struct{
	LinkNode *front,*rear;//���еĶ�ͷ�Ͷ�βָ�� 
}LinkQueue;

void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode))
	Q.front->next=NULL; 
}

//��� 
void EnQueue(LinkQueue &Q,Elempty x){
	LinkNode *s=(LinkNode)malloc(sizeof(LinkNode));
	s->data=x;
	s.next=NULL;
	Q.rear->next=s;	//���� 
	Q.rear=s;		//�޸ı�βָ�� 
} 

//���� 
//��ͼ�Ͷ��� 
void DeQueue(LinkQueue &Q,Elempty &x){
	if(Q.front==Q.rear)
		return false; 
	LinkNode *p=Q.front->next;
	x=p->data;				//���ض�ͷԪ�� 
	Q.front->next=p->next;	 
	if(Q.rear==p)			//��������һ�������� 
		Q.rear=Q.front;		//�޸�rearָ�� 
	free(p);
	return true;
} 

//�����ڶ����������ڴ����� 



	 	 






