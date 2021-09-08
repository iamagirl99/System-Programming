#include <stdio.h>
#include <stdlib.h>

int main(void){
    char** pp_data = NULL;
    int n;
    int length;
    int i;
    
    printf("정수를 입력하세요.: ");
    scanf("%d", &n);
    pp_data = (char**)malloc(sizeof(char*) * n);
    
    printf("입력할 문자의 최대 길이를 입력하세요.: ");
    scanf("%d", &length);
    for(i = 0; i < n; i++){
        pp_data[i] = (char*)malloc(sizeof(char) * length);
    }
    
    for(i = 0; i < n; i++){
        printf("문자열을 입력하세요.: ");
        scanf("%s", pp_data[i]);
    }
    
    printf("문자열을 출력합니다.\n");
    for(i = 0; i < n; i++){
        printf("%s\n", pp_data[i]);
    }
    
    for(int i = 0; i < n; i++){
        free(pp_data[i]);
    }
    free(pp_data);

    return 0;
}


