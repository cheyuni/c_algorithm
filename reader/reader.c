#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 30 -> 기본색 밝은 회색 */
/* 31 -> 밝은 빨강 */
/* 32 -> 녹색 */
/* 33 -> 노랑 */
/* 34 -> 파랑 */
/* 35 -> 연보라 */
/* 36 -> 밝은 파랑 */
/* 37 -> 밝은 흰색 */

typedef struct _line{
    struct _line * prev;
    struct _line * next;
    char * buf;
}line;

line * head, * tail;
int total, now;

void init (void){
    head = (line*)malloc(sizeof(line));
    tail = (line*)malloc(sizeof(line));
    head -> next = tail;
    head -> prev = head;
    tail -> prev = head;
    tail -> next = tail;
}

void load_file(char * file_name){
    FILE * fp;
    char buf[256];
    line * point;

    if((fp = fopen(file_name, "rt")) == NULL){
    	printf("\n Error!! I can't open this file\n");
    	exit(1);
    }

    total = 0;
    printf("\nfile loading ...");
    
    while(!feof(fp)){
	fgets(buf, 255, fp);
	if(strlen(buf) > 80)
	    buf[80] = 0;
	if((point = (line*)malloc(sizeof(line))) == NULL){
	    printf("\nError : Memory overflow");
	    exit(1);
	}
	if((point -> buf = (char*)malloc(strlen(buf))) == NULL){
	    printf("\nError : Memory overflow");
	    exit(1);
	}
	strcpy(point -> buf, buf);
	point -> prev = tail -> prev;
	point -> next = tail;
	tail -> prev -> next = point;
	tail -> prev = point;
	total++;
    }
    printf("\nComplete!!");
    fclose(fp);
}

void move_line(int d, line ** point){


}

void show_page(){
    int i = 0;
    line * viewer = head->next;

    printf("%c[1;33m",27);
    printf("============ cheyuni reader ============ \n\n");    
    while(viewer != tail -> prev){
	printf("%s",viewer -> buf);
	viewer = viewer -> next;
    }
    printf("%c[0m\n",27);      
}

void show_header(){
    

}

int main(int argc, char *argv[]){
    init();
    load_file(argv[1]);
    show_page();
    return 0;
}
