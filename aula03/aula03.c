#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define Erro 1

int main() {

   int M[3][3] = {
    {1, 4, 3},
    {2, 1, 2},
    {0, 5, 6}
   };

int Det = 0;
// M[linha][coluna]

Det = Det + M[0][0] * M[1][1] * M[2][2]; 
Det = Det + M[0][1] * M[1][2] * M[2][0];
Det = Det + M[0][0] * M[1][1] * M[2][1];
Det = Det + M[0][0] * M[1][1] * M[0][2];
Det = Det + M[0][0] * M[1][1] * M[0][0];
Det = Det + M[0][0] * M[1][1] * M[0][1];

printf("%d");
}

