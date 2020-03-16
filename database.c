#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct book{
char Book_name[20];
char Auth_name[100];
int issue;    
struct book *next;
}Book;
typedef struct root{
    Book * book;
}Root;

typedef struct user{
    char name[30];
    Book * b1;
}User;

//char book[][100]={"The Second World War","Homage to Catalonia","Collected Essays","The Open Society and Its Enemies","The Abolition of Man","Captiaism and Freedom","Modern Times","Rationalism in Politics","Capitalism, Socialism, and Democracy","Economy and Society","Black Lamb and Grey Falcon","Sociobiology","The Diary of a Young Girl","The Great Terror","Relativity: The Special and General Theory","Up in the Old Hotel","The Double Helix","The Unheavenly City","The Interpretation of Dreams","The Death and Life of Great American Cities","The End of History and the Last Man","The Age of Reform","God & Man at Yale","Ideas Have Consequences","Ethnic America","An American Dilemma","Three Case Histories","The Struggle for Europe","The Hedgehog and the Fox","Roll, Jordan, Roll","The ABC of Reading","The Second World War","The Strange Ride of Rudyard Kipling","Scrutiny","Robert E. Lee","Bureaucracy","The Seven Storey Mountain","The Good Society","Silent Spring","Strange Defeat","Looking Back","Mont-Saint-Michel and Chartres","The Conservative Mind","Wealth and Poverty","Battle Cry of Freedom","Darwin’s Black Box","The Way the World Works","To the Finland Station","Civilisation","The Russian Revolution","The Idea of History","The Last Lion","The Starr Report","And Then There Were None","Harry Potter and the Philosopher's Stone","The Alchemist","The Hobbit","The Lord of the Rings","The Adventures of Pinocchio","The Da Vinci Code","Harry Potter and the Chamber of Secrets","Harry Potter and the Prisoner of Azkaban","Harry Potter and the Goblet of Fire","Harry Potter and the Order of the Phoenix ","Harry Potter and the Half-Blood Prince","Harry Potter and the Deathly Hallows","To Kill a Mockingbird","Angels & Demons","Kane and Abel","Into the water","Origin","The Hunger Games","Pride And Prejudice","Adventures of Huckleberry Finn","Life After Life","Catch-22","Twilight","The Shadowhunter Chronicles","The dark Tower","Septimus Heap","Shadowplay","Xanth","Young Wizards","Zoo City","Anima","Beyond Apollo","Ulysses","Gone with The Wind","Under The Sun of  Satan","The Joke","Friday","The catcher in the rye","Under the volcano","Armers","Froth on the daydream","Watership Down","Black beauty","Charlotte's web","The ginger man","Flowers in the attic"};
//char author[][100]={"Winston S. Churchill","George Orwell","George Orwell","Karl Popper","C. S Lewis","Milton Friedman","Paul Johnson","Michael Oakeshott","Joseph A. Schumpeter","Max Weber","Rebecca West","Edward O. Wilson","Anne Frank","Robert Conquest","Albert Einstein","Joseph Mitchell","James D. Watson","Edward C. Banfield","Sigmund Freud","Jane Jacobs","Francis Fukuyama","Richard Hofstadter","William F. Buckley Jr","Richard M. Weaver","Thomas Sowell","Gunnar Myrdal","Sigmund Freud","Chester Wilmot","Isaiah Berlin","Eugene D. Genovese","Ezra Pound","John Keegan","Angus Wilson","F. R. Leavis","Douglas Southall Freeman","Ludwig von Mises","Thomas Merton","Walter Lippmann","Rachel Carson","Marc Bloch","Norman Douglas","Henry Adams","Russell Kirk","George Gilder","James M. McPherson","Michael J. Behe","Jude Wanniski","Edmund Wilson","Kenneth Clark","Richard Pipes","R. G. Collingwood","William Manchester","Kenneth W. Starr","Agatha Christie","J. K. Rowling","Paulo Coelho","J. R. R. Tolkien","J. R. R. Tolkien","Carlo Collodi","Dan Brown","J. K. Rowling","J. K. Rowling","J. K. Rowling","J. K. Rowling","J. K. Rowling","J. K. Rowling","Harper Lee","Dan Brown","Jeffrey Archer","Paula Hawkins","Dan Brown","Suzanne Collins","Jane Austen","Mark Twain","Raymond Moody","Joseph Heller","Stephenie Meyer","Cassandra Clare","Stephen King","Angie Sage","Tad Williams","Piers Anthony","Diane Duane","Lauren Beukes","Marie Buchanan","Barry N. Malzberg","James Joyce","Margaret Mitchell","Georges Bernanos","Milan Kundera","Michel Tounier","J.D.Salinger","Malcolm Lowry","Saint John Perse","Boris Vian","Richard Adams","Anna Sewell","E.B.White","J.P.Donleavy","V.C.Andrews"};
char book[][100]={"HP","New_Rules","Percy_Jackson","RJ","Oops","Origin","TDVC"};
char author[][100]={"JKR","TXT","Rick_Riordan","K-Jin","C++","Dan","DB"};

