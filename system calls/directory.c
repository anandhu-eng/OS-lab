#include<stdio.h>
#include<dirent.h>

int main()
{
    char dirname[100];
    DIR* drptr;
    struct dirent* dirp;
    printf("Enter the directory name:");
    scanf("%s", dirname);
    printf("%s", dirname);
    drptr = opendir(dirname);
    if(drptr == NULL)
    {
        printf("The directory could not be opened!\n");
        return 1;
    }
    else
    {
        printf("directory opened!");
    }
    while((dirp = readdir(drptr)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }
    closedir(drptr);
}