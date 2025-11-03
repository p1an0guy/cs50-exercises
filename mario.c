#include <stdio.h>

void print_row(int, int);

int main()
{
    int height;
    do
    {
        printf("Height: ");
        scanf("%i", &height);
    } while (height < 1);

    for (int rows = 0; rows < height; rows++)
    {
        print_row(height, rows);
        printf("\n");
    }
    return 0;
}

void print_row(int height, int curr_row)
{
    const int num_middle_spaces = 2;
    for (int beginning_spaces = 0; beginning_spaces < height - curr_row; beginning_spaces++)
    {
        printf(" ");
    }
    for (int hashes = 0; hashes < curr_row + 1; hashes++)
    {
        printf("#");
    }
    for (int spaces = 0; spaces < num_middle_spaces; spaces++)
    {
        printf(" ");
    }

    for (int hashes = 0; hashes < curr_row + 1; hashes++)
    {
        printf("#");
    }
    for (int beginning_spaces = 0; beginning_spaces < height - curr_row; beginning_spaces++)
    {
        printf(" ");
    }
}