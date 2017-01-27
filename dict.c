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
    dictionary *d = malloc(sizeof(dictionary));
    if (d)
    {
        d->root=NULL;
        return d;
    } else {
        printf("Couldn't allocate dictionary");
        abort(); // Programmabbruch
    }
}

void dict_put(dictionary *dict, char *key, char *value)
{
    if(!dict->root){
        treenode *n=malloc(sizeof(treenode));
        n->key = malloc(sizeof(char)*strlen(key));
        for(int i = 0;i<strlen(key);i++){
            *(n->key+i)=*(key+i);
        }
        n->value = malloc(sizeof(char)*strlen(value));
        for(int i = 0;i<strlen(value);i++){
            *(n->value+i)=*(value+i);
        }
        dict->root=n;
        return;
    }else{
    if(strcmp(key,dict->root->key)==0){
        dict->root->value = malloc(sizeof(char)*strlen(value));
        for(int i = 0;i<strlen(value);i++){
            *(dict->root->value+i)=*(value+i);
        }
        return;
    }
    if(strcmp(key,dict->root->key)>0){
        if(!(dict->root->right)){
            treenode *n=malloc(sizeof(treenode));
            n->key = malloc(sizeof(char)*strlen(key));
            for(int i = 0;i<strlen(key);i++){
                *(n->key+i)=*(key+i);
            }
            n->value = malloc(sizeof(char)*strlen(value));
            for(int i = 0;i<strlen(value);i++){
                *(n->value+i)=*(value+i);
            }
            dict->root->right = n;
        } else {
            dictionary *d = dict_new();
            d->root = dict->root->right;
            dict_put(d,key,value);
        }
        
    }
    if(strcmp(key,dict->root->key)<0){
        if(!(dict->root->left)){
            treenode *n=malloc(sizeof(treenode));
            n->key = malloc(sizeof(char)*strlen(key));
            for(int i = 0;i<strlen(key);i++){
                *(n->key+i)=*(key+i);
            }
            n->value = malloc(sizeof(char)*strlen(value));
            for(int i = 0;i<strlen(value);i++){
                *(n->value+i)=*(value+i);
            }
            dict->root->left = n;
        } else {
            dictionary *d = dict_new();
            d->root = dict->root->left;
            dict_put(d,key,value);
        }
    }
    }
}

char *dict_get(dictionary *dict, char *key)
{
    if(strcmp(key,dict->root->key)==0){
        return dict->root->value;
    }
    if(strcmp(key,dict->root->key)>0){
        if(dict->root->right==NULL){
            return NULL;
        } else {
            dictionary *d = dict_new();
            d->root = dict->root->right;
            return dict_get(d,key);
        }
        
    }
    if(strcmp(key,dict->root->key)<0){
        if(dict->root->left==NULL){
            return NULL;
        } else {
            dictionary *d = dict_new();
            d->root = dict->root->left;
            return dict_get(d,key);
        }
    }
    return NULL;
}
void dict_free_r(treenode *t_node) {
    if(t_node->right){
        dict_free_r(t_node->right);
    }
    if(t_node->left) {
        dict_free_r(t_node->left);
    }
    free(t_node->value);
    free(t_node->key);
    free(t_node);
}
void dict_free(dictionary *dict)
{
    dict_free_r(dict->root);
    free(dict);
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
    for(int i = 0;i<10;i++)
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
    printf("Geschafft");
}