#include <stdio.h>

// 매크로 정의
#define PI 3.141592
#define CIRCLE_AREA(r) (PI * (r) * (r))

// 디버그 매크로 정의
#define DEBUG

void main() {
    double radius = 10.0; // 반지름

#ifdef DEBUG
    printf("디버깅 모드입니다.\n");
#endif

    printf("원의 반지름: %.1f\n", radius);
    printf("원의 면적: %.2f\n", CIRCLE_AREA(radius));

}
