#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
   typedef struct{
       unsigned int weight;
       unsigned int parent;
       unsigned int lChild;
       unsigned int rChild;
  } Node, *HuffmanTree;
  
  typedef char *HuffmanCode;
 
  void select(HuffmanTree *huffmanTree, int n, int *s1, int *s2){
      int i = 0;
      int min;
    for(i = 1; i <= n; i++){
          if((*huffmanTree)[i].parent == 0){
              min = i;
              break;
          }
      }
      for(i = 1; i <= n; i++){
          if((*huffmanTree)[i].parent == 0){
              if((*huffmanTree)[i].weight < (*huffmanTree)[min].weight){
                 min = i;
              }
          }
      }
      *s1 = min;
      for(i = 1; i <= n; i++){
        if((*huffmanTree)[i].parent ==0  && i != (*s1)){
            min = i;
              break;
         }
      }
      for(i = 1; i <= n; i++){
          if((*huffmanTree)[i].parent == 0 && i != (*s1)){
              if((*huffmanTree)[i].weight < (*huffmanTree)[min].weight){
                 min = i;
              }
          }
      }
      *s2 = min;
  }
 
 void createHuffmanTree(HuffmanTree *huffmanTree, int w[], int n){
      int m = 2 * n - 1;
      int s1;
      int s2;
      int i;
      *huffmanTree = (HuffmanTree)malloc((m + 1) * sizeof(Node));
      for(i = 1; i <= n; i++){
          (*huffmanTree)[i] = {w[i],0,0,0};
      }
      
      for(i = n + 1; i <= m; i++){
         (*huffmanTree)[i] ={0,0,0,0};
   }

     
     
    
     for(i = n+1; i <= m; i++){
         select(huffmanTree, i-1, &s1, &s2);
         (*huffmanTree)[s1].parent = i;
         (*huffmanTree)[s2].parent = i;
         (*huffmanTree)[i].lChild = s1;
         (*huffmanTree)[i].rChild = s2;
         (*huffmanTree)[i].weight = (*huffmanTree)[s1].weight + (*huffmanTree)[s2].weight;
         
         
     }
    printf("\n HuffmanTree: \n");
    printf("weight\t\tparent\t\tlChild\t\trChild\n");
    for(i=1;i<=m;i++){
    	printf("%d\t\t%d\t\t%d\t\t%d\n", (*huffmanTree)[i].weight,(*huffmanTree)[i].parent,(*huffmanTree)[i].lChild,(*huffmanTree)[i].rChild);
	}
     printf("\n");
 }
 
 void creatHuffmanCode(HuffmanTree *huffmanTree, HuffmanCode *huffmanCode, int n){
   int i;
   int start;
     int p;
     unsigned int c;
     huffmanCode=(HuffmanCode *)malloc((n+1) * sizeof(char *));
     char *cd = (char *)malloc(n * sizeof(char));
     cd[n-1] = '\0';
     for(i = 1; i <= n; i++){
         start = n - 1;
         for(c = i, p = (*huffmanTree)[i].parent; p != 0; c = p, p = (*huffmanTree)[p].parent){
             if( (*huffmanTree)[p].lChild == c){
                cd[--start] = '0';  
             }
             else{
                cd[--start] = '1';  
             }
         }
         huffmanCode[i] = (char *)malloc((n - start) * sizeof(char));
         
         strcpy(huffmanCode[i], &cd[start]);
     }
     
     free(cd);
     for(i = 1; i <= n; i++){
          printf("HuffmanCode of %c's Huffmancode is %s\n", (i+96), huffmanCode[i]);
     }
     FILE *f1,*f2;
	f1=NULL;
	f2=NULL; 
	f1=fopen("test.txt","r");
	if(f1==NULL){
		printf("打开失败");
	}
	f2=fopen("zip.txt","w+");
	int j,t;
	char *buffer;
	while(fgets(cd,n,f1)!=NULL){
		for(i=0;cd[i]!='\0';i++){
			t=cd[i]-97+1;
			buffer=huffmanCode[t];
  		  	fputs(buffer,f2);
		}	
	}
	fclose(f2);
 }
 
 void getW(int a[26]){
 	int i;
	int t;
	for(i=0;i<26;i++){
		a[i]=0;
	}
	FILE *f1,*f2;
	f1=NULL; 
	f1=fopen("test.txt","r");
	if(f1==NULL){
		printf("打开失败");
	}
	
	char cd[1024];
	while(fgets(cd,1024,f1)!=NULL){
		for(i=0;cd[i]!='\0';i++){
			t=cd[i]-97;
			a[t]=a[t]+1;
		}	
	}
	fclose(f1);

 }
  
 int main(void){
     HuffmanTree HT;
     HuffmanCode HC;
     int *w,i,n,wei,m;
	 n=26;
     w=(int *)malloc((n+1)*sizeof(int));
     getW(w);
     createHuffmanTree(&HT, w, n);
     creatHuffmanCode(&HT,&HC,n); 
     printf("\n\n\n\n\ndone");
     return 0;
 }
