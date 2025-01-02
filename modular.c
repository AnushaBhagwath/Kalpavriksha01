#include <stdio.h>

// Function to perform modular exponentiation
// It returns (base^exponent) % modulus
int mod_exp(int base, int exponent, int modulus) 
{
    if (modulus <= 1)
     {
        printf("Error: Modulus must be greater than 1.\n");
        return -1;
    }

    int result = 1; // Initialize result
    base = base % modulus; // Handle cases where base >= modulus

    while (exponent > 0) 
    {
        // If exponent is odd, multiply base with result
        if (exponent % 2 == 1) 
        {
            result = (result * base) % modulus;
        }

        
        exponent = exponent / 2; // Reduce exponent
        base = (base * base) % modulus; // Square the base
    }

    return result;
}

int main() {
    int base, exponent, modulus;

    
    printf("Enter the base (B): ");
    scanf("%d", &base);

    printf("Enter the exponent (N): ");
    scanf("%d", &exponent);

    printf("Enter the modulus (M): ");
    scanf("%d", &modulus);

  
    if (base < 0 || exponent < 0 || modulus <= 1)
     {
        printf("Invalid input. Ensure that B and N are non-negative and M > 1.\n");
        return 1;
    }

    int result = mod_exp(base, exponent, modulus);

    // Output result
    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}
