#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char source_file[100], copy_file[100];
    FILE *source, *copy;
    int ch; //fgetc() 사용을 위함. 정수 변수에 주의 !! (p21 참고)
    
    //원본 파일과 복사 파일 이름 입력받기
    printf("원본 파일 이름: ");
    scanf("%s", source_file);
    printf("복사 파일 이름: ");
    scanf("%s", copy_file);
    
    //원본 파일 열기
    source = fopen(source_file, "r");
    if (source == NULL){
        printf("원본 파일을 열 수 없습니다.\n");
        return 0;
    }
    
    //복사 파일 열기
    copy = fopen(copy_file, "w");
    if (copy == NULL) {
        printf("복사 파일을 열 수 없습니다.\n");
        fclose(source); //return 전에 열려있는 파일 꼭 닫아줄 것
        return 0;
    }
    
    //파일 복사
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, copy);
    }
    
    // printf("파일 복사가 완료되었습니다.\n")
    
    //파일 닫기
    fclose(source);
    fclose(copy);
    
    return 0;
}
