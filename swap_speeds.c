#include <stdio.h>

void swapSpeeds(int *s1, int *s2) {
    int temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main() {
    int motor1_speed, motor2_speed;
    printf("Enter speed for Motor 1: ");
    scanf("%d", &motor1_speed);
    printf("Enter speed for Motor 2: ");
    scanf("%d", &motor2_speed);

    printf("\n BEFORE SWAP \n");
    printf("Motor 1 Speed: %d , Memory Address: %p\n", motor1_speed, (void *)&motor1_speed);
    printf("Motor 2 Speed: %d , Memory Address: %p\n", motor2_speed, (void *)&motor2_speed);

    swapSpeeds(&motor1_speed, &motor2_speed);

    printf("\n AFTER SWAP \n");
    printf("Motor 1 Speed: %d , Memory Address: %p\n", motor1_speed, (void *)&motor1_speed);
    printf("Motor 2 Speed: %d , Memory Address: %p\n", motor2_speed, (void *)&motor2_speed);

    return 0;
}
