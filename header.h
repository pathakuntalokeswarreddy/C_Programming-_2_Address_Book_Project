struct contact
{
    char name[50];
    char phone[20];
    char email[20];
};

struct address
{
    struct contact c[100];
    int count;
};

void initialization(struct address *, int *);
void create_contact(struct address*, int *);

void search_list(struct address*, int*,int *,int *);

void search_name(struct contact*,char *,int *,int*,int *);
void name_validation(char *);

void search_phone(struct contact*,char *,int *,int*);
void phone_validation(char *);

void search_email(struct contact*,char *,int *,int*);
void email_validation(char *);

void edit_contact(struct address*, int *,int*);

void delete_contact(struct address *, int *, int *);

void list(struct address*, int *);

void save_exit(struct address *, int *);