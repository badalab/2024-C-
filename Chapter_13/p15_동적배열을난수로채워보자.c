#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int *array;
    int max_value;

    // 동적 배열 생성
    array = (int *)malloc(1000 * sizeof(int));
    if (array == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return 1;
    }

    // 난수 생성 초기화
    srand(time(NULL));

    // 배열을 난수로 채우기
    for (int i = 0; i < 1000; i++) {
        array[i] = rand() % 100000; // 0부터 99999 사이의 난수
    }

    // 최대값 계산
    max_value = array[0];
    for (int i = 1; i < 1000; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    // 결과 출력
    printf("최댓값 = %d\n", max_value);

    // 동적 메모리 해제
    free(array);

    return 0;
}
