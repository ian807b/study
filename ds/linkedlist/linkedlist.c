#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node* next;
} node;

node* createList(node* head);
void displayList(node* head);
void countNodes(node* head);
void search(node* head, int data);
node* insertInBeginning(node* head, int data);
void insertAtEnd(node* head, int data);
void insertAfter(node* head, int data, int x);
node* insertBefore(node* head, int data, int x);
node* insertAtPosition(node* head, int data, int k);
node* deleteNode(node* head, int data);
node* reverseList(node* head);

node* createList(node* head) {
  int i, n, data;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  if (n == 0) {
    return head;
  }
  printf("Enter the element #1 to be inserted: ");
  scanf("%d", &data);
  head = insertInBeginning(head, data);

  for (i = 1; i < n; i++) {
    printf("Enter the element #%d to be inserted: ", i + 1);
    scanf("%d", &data);
    insertAtEnd(head, data);
  }

  return head;
}

void displayList(node* head) {
  if (head == NULL) {
    printf("List is empty \n");
    return;
  }
  printf("List is: ");
  node* p = head;
  while (p != NULL) {
    printf("%d ", p->key);
    p = p->next;
  }
  printf("\n");
}

void countNodes(node* head) {
  node* p = head;
  int count = 0;

  while (p != NULL) {
    p = p->next;
    count++;
  }
  printf("Number of nodes = %d \n", count);
}

void search(node* head, int data) {
  node* p = head;
  int position = 1;

  while (p != NULL) {
    if (p->key == data) {
      break;
    }
    position++;
    p = p->next;
  }

  if (p == NULL) {
    printf("%d not found in the list \n", data);
  } else {
    printf("%d is at position %d \n", data, position);
  }
}

node* insertInBeginning(node* head, int data) {
  node* temp = (node*)malloc(sizeof(node));
  temp->key = data;
  temp->next = head;
  head = temp;

  return head;
}

void insertAtEnd(node* head, int data) {
  node* temp = (node*)malloc(sizeof(node));
  temp->key = data;
  node* p = head;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = temp;
  temp->next = NULL;
}

void insertAfter(node* head, int data, int x) {
  node *p, *temp;

  while (p != NULL) {
    if (p->key == x) {
      break;
      p = p->next;
    }
  }
  if (p == NULL) {
    printf("%d not present in the list \n", x);
  } else {
    temp = (node*)malloc(sizeof(node));
    temp->key = data;
    temp->next = p->next;
    p->next = temp;
  }
}

node* insertBefore(node* head, int data, int x) {
  node *p, *temp;
  p = head;

  if (head == NULL) {
    printf("List is empty \n");
  }
  if (x == head->key) {
    temp = (node*)malloc(sizeof(node));
    temp->key = data;
    temp->next = head;
    head = temp;
    return head;
  }
  p = head;
  while (p->next != NULL) {
    if (p->next->key == x) {
      break;
    }
    p = p->next;
  }

  if (p->next == NULL) {
    printf("%d not present in the list \n", x);
  } else {
    temp = (node*)malloc(sizeof(node));
    temp->key = data;
    temp->next = p->next;
    p->next = temp;
  }

  return head;
}

node* insertAtPosition(node* head, int data, int k) {
  node *temp, *p;
  int i;
  if (k == 1) {
    temp = (node*)malloc(sizeof(node));
    temp->key = data;
    temp->next = head;
    head = temp;
    return head;
  }

  p = head;
  for (i = 1; i < k - 1 && p != NULL; i++) {
    p = p->next;
  }
  if (p == NULL)
    printf("You can insert only upto %dth position\n\n", i);
  else {
    temp = (node*)malloc(sizeof(node));
    temp->key = data;
    temp->next = p->next;
    p->next = temp;
  }
  return head;
}

node* deleteNode(node* head, int data) {
  node *temp, *p;
  if (head == NULL) {
    printf("List is empty\n");
    return head;
  }
  if (head->key == data) {
    temp = head;
    head = head->next;
    free(temp);
    return head;
  }

  p = head;
  while (p->next != NULL) {
    if (p->next->key == data) break;
    p = p->next;
  }

  if (p->next == NULL)
    printf("Element %d not in list\n\n", data);
  else {
    temp = p->next;
    p->next = temp->next;
    free(temp);
  }
  return head;
}

node* reverseList(node* head) {
  node *prev, *ptr, *next;
  prev = NULL;
  ptr = head;
  while (ptr != NULL) {
    next = ptr->next;
    ptr->next = prev;
    prev = ptr;
    ptr = next;
  }
  head = prev;
  return head;
}

int main() {
  node* head = NULL;
  int choice, data, x, k;

  head = createList(head);

  while (1) {
    printf("\n");
    printf("1.  Display list\n");
    printf("2.  Count the number of nodes\n");
    printf("3.  Search for an element\n");
    printf("4.  Add to empty list / Add at beginning\n");
    printf("5.  Add a node at end of the list\n");
    printf("6.  Add a node after a specified node\n");
    printf("7.  Add a node before a specified node\n");
    printf("8.  Add a node at a given position\n");
    printf("9.  Delete a node\n");
    printf("10. Reverse the list\n");
    printf("11. Quit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 11) break;

    switch (choice) {
      case 1:
        displayList(head);
        break;
      case 2:
        countNodes(head);
        break;
      case 3:
        printf("Enter the element to be searched: ");
        scanf("%d", &data);
        search(head, data);
        break;
      case 4:
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        head = insertInBeginning(head, data);
        break;
      case 5:
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        insertAtEnd(head, data);
        break;
      case 6:
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        printf("Enter the element after which to insert: ");
        scanf("%d", &x);
        insertAfter(head, data, x);
        break;
      case 7:
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        printf("Enter the element before which to insert: ");
        scanf("%d", &x);
        head = insertBefore(head, data, x);
        break;
      case 8:
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        printf("Enter the position at which to insert: ");
        scanf("%d", &k);
        head = insertAtPosition(head, data, k);
        break;
      case 9:
        printf("Enter the element to be deleted: ");
        scanf("%d", &data);
        head = deleteNode(head, data);
        break;
      case 10:
        head = reverseList(head);
        break;
      default:
        printf("Wrong choice\n");
    }
  }
}
