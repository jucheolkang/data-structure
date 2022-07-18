#include<stdio.h>// 단순 연결리스트에서 노드  삭제하고 탐색하기
#include<stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(suppress : 4996)
//단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* Link;
}ListNode;

//리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	ListNode* head;
}LinkedList_h;

// 공백 연결 리스트를 생성하는 연산
LinkedList_h* createLinkedList_h(void) {
	LinkedList_h* L;
	L = (LinkedList_h*)malloc(sizeof(LinkedList_h));
	L->head = NULL; //공백 리스트이므로 null로 설정
	return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(LinkedList_h* L) {
	ListNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->Link;
		free(p);
		p = NULL;
	}
}

//연결 리스트를 순서대로 출력하는 연산
void printList(LinkedList_h* L) {
	ListNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->Link;
		if (p != NULL) { printf(", "); }
	}
	printf(") \n");
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(LinkedList_h* L, char* x) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode)); // 삽입할 새 노드 할당
	strcpy(newNode->data, x); // 새 노드의 데이터 필드에 x 저장
	newNode->Link = L->head;
	L->head = newNode;
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(LinkedList_h* L, ListNode* pre, char* x) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, x);
	if (L == NULL) { // 공백 리스트인 경우
		newNode->Link = NULL;// 새 노드를 첫 번째이자 마지막 노드로 연결
		L->head = newNode;
	}
	else if (pre == NULL) { // 삽입 위치를 지정하는 포인터 pre가 NULL인 경우
		L->head = newNode;// 새 노드를 첫 번째 노드로 삽입
	}
	else {
		newNode->Link = pre->Link;// 포인터 pre의 노드 뒤에 새 노드 연결
		pre->Link = newNode;
	}
}

//마지막 노드로 삽입하는 연산
void insertLastNode(LinkedList_h* L, char* x) {
	ListNode* newNode;
	ListNode* temp;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, x);
	newNode->Link = NULL;
	if (L->head == NULL) {// 현재 리스트가 공백인 경우
		L->head = newNode;//새 노드를 리스트의 시작 노드로 연결
		return;
	}
	// 현재 리스트가 공백이 아닌 경우
	temp = L->head;
	while (temp->Link != NULL) { temp = temp->Link; }// 현재 리스트의 마지막 노드를 찾음
	temp->Link = newNode; // 새 노드를 마지막 노드(temp)의 다음 노드로 연결
}

//리스트 노드 p를 삭제하는 연산
void deleteNode(LinkedList_h* L, ListNode* p) {
	ListNode* pre;// 삭제할 노드의 선행자 노드를 나타낼 포인터
	if (L->head == NULL) return;// 공백 리스트라면 삭제 연산 중단
	if (L->head->Link == NULL) {// 리스트에 노드가 한 개만 있는 경우
		free(L->head);// 첫번째 노드를 메모리에서 해제하고
		L->head = NULL;//리스트 시작 포인터를 null로 설정
		return;
	}
	else if (p == NULL) return; // 삭제할 노드가 없다면 삭제 연산 중단
	else {
		pre = L->head;
		while (pre->Link != p) {
			pre = pre->Link;
		}
		pre->Link = p->Link;// 삭제할 노드 p의 선행자 노드와 다음 노드를 연결
		free(p);//삭제 노드의 메모리 해제
	}
}

//리스트에서 x노드를 탐색하는 연산
ListNode* searchNode(LinkedList_h * L, char* x ){
	ListNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->Link;
	}
	return temp;
}

// 리스트의 노드 순서를 역순으로 바꾸는 연산
void reverse(LinkedList_h* L) {
	ListNode* p;
	ListNode* q;
	ListNode* r;

	p = L->head;// 포인터 p를 첫 번째 노드에 설정
	q = NULL;
	r = NULL;

	// 리스트의 첫 번째 노드부터 링크를 따라 다음 노드로 이동하면서 노드 간의 연결을 바꿈

	while (p != NULL) {
		r = q;
		q = p;
		p = p->Link;
		q->Link = r;
	}
	L->head = q;
}

int main() {
	LinkedList_h* L;
	ListNode* p;
	L = createLinkedList_h(); // 공백 리스트 생성
	printf("(1) 리스트에 [월], [수], [일] 노드 삽입하기! \n");
	insertLastNode(L, "월"); insertLastNode(L, "수"); insertLastNode(L, "일");
	printList(L); getchar();

	printf("(2) 리스트에서 [수] 노드 탐색하기 \n");
	p = searchNode(L, "수");
	if (p == NULL) printf("찾는 데이터가 없습니다.\n");
	else printf("[%s]를 찾았습니다. \n", p->data);
	getchar();

	printf("(3) 리스트에서 [수] 뒤에 [금] 노드 삽입하기! \n");
	insertMiddleNode(L, p, "금");
	printList(L); getchar();

	printf("(4) 리스트에서 [일] 노드 삭제하기\n");
	p = searchNode(L, "일"); // 삭제할 노드 위치 p를 찾음
	deleteNode(L, p); //포인터 p노드 삭제
	printList(L); getchar();
	printf("(5) 리스트 순서를 역순으로 바꾸기! \n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L); //리스트 메모리 해제
	getchar();

	return 0;
}