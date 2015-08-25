#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int length_of_no(int n){				//Finds length of a no.
	int i=0,t=0;
	if(n<0) t=1;
	do{
		n=n/10;
		i++;
	}while(n!=0);
	return i+t;
}

int length(int *a){						//Finds length of an array
	int i=0;
	while(a[i]!='\0'){
		i++;
	}
	return i;
}

void display(int *a){					//Displays the array
	int i,j,l=length(a),l_no;
	//printf("The Given array is :\n\n");
	printf("\n");
	if(l){
		for(i=0;i<l;i++){
			printf(" ");
			l_no=length_of_no(a[i]);
			for(j=0;j<l_no+2;j++){
				printf("_");
			}
		}
		printf("\n");
		for(i=0;i<l;i++){
			printf("|");
			l_no=length_of_no(a[i]);
			for(j=0;j<l_no+2;j++){
				printf(" ");
			}
		}
		printf("|\n");
		for(i=0;i<l;i++){
			printf("| %d ",a[i]);
		}
		printf("|\n");
		for(i=0;i<l;i++){
			printf("|");
			l_no=length_of_no(a[i]);
			for(j=0;j<l_no+2;j++){
				printf("_");
			}
		}
		printf("|\n");
	}
}

void get_array(int *a, int s){			//Initializes an array
	int i;
	printf("Start Typing the array :\n");
	for(i=0;i<s;i++){
		scanf("%d",&a[i]);
	}
}

void insert(int *a, int pos, int data){	//Insert an element in array
	int l;
	l=length(a);
	for(;pos-1!=l;l--){
		a[l]=a[l-1];
	}
	a[pos-1]=data;
}

void delete(int *a, int pos){			//Delete an element from array
	int l=length(a);
	while(pos<=l){
		a[pos-1]=a[pos];
		pos++;
	}
}

void search(int *a, int data){			//Search an element in array
	int i,f=0,l=length(a);
	for (i=0;i<l;i++){
		if(a[i]==data){
			printf("Found at position %d",i+1);
			f=1;
		}
	}
	if(!f) printf("Not Found");
}

void clean(int *a){						//Cleans the array
	int i;
	for(i=0;i<SIZE;i++){
		a[i]='\0';
	}
}

void menu(){							//Print the array menu
	printf("\nThe Options available are : \n");
	printf("\t1: Initialize given array.\n");
	printf("\t2: Insert an element at given pos.\n");
	printf("\t3: Delete an element at given pos.\n");
	printf("\t4: Search a specific element.\n");
	printf("\t5: Length of given array.\n");
	printf("\t6: Clear the given array.\n");
	printf("\t9: Quit.\n");
	printf("\nEnter Option : ");
}

void main(){
	static int a[SIZE];
	int size,pos,data,opt,display_length=0,display_search=0;
	
	while(1){							//Infinite Loop untill pressed 'q'
		system("clear");
		display(a);
		if(display_length){
			printf("\nThe length of the given array is %d\n",length(a));
			display_length=0;
		}
		if(display_search){
			search(a,data);
			display_search=0;
		}
		menu();
		scanf("%d",&opt);
		switch (opt){
			case 1:	printf("\nEnter Size : ");
						scanf("%d",&size);
						get_array(a,size);
						printf("\nCompleted!\n");
						break;
			case 2:	printf("\nEnter position and data : ");
						scanf("%d %d",&pos,&data);
						insert(a,pos,data);
						printf("\nCompleted!\n");
						break;
			case 3:	printf("\nEnter position to be deleted : ");
						scanf("%d",&pos);
						delete(a,pos);
						printf("\nCompleted!\n");
						break;
			case 4:	printf("\nEnter no. to be searched : ");
						scanf("%d",&data);
						display_search=1;
						break;
			case 5:	display_length=1;
						break;
			case 6:	clean(a);
						printf("\nCompleted!\n");
						break;
			case 9:	system("clear");
						return;
		}
	}
}
