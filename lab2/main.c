#include <stdio.h>
#include <string.h>


char *input_data();
void output_data(char *a_data);

char *input_data()
{
    const int size_in_str = 256;
    const int size_unpack_str = size_in_str * 8;
    const int size_pack_str = size_unpack_str * 8;
    char in_str[size_in_str], unpack_str[size_unpack_str], pack_str[size_pack_str];
    char *addr;
    int num = 0;
    char sym_num = '\1';
    char sym_end = '\0';
    char *ptr = pack_str;

    printf("To exit, press the 'Esc' button\n");
    for (;;)
    {
        printf("Enter any string:\n");
        scanf("%s", in_str);

        if (in_str[0] == 27) break;

        strcat(unpack_str, in_str);
    }

    for (addr = unpack_str; *addr != '\0'; addr++)
    {
        if (*addr >= '0' && *addr <= '9')
        {
            num = num * 10 + (*addr - '0');
        }
        else *ptr++ = *addr;

        if ((*(addr + 1) < '0' || *(addr + 1) > '9') && num != 0)
        {
            memcpy(ptr, &sym_num, sizeof(sym_num));
            ptr += sizeof(sym_num);
            memcpy(ptr, &num, sizeof(num));
            ptr += sizeof(num);

            num = 0;
        }

    }
    strcat(pack_str, &sym_end);

    return pack_str;
}

void output_data(char *a_data)
{
    char *addr;

    for (addr = a_data; *addr != '\0'; addr++)
        printf("%d\n", *addr);
}

int main()
{
    char *data;
    char *addr;

    data = input_data();
    //for (addr = data; *addr != '\0'; addr++)
        //printf("%dьфт \n", *addr);

    //for (int i = 0; i < strlen(data); i++)
        //printf("%d\n", data[i]);

        printf("%d\n", sizeof(data));
    //output_data(data);


    return 0;
}
