#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
// 实现企业级链表

// 定义一个小结点
typedef struct LINKNODE{
	struct LINKNODE* next;
}LinkNode;
// 定义链表
typedef struct LINKLIST{
	LinkNode head;
	int size;
}LinkList;
// 定义一个数据
typedef struct Person{
	LinkNode node;
	char name[1024];
	int age;
}Person;
// 初始化链表
LinkList* Init(){
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}
// 在链尾增加结点
void back_insert(LinkList* list , LinkNode* node){
	if (NULL == list){
		return;
	}
	if (NULL == node){
		return;
	}
	LinkNode*  pCurrent = &(list->head);
	for (int i = 0; i < list->size;i++){
		pCurrent = pCurrent->next;
	}
	pCurrent->next = node;
	list->size++;
}
// 头插
void front_insert(LinkList* list,LinkNode* node){
	if (NULL == list){
		return;
	}
	if (NULL == node){
		return;
	}
	LinkNode* pCurrent = &(list->head);
	node->next = pCurrent->next;
	pCurrent->next = node;
	list->size++;
}
// 指定位置删除
void Del(LinkList* list,int pos){
	if (NULL == list){
		return;
	}
	if (pos < 0 || pos >= list->size){
		pos = list->size - 1;
	}
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos-1;i++){
		pCurrent = pCurrent->next;
	}
	pCurrent->next = pCurrent->next->next;
	list->size-- ;
}
typedef void(*PRINT)(LinkNode*);
void Display(LinkList* list, PRINT print){
	if (NULL == list){
		return;
	}
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < list->size;i++){
		pCurrent = pCurrent->next;
		print(pCurrent);
	}
}
void MyPrint(LinkNode* node){
	if (NULL == node){
		return;
	}
	// 打印的时候用实体，为Person类型
	Person* data = (Person*)node;
	printf("name:%s age:%d\n",data->name,data->age);
}

int main(){

	LinkList* list = Init();
	Person p1, p2, p3, p4;
	strcpy(p1.name, "afdsg");
	strcpy(p2.name, "wsgr");
	strcpy(p3.name, "thwsd");
	strcpy(p4.name, "liwh");
	p1.age = 12;
	p2.age = 13;
	p3.age = 23;
	p4.age = 34;
	//插入的时候用LinkNode类型,p1为实体
	back_insert(list, (LinkNode*)&p1);
	back_insert(list, (LinkNode*)&p2);
	back_insert(list, (LinkNode*)&p3);
	//back_insert();
	front_insert(list, (LinkNode*)&p4);
	Display(list,MyPrint);
	printf("++++++++++++++++++++++\n");
	Del(list,1);
	Display(list, MyPrint);
	printf("++++++++++++++++++++++\n");
	Del(list, 2);
	Display(list, MyPrint);

	system("pause");
	return 0;
}