#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file;
    char filename[] = "student_scores.txt";
    int student_id;
    char name[50];
    float score;
    char choice;
    
    //파일 열기    
    file = fopen(filename,"w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 0;
    }
    
    do {
        //학생 정보 입력 받기
        printf("학번: ");
        scanf("%d", &studnet_id);
        printf("이름: ");
        scanf("%s", name);
        printf("성적: ");
        scanf("%f", &score);
        
        //파일에 기록하기
        fprintf(file, "학번: %d\n이름: %s\n성적: &.1f\n", student_id, name, score);
        
        //추가 입력 여부 확인
        printf("데이터 추가를 계속? (y/n) : ");
        scanf(" %c", &choice); //공백문자 무시를 위해 띄어쓰기 필요
        
    } while (choice == 'y' || choice == 'Y');
    
    fclose(file);
    // printf("%s 파일에 저장 완료",filename);
    
    return 0;
}