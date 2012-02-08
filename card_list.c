#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 20
#define PHONE_SIZE 20
#define COM_SIZE 20
#define ALL_SIZE (NAME_SIZE + PHONE_SIZE + COM_SIZE)

typedef struct _card{
    char phone[PHONE_SIZE];
    char name[NAME_SIZE];
    char com[COM_SIZE];
    struct _card * next;
}card;

card * head, *tail;

void init(){
    head = (card*)malloc(sizeof(card));
    tail = (card*)malloc(sizeof(card));
    head -> next = tail;
    tail -> next = tail;
}

void insert_after(void){
    card * insert = (card*)malloc(sizeof(card));
    printf("please input name : ");
    scanf("%s",insert -> name); 
    printf("please input phone number : ");
    scanf("%s",insert -> phone);
    printf("please input company name : ");
    scanf("%s",insert -> com);
    insert -> next = head -> next;
    head -> next = insert;
}

int user_input(void){
    int i;
    printf("========= Member card list =========\n");
    printf("1: Insert member\n");
    printf("2: Delete member\n");
    printf("3: Find member\n");
    printf("4: Show member\n");
    printf("5: Save member\n");
    printf("6: Load member\n");
    printf("7: End\n");        
    printf("====================================\n");
    do{
	printf("please insert your action number\n");
	scanf("%d", &i);
    }
    while(i < 1 && i > 7);
    return i;
}

void delete_card(char * name){
    card * killer;
    card * scout;
    killer = head;
    scout = killer -> next;
    while(strcmp(name, scout -> name) && scout != tail)
    {
	killer = killer -> next;
	scout = killer -> next;
    }
    if (scout != tail){
	printf("%s is killed\n\n", scout -> name);
	killer -> next = scout -> next;
	free(scout);
    }
}

void find_card(char * name){
    card * finder;
    finder = head -> next;
    while(strcmp(name, finder -> name) && finder != tail){
	finder = finder -> next;
    }
    printf("\n\nname : %s, phone : %s, company : %s\n\n\n",finder -> name, finder -> phone, finder -> com);
}

void print_list(void){
    card * viewer = head->next;
    while(viewer != tail){
	printf("name : %s, phone : %s, company : %s\n",viewer -> name, viewer -> phone, viewer -> com);
	viewer = viewer -> next;
    }
    printf("\n\n");
}

void save_list(char * file){
    card * writer;
    FILE * fp;
    if((fp = fopen(file, "wp")) == NULL){
	printf("\n Error: Write failure");
	return;
    }
    writer = head -> next;
    while(writer != tail){
	fwrite(writer, ALL_SIZE, 1, fp);
	writer = writer -> next;
    }
    fclose(fp);
}

void load_list(char * file){
    card * reader;
    card * dummy;
    FILE * fp;
    if((fp = fopen(file, "rb")) == NULL){
	printf("Error: Read failure");
	return;
    }
    reader = head -> next;
    while(reader != tail){
	dummy = reader;
	reader = reader -> next;
	free(dummy);
    }
    head -> next = tail;
    while(1){
	reader = (card*)malloc(sizeof(card));
	if(!fread(reader, ALL_SIZE, 1, fp)){
	    free(reader);
	    break;
	}
	reader -> next = head -> next;
	head -> next = reader;
    }
    fclose(fp);
}


int main (void){
    char name[NAME_SIZE];
    char * file = "card.text";
    init();
    int i = 0;
    while((i = user_input()) != 7){
	switch(i){
	case 1 :
	    insert_after();
	    break;
	case 2 :
    	    printf("please insert name which you want to delete : ");
    	    scanf("%s", name);
    	    delete_card(name);
    	    break;
	case 3 :
    	    printf("please insert name which you want to find : ");
    	    scanf("%s", name);
	    find_card(name);
	    break;
	case 4 :
	    print_list();
	    break;
	case 5 :
	    save_list(file);
	    break;
	case 6 :
	    load_list(file);
	    break;
	}	
    }
    printf("\n\nprogram end\n\n");
    return 0;
}
