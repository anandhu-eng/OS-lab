#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//for storing filename
struct file
{
    char filename[50];
};

//structure for directory
struct dir
{
    char dirname[50];
    struct file* dirfiles;      //inorder to access the corresponding file array related to specific directory
    int nfiles;
    int pointer;
};

//to allocate the files
int allocate(struct dir* directory, char* filename)
{
    int i;
    //loop to check if file with the given filename is already present
    for(i=0;i<directory->pointer;i++)
    {
        if(strcmp(directory->dirfiles[i].filename, filename) == 0)
        {
            return 0;
        }
    }
    //copy the filename to file array
    strcpy(directory->dirfiles[directory->pointer].filename, filename);
    directory->pointer++;
    return 1;
}

int main()
{
    int choice, nofd, i, dirno, j;
    char filename[50];
    printf("Enter the number of directories:");
    scanf("%d", &nofd);
    struct dir directories[nofd];
    for(i=0;i<nofd;i++)
    {
        printf("Enter the name of the directory %d:", i+1);
        scanf("%s", directories[i].dirname);
        printf("Enter the max number of files stored in the directory:");
        scanf("%d", &directories[i].nfiles);
        directories[i].dirfiles = (struct file*)malloc(sizeof(struct file)*directories[i].nfiles);
        directories[i].pointer = 0;
    }
    while(1)
    {
        printf("Choose from the option:\n1.Allocate\n2.Display the directory structure\n3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: //for allocating files
                printf("Enter the directory number you want to allocate the file:");
                scanf("%d", &dirno);
                if(directories[dirno-1].pointer>=directories[dirno-1].nfiles)
                {
                    printf("There is no space in the directory!\n");
                }
                else
                {
                    printf("Enter the name of the file:");
                    scanf("%s", filename);
                    if(allocate(&directories[dirno-1], filename) == 1)
                    {
                        printf("File allocated successfully!\n");
                    }
                    else
                    {
                        printf("File already present in the specified directory!\nPlease choose another name!\n");
                    }
                }
                break;
            
            case 2: //for displaying the current directory structure
                for(i=0;i<nofd;i++)
                {
                    printf("Name of the directory:%s\n", directories[i].dirname);
                    printf("The files in the directory are:\n");
                    for(j=0;j<directories[i].pointer;j++)
                    {
                        printf("%s\n", directories[i].dirfiles[j].filename);
                    }
                }
                break;
            
            case 3:
                printf("Program exited!\n");
                exit(1);
                break;
        
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    for(i=0;i<nofd;i++)
    {
        printf("The name of the directory is:%s\n", directories[i].dirname);
    }

}


