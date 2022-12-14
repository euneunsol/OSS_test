#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentInfo{
	char* univ;
	int sNo;
	char* major;
	char name[15];
};

int isEqualStudent(struct studentInfo a, struct studentInfo b){
	if (!strcmp(a.univ, b.univ) && !strcmp(a.major, b.major)
		&& !strcmp(a.name, b.name) && a.sNo == b.sNo){
		return 1;
	}
	else{
		return 0;
	}
};

int main(void){
	struct studentInfo student[4] = {
		{"DCU", 21000001, "ComputerSW", "Kim"},
		{"DCU", 21000002, "AIBigdata", "Lee"},
		{"DCU", 21000003, "SWConvergence", "Park"}
	};

	int i;
	char temp[80];
	struct studentInfo* ptr = &student[3];

	printf("Input your name : ");
	scanf("%s", temp);
	strcpy(student[3].name, temp);

	while (1){
		int count = 0;
		printf("Input your student number : ");
		scanf("%d", &(ptr->sNo));

		for (int j = 0; j < 3; j++){
			if ((ptr->sNo) == student[j].sNo){
				count++;
				break;
			}
		}
		if (count > 0){
			printf("Wrong sutdent number!!\n");
		}
		else{
			break;
		}
	}

	printf("Input your major : ");
	scanf("%s", temp);
	ptr->major = malloc(sizeof(char) * strlen(temp));
	strcpy(ptr->major, temp);

	printf("Input your university : ");
	scanf("%s", temp);
	ptr->univ = malloc(sizeof(char) * strlen(temp));
	strcpy(ptr->univ, temp);

	for (i = 0; i < 4; i++){
		printf("%s [%d, %s, %s]\n", student[i].univ, student[i].sNo, student[i].major, student[i].name);
	}

	if (isEqualStudent(student[0], student[3])){
		printf("student 0 and student 3 are same.");
	}
	else{
		printf("student 0 and student 3 are not same.");
	}
	return 0;
}