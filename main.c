#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

#define LIST_AMOUNT 3


int main(){
    struct Node* p_array[LIST_AMOUNT] = {NULL};
    int value = 0;  
    int choose = 0;
    int pos = 0;
    char file_name[50];
    int list1 = 0;
    int list2 = 0;
 
    char* message = "Make an option:\n"
                "\t[1] Append.\n"
                "\t[2] Prepend.\n"
                "\t[3] Reverse.\n"
                "\t[4] Add a value to the specific index.\n"
                "\t[5] Remove a value the from index.\n"
                "\t[6] Search for a value.\n"
                "\t[7] Join two linked lists.\n"
                "\t[8] Backwards traversal.\n"
                "\t[9] Sort the linked list.\n"
                "\t[p] Print list.\n"
                "\t[v] View all lists.\n"
                "\t[c] Choose list to work with.\n"
                "\t[w] Write linked list in a file.\n"
                "\t[r] Read a linked list from a file.\n"
                "Your option: ";

    printf(message);

    char command ;
    while(command = getchar()) 
    {
        switch(command)
        {
            case '1':
                printf("\nProvide data value: ");
                scanf("%d", &value);
                append(&p_array[choose], value);
                break;

            case '2':
                printf("\nProvide data value: ");
                scanf("%d", &value);
                prepend(&p_array[choose], value);
                break;

            case '3':
                reverse(&p_array[choose]);
                break;

            case '4':
                printf("\nProvide the position in list: ");
                scanf("%d", &pos);
                printf("\nProvide data value: ");
                scanf("%d", &value);
                insert(&p_array[choose], pos, value);
                break;
            
            case '5':
                printf("\nProvide the position in list of element which you want to deleted : ");
                scanf("%d", &pos);
                removeAt(&p_array[choose], pos);
                break;

            case '6':
                printf("\nProvide the value which you want to find: ");
                scanf("%d", &value);
                search(p_array[choose], value);
                break;

            case '7':
                printf("\nChoose what lists should be joined: ");
                scanf("%d %d", &list1, &list2);
                join(p_array[list1-1], p_array[list2-1]);
                p_array[list2-1] = NULL;
                break;

            case '8':
                traverseBack(p_array[choose]);
                break;

            case '9':
                sort(p_array[choose]);
                break;

            case 'c':
                printf("\nProvide list number: ");
                scanf("%d", &choose );
                choose -= 1;
                break;

            case 'v':
                printf("[%d]\n", choose + 1);
                for(int i = 0; i < LIST_AMOUNT; i++)
                    print(p_array[i]);
                break;

            case 'p':
                printf("[%d]\n", choose + 1);
                print(p_array[choose]);
                break;

            case 'w':
                printf("\nProvide a file name: ");
                scanf("%s", file_name);
                serialize(p_array[choose], file_name);
                break;

            case 'r':
                deserialize(&p_array[choose], file_name);
                break;

        default:
                printf("\nYour option: ");
                break;
        }
    }
        return 0;
    }
    