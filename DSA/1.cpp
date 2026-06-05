#include<stdio.h>
#include<stdlib.h>

int *ptr = NULL;
int size = 0;

/* Function for malloc */
void useMalloc()
{
    int i;
    printf("Enter number of elements: ");
    scanf("%d",&size);

    ptr = (int*)malloc(size * sizeof(int));

    printf("Enter elements:\n");
    for(i=0;i<size;i++)
        scanf("%d",&ptr[i]);

    printf("Data using malloc:\n");
    for(i=0;i<size;i++)
        printf("%d ", ptr[i]);
}

/* Function for calloc */
void useCalloc()
{
    int i;
    printf("\nEnter number of elements: ");
    scanf("%d",&size);

    ptr = (int*)calloc(size, sizeof(int));

    printf("Enter elements:\n");
    for(i=0;i<size;i++)
        scanf("%d",&ptr[i]);

    printf("Data using calloc:\n");
    for(i=0;i<size;i++)
        printf("%d ", ptr[i]);
}

/* Function for realloc */
void useRealloc()
{
    int newSize,i;
    printf("\nEnter new size: ");
    scanf("%d",&newSize);

    ptr = (int*)realloc(ptr, newSize * sizeof(int));

    printf("Enter new elements:\n");
    for(i=0;i<newSize;i++)
        scanf("%d",&ptr[i]);

    size = newSize;

    printf("Data after realloc:\n");
    for(i=0;i<size;i++)
        printf("%d ", ptr[i]);
}

/* Function for free */
void useFree()
{
    free(ptr);
    ptr = NULL;
    printf("\nMemory freed successfully.");
}

int main()
{
    int choice;

    do{
        printf("\n\n1. malloc\n2. calloc\n3. realloc\n4. free\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: useMalloc(); break;
            case 2: useCalloc(); break;
            case 3: useRealloc(); break;
            case 4: useFree(); break;
        }
    }while(choice!=5);

    return 0;
}
