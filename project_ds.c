#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct node{
 int data;
 struct node *next;
};
struct node *head=NULL,*ptr;


void interface(){

 system("COLOR 02");
 printf("\n\n\n\t\t\t\t\t _________________________________");
 printf("\n\n\t\t\t\t\t\tWELCOME TO PROJECT \n");
 printf("\t\t\t\t\t _________________________________\n");
 printf("\n\n\t\t\t\t\tCourse Name: Data Structure Sessional");
 printf("\n\t\t\t\t\tCourse Code: CSE-1315");
 printf("\n\t\t\t\t\tID: 2112020040\n\n");

}


//#LINKEDLIST

void insert_begin_linkedList(int value)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }else
    {
        temp->next=head;
        head=temp;
    }
}

void insert_end_LinkedList(int value)
{
     struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    if(head==NULL)
    {
        head=temp;
    }else
    {
        ptr=head;
        while(ptr->next !=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
    }
}

void delete_begin_LinkedList()
{
    if(head==NULL)
    {
        printf("LinkedList if Empty.Delete operarion is not working.");
    }
    else
    {
        ptr=head;
        head=head->next;
        ptr->next=NULL;
        free(ptr);
    }
}

void delete_end_LinkedList()
{
    if(head==NULL)
    {
        printf("LinkedList if Empty.Delete operation is not possible");
    }
    else
    {
        struct node *p;
        ptr=head;
        while(ptr->next !=NULL)
        {
            p=ptr;
            ptr=ptr->next;
        }
        p->next=NULL;
        free(ptr); //remove ptr=free function
    }
}

int searchValue_LinkedList(struct node* head, int value) {
    struct node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == value) {

            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

void updateValue_LinkedList(struct node* head, int oldValue, int newValue) {
    struct node* current = head;
    while (current != NULL) {
        if (current->data == oldValue) {

            current->data = newValue;
            return;
        }
        current = current->next;
    }
}

void display_LinkedList()
{
    if(head==NULL)
    {
        printf("LinkedList is Empty");
    }
    else
    {
        ptr=head;
        while(ptr !=NULL)
        {
            printf("-> %d",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}


//#ARRAY


void display_Array(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int searchValue_Array(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {

            return i + 1;
        }
    }

    return -1;
}


void updateValue_Array(int arr[], int size, int oldValue, int newValue) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == oldValue) {
            // Update the value
            arr[i] = newValue;
            return;
        }
    }
}


void deleteValue_Array(int arr[], int* size, int value) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == value) {

            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Value %d not found in the array.\n", value);
    }
}


//#Satck

struct Stack {
    int data[MAX_SIZE];
    int top;
};

// stack create
void initialize_Stack(struct Stack* stack) {
    stack->top = -1;
}

//  stack is empty??
int isEmpty_Stack(struct Stack* stack) {
    return stack->top == -1;
}

//  stack is full??
int isFull_Stack(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}


void push_Stack(struct Stack* stack, int value) {
    if (isFull_Stack(stack)) {
        printf("Stack overflow. So push operation can not working.\n\n");
    } else {
        stack->data[++stack->top] = value;
        printf("Push: %d\n", value);
    }
}


void pop_Stack(struct Stack* stack) {
    if (isEmpty_Stack(stack)) {
        printf("Stack underflow. So pop operation can not working.\n\n");
    } else {
        printf("Pop: %d\n", stack->data[stack->top--]);
    }
}


