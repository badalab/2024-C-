#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n; //배열의 크기
    int *array; //동적으로 할당할 배열
    
    //항목의 개수 입력
    printf("항목의 개수는 몇개입니까? ");
    scanf("%d", &n);
    
    //동적 메모리 할당
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return 0;
    }
    
    //사용자로부터 배열 값 입력
    for (int i = 0; i < n; i++) {
        printf("항목(정수)을 입력하시오: ");
        scanf("%d", &array[i]);
    }
    
    //입력된 값 출력
    printf("\n입력된 값은 다음과 같습니다:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    //동적 메모리 해제
    free(array);
    
    return 0;
}
