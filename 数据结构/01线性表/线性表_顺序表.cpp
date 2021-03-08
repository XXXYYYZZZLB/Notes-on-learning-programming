//##线性表-顺序表(物理位置连续)
 
//----------静态分配，长度不可变 
#define Maxsize 10
#define EleType int
typedef struct{
	EleType data[MaxSize];
	int length;
}SqList; 

//初始化一个顺序表
//&:把数据带回来 
void InitList(SqList &L){
	for(int i=0;i<MaxSize;i++){
		L.data[i]=0
	}
	L.length=0
} 

//插入，第i个位置插入
//i的范围[i,length+1] 
//时间复杂度：最好O(1)，最坏O(n)，平均O(n) 
void ListInsert(SqList &L,int i,EleType e){
	for(int j=L.length;j>=i;i--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
} 
bool ListInsert(SqList &L,int i,EleType e){
	//位置错误或者存满了 
	if(i<1 || i>L.length+1 || L.length>=MaxSize) return false;
	//符合条件 
	for(int j=L.length;j>=i;i--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
} 

//删除
//时间复杂度：O(n) 
bool ListDelete(SqList &L,int i,EleType &e){
	if(i<1 || i>L.length) return false;
	e=L.data[i-1];
	for(int j=i;j<L.length;j++){
		L.data[j-1]=L.data[j];
	} 
	L.length--;
	ruturn true;
}

//查找(随机存取)
ElemType GetElem(SqList L,int i){
	return L.data[i-1];
}

//main 
int main(){
	SqList L;				//声明L 
	
	InitList(L)				//初始化一个顺序表
	
	ListInsert(L,1,2)		//在L的1位置插入2
	ListInsert(L,2,2)
	
	int e=-1;
	if(ListDelete(L,1,e)){	//删除操作 
		printf("删除的元素为%d\n",e); 
	}else{
		printf("失败，元素位置不合法\n");
	}
	
	return 0;
}


/*===================================================*/ 

//----------动态分配，长度可变
#define InitSize 10	//初始长度 
#define EleType int
typedef struct{
	EleType *data;
	int MaxSize;
	int length;
}SeqList; 

//初始化，申请空间 
void InitList(SeqList &L){
	L.data(int *)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize;
} 

//增加动态数组的长度
void IncreaseSize(SeqList &L,int len){
	int *p=L.data;
	L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++){
		L.data[i]=p[i];
	}
	L.MaxSize=L.MaxSize+len;
	free(p); 
} 

//查找(随机存取)
ElemType GetElem(SeqList L,i){
	return L.data[i-1];
} 

//在顺序表中查找第一个元素值等于e的元素，返回位序
int LocateElem(SeqList L,ElemType e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e) return i+1;
	}
	return 0;
} 










