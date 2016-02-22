#include <iostream>

int main()
{
    uint32_t a = 5;
    uint32_t b = 4;
    uint32_t result = 0; 
    
    asm (
        "mov %1, %%ebx;"
        "xor %%eax, %%eax;"
        "mov %2, %%ecx;"
        "l:"
        "add %%ebx, %%eax;"
        "loop l;" 
        "mov %%eax, %0"
        :"=r"(result)
        :"r"(a), "r"(b)
        :"%eax", "%ebx", "%ecx" 
    );
    
    std::cout << result << std::endl;
}