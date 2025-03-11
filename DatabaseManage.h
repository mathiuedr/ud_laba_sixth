#ifndef DATABASE_MANAGE_H
#define DATABASE_MANAGE_H
#ifdef __cplusplus
extern "C" {
#endif
/* Processed by ecpg (16.8 (Ubuntu 16.8-0ubuntu0.24.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "DatabaseManage.pgc"
#include <stdio.h>
#include <string.h>
#include <pgtypes_date.h>
#include <time.h>
#include <stdlib.h>

int validate_date_format(const char *date) {
    struct tm tm;
    memset(&tm, 0, sizeof(struct tm));
    if (strptime(date, "%Y-%m-%d", &tm)) {
        return 1;
    }
    return 0;
}

int validate_cortege(const char *isbn, const char *book_name, const char *description, const char *publication_date, const char *author_name) {
    if (strlen(isbn) != 13) {
        printf("Error: ISBN must have exactly 13 characters.\n");
        return 0;
    }
    if (strlen(book_name) > 255) {
        printf("Error: Book name must be no more than 255 characters.\n");
        return 0;
    }
    if (!validate_date_format(publication_date)) {
        printf("Error: Publication date must be in the format 'yyyy-MM-dd'.\n");
        return 0;
    }
    if (strlen(author_name) > 255) {
        printf("Error: Author name must be no more than 255 characters.\n");
        return 0;
    }
    return 1;
}

int connect_to_db(const char *username, const char *password) {
    /* exec sql begin declare section */




#line 38 "DatabaseManage.pgc"
    const char * conn_str = "library" ;

#line 39 "DatabaseManage.pgc"
    const char * user = username ;

#line 40 "DatabaseManage.pgc"
    const char * pass = password ;
/* exec sql end declare section */
#line 41 "DatabaseManage.pgc"


    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 43 "DatabaseManage.pgc"


    { ECPGconnect(__LINE__, 0, conn_str , user , pass , NULL, 0);
#line 45 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 45 "DatabaseManage.pgc"

    printf("Connected to the database.\n");
    return 0;

error_handler:
    return -1;
}

int disconnect_from_db(){
    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 54 "DatabaseManage.pgc"

    { ECPGdisconnect(__LINE__, "CURRENT");
#line 55 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 55 "DatabaseManage.pgc"

    printf("Disconnected from the database.\n");
    return 0;
error_handler:
    return -1;
}

int create_db() {
    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 63 "DatabaseManage.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call create_db ( )", ECPGt_EOIT, ECPGt_EORT);
#line 64 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 64 "DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 65 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 65 "DatabaseManage.pgc"

    printf("Database created successfully.\n");
    return 0;

error_handler:
{ ECPGtrans(__LINE__, NULL, "rollback");
#line 70 "DatabaseManage.pgc"

    if (sqlca.sqlcode < 0) goto error_handler;}
#line 70 "DatabaseManage.pgc"

    return -1;
}

int drop_db() {
    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 75 "DatabaseManage.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call drop_db ( )", ECPGt_EOIT, ECPGt_EORT);
#line 76 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 76 "DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 77 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 77 "DatabaseManage.pgc"

    printf("Database dropped successfully.\n");
    return 0;

error_handler:
{ ECPGtrans(__LINE__, NULL, "rollback");
#line 82 "DatabaseManage.pgc"

    if (sqlca.sqlcode < 0) goto error_handler;}
#line 82 "DatabaseManage.pgc"

    return -1;
}

int clear_db() {
    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 87 "DatabaseManage.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call clear_table ( )", ECPGt_EOIT, ECPGt_EORT);
#line 88 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 88 "DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 89 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 89 "DatabaseManage.pgc"

    printf("Tables cleared successfully.\n");
    return 0;

error_handler:
{ ECPGtrans(__LINE__, NULL, "rollback");
#line 94 "DatabaseManage.pgc"

    if (sqlca.sqlcode < 0) goto error_handler;}
#line 94 "DatabaseManage.pgc"

    return -1;
}

