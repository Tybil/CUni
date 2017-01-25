#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treenode
{
    char *key;
    char *value;
    struct treenode *left;
    struct treenode *right;
} treenode;

typedef struct dictionary
{
    treenode *root;
} dictionary;

dictionary *dict_new()
{
    dictionary *d = calloc(1, sizeof(dictionary));
    if (d)
    {
        return d;
    } else {
        printf("Couldn't allocate dictionary");
        abort(); // Programmabbruch
    }
}

void dict_put(dictionary *dict, char *key, char *value)
{
    // Aufgabe b)
}

char *dict_get(dictionary *dict, char *key)
{
    // Aufgabe c)
    return NULL;
}

void dict_free(dictionary *dict)
{
    // Aufgabe d)
}

void dict_delete(dictionary *dict, char *key)
{
    // Aufgabe e)
}
////enddelete)

int main(void)
{
    dictionary *dict = dict_new();
    int bufferSize = 2048;
    char buffer[bufferSize];
    while (true)
    {
        char *s = fgets(buffer, bufferSize, stdin);
        if (s == NULL)
        {
            break;
        }

        char *newlineChar = strchr(s, '\n');
        if (newlineChar)
        {
            *newlineChar = '\0';
        }

        char *firstSpace = strchr(s, ' ');
        if (firstSpace == NULL)
        {
            printf("missing key\n");
            continue;
        }
        *firstSpace = '\0';
        char *key = firstSpace + 1;

        if (strcmp("put", s) == 0)
        {
            char *secondSpace = strchr(key, ' ');
            if (secondSpace == NULL)
            {
                printf("missing value\n");
                continue;
            }
            *secondSpace = '\0';
            char *val = secondSpace + 1;
            dict_put(dict, key, val);
        }
        else if (strcmp("get", s) == 0)
        {
            char *val = dict_get(dict, key);
            printf("%s\n", val);
        }
        else if (strcmp("del", s) == 0)
        {
            dict_delete(dict, key);
        }
        else
        {
            printf("unknown command %s\n", s);
        }
    }
    dict_free(dict);
}