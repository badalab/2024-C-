#include <stdio.h>
#include <windows.h>

int main(void) {
    HDC hdc = getWindowDC(GetForegroundWindow());
    
    FILE *fp = fopen("d:\\lena(256x256).raw","rb");
    if (fp == NULL) {
        printf("lena.raw 파일을 열 수 없습니다.");
        exit(1);
    }
    char image[256][256];
    fread(image, 1, 256*256, fp);
    fclose(fp);
    
    int r, c; //row 행, column 열
    for(r = 0; r < 256; r++){
        for (c = 0; c < 256; c++) {
            int red = image[r][c];
            int green = image[r][c];
            int blue = image[r][c];
            SetPixel(hdc, c, r, RGB(red, green, blue));
        }
    }
    return 0;
}