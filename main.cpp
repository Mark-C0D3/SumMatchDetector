#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char *argv[])
{   
    FILE *fp = fopen("result.txt", "w"); // Open file "result.txt"

    if (fp == NULL) {
        perror("Error opening the file");
        return 1;
    }

    if(argc < 3) {
        printf("Please provide the .\'main.exe' <array length> <search length> <numbers> as arguments.\n");
        return 1;
    }

    int size = atoi(argv[1]); 
    int search_length = atoi(argv[2]);

    if(argc != search_length + 3) {
        printf("Please provide the .\'main.exe' <numbers> to search as arguments.\n");
        return 1;
    }

    std::vector<int> result(size);

    for (int o = 0; o < search_length; o++)
    {
        result[o] = atoi(argv[o+3]);
    }

    for (int a = 0; a < search_length; a++)
    {
       fprintf(fp, "[Result = %d]\n", result[a]);

        for (int b = 0; b < size; b++)
        {
            for (int c = b; c < size; c++)
            {
                if ((b + c) == result[a])
                {
                    fprintf(fp, "Arr[%d,%d] == %d\n", b, c, result[a]);
                    break;
                }
                
            }
            
        }
        fprintf(fp, "\n\n");
    }
    fclose(fp); // Close file
    return 0;
}
