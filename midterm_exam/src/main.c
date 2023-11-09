#include "../include/customer.h"
#include "../include/queues.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define SIZE 20

int TreeHeight[50];
int TreeSize = -1; // or NULL, no elements yet

int main() {
    // testPQLane();
    // testPQLane2();


    system("clear");
    printf("\t*---------------------------------------------------*\n");
    printf("\t| RX Drugstore Inventory and Sales Management System |\n");
    printf("\t*---------------------------------------------------*\n");
    int choiceMainMenu, choiceSubMenu, loc1, loc2, value;
    // system("clear");
    while (1) {
    mainMenu:
        printf("\n\n\t* ------------------- * MENU * ------------------- *\n"\
                "\n\t[1] Buy Medicine\n \t[2] Quick Inquiry\n \t[3] Inventory and Sales\n \t[4] Exit\n" \
                "\n\tEnter your choice: ");
        scanf("%d", &choiceMainMenu);
        switch (choiceMainMenu) {
        case 1:
            while (1) {
                printf("\n\n\n\t*----------------------------------");
                printf("\n\t| Get Priority Slip: ");
                printf("\n\t*----------------------------------\n");
                printf("\n\t[1] Priority Lane\n\t[2] Regular Lane\n\t[3] Back to Main Menu\n");
                printf("\n\tEnter choice : ");
                scanf("%d", &choiceSubMenu);
                switch (choiceSubMenu) {
                case 1:
                    printf("\n\tGenerating Priority Slip for Priority / Special Lane Customer....\n");
                    // printPrioritySlipSpecial();
                    // enQueue(, )
                    // showQueue()
                    goto mainMenu;
                    // break;
                case 2:
                    printf("\n\tGenerating Priority Slip for Regular Customer...\n");
                    // printPrioritySlipRegular();
                    // addNode()
                    // showPriorityQueue()
                    goto mainMenu;
                    // break;
                case 3:
                    printf("\n\tThank you for choosing RX Drugstore! Going back to Main Menu\n");
                    goto mainMenu;
                default:
                    printf("\tOooops Something went wrong! Try again.\n\n");
                    goto mainMenu;
                }
                goto subMenuEnd;
            }
        subMenuEnd:
            break;
        case 2:
            printf("\n\t~ Quick Inquiry Menu --\n");
            goto mainMenu;
            // break;
        case 3:
            while(1) {
                printf("\n\t Inventory and Sales");
                // break;
                printf("\n\t[1] Add Medicine\n\t[2] Search Medicine Information \n\t[3] View Medicine List" \
                        "\n\t[4] Edit Medicine \n\t[5] Delete Medicine \n\t[6] Clear Medicine By Type" \
                        "\n\t[7] Clear Medicine \n\t[8] Go back to Main Menu \n\t[9] Exit App\n");
                printf("\n\t >> ");
                scanf("%d", &choiceSubMenu);
                switch (choiceSubMenu) {
            //     case 1:
            //         printf("");
            //         break;
            //     case 2:
            //         printf("");
            //         break;
            //     case 3:
            //         printf("");
            //         break;
            //     case 4:
            //         printf("");
            //         break;
            //     case 5:
            //         printf("");
            //         break;
            //     case 6:
            //         printf("");
            //         break;
            //     case 7:
            //         printf("");
            //         break;
                case 8:
                    printf("\n\tGoing back to Main Menu.\n");
                    goto mainMenu;
                case 9:
                    printf("\n\tExiting...\n");
                    break;
                default:
                    printf("\n\tWrong Input. Try again!!!\n\n");
                    goto mainMenu;
                    break;
                }
            }
        case 4:
            printf("\n\tThank you for choosing RX Drugstore!\n");
            break;
        default:
            printf("\tOooops Something went wrong! Try again.\n\n");
        }

    return 0;
    }
}

// void testPQLane() {

//     insertNode(5);
//     insertNode(3);
//     insertNode(2);
//     insertNode(2);
//     insertNode(4);
//     insertNode(1);

//     int i = 0;

//     // Priority queue before extracting max
//     puts("Priority Queue : ");
//     while (i <= TreeSize) {
//         printf("%d ", TreeHeight[i]);
//         i++;
//     }

//     printf("\n");

//     // Node with maximim priority
//     printf("Node with maximum priority : %d", extractMax());

//     printf("\n");
//     // Priority queue after extracting max
//     printf("Priority queue after extracting maximum : ");
//     int j = 0;
//     while (j <= TreeSize) {
//         printf("%d ", j);
//         j++;
//     }

//     printf("\n");

//     changePriority(2, 49);
//     printf("Priority queue after priority change : ");
//     int k = 0;
//     while (k <= TreeSize) {
//         printf("%d ", k);
//         k++;
//     }

//     printf("\n");

//     removeNode(3);
//     printf("Priority queue after removing the element: ");
//     int l = 0;
//     while (l <= TreeSize) {
//         printf("%d ", l);
//         l++;
//     }

//     printf("\n");
// }

// void testPQLane2() {
//     srand(time(NULL));

//     int array[SIZE];
//     for (int i = 0; i < SIZE; i++) {
//         array[i] = rand() % 1000;
//     }

//     heapSort(&array, SIZE);

//     for (int i = 1; i < SIZE; i++) {
//         assert(array[i-1] <= array[i]);
//     }
// }

// void heapSort(int *array, int n) {
//     minheap h = minheapHeapify(array, n);

//     int i = 0;
//     while(!minheapisEmpty(h)) {
//         array[i++] = minheapFindmin(h);
//         minheapDeleteMin(h);
//     }

//     minheapDestroy(h);
// }
