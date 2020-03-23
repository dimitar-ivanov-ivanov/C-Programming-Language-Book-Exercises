#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int menu(void);
void display(int i);
void author_search(void);
void title_search(void);
void enter(void);
void save(void);
void load(void);

struct catalog {
    char name[80]; //author name
    char title[80]; //title
    char pub[80]; //publisher
    unsigned date;
    unsigned char ed; //edition
} cat[MAX];

int top = 0;

int main() {
    int choice;
    load();

    do {
        choice = menu();
        switch(choice) {
        case 1:
            enter();
            break;
        case 2:
            author_search();
            break;
        case 3:
            title_search();
            break;
        case 4:
            save();
            break;
        }
    } while(choice != 5);

    return 0;
}

int menu(void) {
    int i;
    char str[80];

    //Display options
    printf("Card catalog:\n");
    printf("  1.Enter\n");
    printf("  2.Search by author\n");
    printf("  3.Search by title\n");
    printf("  4.Save catalog\n");
    printf("  5.Quit\n");

    //Get option
    do {
        printf("Choose your selection: ");
        gets(str);
        i = atoi(str);
        printf("\n");
    } while(i< 1 || i > 5);

    return i;
}

void enter(void) {

    int i;
    char temp[80];

    for(i=top; i<MAX; i++) {
        printf("Enter author name (ENTER to quit): ");
        gets(cat[i].name);
        if(!*cat[i].name)
            break;

        printf("Enter tittle: ");
        gets(cat[i].title);
        printf("Enter publisher: ");
        gets(cat[i].pub);
        printf("Enter copyright date: ");
        gets(temp);
        cat[i].date = (unsigned)atoi(temp);
        printf("Enter edition: \n");
        gets(temp);
        cat[i].ed = (unsigned char)atoi(temp);
    }

    top = i;
}

void author_search(void) {
    char name[80];
    int i,found;

    printf("Name: ");
    gets(name);

    found = 0;
    for(i = 0; i < top; i++) {
        if(!strcmp(name,cat[i].name)) {
            display(i);
            found = 1;
            printf("\n");
        }
    }
    if(!found)
        printf("Not found\n");
}

void title_search(void) {
    char title[80];
    int i,found;

    printf("Title: ");
    gets(title);

    found = 0;
    for(i = 0; i <top; i++) {
        if(!strcmp(title,cat[i].title)) {
            display(i);
            found = 1;
            printf("\n");
        }
    }
    if(!found)
        printf("Not found\n");
}

void display(int i) {
    printf("%s\n",cat[i].title);
    printf("by %s\n",cat[i].name);
    printf("Published by %s\n",cat[i].pub);
    printf("Copyright: %u, %u edition",cat[i].date,cat[i].ed);
}

void load(void) {
    FILE *fp;

    if((fp = fopen("catalog","rb")) == NULL) {
        printf("Catalog file not on disk.\n");
        exit(1);
    }
    //count of data
    if(fread(&top,sizeof(top),1,fp) != 1) {
        printf("Error reading count\n");
        exit(1);
    }

    for(int i=0; i<=top; i++) {
        if(fread(&cat[i],sizeof(struct catalog),1,fp) !=1) {
            printf("Error reading catalog data.\n");
            exit(1);
        }
    }

    if(fclose(fp) == EOF) {
        printf("Error trying to close file.\n");
        exit(1);
    }
}

void save(void) {
    FILE *fp;

    if((fp = fopen("catalog","wb")) == NULL) {
        printf("Cannot open catalogue file.\n");
        return;
    }
    if(fwrite(&top,sizeof(top),1,fp) != 1) {
        printf("Error writing count.\n");
        exit(1);
    }
    if(fwrite(cat,sizeof(cat),1,fp) != 1) {
        printf("Error writing catalogue data.\n");
        exit(1);
    }

    fclose(fp);
}
