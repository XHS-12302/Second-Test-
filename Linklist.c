#include<stdio.h>
#include<stdlib.h>
//定义LNode结构体
typedef struct LNode{
  int data;
  struct LNode * next;
}LNode,*LinkList;
//初始化单链表
void InitLink(LinkList L){
	L->next=NULL;
}
//插入数据
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
//删除数据
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
//打印单链表
void PrintLink(LinkList L){
    LinkList p;
	p=L->next;
	while(p){
	printf("%d   ",p->data);
	p=p->next;
	}
	printf("\n");
}
//主函数
int main(){
   LNode M;
   int x,w,e;
   InitLink(&M);
   for(x=1;x<=12;x++){
      InsertLink(&M,x,x);
   }
   PrintLink(&M);
   
     printf("请输入要删除数据的位置\n");
	 scanf("%d",&e);
	 while(e!=0){
	 DeleteLink(&M,e);
	 PrintLink(&M);
       printf("请输入要删除数据的位置\n");
	 scanf("%d",&e);
	 }
return 0;
}