void display_Stack(struct Stack* stack) {
    if (isEmpty_Stack(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}


//# Queue


struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

//create queue
void initialize_Queue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// queue is empty
int isEmpty_Queue(struct Queue* queue) {
    return queue->front == -1;
}

// queue is full
int isFull_Queue(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}


void insert_Queue(struct Queue* queue, int value) {
    if (isFull_Queue(queue)) {
        printf("Queue overflow. So insert operation can not working.\n");
    } else {
        if (isEmpty_Queue(queue)) {
            queue->front = 0; // Initialize front if the queue is empty
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE; // Circular increment
        queue->data[queue->rear] = value;
        printf("Queue Inserted: %d \n", value);
    }
}


void delete_Queue(struct Queue* queue) {
    if (isEmpty_Queue(queue)) {
        printf("Queue underflow. So delete operation can not working.\n");
    } else {
        int deletedValue = queue->data[queue->front];
        printf("Queue Deleted: %d\n", deletedValue);

        if (queue->front == queue->rear) {

            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
    }
}


void display_Queue(struct Queue* queue) {
    if (isEmpty_Queue(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        int i = queue->front;
        do {
            printf("%d ", queue->data[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}



//## BST

// create BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// new Node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//
struct Node* insert_BST(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert_BST(root->left, value);
    } else if (value > root->data) {
        root->right = insert_BST(root->right, value);
    }

    return root;
}


struct Node* findMin_BST(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a value from the BST
struct Node* deleteNode_BST(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode_BST(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode_BST(root->right, value);
    } else {

        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }


        struct Node* temp = findMin_BST(root->right);
        root->data = temp->data;
        root->right = deleteNode_BST(root->right, temp->data);
    }

    return root;
}

// Inorder Traversal
void display_BST(struct Node* root) {
    if (root != NULL) {
        display_BST(root->left);
        printf("%d ", root->data);
        display_BST(root->right);
    }
}



void main(){

interface();

      int num,value,oldValue,newValue;

      int arr[MAX_SIZE];
      int size = 0;

       struct Stack stack;
    initialize_Stack(&stack);

    struct Queue queue;
    initialize_Queue(&queue);

     struct Node* root = NULL;


      printf("\n\t\t1.LinkList\n");
      printf("\t\t2.Array\n");
      printf("\t\t3.Stack\n");
      printf("\t\t4.Queue\n");
      printf("\t\t5.BST\n");
      printf("\t\t6.Exit\n\n");

      while(1)
      {

      printf("\t\nEnter a topic number: ");
      scanf("%d",&num);


  switch(num){

  //LinkedList:

  case 1:


      printf("\n\t\t\t\tAll LinkList Operation\n");
      printf("\n\t\t\t\t\t1.Insert_Begin\n");
      printf("\t\t\t\t\t2.Insert_End\n");
      printf("\t\t\t\t\t3.Delete_Begin\n");
      printf("\t\t\t\t\t4.Delete_End\n");
      printf("\t\t\t\t\t5.Search\n");
      printf("\t\t\t\t\t6.Update\n");
      printf("\t\t\t\t\t7.Exit\n");

    while(1)
      {


      printf("\n\t\t\t\tEnter a number: ");
      scanf("%d",&num);
      switch(num){

   case 1:
       printf("Enter the value to insert in the LinkedList : ");
                scanf("%d",&value);
                insert_begin_linkedList(value);
                display_LinkedList();
                break;

    case 2:
      printf("Enter the value to insert in the LinkedList: ");
                scanf("%d",&value);
                insert_end_LinkedList(value);
                display_LinkedList();
                break;

    case 3:
       delete_begin_LinkedList();
       display_LinkedList();
       break;

    case 4:
       delete_end_LinkedList();
        display_LinkedList();
        break;

    case 5:

    printf("Enter the value to search in the linked list: ");
    scanf("%d", &value);
    int result = searchValue_LinkedList(head,value);
    if (result != -1) {
        printf("Value %d found and position number %d.\n", value, result);
    } else {
        printf("Value %d not found in the linked list.\n", value);
    }

    break;

    case 6:
          printf("Enter the value to update: ");
                scanf("%d", &oldValue);
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                updateValue_LinkedList(head, oldValue, newValue);
                display_LinkedList();
                break;
    case 7:
        printf("Exit the LinkedList Operation\n");
          exit(0);

    default:
        printf("\n\tNot Required\n");

      }
      }

      break;


//Array:

  case 2:

      printf("\n\t\t\t\tAll Array Operation\n");
      printf("\n\t\t\t\t\t1.Insert\n");
      printf("\t\t\t\t\t2.Search\n");
      printf("\t\t\t\t\t3.Update\n");
      printf("\t\t\t\t\t4.Delete\n");
      printf("\t\t\t\t\t5.Exit\n");



      while(1)
      {


      printf("\n\t\t\t\tEnter a number: ");
      scanf("%d",&num);
      switch(num){

   case 1:
        if (size < MAX_SIZE) {
                    printf("Enter a value to insert in the array: ");
                    scanf("%d", &value);
                    arr[size++] = value;
                    printf("Array Inserted: %d \n", value);
                } else {
                    printf("Array is full. Cannot insert more elements.\n");
                }

                    display_Array(arr, size);


      break;

    case 2:
        if (size > 0) {
                    printf("Enter a value to search in the array: ");
                    scanf("%d", &value);
                    int result = searchValue_Array(arr, size, value);
                    if (result != -1) {
                        printf("Value %d found and position number %d.\n", value, result);
                    } else {
                        printf("Value %d not found in the array.\n", value);
                    }
                } else {
                    printf("Array is empty. So search operation can not working.\n");
                }
      break;

    case 3:
       if (size > 0) {
                    printf("Enter the value to update: ");
                    scanf("%d", &oldValue);
                    printf("Enter the new value: ");
                    scanf("%d", &newValue);
                    updateValue_Array(arr, size, oldValue, newValue);
                    printf("Value %d updated to %d.\n", oldValue, newValue);
                } else {
                    printf("Array is empty. So update operation can not working.\n");
                }

                    display_Array(arr, size);

      break;

    case 4:
      if (size > 0) {
                    printf("Enter a value to delete from the array: ");
                    scanf("%d", &value);
                    deleteValue_Array(arr, &size, value);
                } else {
                    printf("Array is empty. So delete operation can not working.\n");
                }
                 if (size > 0) {
                    display_Array(arr, size);
                } else {
                    printf("Array is empty.\n");
                }

      break;

    case 5:
        printf("Exit the Array Operation\n");
          exit(0);
        break;

    default:
        printf("\n\tNot Required\n");

      }

      }

      break;




// Satck:

    case 3:

      printf("\n\t\t\t\tAll Stack Operation\n");
      printf("\n\t\t\t\t\t1.Push\n");
      printf("\t\t\t\t\t2.Pop\n");
      printf("\t\t\t\t\t3.Exit\n");


      while(1)
      {


      printf("\n\t\t\t\tEnter a number: ");
      scanf("%d",&num);
      switch(num){

   case 1:
                printf("Enter a value to push in the Stack : ");
                scanf("%d", &value);
                push_Stack(&stack, value);
                display_Stack(&stack);

                break;

    case 2:

       pop_Stack(&stack);
       display_Stack(&stack);
      break;


    case 3:
       printf("Exit the Stack Operation\n");
          exit(0);

      break;

    default:
        printf("\n\tNot Required\n");

      }
      }

      break;


// Queue:
    case 4:

      printf("\n\t\t\t\tAll Queue Operation\n");
      printf("\n\t\t\t\t\t1.Insert\n");
      printf("\t\t\t\t\t2.Delete\n");
      printf("\t\t\t\t\t3.Exit\n");


      while(1)
      {


      printf("\n\t\t\t\tEnter a number: ");
      scanf("%d",&num);
      switch(num){

   case 1:

       printf("Enter a value to insert in the queue: ");
                scanf("%d", &value);
                insert_Queue(&queue, value);
                display_Queue(&queue);

      break;

    case 2:

        delete_Queue(&queue);
        display_Queue(&queue);
        break;

    case 3:
      printf("Exit the Queue Operation\n");
          exit(0);


      break;


    default:
        printf("\n\tNot Required\n");

      }
      }

      break;


// BST:
    case 5:

      printf("\n\t\t\t\tAll BST Operation\n");
      printf("\n\t\t\t\t\t1.Insert\n");
      printf("\t\t\t\t\t2.Delete\n");
      printf("\t\t\t\t\t3.Exit\n");

      while(1)
      {



      printf("\n\t\t\t\tEnter a number: ");
      scanf("%d",&num);
      switch(num){

   case 1:
                printf("Enter a value to insert in the BST: ");
                scanf("%d", &value);
                root = insert_BST(root, value);
                 printf("BST: ");
                display_BST(root);

      break;

    case 2:
                printf("Enter a value to delete from the BST: ");
                scanf("%d", &value);
                root = deleteNode_BST(root, value);
                 printf("BST: ");
                display_BST(root);

      break;

    case 3:
       printf("Exit the BST Operation\n");
          exit(0);

      break;


    default:
        printf("\n\tNot Required\n");

      }
      }

      break;


    case 6:
        exit(0);


    default:
        printf("\n\tNot Required\n");
  }

  }

return 0;

}
