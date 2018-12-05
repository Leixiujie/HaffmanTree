#include<stdio.h>
#include<stdlib.h>
typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanCode;
typedef char * *HuffmanCode;

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
	if (n<1) return;
	m=2*n-1;
	HT=(HuffmanTree) malloc((m+1)*sizeof(HTNode));
	for(p=HT+1,i=1;i<n;++i,++p,++w) *p={*w,0,0,0};
	for(;i<=m;++i,++p) *p={0,0,0,0};
	for(i=n+1;i<=m;++i){
		select(HT,i<=m;++i);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
}

int main(){
	
}
