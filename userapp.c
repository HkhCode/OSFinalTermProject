// user/hello.c
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    int x = 0;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                x += 1;
            }
        }
    }

    printf(1, "The value of x is: %d\n", x);
    exit();
}
