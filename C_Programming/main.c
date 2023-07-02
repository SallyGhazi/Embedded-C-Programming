#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;
typedef struct node
{
  Item element;
  struct node *next;
} Node;

typedef struct
{
  Node *start; // pointer to the node at the beginning of the row (it would be the first node in the linked list)
  Node *end;   // pointer to the node that is at the end of the row (it would be the last node in the linked list)
} Row;

/*Initialize a row, making the start and end points to NULL*/
void createRow(Row *row)
{
  row->start = NULL;
  row->end = NULL;
}

/*Create a node and return its address*/
Node *createNode(Item element)
{
  Node *t;
  t = (Node *)malloc(sizeof(Node));
  t->element = element;
  t->next = NULL;
  return t;
}

/*Returns 1 if the row is empty, and 0 otherwise*/
int emptyRow(Row row)
{
  return row.start == NULL;
}

/*"Insert a new element to the row (at the end, which would be
the end of the linked list)*/

/// @brief
/// @param row
/// @param input
void insert(Row *row, Item input)
{
  Node *a;
  a = createNode(input);
  if (emptyRow(*row)) // The start must also be modified
    row->start = a;
  else
    row->end->next = a;
  row->end = a; // It will be the "new last element" of the list
}

/// @brief
/// @param row
void deleteFirstNode(Row *row)
{
  if (!emptyRow(*row))
  {
    Node *f;
    f = row->start;
    row->start = f->next;
    free(f);
  }
}

/* Returns the item at the start of the row, taking it out of the row */

/// @brief
/// @param row
/// @return
Item remove_t(Row *row)
{
  if (emptyRow(*row))
  {
    puts("Underflow");
    exit(1);
  }
  Item temp = row->start->element;
  deleteFirstNode(row);
  return temp;
}
/// @brief
/// @param row
/// @return
Item front(Row row)
{
  if (emptyRow(row))
  {
    puts("Underflow");
    exit(1);
  }
  return row.start->element;
}

/*"Cleans" a row, freeing up the space occupied by the elements*/

/// @brief
/// @param row
void clearRow(Row *row)
{
  while (!emptyRow(*row))
  {
    deleteFirstNode(row);
  }
}
/*Returns the number of elements stored in the row*/

/// @brief
/// @param row
/// @return
int rowSize(Row row)
{
  Node *actual;
  int cantElementos = 0;
  for (actual = row.start; actual != NULL; actual = actual->next)
    cantElementos++;
  return cantElementos;
}

/// @brief
/// @param
/// @return
int main(void)
{
  Row row; // the idea is that it only has non-repeating characters
  createRow(&row);
  char letter, str[1000];
  strcpy(str, "aabc");
  strcpy(str, "abdaccbadeefzxxf");

  int i, pos, n;
  n = 'z' - 'a' + 1;
  int frequencies[n];
  // count the number of occurrences of each letter
  for (i = 0; i < n; i++)
    frequencies[i] = 0; // initialization
  for (i = 0; str[i] != '\0'; i++)
    printf("%c ", str[i]);
  printf("\n"); // original str
  for (i = 0; str[i] != '\0'; i++)
  {
    /* code */
    letter = str[i];
    if (frequencies[letter - 'a'] == 0)
      insert(&row, letter);      // insert the letter
    frequencies[letter - 'a']++; // increment the respective position in the alphabet
    // find the first non-repeating character
    while (!emptyRow(row))
    {
      /* code */
      if (frequencies[front(row) - 'a'] > 1)
      {
        /* code */
        // if the character is repeated, we remove it
        remove_t(&row);
      }
      else
      {
        printf("%c ", front(row));
        break;
      }
    }

    if (emptyRow(row))
    {
      printf("%d ", -1);
    }
  }

  printf("\n");
  return 0;
}
