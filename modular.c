#include <stdio.h>
long long mod_exp(long long base, long long exponent, long long modulus) 
{
    if (modulus <= 1) 
    {
        printf("Error: Modulus must be greater than 1.\n");
        return -1;
    }

    long long result = 1; 
    base = base % modulus; // Handle cases where base >= modulus

    while (exponent > 0) 
    {
        // If exponent is odd, multiply base with result
        if (exponent % 2 == 1) 
        {
            result = (result * base) % modulus;
        }

        exponent = exponent / 2; 
        base = (base * base) % modulus; 
    }

    return result;
}

int main() 
{
    long long base, exponent, modulus;
    printf("Enter the base (B): ");
    scanf("%lld", &base);

    printf("Enter the exponent (N): ");
    scanf("%lld", &exponent);

    printf("Enter the modulus (M): ");
    scanf("%lld", &modulus);

    if (base < 0 || exponent < 0 || modulus <= 1) 
    {
        printf("Invalid input. Ensure that B and N are non-negative and M > 1.\n");
        return 1;
    }

    long long result = mod_exp(base, exponent, modulus);

    if (result != -1) {
        printf("Result: %lld\n", result);
    }

    return 0;
}
