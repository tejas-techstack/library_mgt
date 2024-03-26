#include<stdio.h>
#include<string.h>

int char_input(char *);

struct book_module {
	char ISBN[10];
	char title[20];
	char author[20];
	char genre[20];
	int quantity;
};


struct member_module {
	char member_id[10];
	char name[20];
	char address[50];
	int phone_no;
};

struct trans_detail {
	int trans_id;
	char member_id[10];
	char ISBN[10];
	char issue_date[10];
	char return_date[10];
};

struct book_module books[100];
struct member_module members[100];
struct trans_detail trans_detail[100];

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
int display_members();

//Transaction Module Functions
int trans_module();
int issue_book();
int return_book();
int display_history();


int main(){
	printf("------------------\n");
	printf("Welcome to Library\n");
	printf("------------------\n");
	

	char temp_Char[2];
	//initiate few starting values for ease of use
	
	for (int i = 0; i < 5; i++){
		temp_Char[0] = '0' + (i+1);
		temp_Char[1] = '\0';
		strcpy(books[i].ISBN, "PESLIB00");
		strcat(books[i].ISBN, temp_Char);
		strcpy(books[i].title,"Book ");
		strcat(books[i].title, temp_Char);
		strcpy(books[i].author, "Author ");
		strcat(books[i].author, temp_Char);
		strcpy(books[i].genre, "Genre ");
		strcat(books[i].genre, temp_Char);
		books[i].quantity = i;
		num_books++;

		strcpy(members[i].member_id, "PESLIM00");
		strcat(members[i].member_id, temp_Char);
		strcpy(members[i].name, "Name ");
		strcat(members[i].name, temp_Char);
		strcpy(members[i].address, "Address ");
		strcat(members[i].address, temp_Char);
		members[i].phone_no = 666000 + i;
		num_members++;
	}



	menu();

	return 0;
}


int char_input(char * ch){
	int i = 0;
	char input_char;
	while((input_char = getchar()) != '\n' && input_char != EOF){
		if (i >= 1) {
			i++;
			continue;
		} 
		*ch = input_char;
		i++;
	}
	if (i > 1 || i == 0) *ch = 'w';
	return 0;
}

