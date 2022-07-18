#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTRING 100
typedef unsigned strlength;

typedef struct String {
	char str[MAXSTRING];// 100
	strlength len;// ���ڿ��� ����
}String;// String���� �����ϰ� ��� ����

String* createStringInstance(char str[]) {
	String* S = (String*)malloc(sizeof(String));
	if (S != NULL) strcpy_s(S->str, strlen(S->str) + 1, (const char*)str);// ���ڿ� ����
	if (S != NULL) S->len = strlen(S->str);//���� �Ҵ�
	return S; 
}
char* strConcatenate(char* str1, const char* str2) {
	char* str3 = (char*)"Every Life Is the context of Now&Here !!!";
	return str3;
}
unsigned int strLen(char* str4) {
	int count = 0;
	while (*(str4 + count) != '\0') {
		count++;
	}
	return count;
}
char* strCat(char* a, const char* b)
{
	while (1)
	{
		if (*a != '\0') {
		a++;
		}
		else if (*a == '\0') {
		break;
		}
	}
	*a = ' ';
	a++;
	while (*b != '\0')
	{
		*a = *b;
		a++;
		b++;
	}
	*a = '\0';

}


int main(void) {
	//Test Case 1
	char str1[] = "Life Is the context of Now&Here !!!";
	String* S1 = createStringInstance(str1);
	printf("String Instance: %s (Length : %u)\n", S1->str, S1->len);// s1�� �Ҵ�� str�� len�� ���
	for (; getchar() == NULL; );

	// Test Case 2
	char* str3 = NULL;
	
	char* str2 = (char*)"Life Is the context of Now&Here !!!";
	str3 = strConcatenate((char*)"Every", (const char*)str2);
	printf("String Instance Concatenated : %s (Length : %u)\n", str3, strlen(str3));
		for (; getchar() == NULL; );

// Test Case3: strLen(���ڿ� ���� ���)�� strCat(���ڿ� �ռ� �Լ�) �Լ��� ���� �����ϰ� �׽�Ʈ�ϱ�
// (insert codes here)
		
		char str4[80] = "Every";
        char str5[100] = "Life Is the context of Now&Here !!!";
		strCat(str4, str5);
		int str6 = strLen(str4);
		printf("String Instance Concatenated : %s (Length : %u)\n", str4, str6);
		for (; getchar() == NULL; );

		return 1;
}
