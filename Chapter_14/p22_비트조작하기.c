#include <stdio.h>

// 매크로 정의
#define SETBIT(x, n)   ((x) |= (1 << (n-1)))
#define CLEARBIT(x, n) ((x) &= ~(1 << (n-1)))
#define TESTBIT(x, n)  ((x) & (1 << (n-1)))

// 2진수 출력을 위한 함수
void printBinary(unsigned int num) {
    for (int i = 3; i >= 0; i--) { //4비트까지만 출력
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

//수업자료와 같은 결과를 출력하기 위해서는 n 값은 8이 아닌 3이여야 하고
//매크로 정의도 n이 아닌 n-1이여야 함

int main() {
    unsigned int x = 0b1011; // 초기값을 2진수 1011로 설정

    // 현재 x 출력 (2진수로 출력)
    printf("SETBIT(x,3)전 변수 x = ");
    printBinary(x); // 출력: 1011

    // 비트 3이 1로 설정
    printf("SETBIT(x, 3)후 변수 x = ");
    SETBIT(x, 3);
    printBinary(x); // 출력: 1111

    // 현재 x 출력 (2진수로 출력)
    printf("CLEARBIT(x,3)전 변수 x = ");
    printBinary(x); // 출력: 1111

    // 비트 3을 0으로 설정
    CLEARBIT(x, 3);
    printf("CLEARBIT(x, 3)후 변수 x = ");
    printBinary(x); // 출력: 1011

    return 0;
}
