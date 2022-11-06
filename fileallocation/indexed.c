#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int get_random_number(int memsize)
{
    int num;
    num = rand()%memsize;
    return num;
}

int allocate(int freemem, int msize, int* allocated, int blocks[][6], int filenum)
{
    int alloc_file_size, alloc_blcks_need, nofindexblk, r_num, i, j, temp, firstalloc=0;
    printf("Enter the size of the file to be allocated:");
    scanf("%d", &alloc_file_size);
    alloc_blcks_need = ceil(((float)alloc_file_size)/((float)5));       //size of each block is 5
    nofindexblk = ceil(((float)alloc_blcks_need)/((float)5));       //index block size is 5
    temp = alloc_blcks_need;            //for looping
    int indexblk[nofindexblk], alloc[alloc_blcks_need], i_ind = 0, i_blck = 0, count=0;
    if(freemem-alloc_blcks_need-nofindexblk<0)      //index blocks are also considered while 
    {
        printf("Memory limit exceeded!\n");
        return 0;
    }
    else
    {
        while(alloc_blcks_need!=0)
        {
            //get random numbers
            r_num = get_random_number(msize);
            if(allocated[r_num] == 0)
            {
                if(firstalloc<nofindexblk)      //first alloc variable is used to check whether all
                {                               //index block spaces are allocated
                    indexblk[i_ind] = r_num;
                    allocated[r_num] = -1;
                    firstalloc++;
                    i_ind++;
                }
                else
                {
                    alloc[i_blck] = r_num;
                    allocated[r_num] = 1;
                    i_blck++;
                    alloc_blcks_need--;
                }
                
            }
        }
        for(i=0;i<nofindexblk;i++)
        {
            for(j=0;j<5;j++)
            {
                if(count<temp)
                {
                    blocks[indexblk[i]][j] = alloc[count];
                    count++;
                }
                else if(j<5)
                {
                    blocks[indexblk[i]][j] = -1;
                }
            }
            blocks[indexblk[i]][5] = filenum;   //the 6th position is used to identify the filenum to 
        }                                       //it is allocated.
        return temp+nofindexblk;
    }
}

int main()
{
    int msize, i, j, choice, freemem, usedmem, firstalloc, flag, filenum = 1;
    printf("Enter the number of available memory blocks:");
    scanf("%d", &msize);
    freemem = msize;
    int blocks[msize][6], allocated[msize];     //last index of the block is used to identify the file
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
            usedmem = allocate(freemem, msize, allocated, blocks, filenum);
            if(usedmem != 0)
            {
                filenum++;
                freemem = freemem - usedmem;
            }
            break;
        case 2:
            //display
            flag=0;
            for(i=0;i<msize;i++)
            {
                if(allocated[i] == -1)
                {
                    flag=1;
                    printf("block %d which stores address of file %d refers to blocks:", i, blocks[i][5]);
                    for(j=0;j<5;j++)
                    {
                        if(blocks[i][j] != -1)
                        {
                            printf("%d ", blocks[i][j]);
                        }
                    }
                    printf("\n");
                }
            }
            if(flag == 0)
            {
                printf("Nothing assigned yet!\n");
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