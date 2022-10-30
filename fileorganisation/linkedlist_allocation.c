#include<stdio.h>
#include<stdlib.h>

struct blocks
{
    int blkno;
    struct blocks* nxtblk;
};

struct blkhdrs
{
    int blknm;
    struct blocks* header;
    struct blkhdrs* nxthdr;
};

int main()
{
    int nofblks, choice, rqblks, cntr_blks = 0, inpblk, flag;
    struct blkhdrs* header = (struct blkhdrs *)malloc(sizeof(struct blkhdrs));
    struct blkhdrs* ptr_hdr = header; //used to increment the header
    struct blocks* ptr_blk; //used to increment the block
    printf("Enter the total number of memory blocks in the system:");
    scanf("%d", &nofblks);
    int blks[nofblks];
    while(1)
    {
        printf("Enter your choice:\n1.Allocate\n2.show the allocated files and memory\n3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                //allocating memory block
                printf("Enter the number of blocks required:");
                scanf("%d", &rqblks);
                if(cntr_blks+rqblks>nofblks)
                {
                    printf("Not nenough space to allocate the file!\n");
                    break;
                }
                printf("Enter the header blocknumber:");
                scanf("%d", &inpblk);
                if(blks[inpblk-1] != 1)
                {
                    if(header == NULL)
                    {
                        header->blknm = inpblk-1;
                        struct blocks* block = (struct blocks*)malloc(sizeof(struct blocks));
                        header->header = block;
                        blks[inpblk-1] = 1;
                        cntr_blks++;
                    }
                    else
                    {
                        struct blkhdrs* temp = (struct blkhdrs*)malloc(sizeof(struct blkhdrs));
                        temp->blknm = inpblk-1;
                        ptr_hdr->nxthdr = temp;
                        ptr_hdr = ptr_hdr->nxthdr;
                        blks[inpblk-1] = 1;
                        cntr_blks++;
                    }
                }
                else
                {
                    printf("Block already allocated!\n");
                    break;
                }
                printf("Enter the other blocknumbers:");
                flag = 1;
                while(1)
                {
                    if(flag>=rqblks)
                    {
                        break;
                    }
                    else
                    {
                        scanf("%d", &inpblk);
                        if(blks[inpblk-1] != 1)
                        {
                            if(ptr_hdr->header == NULL)
                            {
                                struct blocks* block = (struct blocks*)malloc(sizeof(struct blocks));
                                ptr_hdr->header = block;
                                block->blkno = inpblk-1;
                                ptr_blk = block;
                                blks[inpblk-1] = 1;
                            }
                            else
                            {
                                struct blocks* temp = (struct blocks*)malloc(sizeof(struct blocks));
                                temp->blkno = inpblk-1;
                                ptr_blk->nxtblk = temp;
                                ptr_blk = ptr_blk->nxtblk;
                                blks[inpblk-1] = 1;
                            }
                            cntr_blks++;
                            flag++;
                        }
                        else
                        {
                            printf("Block already allocated!\n");
                        }
                    }
                }
            
            case 2:
                //printing the allocated files
                struct blkhdrs* traverse_hdr = (struct blkhdrs *)malloc(sizeof(struct blkhdrs));
                struct blocks* traverse_blk = (struct blocks *)malloc(sizeof(struct blocks));
                traverse_hdr = header->nxthdr;
                int i = 1;
                while(traverse_hdr != NULL)
                {
                    traverse_blk = traverse_hdr->header;
                    printf("File %d allocated on blocks:", i);
                    printf("%d ", traverse_hdr->blknm);
                    while(traverse_blk != NULL)
                    {
                        printf("%d ", traverse_blk->blkno);
                        traverse_blk = traverse_blk->nxtblk;
                    }
                    traverse_hdr = traverse_hdr->nxthdr;
                    i++;
                    printf("\n");
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

/*
Enter the total number of memory blocks in the system:10
Enter your choice:
1.Allocate
2.show the allocated files and memory
3.Exit
1
Enter the number of blocks required:5
Enter the header blocknumber:1
Enter the other blocknumbers:2
3
4
5
File 1 allocated on blocks:0 1 2 3 4 
Enter your choice:
1.Allocate
2.show the allocated files and memory
3.Exit
1
Enter the number of blocks required:6
Not nenough space to allocate the file!
Enter your choice:
1.Allocate
2.show the allocated files and memory
3.Exit
1
Enter the number of blocks required:4
Enter the header blocknumber:5
Block already allocated!
Enter your choice:
1.Allocate
2.show the allocated files and memory
3.Exit
1
Enter the number of blocks required:4
Enter the header blocknumber:6
Enter the other blocknumbers:7
8
9
File 1 allocated on blocks:0 1 2 3 4 
File 2 allocated on blocks:5 6 7 8 
Enter your choice:
1.Allocate
2.show the allocated files and memory
3.Exit
1
Enter the number of blocks required:2
Not nenough space to allocate the file!
Enter your choice:
1.Allocate
2.show the allocated files and memory
3.Exit
1
Enter the number of blocks required:1
Enter the header blocknumber:10
Enter the other blocknumbers:File 1 allocated on blocks:0 1 2 3 4 
File 2 allocated on blocks:5 6 7 8 
File 3 allocated on blocks:9 
Enter your choice:
1.Allocate
2.show the allocated files and memory
3.Exit
2
File 1 allocated on blocks:0 1 2 3 4 
File 2 allocated on blocks:5 6 7 8 
File 3 allocated on blocks:9 
Enter your choice:
1.Allocate
2.show the allocated files and memory
3.Exit
3

*/