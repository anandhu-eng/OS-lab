//stat system call is used to check the file attributes in c
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>

int main()
{
    char filename[100];
    printf("Enter the filename to find the status:");
    scanf("%s", filename);
    struct stat* nfile = (struct stat*)malloc(sizeof(struct stat));
    stat(filename, nfile);
    printf("%ld", nfile->st_size);
}