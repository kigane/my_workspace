#include <stdio.h>
#include <stdlib.h> // exit()
#include <fileapi.h>

void readfile(int argc, char const *argv[])
{
    int ch;
    FILE *fp;
    unsigned long count = 0;
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // 确定文件存在
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't Open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    // 读取整个文件内容
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", argv[1], count);
}

void temp_file()
{
    char *tmp;
    tmp = tmpnam(NULL);
    FILE *fp = fopen(tmp, "w");
    fprintf(fp, "Hello World\n"); // 如果没内容，tmpfile不会真的生成
    fclose(fp);
    char *new = "hello.txt";
    rename(tmp, new);
}

int main(int argc, char const *argv[])
{
    // readfile(argc, argv);
    // temp_file();
    char buf[1024] = {};
    sprintf(buf, "93+12");
    int n;
    // sscanf(buf, "%d", &n);
    printf("%d\n", buf);
    return 0;
}
