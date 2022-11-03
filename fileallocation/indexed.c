#include<stdio.h>
#include<stdlib.h>

int get_random_number(int memsize)
{
    int num;
    num = rand()%memsize;
    return num;
}

int main()
{
    int msize, i, j, choice, alloc_file_size, alloc_blcks_need, freemem, r_num, firstalloc, nofindexblk;
    printf("Enter the number of available memory blocks:");
    scanf("%d", &msize);
    freemem = msize;
    int blocks[msize][5], allocated[msize];
    //initially no blocks are allocated
    for(i=0;i<msize;i++)
    {
        allocated[i] = 0;
    }
    while(1)
    {
        firstalloc = 0;
        printf("Enter the choice:\n1.Allocate\n2.View allocated blocks\n3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            //allocate
            printf("Enter the size of the file to be allocated:");
            scanf("%d", &alloc_file_size);
            alloc_blcks_need = alloc_file_size%5;       //size of each block is 5
            nofindexblk = alloc_blcks_need%5;
            int indexblk[nofindexblk], alloc[alloc_blcks_need], i_ind = 0, i_blck = 0, count=0;
            if(freemem-alloc_blcks_need<0)
            {
                printf("Memory limit exceeded!\n");
            }
            else
            {
                while(alloc_blcks_need!=0)
                {
                    //get random numbers
                    r_num = get_random_number(msize);
                    if(allocated[r_num] == 0)
                    {
                        if(firstalloc<nofindexblk)
                        {
                            indexblk[i_ind] = r_num;
                            allocated[r_num] = -1;
                            firstalloc++;
                        }
                        else
                        {
                            alloc[i_blck] = r_num;
                            allocated[r_num] = 1;
                            i_blck++;
                        }
                        alloc_blcks_need--;
                    }
                }
                for(i=0;i<nofindexblk;i++)
                {
                    for(j=0;j<5;j++)
                    {
                        if(count<alloc_blcks_need)
                        {
                            blocks[indexblk[i]][j] = alloc[count];
                            count++;
                        }
                    }
                }
            }
            break;
        case 2:
            //display
            for(i=0;i<msize;i++)
            {
                if(allocated[i] = -1)
                {
                    printf("block %d refers to blocks:");
                    for(j=0;j<5;j++)
                    {
                        printf("%d", blocks[i][j]);
                    }
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
}


//put the case 2 statements in a seperate function and see 