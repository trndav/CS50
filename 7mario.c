// #include <stdio.h>
// int main(void)
// {
//     // Get size of bricks
//     int bricks;   
//     do
//     {
//         printf("How big is brick?\n");
//         scanf("%i", &bricks);
//     }
//     while (bricks < 1);
//     // Print grid of blocks
//     for (int i=0; i<bricks; i++)    
//     {                
//         for (int j=0; j<bricks; j++)
//         {
//             printf("#");
//         }        
//         printf("\n");        
//     }
// }

int main(void) {
    // Get size of bricks
    int bricks;
    do {
        printf("Height: ");
        scanf("%i", &bricks);
    } while (bricks < 1 || bricks > 8);

    // Print grid of blocks
    for (int i = 1; i <= bricks; i++) {
        for (int space = 1; space <= bricks - i; space++) {
            printf(" "); // Print spaces based on column index
        }
        for (int hash = 1; hash <= i; hash++) {
            printf("#"); // Print a hash followed by a space for each block
        }
        printf("\n");
    }
}

// number = get_valid_input()
// for num in range(1, number+1):
//     spaces = " " * (number-num)
//     print(spaces + "#" *num)