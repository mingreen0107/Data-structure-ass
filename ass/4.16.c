#define DataType Movie
#include <stdio.h>
#include <stdlib.h>

// 영화 정보를 저장하는 구조체 Movie 정의
typedef struct Movie {
	char title[50];
	int release;
	int viewers;
} Movie;

typedef struct Node {
	DataType data;
	struct Node* link;
} Node;

typedef struct LinkedB0_C {
	int length;
	Node* tail;
} LinkedB0_C;

Node* create_node(DataType data) {
	Node* new = (Node*)malloc(sizeof(Node));
	if (!new) {
		printf("노드 생성 실패");
		exit(1);
	}
	new->data = data;
	new->link = NULL;
	return new;
}

void init_list(LinkedB0_C* B0) { // 초기화겟쇼
	B0->length = 0;
	B0->tail = NULL;
}

void print_list(LinkedB0_C* B0) {
	Node* ptr = B0->tail; // Movie의 정보를 넘겨줌
	int j = 1;
	for (int i = 1; i <= B0->length; i++) {
		ptr = ptr->link; // 얘도 초기화겠져
		printf("%d) 제목=%s, 개봉연도=%d, 관객수=%d\n",
			j, ptr->data.title, ptr->data.release, ptr->data.viewers);
		j++;
	}
}

void insert_node_last(LinkedB0_C* B0, Node* new) {
	B0->length++; 
	if (B0->tail == NULL) { // 빈 연결리스트
		B0->tail = new;
		new->link = new;
	}
	else { // 마지막 삽입
		new->link = B0->tail->link;
		B0->tail->link = new; 
		B0->tail = new;
	}
}

LinkedB0_C merge_B0(LinkedB0_C* a, LinkedB0_C* b) {
	LinkedB0_C c;
	Node* p2a = a->tail, * p2b = b->tail;
	int num_a = a->length, num_b = b->length;

	init_list(&c);
	if (p2a) p2a = p2a->link; // 뭔데 지우면 중구난방이 되지?
	if (p2b) p2b = p2b->link; 

	while (num_a != 0 && num_b != 0) {
		if (p2a->data.viewers >= p2b->data.viewers) {
			insert_node_last(&c, create_node(p2a->data));
			p2a = p2a->link;
			num_a--;
		}
		else {
			insert_node_last(&c, create_node(p2b->data));
			p2b = p2b->link;
			num_b--;
		}
	}
	while (num_a != 0) {
		insert_node_last(&c, create_node(p2a->data));
		p2a = p2a->link;
		num_a--;
	}
	while (num_b != 0) {
		insert_node_last(&c, create_node(p2b->data));
		p2b = p2b->link;
		num_b--;
	}
	return c;
}

int main() {
	LinkedB0_C domestic, foreign;
	Movie m1 = { "명량", 2014, 1761 };
	Movie m2 = { "베테랑", 2015, 1341 };
	Movie m3 = { "도둑들", 2012, 1298 };
	Movie m4 = { "암살", 2015, 1270 };
	Movie m5 = { "아바타", 2009, 1333 };
	Movie m6 = { "인터스텔라", 2014, 1030 };
	Movie m7 = { "겨울왕국", 2014, 1029 };

	init_list(&domestic);
	init_list(&foreign);

	insert_node_last(&domestic, create_node(m1));
	insert_node_last(&domestic, create_node(m2));
	insert_node_last(&domestic, create_node(m3));
	insert_node_last(&domestic, create_node(m4));

	insert_node_last(&foreign, create_node(m5));
	insert_node_last(&foreign, create_node(m6));
	insert_node_last(&foreign, create_node(m7));

	LinkedB0_C merged = merge_B0(&domestic, &foreign);
	print_list(&merged);
}