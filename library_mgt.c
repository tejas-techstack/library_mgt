#include<stdio.h>
#include<string.h>

struct book_module {
	char ISBN[10];
	char title[20];
	char author[20];
	char genre[20];
	int quantity;
};


struct member_module {
	char member_ID[10];
	char name[20];
	char address[20];
	int phone_no;
};

struct trans_detail {
	char trans_id[10];
	char member_id[10];
	char ISBN[10];
	char issue_date[10];
	char return_date[10];
};

struct book_module books[100];
struct member_module members[100];
struct trans_detail transactions[100];

int num_books = 0;
int num_members = 0;
int num_transactions = 0; 

int menu();

//Book Module Functions
int book_module();
int add_book();
int update_book();
int delete_book();
int display_book();

//Member Details Functions
int member_module();
int add_member();
int update_member();
int delete_member();
int display_member();

//Transaction Module Functions
int trans_module();
int issue_book();
int return_book();
int display_history();


int main(){
	printf("------------------\n");
	printf("Welcome to Library\n");
	printf("------------------\n");
	
	menu();

	return 0;
}

int menu(){

	char ch;
	
	printf("\n\nMenu:\n");
	printf("   1. Books (b):\n   2. Members (m):\n   3. Transaction (t):\n");
		
	do{	
		printf("\n\nEnter Choice (in main menu):");
		ch = getchar();
		getchar();	
		switch(ch){
			case 'b' : book_module(); break;
			case 'm' : member_module(); break;
			case 't' : trans_module(); break;
			case 'e' : printf("Thank You!\n"); break;
			default: printf("\n###########Enter correct Choice##########\n"); break;
		}	
	}while (ch!='e');



	return 0;
}


int book_module(){
	printf("What do you want to do:\n");

	printf("   1.Add book(a):\n   2.Update book(u):\n   3.Delete book(d):\n   4.Display books(s):\n");

	char ch;

	do {
		
		printf("\nEnter choice (in book module):");
		ch = getchar();
		getchar();
		switch(ch){
			case 'a': add_book(); break;
			case 'u': update_book(); break;
			case 'd': delete_book(); break;
			case 's': display_book(); break;
			case 'e': printf("Going back to menu.....\n"); break;
			default: printf("##########Enter correct Choice##########"); break;
		}

	}while (ch != 'e');
			
	return 0;
}

int add_book(){

	if (num_books == 99) return 1;  

	char ISBN[10];
	char title[20];
	char author[20];
	char genre[20];
	int quantity;
	

	printf("Enter ISBN:");
	scanf("%[^\n]", ISBN); getchar();
	strcpy(books[num_books].ISBN, ISBN);

	printf("Enter Title:");
	scanf("%[^\n]", title); getchar();
	strcpy(books[num_books].title, title);

	printf("Enter author:");
	scanf("%[^\n]", author); getchar();
	strcpy(books[num_books].author, author);

	printf("Enter genre:");
	scanf("%[^\n]", genre); getchar();
	strcpy(books[num_books].genre, genre);

	printf("Enter quantity:");
	scanf("%d", &quantity); getchar();
	books[num_books].quantity = quantity;
	
	num_books++;
	return 0;
}

int update_book(){
	char update_book_isbn[10];
	printf("Enter ISBN of the book to be updated:");
	scanf("%s", update_book_isbn);
	getchar();
	
	for (int i = 0; i < num_books ; i++){
		printf("%d %s %s \n", i, update_book_isbn, books[i].ISBN);
		if (strcmp(update_book_isbn, books[i].ISBN) == 0){				
			printf("Enter Title:");
			scanf("%[^\n]", books[i].title); getchar();

			printf("Enter author:");
			scanf("%[^\n]", books[i].author); getchar();

			printf("Enter genre:");
			scanf("%[^\n]", books[i].genre); getchar();

			printf("Enter quantity:");
			scanf("%d", &books[i].quantity); getchar();
			
			break;	
		}
		else continue;
	}

	return 0;
}

int delete_book(){
	char book_delete[10];
	printf("Enter isbn of book to be deleted:");
	scanf("%s", book_delete);
	getchar();

	for (int i = 0; i < num_books; i++){
		if (strcmp(book_delete, books[i].ISBN) == 0){
			strcpy(books[i].ISBN, "\0");	
			strcpy(books[i].title, "\0");	
			strcpy(books[i].author, "\0");	
			strcpy(books[i].genre, "\0");	
			books[i].quantity = 0;
		}	
	}
	return 0;
}

int display_book(){
	
	printf("ISBN      |title               |author               |genre               |quantity   \n");
	for (int i = 0; i < num_books; i++){

		if (strcmp(books[i].ISBN, "\0") == 0) {
			continue;
		}
	

		printf("%s      |%s               |%s               |%s               |%d   \n", books[i].ISBN, books[i].title, books[i].author, books[i].genre, books[i].quantity);

	}
	return 0;
}


int member_module(){
	return 0;
}

int trans_module(){
	return 0;
}


