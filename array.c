#include<ncurses.h>
#define SIZE 100

int length_of_no(int n){
	int i=0,t=0;
	if(n<0) t=1;
	do{
		n=n/10;
		i++;
	}while(n!=0);
	return i+t;
}

void display(int *a){
	int i,j,l=length(a),l_no;
	//printw("The Given array is :\n\n");
	printw("\n");
	if(l){
		for(i=0;i<l;i++){
			printw(" ");
			l_no=length_of_no(a[i]);
			for(j=0;j<l_no+2;j++){
				printw("_");
			}
		}
		printw("\n");
		for(i=0;i<l;i++){
			printw("|");
			l_no=length_of_no(a[i]);
			for(j=0;j<l_no+2;j++){
				printw(" ");
			}
		}
		printw("|\n");
		for(i=0;i<l;i++){
			printw("| %d ",a[i]);
		}
		printw("|\n");
		for(i=0;i<l;i++){
			printw("|");
			l_no=length_of_no(a[i]);
			for(j=0;j<l_no+2;j++){
				printw("_");
			}
		}
		printw("|\n");
	}
}
int length(int *a){
	int i=0;
	while(a[i]!='\0'){
		i++;
	}
	return i;
}
void get_array(int *a, int s){
	int i;
	printw("Start Typing the array :\n");
	refresh();
	for(i=0;i<s;i++){
		scanw("%d",&a[i]);
	}
}
void insert(int *a, int pos, int data){
	int l;
	l=length(a);
	for(;pos-1!=l;l--){
		a[l]=a[l-1];
	}
	a[pos-1]=data;
}
void delete(int *a, int pos){
	int l=length(a);
	while(pos<=l){
		a[pos-1]=a[pos];
		pos++;
	}
}
void search(int *a, int data){
	int i,f=0,l=length(a);
	for (i=0;i<l;i++){
		if(a[i]==data){
			printw("Found at position %d",i+1);
			f=1;
		}
	}
	if(!f) printw("Not Found");
	refresh();
}
void clean(int *a){
	int i;
	for(i=0;i<SIZE;i++){
		a[i]='\0';
	}
}
void menu(){
	printw("\nThe Options available are : \n");
	printw("\tA: Initialize given array.\n");
	printw("\tI: Insert an element at given pos.\n");
	printw("\tD: Delete an element at given pos.\n");
	printw("\tS: Search a specific element.\n");
	printw("\tP: Print the array.\n");
	printw("\tL: Length of given array.\n");
	printw("\tC: Clear the given array.\n");
	printw("\tQ: Quit.\n");
	printw("\nEnter Option : ");
}
int main(){
	static int a[SIZE];
	int size,pos,data;
	char opt;
	initscr();
	cbreak();
	while(1){
		clear();
		display(a);
		menu();
		refresh();
		opt=getch();
		switch (opt){
			case 'a':
			case 'A':	printw("\nEnter Size : ");
						refresh();
						scanw("%d",&size);
						get_array(a,size);
						printw("\nCompleted!\n");
						refresh();
						break;
			case 'i':
			case 'I':	printw("\nEnter position and data : ");
						refresh();
						scanw("%d %d",&pos,&data);
						insert(a,pos,data);
						printw("\nCompleted!\n");
						refresh();
						break;
			case 'd':
			case 'D':	printw("\nEnter position to be deleted : ");
						refresh();
						scanw("%d",&pos);
						delete(a,pos);
						printw("\nCompleted!\n");
						refresh();
						break;
			case 's':
			case 'S':	printw("\nEnter no. to be searched : ");
						refresh();
						scanw("%d",&data);
						search(a,data);
						printw("\nCompleted!\n");
						refresh();
						getch();
						break;
			case 'p':
			case 'P':	display(a);
						refresh();
						getch();
						break;
			case 'l':
			case 'L':	printw("\nThe length of the given array is %d\n",length(a));
						refresh();
						getch();
						break;
			case 'c':
			case 'C':	clean(a);
						printw("\nCompleted!\n");
						refresh();
						break;
			case 'q':
			case 'Q':	endwin();
						return 0;
			default	:	printw("\n");
						refresh();
						break;
		}
	}
	
	endwin();
}
