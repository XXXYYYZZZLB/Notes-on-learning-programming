//2.2.3-综合应用题 

//	1
bool ListDeleteMin(SqList &L,int &e){
	if(L.length==0) return false;
	e=L.data[0];
	int index=0;
	for(int i=0;i<L.length;i++){
		if(e>L.data[i]){
			index=i;
		}
	}
	L.data[i]=L.data[L.length-1];
	L.length--;
	return true;
}

//	2
//循环n/2，时间复杂度是O(1) 
void ReverseList(SqList &L){
	for(int i=0;i<L.length;i++){
		int temp=L.data[L.length-i-1];
		L.data[L.length-i-1]=L.data[i];
		L.data[i]=temp;
	}
}

//	3
void DeleteListElem(SqList &L,int e){
	int j=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]!=e){
			L.data[j]=L.data[i];
			j++
		}
	}
	L.length=j;
} 

//	4
bool DeleteListAtoB(SqList &L,int a,int b){
	if(a>=b||L.length==0) return false;
	int index=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]>=b||L.data[i]<=a){
			L.data[index]=L.data[i];
			index++;
		}
	}
	L.length=index;
	return true;
}

//	5
bool DeleteListAtoB(SqList &L,int a,int b){
	if(a>=b||L.length==0) return false;
	int index=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]>b||L.data[i]<a){
			L.data[index]=L.data[i];
			index++;
		}
	}
	L.length=index;
	return true;
}

//	6(有序顺序表)
void ListDuplicateRemoval(SqList &L){
	int index=0;
	for(int i=1;i<L.length;i++){
		if(L.data[index]!=L.data[i]){
			L.data[index]=L.data[i];
			index++;
		}
	}
	L.length=index;
}

//	7
bool ListSum(SqList A,SqList B,SqList &C){
	if(A.length+B.length>C.MaxSize) return false;
	int i,j,k=0;
	while(i<A.length&&j<B.length){
		if(A.data[i]<=B.data[j]){
			C.data[k++]=A.data[i++];
		}else{
			C.data[k++]=B.data[j++];
		}
	}
	//如果还有没比完的就都添加
	while(i<A.length){
		C.data[k++]=A.data[i++];
	} 
	while(j<B.length){
		C.data[k++]=B.data[j++];
	}
	C.length=k;
	return true;
}

//	8

//	9
//	10 
//	11
//	12
//	13
//	14  
