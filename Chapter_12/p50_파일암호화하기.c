#include <stdio.h>
#include <stdlib.h>

void xor_encrypt_decrypt(const char *input_filename, const char *output_filename, char key);

int main(void) {
    char key;
    char input_filename[100], output_filename[100];
    
    printf("입력 파일 이름: ");
    scanf("%s", input_filename);
    printf("출력 파일 이름: ");
    scanf("%s", output_filename);
    printf("암호화 키(문자): ");
    scanf(" %c", &key); //공백문자 무시를 위해 띄어쓰기 필요
    
    xor_encrypt_decrypt(input_filename, output_filename, key);
    
    return 0;
}

void xor_encrypt_decrypt(cont char *input_filename, const char *output_filename, char key) {
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");
    // 텍스트 모드(r,w)로 파일을 열게 되면 운영체제에 따라 줄바꿈 변환 및 EOF 처리 등으로 데이터에 변형이 일어날 수 있음
    // 암호화 및 복호화를 위해선 데이터를 그대로 읽고 쓰는 바이너리 모드가 적합함
    
    if (input_file == NULL || output_file == NULL) {
        printf("파일 열기에 실패했습니다.\n");
        exit(1)
    }
    
    char ch;
    while (fread(&ch, sizeof(char), 1, input_file) == 1) { //1개의 문자를 정확히 읽었는지 확인, 파일의 끝이나 오류 감지를 위함
        ch ^= key; //XOR 연산
        fwrite(&ch, sizeof(char), 1, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    printf("%s 파일을 $s 파일로 암호화/복호화 했습니다.\n", input_filename, output_filename);
    
    // 복호화 또한 같은 연산이므로 암호화한 파일을 input으로 입력하면 원본과 똑같이 복호화됨
}