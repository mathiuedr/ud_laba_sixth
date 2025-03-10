/* Processed by ecpg (16.8 (Ubuntu 16.8-0ubuntu0.24.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "../DatabaseManage.pgc"
#include <stdio.h>
#include <string.h>
#include <pgtypes_date.h>  // Для работы с типом date
#include <time.h>
#include <stdlib.h>


int validate_date_format(const char *date) {
    struct tm tm;
    memset(&tm, 0, sizeof(struct tm));

    // Пытаемся разобрать строку в формате "yyyy-MM-dd"
    if (strptime(date, "%Y-%m-%d", &tm)) {
        return 1;  // Дата корректна
    }
    return 0;  // Дата некорректна
}

// Функция для проверки входных данных
int validate_cortege(const char *isbn, const char *book_name, const char *description, const char *publication_date, const char *author_name) {
    // Проверка длины ISBN (должен быть ровно 13 символов)
    if (strlen(isbn) != 13) {
        printf("Error: ISBN must have exactly 13 characters.\n");
        return 0;
    }

    // Проверка длины названия книги (не более 255 символов)
    if (strlen(book_name) > 255) {
        printf("Error: Book name must be no more than 255 characters.\n");
        return 0;
    }

    // Проверка формата даты
    if (!validate_date_format(publication_date)) {
        printf("Error: Publication date must be in the format 'yyyy-MM-dd'.\n");
        return 0;
    }

    // Проверка длины имени автора (не более 255 символов)
    if (strlen(author_name) > 255) {
        printf("Error: Author name must be no more than 255 characters.\n");
        return 0;
    }

    // Все проверки пройдены
    return 1;
}

// Функция для подключения к базе данных
int connect_to_db(const char *username, const char *password) {
    /* exec sql begin declare section */
              // Имя базы данных



#line 52 "../DatabaseManage.pgc"
 const char * conn_str = "library" ;

#line 53 "../DatabaseManage.pgc"
 const char * user = username ;

#line 54 "../DatabaseManage.pgc"
 const char * pass = password ;
/* exec sql end declare section */
#line 55 "../DatabaseManage.pgc"


    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 57 "../DatabaseManage.pgc"


    // Подключение к базе данных
    { ECPGconnect(__LINE__, 0, conn_str , user , pass , NULL, 0);
#line 60 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 60 "../DatabaseManage.pgc"

    printf("Connected to the database.\n");
    return 0;

error_handler:
    return -1;
}

