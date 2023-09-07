#include <stdio.h>

int main(){
    int n, i;

    scanf(" %d", &n);

    for (i = 0 ; i < n ; i++){
        if ((((i + 1) % 3) == 0) && (((i + 1) % 5) == 0)) {
            printf("%s\n", "RilNyata");
        } else if (((i + 1) % 3) == 0){
            printf("%s\n", "Nyata");
        } else if (((i + 1) % 5) == 0) {
            printf("%s\n", "Ril");
        } else {
            printf("%d\n", (i + 1));
        }
    }

    return 0;
}