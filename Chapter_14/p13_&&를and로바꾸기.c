#include <stdio.h>

#define and &&
#define or ||

#define GRADUATION_CREDITS 120
#define MINIMUM_GPA 2.0

void main() {
    int credits;
    float gpa;

    printf("지금까지 획득한 학점을 입력하세요: ");
    scanf("%d", &credits);

    printf("지금까지 획득한 성적평균을 입력하세요: ");
    scanf("%f", &gpa);

    if (credits >= GRADUATION_CREDITS and gpa >= MINIMUM_GPA) {
        printf("졸업 가능합니다.\n");
    } else {
        printf("졸업 조건을 충족하지 못했습니다.\n");
    }

}