int menu(){

	char ch;
	
	printf("\n\nMenu:\n");
	printf("   1. Books (b):\n   2. Members (m):\n   3. Transaction (t):\n");
		
	do{	
		printf("\n\nEnter Choice (in main menu):");
		char_input(&ch);
		switch(ch){
			case 'b' : book_module(); break;
			case 'm' : member_module(); break;
			case 't' : trans_module(); break;
			case 'e' : printf("Thank You!\n"); break;
			case 'w' : printf("\n###########Enter correct Choice##########\n"); break;
			default: break;
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
		char_input(&ch);
		switch(ch){
			case 'a': add_book(); break;
			case 'u': update_book(); break;
			case 'd': delete_book(); break;
			case 's': display_book(); break;
			case 'e': printf("Going back to menu.....\n"); break;
			case 'w':printf("\n###########Enter correct Choice##########\n"); break;
			default: break;
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
	scanf("%[^\n]", books[num_books].ISBN); getchar();

	printf("Enter Title:");
	scanf("%[^\n]", books[num_books].title); getchar();

	printf("Enter author:");
	scanf("%[^\n]", books[num_books].author); getchar();

	printf("Enter genre:");
	scanf("%[^\n]", books[num_books].genre); getchar();

	printf("Enter quantity:");
	scanf("%d", &books[num_books].quantity); getchar();
	
	num_books++;
	return 0;
}

int update_book(){
	char update_book_isbn[10];
	printf("Enter ISBN of the book to be updated:");
	scanf("%s", update_book_isbn);
	getchar();
	
	for (int i = 0; i < num_books ; i++){
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
	
	printf("ISBN      |title               |author              |genre               |quantity   \n");
	for (int i = 0; i < num_books; i++){

		if (strcmp(books[i].ISBN, "\0") == 0) {
			continue;
		}
	

		printf("%-10s|%-20s|%-20s|%-20s|%d\n", books[i].ISBN, books[i].title, books[i].author, books[i].genre, books[i].quantity);

	}
	return 0;
}


int member_module(){
	printf("What do you want to do:\n");

        printf("   1.Add member(a):\n   2.Update member(u):\n   3.Delete member(d):\n   4.Display members(s):\n");

        char ch;

        do {

                printf("\nEnter choice (in member module):");
                char_input(&ch);
                switch(ch){
                        case 'a': add_member(); break;
                        case 'u': update_member(); break;
                        case 'd': delete_member(); break;
                        case 's': display_members(); break;
                        case 'e': printf("Going back to menu.....\n"); break;
			case 'w':printf("\n###########Enter correct Choice##########\n"); break;
                        default: break;
                }

        }while (ch != 'e');
	return 0;
}

int add_member(){
	
	if (num_members > 99) { return 1;}

	char member_id[10];
        char name[20];
        char address[20];
        int phone_no;

	printf("Enter member ID:");
	scanf("%[^\n]", members[num_members].member_id);getchar();

	printf("Enter name:");
	scanf("%[^\n]", members[num_members].name);getchar();

	printf("Enter address:");
	scanf("%[^\n]", members[num_members].address);getchar();

	printf("Enter phone number:");
	scanf("%d", &members[num_members].phone_no);getchar();

	num_members++;
	return 0;
}

int update_member(){
	printf("Enter member ID of the member to be updated:");

	char update_member_id[10];
	scanf("%s", update_member_id);getchar();

	for (int i = 0; i < num_members; i++){
		if (strcmp(update_member_id, members[i].member_id) == 0){
			printf("Enter name:");
			scanf("%s", members[i].name);getchar();

			printf("Enter address:");
			scanf("%s", members[i].address);getchar();

			printf("Enter phone number:");
			scanf("%d", &members[i].phone_no);getchar();
			break;
		}
		else continue;
	}

	return 0;
}

int delete_member(){
	char delete_member_id[10];

	printf("Enter member id of member to be deleted:");
        scanf("%s", delete_member_id);getchar();

        for (int i = 0; i < num_members; i++){
                if (strcmp(delete_member_id, members[i].member_id) == 0){
                        
			strcpy(members[i].member_id, "\0");
			strcpy(members[i].name, "\0");
			strcpy(members[i].address, "\0");
			members[i].phone_no = 0;

			break;
                }
                else continue;
        }
	return 0;
}

int display_members(){
	printf("Member ID |Name                |address             |phone number\n");
	for (int i = 0; i < num_members; i++){
		if (strcmp(members[i].member_id, "\0") == 0) continue;

		printf("%-10s|%-20s|%-20s|%d\n", members[i].member_id, members[i].name, members[i].address, members[i].phone_no);
	}
	
	return 0;
}




int trans_module(){

	printf("What do you want to do:\n");

        printf("   1.Issue book(i):\n   2.Return book(r):\n   3.Display history(s):\n");

        char ch;

        do {

                printf("\nEnter choice (in transactions module):");
                char_input(&ch);
                switch(ch){
                        case 'i': issue_book(); break;
                        case 'r': return_book(); break;
                        case 's': display_history(); break;
                        case 'e': printf("Going back to menu.....\n"); break;
			case 'w': printf("\n###########Enter correct Choice##########\n"); break;
                        default: break;
                }

        }while (ch != 'e');

	return 0;
}

int issue_book(){
	char issue_member_id[10];
	char issue_book_id[10];
	int member_found = 0;
	
	printf("Enter member id to issue book:");
	scanf("%s", issue_member_id); getchar();
	printf("Enter book id to be issued:");
	scanf("%s", issue_book_id); getchar();

	for (int i = 0; i < num_members; i++){
		if (strcmp(issue_member_id, members[i].member_id) == 0){
			trans_detail[num_transactions].trans_id = 813001 + num_transactions;
			strcpy(trans_detail[num_transactions].member_id, issue_member_id);
	

			for (int j = 0; j < num_books; j++){
				if ((strcmp(issue_book_id, books[i].ISBN) == 0)){
					strcpy(trans_detail[num_transactions].ISBN, issue_book_id);
					break;
				}
			}
			strcpy(trans_detail[num_transactions].issue_date, "01/01/2001");
			strcpy(trans_detail[num_transactions].return_date, "--/--/----");
			
			num_transactions++;


			break;
		}
	}
	

	return 0;
}

int return_book(){
	
	int return_trans_id;

	printf("Enter transaction id to return book:");
	scanf("%d", &return_trans_id);getchar();

	for (int i = 0; i < num_transactions; i++){
		if (return_trans_id == trans_detail[i].trans_id){
			strcpy(trans_detail[i].return_date, "12/12/2024");
			break;
		}
	}


	return 0;
}

int display_history(){
	printf("Transaction ID |Member Id        |ISBN         |Issue date         |Return date\n");

	for (int i = 0; i < num_transactions;i++){
		printf("%-14d|%-10s|%-10s|%-10s|%-10s\n", trans_detail[i].trans_id, trans_detail[i].member_id, trans_detail[i].ISBN, trans_detail[i].issue_date, trans_detail[i].return_date);
	}
	return 0;
}



