//���Ա�-������ʽ�洢,��֧�������ȡ��

//��� 
//LNode = LNode,LinkList = *LNode
//LNode *L = LinkList L
typedef struct LNode{
	ElemType data;//������ 
	struct LNode *next;//ָ���� 
}LNode,*LinkList;

//LNode * L; 	//����һ��ָ�������һ������ָ��
//LinkList L;	//����һ��ָ�������һ������ָ��




//---��ͷ�ڵ�ĵ�����(д��������)---
bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));//����һ��ͷ�ڵ�
	if(L==NULL)
		return false;
	L->next=NULL
	return true;
}

//�������,��i��λ�ò���e,ͷ�ڵ��൱��0 
//ʱ�临�Ӷ�O(n) 
ListInsert(LinkList &L,int i,ElemType e){
	if(i<1)
		return false;
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i-1){//�ҵ���i-1����� 
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

//������:��p���֮�����Ԫ��e
//����LinkListŶ 
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

//ǰ�����,ʱ�临�Ӷ�O(1) 
//͵�컻�� 
//LNode,����LinkList 
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

//ɾ������
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


//ɾ��ָ�����,ʱ�临�Ӷ�O(1) 
//��bug������ɾ�����һ����� 
bool DeleteNode(LNode *p){
	if(p==NULL)
		return false;
	LNode *q=p->next;
	p->data=p->next->data;
	p->next=q->next;
	free(q);
	return true;
} 


//��λ����
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

//��ֵ���� 
LNode *LocateElem(LinkList L,ElemType e){
	LNode *p = L->next;
	while(p!=NULL && p->next!=e){
		p=p->next;
		return p;
	}
}

//���ĳ���
int Length(LinkList L){
	int len=0;
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	return len;
} 

//������Ľ�����β�壬ͷ��
 

 


//---����ͷ�ڵ�ĵ�����(д���벻����)---
//��ʼ��һ���յĵ�����
bool IntiList(LinkList &L){
	L=NULL;
	return true;
} 

//�������,��i��λ�ò���e,ͷ�ڵ��൱��0 
//ʱ�临�Ӷ�O(n) 
//����ͷ�ڵ����Ҫ����дһ���Ե�һ�����Ĳ��� 
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
	while(p!=NULL && j<i-1){//�ҵ���i-1����� 
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
	LinkList L;	//����һ��ָ�������һ������ָ��
	InitList(L);
	
}


 


 
