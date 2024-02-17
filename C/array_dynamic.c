#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr = NULL;
    int size, choice, element, position, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n1. Linear search for an element\n");
        printf("2. Insert an element at specified position\n");
        printf("3. Delete an element from the specified position\n");
        printf("4. Reverse the array\n");
        printf("5. Update the array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                {
                    int found = 0;
                    for (int i = 0; i < size; i++) {
                        if (arr[i] == key) {
                            printf("Element %d found at position %d\n", key, i);
                            found = 1;
                            break;
                        }
                    }
                    if (!found)
                        printf("Element %d not found\n", key);
                }
                for(int i=0;i<size;i++){

                    printf("%d ",arr[i]);
                }
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                if (position >= 0 && position <= size) {
                    size++;
                    arr = (int*)realloc(arr, size * sizeof(int));
                    for (int i = size - 1; i >= position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = element;
                } else {
                    printf("Invalid position\n");
                }
                for(int i=0;i<size;i++){

                    printf("%d ",arr[i]);
                }break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                if (position >= 0 && position < size) {
                    for (int i = position; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                    arr = (int*)realloc(arr, size * sizeof(int));
                } else {
                    printf("Invalid position\n");
                }
                for(int i=0;i<size;i++){

                    printf("%d ",arr[i]);
                }
                break;
            case 4:
                for (int i = 0; i < size / 2; i++) {
                    int temp = arr[i];
                    arr[i] = arr[size - i - 1];
                    arr[size - i - 1] = temp;
                }
                printf("Array reversed successfully\n");
                for(int i=0;i<size;i++){

                    printf("%d ",arr[i]);
                }
                break;
            case 5:
                for (int i = 0; i < size; i++) {
                    if (i % 2 == 0) {
                        arr[i] += 5;
                    } else {
                        arr[i] *= 2;
                    }
                }
                printf("Array updated successfully\n");
                for(int i=0;i<size;i++){
                    printf("%d ",arr[i]);
                }
                break;
            case 6:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 6);

    free(arr);
    return 0;
}