int disconnect_from_db(){
    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 69 "../DatabaseManage.pgc"

    { ECPGdisconnect(__LINE__, "CURRENT");
#line 70 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 70 "../DatabaseManage.pgc"

    printf("Disconnected from the database.\n");
    return 0;
    error_handler:
        return -1;
}


// Создание базы данных
int create_db() {
    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 80 "../DatabaseManage.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call create_db ( )", ECPGt_EOIT, ECPGt_EORT);
#line 81 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 81 "../DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 82 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 82 "../DatabaseManage.pgc"

    printf("Database created successfully.\n");
    return 0;

error_handler:
    { ECPGtrans(__LINE__, NULL, "rollback");
#line 87 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 87 "../DatabaseManage.pgc"

    return -1;
}

// Удаление базы данных
int drop_db() {
    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 93 "../DatabaseManage.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call drop_db ( )", ECPGt_EOIT, ECPGt_EORT);
#line 94 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 94 "../DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 95 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 95 "../DatabaseManage.pgc"

    printf("Database dropped successfully.\n");
    return 0;

error_handler:
    { ECPGtrans(__LINE__, NULL, "rollback");
#line 100 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 100 "../DatabaseManage.pgc"

    return -1;
}

// Очистка таблиц
int clear_db() {
    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 106 "../DatabaseManage.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call clear_table ( )", ECPGt_EOIT, ECPGt_EORT);
#line 107 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 107 "../DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 108 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 108 "../DatabaseManage.pgc"

    printf("Tables cleared successfully.\n");
    return 0;

error_handler:
    { ECPGtrans(__LINE__, NULL, "rollback");
#line 113 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 113 "../DatabaseManage.pgc"

    return -1;
}

// Вставка книги
int insert_book(const char *isbn_inp, const char *book_name_inp, const char *description_inp, const char *publication_date, const char *author_name_inp) {
    if (!validate_cortege(isbn_inp, book_name_inp, description_inp, publication_date, author_name_inp)) {
        return 1;
    }

    /* exec sql begin declare section */
           // ISBN (13 символов + \0)

           // Описание (TEXT)
           // Дата публикации


#line 124 "../DatabaseManage.pgc"
 char isbn [ 14 ] ;

#line 125 "../DatabaseManage.pgc"
 char book_name [ 256 ] ;

#line 126 "../DatabaseManage.pgc"
 char description [ 4096 ] ;

#line 127 "../DatabaseManage.pgc"
 date pub_date ;

#line 128 "../DatabaseManage.pgc"
 char author_name [ 256 ] ;
/* exec sql end declare section */
#line 129 "../DatabaseManage.pgc"


    // Копируем данные в переменные ESQL
    strncpy(isbn, isbn_inp, sizeof(isbn) - 1);
    isbn[sizeof(isbn) - 1] = '\0';  // Убедимся, что строка завершена
    strncpy(book_name, book_name_inp, sizeof(book_name) - 1);
    book_name[sizeof(book_name) - 1] = '\0';
    strncpy(description, description_inp, sizeof(description) - 1);
    description[sizeof(description) - 1] = '\0';
    strncpy(author_name, author_name_inp, sizeof(author_name) - 1);
    author_name[sizeof(author_name) - 1] = '\0';

    // Преобразуем строку даты в тип date
    pub_date = PGTYPESdate_from_asc((char *)publication_date, NULL);

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 144 "../DatabaseManage.pgc"


    // Вызов хранимой процедуры
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
#line 147 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 147 "../DatabaseManage.pgc"


    // Завершаем транзакцию
    { ECPGtrans(__LINE__, NULL, "commit");
#line 150 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 150 "../DatabaseManage.pgc"


    printf("Book inserted successfully.\n");
    return 0;

error_handler:
    printf("Error inserting book: SQLCODE=%d, SQLERRM=%s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
    { ECPGtrans(__LINE__, NULL, "rollback");
#line 157 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 157 "../DatabaseManage.pgc"
  // Откатываем транзакцию в случае ошибки
    return -1;
}

// Поиск книг по автору
char* search_books_by_author_name(const char *author_name) {
    if (strlen(author_name) > 255) {
        return NULL;  // Возвращаем NULL, если имя автора слишком длинное
    }

    /* exec sql begin declare section */
           // Имя автора
                // ID книги
              // ISBN
           // Название книги
           // Описание

              // Дата публикации

#line 168 "../DatabaseManage.pgc"
 char author [ 256 ] ;

#line 169 "../DatabaseManage.pgc"
 int book_id ;

#line 170 "../DatabaseManage.pgc"
 char isbn [ 14 ] ;

#line 171 "../DatabaseManage.pgc"
 char book_name [ 256 ] ;

#line 172 "../DatabaseManage.pgc"
 char description [ 4096 ] ;

#line 173 "../DatabaseManage.pgc"
 date pub_date ;

#line 174 "../DatabaseManage.pgc"
 char goida [ 256 ] ;
/* exec sql end declare section */
#line 175 "../DatabaseManage.pgc"


    // Копируем имя автора в переменную ESQL
    strncpy(author, author_name, sizeof(author) - 1);
    author[sizeof(author) - 1] = '\0';  // Убедимся, что строка завершена

    // Динамически выделяем память для результата
    char *result = (char *)malloc(1);  // Начальный размер — 1 байт (для '\0')
    if (!result) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    result[0] = '\0';  // Инициализируем пустую строку

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 189 "../DatabaseManage.pgc"


    // Объявляем курсор для выборки данных
    ECPGset_var( 0, ( author ), __LINE__);\
 /* declare book_cursor cursor for select * from search_books_by_author_name ( $1  ) */
#line 193 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;
#line 193 "../DatabaseManage.pgc"

#line 193 "../DatabaseManage.pgc"
  // Явно указываем тип

    // Открываем курсор
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare book_cursor cursor for select * from search_books_by_author_name ( $1  )",
    ECPGt_char,(author),(long)256,(long)1,(256)*sizeof(char),
    ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 196 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 196 "../DatabaseManage.pgc"


    // Читаем данные из курсора
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
#line 200 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 200 "../DatabaseManage.pgc"

        if (sqlca.sqlcode == 100) break;  // Конец данных
        if (sqlca.sqlcode != 0) goto error_handler;

        // Формируем строку с информацией о книге
        char book_info[512];
        snprintf(book_info, sizeof(book_info), "ID: %d, ISBN: %s, Name: %s, Description: %s\n",
                 book_id, isbn, book_name, description);

        // Увеличиваем размер результата и добавляем информацию о книге
        size_t new_length = strlen(result) + strlen(book_info) + 1;
        result = (char *)realloc(result, new_length);
        if (!result) {
            fprintf(stderr, "Memory reallocation failed.\n");
            return NULL;
        }
        strcat(result, book_info);
    }

    // Закрываем курсор
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close book_cursor", ECPGt_EOIT, ECPGt_EORT);
#line 220 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 220 "../DatabaseManage.pgc"


    return result;

error_handler:
    printf("Error searching books: SQLCODE=%d, SQLERRM=%s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
    free(result);  // Освобождаем память в случае ошибки
    return NULL;
}

int update_book_by_id(int book_id, const char *isbn_inp, const char *book_name_inp, const char *description_inp, const char *publication_date, const char *author_name_inp) {
    if(book_id<0) return 1;
    if (!validate_cortege(isbn_inp, book_name_inp, description_inp, publication_date, author_name_inp)) {
        return 1;
    }
    /* exec sql begin declare section */







#line 236 "../DatabaseManage.pgc"
 int id = book_id ;

#line 237 "../DatabaseManage.pgc"
 char isbn [ 14 ] ;

#line 238 "../DatabaseManage.pgc"
 char book_name [ 256 ] ;

#line 239 "../DatabaseManage.pgc"
 char description [ 4096 ] ;

#line 240 "../DatabaseManage.pgc"
 date pub_date ;

#line 241 "../DatabaseManage.pgc"
 char author_name [ 256 ] ;
/* exec sql end declare section */
#line 242 "../DatabaseManage.pgc"


    strncpy(isbn, isbn_inp, sizeof(isbn) - 1);
    strncpy(book_name, book_name_inp, sizeof(book_name) - 1);
    strncpy(description, description_inp, sizeof(description) - 1);
    strncpy(author_name, author_name_inp, sizeof(author_name) - 1);

    pub_date = PGTYPESdate_from_asc(publication_date, NULL);

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 251 "../DatabaseManage.pgc"


    // Вызов хранимой процедуры
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
#line 254 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 254 "../DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 255 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 255 "../DatabaseManage.pgc"


    printf("Book updated successfully.\n");
    return 0;

error_handler:
    { ECPGtrans(__LINE__, NULL, "rollback");
#line 261 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 261 "../DatabaseManage.pgc"

    return -1;
}

int delete_book_by_name(const char *book_name) {
    if(strlen(book_name)>255) return 1;
    /* exec sql begin declare section */


#line 268 "../DatabaseManage.pgc"
 char name [ 256 ] ;
/* exec sql end declare section */
#line 269 "../DatabaseManage.pgc"


    strncpy(name, book_name, sizeof(name) - 1);

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 273 "../DatabaseManage.pgc"


    // Вызов хранимой процедуры
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call delete_book_by_name ( $1  )",
    ECPGt_char,(name),(long)256,(long)1,(256)*sizeof(char),
    ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 276 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 276 "../DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 277 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 277 "../DatabaseManage.pgc"

    printf("Book deleted successfully.\n");
    return 0;

error_handler:
    { ECPGtrans(__LINE__, NULL, "rollback");
#line 282 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 282 "../DatabaseManage.pgc"

    return -1;
}


void grant_user_on_procedure(const char *procedure_name, const char *username) {
    /* exec sql begin declare section */
           // Имя процедуры
                // Имя пользователя

#line 289 "../DatabaseManage.pgc"
 char proc_name [ 256 ] ;

#line 290 "../DatabaseManage.pgc"
 char user [ 256 ] ;
/* exec sql end declare section */
#line 291 "../DatabaseManage.pgc"


    // Копируем входные данные в переменные ESQL
    strncpy(proc_name, procedure_name, sizeof(proc_name) - 1);
    proc_name[sizeof(proc_name) - 1] = '\0';  // Убедимся, что строка завершена
    strncpy(user, username, sizeof(user) - 1);
    user[sizeof(user) - 1] = '\0';

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 299 "../DatabaseManage.pgc"


    // Вызов хранимой процедуры
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call grant_user_on_procedure ( $1  , $2  )",
    ECPGt_char,(proc_name),(long)256,(long)1,(256)*sizeof(char),
    ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
    ECPGt_char,(user),(long)256,(long)1,(256)*sizeof(char),
    ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 302 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 302 "../DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 303 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 303 "../DatabaseManage.pgc"

    printf("Procedure '%s' granted to user '%s' successfully.\n", proc_name, user);
    return;

error_handler:
    { ECPGtrans(__LINE__, NULL, "rollback");
#line 308 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 308 "../DatabaseManage.pgc"

    printf("Error granting procedure: SQLCODE=%d, SQLERRM=%s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
}

void grant_user_on_function(const char *procedure_name, const char *username) {
    /* exec sql begin declare section */
           // Имя процедуры
                // Имя пользователя

#line 314 "../DatabaseManage.pgc"
 char proc_name [ 256 ] ;

#line 315 "../DatabaseManage.pgc"
 char user [ 256 ] ;
/* exec sql end declare section */
#line 316 "../DatabaseManage.pgc"


    // Копируем входные данные в переменные ESQL
    strncpy(proc_name, procedure_name, sizeof(proc_name) - 1);
    proc_name[sizeof(proc_name) - 1] = '\0';  // Убедимся, что строка завершена
    strncpy(user, username, sizeof(user) - 1);
    user[sizeof(user) - 1] = '\0';

    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 324 "../DatabaseManage.pgc"


    // Вызов хранимой процедуры
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call grant_user_on_function ( $1  , $2  )",
    ECPGt_char,(proc_name),(long)256,(long)1,(256)*sizeof(char),
    ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
    ECPGt_char,(user),(long)256,(long)1,(256)*sizeof(char),
    ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 327 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 327 "../DatabaseManage.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 328 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 328 "../DatabaseManage.pgc"

    printf("Procedure '%s' granted to user '%s' successfully.\n", proc_name, user);

    return;

error_handler:
    { ECPGtrans(__LINE__, NULL, "rollback");
#line 334 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 334 "../DatabaseManage.pgc"

    printf("Error granting procedure: SQLCODE=%d, SQLERRM=%s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
}


int create_user(char* login, char* password, bool create_db_right, bool delete_db_right,bool clear_db_right,
bool insert_right, bool search_right, bool update_right, bool delete_right, bool create_user_right){
    /* exec sql whenever sqlerror  goto  error_handler ; */
#line 341 "../DatabaseManage.pgc"

    /* exec sql begin declare section */



#line 343 "../DatabaseManage.pgc"
 char name [ 256 ] ;

#line 344 "../DatabaseManage.pgc"
 char user_password [ 256 ] ;
/* exec sql end declare section */
#line 345 "../DatabaseManage.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "call create_user ( $1  , $2  )",
    ECPGt_char,(name),(long)256,(long)1,(256)*sizeof(char),
    ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L,
    ECPGt_char,(user_password),(long)256,(long)1,(256)*sizeof(char),
    ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 346 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 346 "../DatabaseManage.pgc"

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
    { ECPGtrans(__LINE__, NULL, "commit");
#line 373 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 373 "../DatabaseManage.pgc"


    error_handler:
    { ECPGtrans(__LINE__, NULL, "rollback");
#line 376 "../DatabaseManage.pgc"

if (sqlca.sqlcode < 0) goto error_handler;}
#line 376 "../DatabaseManage.pgc"

        return -1;
}
