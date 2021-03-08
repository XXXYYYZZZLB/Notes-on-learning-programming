//线性表-链表（链式存储,不支持随机存取）

//结点 
//LNode = LNode,LinkList = *LNode
//LNode *L = LinkList L
typedef struct LNode{
	ElemType data;//数据域 
	struct LNode *next;//指针域 
}LNode,*LinkList;

//LNode * L; 	//声明一个指向单链表第一个结点的指针
//LinkList L;	//声明一个指向单链表第一个结点的指针




//---带头节点的单链表(写代码容易)---
bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));//分配一个头节点
	if(L==NULL)
		return false;
	L->next=NULL
	return true;
}

//插入操作,再i的位置插入e,头节点相当于0 
//时间复杂度O(n) 
ListInsert(LinkList &L,int i,ElemType e){
	if(i<1)
		return false;
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i-1){//找到第i-1个结点 
		p=p->next;
		j++; 
	}
	if(p==NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p.next;
	p->next=s;
	return true;
} 

//后插操作:在p结点之后插入元素e
//不是LinkList哦 
bool InsertNextNode(LNode *p,ElemType e){
	if(p==NULL)
		return false;
	LNode *s=(LNode *)mallco(sizeof(LNode));
	if(s==NULL)
		return false;
	s->data=e;
	s->next=p->next
	p->next=s;
	return true;
} 

//前插操作,时间复杂度O(1) 
//偷天换日 
//LNode,不是LinkList 
bool InsertPriorNode(LNode *p,ElemType e){
	if(p==NULL)
		return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL)
		return false;
	s->next=p->next;
	p->next=s;
	s->data=p->data;
	p->next=e;
	return true;	
} 

//删除操作
bool ListDelete(LinkList &L,int i,ElemType &e){
	if(i<1)
		return false;
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	LNode *q=p->next;
	e=q->data;
	e=q.next;
	p.next=q.next;
	free(q);
	return true;
} 


//删除指定结点,时间复杂度O(1) 
//有bug，不能删除最后一个结点 
bool DeleteNode(LNode *p){
	if(p==NULL)
		return false;
	LNode *q=p->next;
	p->data=p->next->data;
	p->next=q->next;
	free(q);
	return true;
} 


//按位查找
LNode* GetElem(LinkList L,int i){
	if(i<0)
		return false;
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i){
		p=p->next;
		j++;
	} 
	return p;
} 

//按值查找 
LNode *LocateElem(LinkList L,ElemType e){
	LNode *p = L->next;
	while(p!=NULL && p->next!=e){
		p=p->next;
		return p;
	}
}

//求表的长度
int Length(LinkList L){
	int len=0;
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	return len;
} 

//单链表的建立：尾插，头插
 

 


//---不带头节点的单链表(写代码不容易)---
//初始化一个空的单链表
bool IntiList(LinkList &L){
	L=NULL;
	return true;
} 

//插入操作,再i的位置插入e,头节点相当于0 
//时间复杂度O(n) 
//不带头节点的需要单独写一个对第一个结点的操作 
ListInsert(LinkList &L,int i,ElemType e){
	if(i<1)
		return false;
	if(i==1){
		LNode *s=(LNode *)malloc(sizeof(LNode));
		s->data=e;
		s->next=L;
		L=s;
		reuturn true;
	} 
	LNode *p;
	int j=1;
	p=L;
	while(p!=NULL && j<i-1){//找到第i-1个结点 
		p=p->next;
		j++; 
	}
	if(p==NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p.next;
	p->next=s;
	return true;
} 


void test(){
	LinkList L;	//声明一个指向单链表第一个结点的指针
	InitList(L);
	
}


 


 
