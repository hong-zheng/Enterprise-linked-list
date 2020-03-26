#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
// ʵ����ҵ������

// ����һ��С���
typedef struct LINKNODE{
	struct LINKNODE* next;
}LinkNode;
// ��������
typedef struct LINKLIST{
	LinkNode head;
	int size;
}LinkList;
// ����һ������
typedef struct Person{
	LinkNode node;
	char name[1024];
	int age;
}Person;
// ��ʼ������
LinkList* Init(){
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}
// ����β���ӽ��
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
// ͷ��
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
// ָ��λ��ɾ��
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
	// ��ӡ��ʱ����ʵ�壬ΪPerson����
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
	//�����ʱ����LinkNode����,p1Ϊʵ��
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