int insert_book(const char *isbn_inp, const char *book_name_inp, const char *description_inp, const char *publication_date, const char *author_name_inp) {
    if (!validate_cortege(isbn_inp, book_name_inp, description_inp, publication_date, author_name_inp)) {
        return 1;
    }

    /* exec sql begin declare section */






#line 104 "DatabaseManage.pgc"
    char isbn [ 14 ] ;

#line 105 "DatabaseManage.pgc"
    char book_name [ 256 ] ;

#line 106 "DatabaseManage.pgc"
    char description [ 4096 ] ;

#line 107 "DatabaseManage.pgc"
    date pub_date ;

#line 108 "DatabaseManage.pgc"
    char author_name [ 256 ] ;
/* exec sql end declare section */
#line 109 "DatabaseManage.pgc"


    strncpy(isbn, isbn_inp, sizeof(isbn) - 1);
    isbn[sizeof(isbn) - 1] = '\0';
    strncpy(book_name, book_name_inp, sizeof(book_name) - 1);
    book_name[sizeof(book_name) - 1] = '\0';
    strncpy(description, description_inp, sizeof(description) - 1);
    description[sizeof(description) - 1] = '\0';
    strncpy(author_name, author_name_inp, sizeof(author_name) - 1);
    author_name[sizeof(author_name) - 1] = '\0';

    pub_date = PGTYPESdate_from_asc((char *)publication_date, NULL);

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 122 "DatabaseManage.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call insert_book ( $1  , $2  , $3  , $4  , $5  )",
               ECPGt_char,(isbn),(long)14,(long)1,(14)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_char,(book_name),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_char,(description),(long)4096,(long)1,(4096)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_date,&(pub_date),(long)1,(long)1,sizeof(date),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_char,(author_name),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 124 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 124 "DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 125 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 125 "DatabaseManage.pgc"


    printf("Book inserted successfully.\n");
    return 0;

error_handler:
    printf("Error inserting book: SQLCODE=%d, SQLERRM=%s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
    { ECPGtrans(__LINE__, NULL, "rollback");
#line 132 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 132 "DatabaseManage.pgc"

    return -1;
}

char* search_books_by_author_name(const char *author_name) {
    if (strlen(author_name) > 255) {
        return NULL;
    }

    /* exec sql begin declare section */








#line 142 "DatabaseManage.pgc"
    char author [ 256 ] ;

#line 143 "DatabaseManage.pgc"
    int book_id ;

#line 144 "DatabaseManage.pgc"
    char isbn [ 14 ] ;

#line 145 "DatabaseManage.pgc"
    char book_name [ 256 ] ;

#line 146 "DatabaseManage.pgc"
    char description [ 4096 ] ;

#line 147 "DatabaseManage.pgc"
    date pub_date ;

#line 148 "DatabaseManage.pgc"
    char goida [ 256 ] ;
/* exec sql end declare section */
#line 149 "DatabaseManage.pgc"


    strncpy(author, author_name, sizeof(author) - 1);
    author[sizeof(author) - 1] = '\0';

    char *result = (char *)malloc(1);
    if (!result) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    result[0] = '\0';

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 161 "DatabaseManage.pgc"


    ECPGset_var( 0, ( author ), __LINE__);\
    /* declare book_cursor cursor for select * from search_books_by_author_name ( $1  ) */
#line 164 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;
#line 164 "DatabaseManage.pgc"

#line 164 "DatabaseManage.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare book_cursor cursor for select * from search_books_by_author_name ( $1  )",
               ECPGt_char,(author),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 166 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 166 "DatabaseManage.pgc"


    while (1) {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch book_cursor", ECPGt_EOIT,
                   ECPGt_int,&(book_id),(long)1,(long)1,sizeof(int),
                   ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
                   ECPGt_char,(isbn),(long)14,(long)1,(14)*sizeof(char),
                   ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
                   ECPGt_char,(book_name),(long)256,(long)1,(256)*sizeof(char),
                   ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
                   ECPGt_char,(description),(long)4096,(long)1,(4096)*sizeof(char),
                   ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
                   ECPGt_date,&(pub_date),(long)1,(long)1,sizeof(date),
                   ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
                   ECPGt_char,(goida),(long)256,(long)1,(256)*sizeof(char),
                   ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 169 "DatabaseManage.pgc"

            if (sqlca.sqlcode < 0) goto error_handler;}
#line 169 "DatabaseManage.pgc"

        if (sqlca.sqlcode == 100) break;
        if (sqlca.sqlcode != 0) goto error_handler;

        char book_info[512];
        snprintf(book_info, sizeof(book_info), "ID: %d, ISBN: %s, Name: %s, Description: %s, Date: %s\n",
                 book_id, isbn, book_name, description, PGTYPESdate_to_asc(pub_date));

        size_t new_length = strlen(result) + strlen(book_info) + 1;
        result = (char *)realloc(result, new_length);
        if (!result) {
            fprintf(stderr, "Memory reallocation failed.\n");
            return NULL;
        }
        strcat(result, book_info);
    }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close book_cursor", ECPGt_EOIT, ECPGt_EORT);
#line 186 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 186 "DatabaseManage.pgc"


    return result;

error_handler:
    printf("Error searching books: SQLCODE=%d, SQLERRM=%s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
    free(result);
    return NULL;
}

int update_book_by_id(int book_id, const char *isbn_inp, const char *book_name_inp, const char *description_inp, const char *publication_date, const char *author_name_inp) {
    if(book_id < 0) return 1;
    if (!validate_cortege(isbn_inp, book_name_inp, description_inp, publication_date, author_name_inp)) {
        return 1;
    }

    /* exec sql begin declare section */








#line 203 "DatabaseManage.pgc"
    int id = book_id ;

#line 204 "DatabaseManage.pgc"
    char isbn [ 14 ] ;

#line 205 "DatabaseManage.pgc"
    char book_name [ 256 ] ;

#line 206 "DatabaseManage.pgc"
    char description [ 4096 ] ;

#line 207 "DatabaseManage.pgc"
    date pub_date ;

#line 208 "DatabaseManage.pgc"
    char author_name [ 256 ] ;

#line 209 "DatabaseManage.pgc"
    char pub_date_str [ 256 ] ;
/* exec sql end declare section */
#line 210 "DatabaseManage.pgc"


    strncpy(isbn, isbn_inp, sizeof(isbn) - 1);
    isbn[sizeof(isbn) - 1] = '\0';
    strncpy(book_name, book_name_inp, sizeof(book_name) - 1);
    book_name[sizeof(book_name) - 1] = '\0';
    strncpy(description, description_inp, sizeof(description) - 1);
    description[sizeof(description) - 1] = '\0';
    strncpy(author_name, author_name_inp, sizeof(author_name) - 1);
    author_name[sizeof(author_name) - 1] = '\0';

    strncpy(pub_date_str, publication_date, sizeof(pub_date_str) - 1);
    pub_date_str[sizeof(pub_date_str) - 1] = '\0';
    pub_date = PGTYPESdate_from_asc(pub_date_str, NULL);

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 225 "DatabaseManage.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call update_book ( $1  , $2  , $3  , $4  , $5  , $6  )",
               ECPGt_int,&(id),(long)1,(long)1,sizeof(int),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_char,(isbn),(long)14,(long)1,(14)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_char,(book_name),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_char,(description),(long)4096,(long)1,(4096)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_date,&(pub_date),(long)1,(long)1,sizeof(date),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_char,(author_name),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 227 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 227 "DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 228 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 228 "DatabaseManage.pgc"


    printf("Book updated successfully.\n");
    return 0;

error_handler:
{ ECPGtrans(__LINE__, NULL, "rollback");
#line 234 "DatabaseManage.pgc"

    if (sqlca.sqlcode < 0) goto error_handler;}
#line 234 "DatabaseManage.pgc"

    printf("Error updating book: SQLCODE=%ld, SQLERRM=%s\n", (long)sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
    return -1;
}

int delete_book_by_name(const char *book_name) {
    if(strlen(book_name)>255) return 1;
        /* exec sql begin declare section */


#line 242 "DatabaseManage.pgc"
    char name [ 256 ] ;
/* exec sql end declare section */
#line 243 "DatabaseManage.pgc"


    strncpy(name, book_name, sizeof(name) - 1);

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 247 "DatabaseManage.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call delete_book_by_name ( $1  )",
               ECPGt_char,(name),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 249 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 249 "DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 250 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 250 "DatabaseManage.pgc"

    printf("Book deleted successfully.\n");
    return 0;

error_handler:
{ ECPGtrans(__LINE__, NULL, "rollback");
#line 255 "DatabaseManage.pgc"

    if (sqlca.sqlcode < 0) goto error_handler;}
#line 255 "DatabaseManage.pgc"

    return -1;
}

void grant_user_on_procedure(const char *procedure_name, const char *username) {
    /* exec sql begin declare section */



#line 261 "DatabaseManage.pgc"
    char proc_name [ 256 ] ;

#line 262 "DatabaseManage.pgc"
    char user [ 256 ] ;
/* exec sql end declare section */
#line 263 "DatabaseManage.pgc"


    strncpy(proc_name, procedure_name, sizeof(proc_name) - 1);
    proc_name[sizeof(proc_name) - 1] = '\0';
    strncpy(user, username, sizeof(user) - 1);
    user[sizeof(user) - 1] = '\0';

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 270 "DatabaseManage.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call grant_user_on_procedure ( $1  , $2  )",
               ECPGt_char,(proc_name),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_char,(user),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 272 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 272 "DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 273 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 273 "DatabaseManage.pgc"

    printf("Procedure '%s' granted to user '%s' successfully.\n", proc_name, user);
    return;

error_handler:
{ ECPGtrans(__LINE__, NULL, "rollback");
#line 278 "DatabaseManage.pgc"

    if (sqlca.sqlcode < 0) goto error_handler;}
#line 278 "DatabaseManage.pgc"

    printf("Error granting procedure: SQLCODE=%d, SQLERRM=%s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
}

void grant_user_on_function(const char *procedure_name, const char *username) {
    /* exec sql begin declare section */



#line 284 "DatabaseManage.pgc"
    char proc_name [ 256 ] ;

#line 285 "DatabaseManage.pgc"
    char user [ 256 ] ;
/* exec sql end declare section */
#line 286 "DatabaseManage.pgc"


    strncpy(proc_name, procedure_name, sizeof(proc_name) - 1);
    proc_name[sizeof(proc_name) - 1] = '\0';
    strncpy(user, username, sizeof(user) - 1);
    user[sizeof(user) - 1] = '\0';

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 293 "DatabaseManage.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call grant_user_on_function ( $1  , $2  )",
               ECPGt_char,(proc_name),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_char,(user),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 295 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 295 "DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 296 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 296 "DatabaseManage.pgc"

    printf("Procedure '%s' granted to user '%s' successfully.\n", proc_name, user);

    return;

error_handler:
{ ECPGtrans(__LINE__, NULL, "rollback");
#line 302 "DatabaseManage.pgc"

    if (sqlca.sqlcode < 0) goto error_handler;}
#line 302 "DatabaseManage.pgc"

    printf("Error granting procedure: SQLCODE=%d, SQLERRM=%s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
}

int create_user(const char* login,const char* password, bool create_db_right, bool delete_db_right,bool clear_db_right,
                bool insert_right, bool search_right, bool update_right, bool delete_right, bool create_user_right){
    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 308 "DatabaseManage.pgc"

    /* exec sql begin declare section */



#line 310 "DatabaseManage.pgc"
    char name [ 256 ] ;

#line 311 "DatabaseManage.pgc"
    char user_password [ 256 ] ;
/* exec sql end declare section */
#line 312 "DatabaseManage.pgc"

    strncpy(name, login, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    strncpy(user_password, password, sizeof(user_password) - 1);
    user_password[sizeof(user_password) - 1] = '\0';
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call create_user ( $1  , $2  )",
               ECPGt_char,(name),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
               ECPGt_char,(user_password),(long)256,(long)1,(256)*sizeof(char),
               ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 317 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 317 "DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 318 "DatabaseManage.pgc"

        if (sqlca.sqlcode < 0) goto error_handler;}
#line 318 "DatabaseManage.pgc"

    if(create_db_right){
        grant_user_on_procedure("create_db", login);
    }
    if(delete_db_right){
        grant_user_on_procedure("drop_db", login);
    }
    if(clear_db_right){
        grant_user_on_procedure("clear_table", login);
    }
    if(insert_right){
        grant_user_on_procedure("insert_book", login);
    }
    if(search_right){
        grant_user_on_procedure("search_books_by_author_name", login);
    }
    if(update_right){
        grant_user_on_procedure("update_book", login);
    }
    if(delete_right){
        grant_user_on_procedure("delete_book_by_name", login);
    }
    if(create_user_right){
        grant_user_on_procedure("create_user", login);
        grant_user_on_procedure("grant_user_on_function", login);
        grant_user_on_procedure("grant_user_on_procedure", login);
    }
    return 0;
error_handler:
{ ECPGtrans(__LINE__, NULL, "rollback");
#line 347 "DatabaseManage.pgc"

    if (sqlca.sqlcode < 0) goto error_handler;}
#line 347 "DatabaseManage.pgc"

    return -1;
}






#ifdef __cplusplus
}
#endif

#endif // DATABASE_MANAGE_H