Root *init(){
    Root * r1=(Root *)malloc(sizeof(Root));
    r1->book=NULL;
    return r1;
}
Root * create(Root * t1){
    Book * b1=(Book *)malloc(sizeof(Book));
    t1->book=b1;
    for(int i=0;i<7;i++){
        strcpy(b1->Book_name,book[i]);
        strcpy(b1->Auth_name,author[i]);
        b1->issue=0;
            if(i!=6){
            b1->next=(Book *)malloc(sizeof(Book));
            b1=b1->next;
            }
            else{
                b1->next=NULL;
            }
        }
        //printf("%d\t%s\t%s\n",b1->issue,b1->Book_name,b1->Auth_name);
        return t1;
    }
    


void display(Root * b1){
    Book * b2=b1->book;
    while(b2!=NULL){
    if(b2->issue!=1){
        printf("%s-%s\n%d\n",b2->Book_name,b2->Auth_name,b2->issue);
    }
        b2=b2->next;
    }
    return;
}
int check(User * u1){
    if(u1->b1==NULL){
        return 1;
    }
    return 0;
}

Root * insert(Root * t1,User * u1){
    if(check(u1)==1){
        printf("issue books first\n");
        return t1;
    }
    if(t1!=NULL){
    Book * new=t1->book;
    for(int i=0;i<7;i++){
    while((new!=NULL)){
    if(strncmp(new->Book_name,u1->b1->Book_name,strlen(new->Book_name))==0){
        break;
    }
    else{
        new=new->next;
    }
    }
    if(new==NULL){
        printf("Book not found. Try entering the name again\n");
        return t1;
    }
    else{
       if(!strncmp(new->Auth_name,u1->b1->Auth_name,strlen(new->Auth_name))&&(new->issue==1)){
            new->issue=0;
            printf("Book successfully returned\n");
            u1->b1=NULL;
	    return t1;
        }
    }
    }
    }
    return t1;
}
void search(Root *t1)
{
    Book * temp=t1->book;
    int x;
    char cmp[100];
    printf("1.search by author name\n2.search by book name\n");
    scanf("%d",&x);
    if(x==1)
    {  
        printf("Enter author name to search\n");
        scanf("%s",cmp);
        while(temp!=NULL){
            if(strcmp(temp->Auth_name,cmp)==0)
            {
                printf("%s",temp->Auth_name);printf(":"); printf("%s\n",temp->Book_name);
                return;
            }
            temp=temp->next;
    }
    }
    else if(x==2)
    {
        printf("Enter book name to search\n");
        scanf("%s",cmp);
        while(temp!=NULL){
            if(strcmp(temp->Book_name,cmp)==0)
            {
             printf("Book present!\n");
             return;
            }
            temp=temp->next;
    }
    }
    else
    {
        printf("The book/author you are searching for is not found\n");
    }
    return;
}
void issue(Root * r1 ,User * u1)
{
    if(check(u1)==0){
        printf("Please return your books first!\n");
        return;
    }
    if(r1!=NULL){
    char book[20];
    printf("Enter the book that you want to issue\n");
    scanf("%s",book);
    Book* temp=r1->book;
    while(temp!=NULL){
        if(strcmp(temp->Book_name,book)==0)
            {
            if(temp->issue==0){
                temp->issue=1;
                u1->b1=temp;
                printf("Issued successfully\n");
            return ;
            }
            }
            temp=temp->next;
    }
    if(temp==NULL){
        printf("Unsuccessful\n");
        return;
    }
}
}
void my_book(User *u1){
    if(u1->b1==NULL){
        printf("Issue books first\n");
        return;
    }
    printf("Name:%s\n",u1->name);
    printf("Book name:%s\n",u1->b1->Book_name);
    printf("Author name:%s\n",u1->b1->Auth_name);
    return;
}
void main(){
Root * Node=init();
Node =create(Node);
printf("Welcome to the LIBRARY \t\t\t\t\t\n");
display(Node);
char new_name[100];
printf("Enter your name\n");
scanf("%s",new_name);
User *u1=(User *)malloc(sizeof(User));
strcpy(u1->name,new_name);
u1->b1=NULL;
int loop=1;
int choice;
while(loop){
    printf("\n0.Exit\n1.Issue new books\n2.Return book\n3.Display books\n4.Search for books\n5.My books\n");
    scanf("\n%d" , &choice);
    switch(choice){
        case 0:loop=0;break;
        case 1:{issue(Node,u1);}break;
        case 2:{insert(Node,u1);}break;
        case 3:display(Node);break;
        case 4:search(Node);break;
        case 5:my_book(u1);break;
    }
}

}