//ջ�Ͷ���


//------------ջ(�Ƚ����)
//--˳��ջ 
//����-˳��洢 
#define MaxSize 10
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

//��ʼ��
void InitStack(SqStack &S){
	S.top=-1;	//��ʼ��ջ��ָ�� 
				//���ַ�ʽ�ǣ�ջ��ָ��ָ��ջ��Ԫ��
				//����һ�ַ�ʽ��ָ�򣨽�Ҫ��Ϊ�ģ�ջ��Ԫ�� 
} 

//�п�
bool StackEmpty(SqStack S){
	if(S.top==-1) 
		return true;
	else
		return false;
}

//��ջ
bool Push(SqStack &S,Elempty x){
	if(S.top==MaxSize-1)
		return false;
	S.top++;
	S.data[S.top]=x;
	return true;
} 

//��ջ����
bool Pop(SqStack &S,Elempty &x){
	if(S.top==-1)
		return false;
	x=S.data[S.top];
	S.top--;
	return true;
} 

//��ջ��Ԫ��
 bool GetTop(SqStack S,ElemType &x){
 	if(S.top==-1)
 		return false;
 	x=S.data[S.top];
 	return true;
} 

//--����ջ

#define MaxSize 10
typedef struct{
	ElemType data[MaxSize];
	int top0;
	int top1; 
}ShStack;

//��ʼ��
//����������ջ ����:"||||oooo-> oo <-oo|||||"  
//ջ��������: "top0+1=top1" 
void InitStack(ShStack &S){
	S.top0=-1;
	S.top1=MaxSize;	
}

//--��ջ
//	ͷ�巨���������� = ��ջ
// 	��ͷ�ڵ�ĺ�ɾ = ��ջ
typedef struct Linknode{
	ElemType data;
	struct Linknode *next;
} *LiStack;



 
 






