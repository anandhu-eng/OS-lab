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


/*
Enter the number of directories:3
Enter the name of the directory 1:dir1
Enter the max number of files stored in the directory:5
Enter the name of the directory 2:dir2
Enter the max number of files stored in the directory:4
Enter the name of the directory 3:dir3
Enter the max number of files stored in the directory:3
Choose from the option:
1.Allocate
2.Display the directory structure
3.Exit
1
Enter the directory number you want to allocate the file:1
Enter the name of the file:dir1file1
File allocated successfully!
Choose from the option:
1.Allocate
2.Display the directory structure
3.Exit
1
Enter the directory number you want to allocate the file:3
Enter the name of the file:dir3file1
File allocated successfully!
Choose from the option:
1.Allocate
2.Display the directory structure
3.Exit
1
Enter the directory number you want to allocate the file:3
Enter the name of the file:dir3file2
File allocated successfully!
Choose from the option:
1.Allocate
2.Display the directory structure
3.Exit
1
Enter the directory number you want to allocate the file:3
Enter the name of the file:dir3file3
File allocated successfully!
Choose from the option:
1.Allocate
2.Display the directory structure
3.Exit
1
Enter the directory number you want to allocate the file:3
There is no space in the directory!
Choose from the option:
1.Allocate
2.Display the directory structure
3.Exit
2
Name of the directory:dir1
The files in the directory are:
dir1file1
Name of the directory:dir2
The files in the directory are:
Name of the directory:dir3
The files in the directory are:
dir3file1
dir3file2
dir3file3
Choose from the option:
1.Allocate
2.Display the directory structure
3.Exit
1
Enter the directory number you want to allocate the file:2
Enter the name of the file:dir2file1
File allocated successfully!
Choose from the option:
1.Allocate
2.Display the directory structure
3.Exit
1 
Enter the directory number you want to allocate the file:2
Enter the name of the file:dir2file2
File allocated successfully!
Choose from the option:
1.Allocate
2.Display the directory structure
3.Exit
2
Name of the directory:dir1
The files in the directory are:
dir1file1
Name of the directory:dir2
The files in the directory are:
dir2file1
dir2file2
Name of the directory:dir3
The files in the directory are:
dir3file1
dir3file2
dir3file3
Choose from the option:
1.Allocate
2.Display the directory structure
3.Exit
3
Program exited!
*/