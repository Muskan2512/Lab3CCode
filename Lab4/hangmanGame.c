// 2.	Implement hangman game using linked list:
// •  The Letter structure represents each character in the word, storing the letter and whether it has been revealed or hidden.
// •  The Linked List holds each letter of the word, with each node containing a letter and a pointer to the next.
// •  During the Game Loop, the player guesses one letter at a time. If the guessed letter is in the word, the corresponding letters are revealed; if not, the player gets closer to being "hanged."
// •  The Victory Condition is met when the entire word is revealed before the player reaches the maximum number of incorrect guesses.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct Node
{
    char data;
    struct Node *next;
};

char random_Words[][15] = {"Code", "Programming", "Interview", "Placement", "Package", "Job"};
// int len = sizeof(random_Words) / 15;
// this state array will store the current state of the guessed word(like how many correct guess and other)
char state[20];

struct Node *createLList(struct Node *head, char *randWord)
{
    int length = strlen(randWord);
    struct Node *prevNode = NULL;
    int i = 0;
    while (i < length)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = randWord[i];
        newNode->next = NULL;
        if (head == NULL)
        {
            // this is the first letter of the random guessed word.
            head = newNode;
            prevNode = newNode;
        }
        else
        {
            prevNode->next = newNode;
            prevNode = newNode;
        }
        i++;
    }
    return head;
}
void print(struct Node *head)
{
    while (head)
    {
        printf("%c ", head->data);
        head = head->next;
    }
}

void show_Guessed_Word(struct Node *head, char ch, char *randWord)
{
    int len = strlen(randWord);
    for (int i = 0; i < len; i++)
    {
        printf("%c ", state[i]);
    }
}

int check_If_Exists(struct Node *head, char ch)
{
    struct Node *temp = head;
    int index = 0;
    while (temp)
    {
        if (temp->data == ch)
        {
            temp->data=' ';
            state[index] = ch;
            return 1;
        }
        temp = temp->next;
        index++;
    }
    return 0;
}
int checkSame(char *randWord)
{
    int len = strlen(randWord);
    for (int i = 0; i < len; i++)
    {
        if (randWord[i] != state[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    for (int i = 0; i < 20; i++)
    {
        state[i] = '_';
    }
    srand(time(0));
    int random_index = rand() % 6;
    char* randWord = random_Words[random_index];
    int length = strlen(randWord);

    struct Node *head = createLList(NULL, randWord);
    // print(head);
    for(int i=0;i<50;i++)printf("*");
    printf("\nStart Guessing the letters you can make atmost 3 mistakes\n");
    int count = 0;
    while (count < length)
    {
        printf("_ ");
        count++;
    }
    printf("\n");
    int mistakes = 0;
    char ch;
    int correct = 0;
    while (mistakes < 3)
    {
        printf("Guess Letter:");
        scanf(" %c", &ch);
        // check if this ch is in the word.
        int exist = check_If_Exists(head, ch);
        if (exist == 0)
        {
            mistakes++;
            printf("You missed\nYou can make atmost %d more mistakes\n", 3 - mistakes);
        }
        else
        {
            correct++;
        }
        if (correct == strlen(randWord))
        {
            printf("Hurray! You guessed it right");
            return 0;
        }
        show_Guessed_Word(head, ch, randWord);

        printf("\n");
    }

    // u will come out of this loop only when u had not guessed the right word in the max attempts given
    printf("\nYou are Hanged\nThe right Word is:");
    printf("%s", randWord);

    return 0;
}