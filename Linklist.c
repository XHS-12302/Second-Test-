#include<stdio.h>
#include<stdlib.h>
//����LNode�ṹ��
typedef struct LNode{
  int data;
  struct LNode * next;
}LNode,*LinkList;
//��ʼ��������
void InitLink(LinkList L){
	L->next=NULL;
}
//��������
void InsertLink(LinkList L,int i,int e){
   LinkList p,s;
   int j=0;
   p=L;
   while(p&&j<i-1){
   p=p->next;
   j++;
   }
   if(!p||i<j+1)
	   exit(0);
   s=malloc(sizeof(LNode));
   s->next=p->next;
   p->next=s;
   s->data=e;
   
}
//ɾ������
void DeleteLink(LinkList L,int i){
   LinkList p,s;
   int j;
   p=L;j=0;
   while(p->next &&j<i-1){
     p=p->next;
	 j++;
   }
   if(!(p->next)||i<j+1)
	   exit(0);
   s=p->next;
   p->next=s->next;
   free(s);
   
}
//��ӡ������
void PrintLink(LinkList L){
    LinkList p;
	p=L->next;
	while(p){
	printf("%d   ",p->data);
	p=p->next;
	}
	printf("\n");
}
//������
int main(){
   LNode M;
   int x,w,e;
   InitLink(&M);
   for(x=1;x<=12;x++){
      InsertLink(&M,x,x);
   }
   PrintLink(&M);
   
     printf("������Ҫɾ�����ݵ�λ��\n");
	 scanf("%d",&e);
	 while(e!=0){
	 DeleteLink(&M,e);
	 PrintLink(&M);
       printf("������Ҫɾ�����ݵ�λ��\n");
	 scanf("%d",&e);
	 }
return 0;
}