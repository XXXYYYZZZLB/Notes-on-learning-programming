//##���Ա�-˳���(����λ������)
 
//----------��̬���䣬���Ȳ��ɱ� 
#define Maxsize 10
#define EleType int
typedef struct{
	EleType data[MaxSize];
	int length;
}SqList; 

//��ʼ��һ��˳���
//&:�����ݴ����� 
void InitList(SqList &L){
	for(int i=0;i<MaxSize;i++){
		L.data[i]=0
	}
	L.length=0
} 

//���룬��i��λ�ò���
//i�ķ�Χ[i,length+1] 
//ʱ�临�Ӷȣ����O(1)���O(n)��ƽ��O(n) 
void ListInsert(SqList &L,int i,EleType e){
	for(int j=L.length;j>=i;i--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
} 
bool ListInsert(SqList &L,int i,EleType e){
	//λ�ô�����ߴ����� 
	if(i<1 || i>L.length+1 || L.length>=MaxSize) return false;
	//�������� 
	for(int j=L.length;j>=i;i--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
} 

//ɾ��
//ʱ�临�Ӷȣ�O(n) 
bool ListDelete(SqList &L,int i,EleType &e){
	if(i<1 || i>L.length) return false;
	e=L.data[i-1];
	for(int j=i;j<L.length;j++){
		L.data[j-1]=L.data[j];
	} 
	L.length--;
	ruturn true;
}

//����(�����ȡ)
ElemType GetElem(SqList L,int i){
	return L.data[i-1];
}

//main 
int main(){
	SqList L;				//����L 
	
	InitList(L)				//��ʼ��һ��˳���
	
	ListInsert(L,1,2)		//��L��1λ�ò���2
	ListInsert(L,2,2)
	
	int e=-1;
	if(ListDelete(L,1,e)){	//ɾ������ 
		printf("ɾ����Ԫ��Ϊ%d\n",e); 
	}else{
		printf("ʧ�ܣ�Ԫ��λ�ò��Ϸ�\n");
	}
	
	return 0;
}


/*===================================================*/ 

//----------��̬���䣬���ȿɱ�
#define InitSize 10	//��ʼ���� 
#define EleType int
typedef struct{
	EleType *data;
	int MaxSize;
	int length;
}SeqList; 

//��ʼ��������ռ� 
void InitList(SeqList &L){
	L.data(int *)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize;
} 

//���Ӷ�̬����ĳ���
void IncreaseSize(SeqList &L,int len){
	int *p=L.data;
	L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++){
		L.data[i]=p[i];
	}
	L.MaxSize=L.MaxSize+len;
	free(p); 
} 

//����(�����ȡ)
ElemType GetElem(SeqList L,i){
	return L.data[i-1];
} 

//��˳����в��ҵ�һ��Ԫ��ֵ����e��Ԫ�أ�����λ��
int LocateElem(SeqList L,ElemType e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e) return i+1;
	}
	return 0;
} 










