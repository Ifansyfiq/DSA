// This code is from the slide. Added printf to see what happened in every stage. Run on CodeBlock.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int heap[10], no, i, j, c, root, temp, k;
    printf("\nEnter no of elements :");
    scanf("%d", &no);
    printf("\nEnter the element : \n");
    for (i = 0; i < no; i++)
        scanf("%d", &heap[i]);
    for (i = 1; i < no; i++)
    {
        //c = i;
        printf("\ni = %d\n", i);
        for (c = i; c > 0; c=root)
        {
            root = (c - 1) / 2;
            printf("c = heap[c]\t%r = heap[root]\n");
            printf("%d = %d\t\t%d = %d\n", c, heap[c], root, heap[root]);
            printf("%d %d %d %d %d %d\n",heap[0],heap[1],heap[2],heap[3],heap[4],heap[5]);
            if (heap[root] < heap[c])
            {
                printf("True\n");
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            printf("%d %d %d %d %d %d\n",heap[0],heap[1],heap[2],heap[3],heap[4],heap[5]);
        }
    }

    printf("\n");
    for (i = 0; i < no; i++)
    {
        printf("%d\t", heap[i]);
    }
    printf("\n");

    for (j = no - 1; j >= 0; j--)
    {
        printf("\nj = %d\n", j);
        printf("heap[0] = %d\theap[j] = %d\n",heap[0],heap[j]);
        temp = heap[0];
        heap[0] = heap[j];
        heap[j] = temp;
        root = 0;
        printf("%d %d %d %d %d %d\n",heap[0],heap[1],heap[2],heap[3],heap[4],heap[5]);
        do
        {
            c = 2 * root + 1;
            printf("c = heap[c]\t%r = heap[root]\n");
            printf("%d = %d\t\t%d = %d\n", c, heap[c], root, heap[root]);
            printf("heap[c] < heap[c+1]\tc < j\n");
            printf("%d < %d\t\t\t%d < %d\n", heap[c], heap[c+1], c, j);
            if ((heap[c] < heap[c + 1]) && c < j-1)
            {
                c++;
                printf("True1\n");
            }
            printf("heap[root] < heap[c]\tc < j\n");
            printf("%d < %d\t\t\t%d < %d\n", heap[root], heap[c], c, j);
            if (heap[root]<heap[c] && c < j)
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
                printf("True2\n");
            }
            root = c;
            printf("%d %d %d %d %d %d\n",heap[0],heap[1],heap[2],heap[3],heap[4],heap[5]);
        } while (c < j);
    }
    return 0;
}


