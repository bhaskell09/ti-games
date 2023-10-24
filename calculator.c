#include <stdio.h>
#include <stdlib.h>

int calculate_gcd(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return calculate_gcd(num2, num1 % num2);
}

int calculate_lcm(int num1, int num2) {
    int gcd = calculate_gcd(num1, num2);
    int lcm = (num1 * num2) / gcd;
    return lcm;
}

int main() {
    int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int gcd_result = calculate_gcd(num1, num2);
    int lcm_result = calculate_lcm(num1, num2);
    int sum_result = num1 + num2;
    int difference_result = abs(num1 - num2);
    int product_result = num1 * num2;
    
    if (num2 == 0) {
        printf("Cannot divide by zero!\n");
    } else {
        float quotient_result = (float)num1 / num2;
        printf("The Least Common Multiple of %d and %d is: %d\n", num1, num2, lcm_result);
        printf("The Greatest Common Divisor of %d and %d is: %d\n", num1, num2, gcd_result);
        printf("The Sum of %d and %d is: %d\n", num1, num2, sum_result);
        printf("The Difference of %d and %d is: %d\n", num1, num2, difference_result);
        printf("The Product of %d and %d is: %d\n", num1, num2, product_result);
        printf("The Quotient of %d and %d is: %.2f\n", num1, num2, quotient_result);
    }
    
    return 0;
}