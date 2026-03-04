#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
    char *some_secret_data = malloc(sizeof(char) * 20);
    char *public_data = malloc(sizeof(char) * 20);
    printf("secret: %p\npublic: %p\n", some_secret_data, public_data);

    const char *k = "SECRETDATA_SECRET_DATA_THATWEAREWRITINGTOOMUCHTOSERFAAFAFAFAFAFAFAFAFAFA";
    int n = strlen(k) + 1;
    memcpy(some_secret_data, k, n);

    for (int i = 0; i<20;i++) {
        printf("public_data[%d]: %c\n", i, public_data[i]);
    }

    return 0;
}
