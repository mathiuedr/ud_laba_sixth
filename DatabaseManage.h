#ifndef DATABASE_MANAGE_H
#define DATABASE_MANAGE_H

#ifdef __cplusplus
extern "C" {
#endif

// Пример объявления функций
int connect_to_db(const char *username, const char *password);
int disconnect_from_db();
int create_db();
int drop_db();
int clear_db();
int insert_book(const char *isbn_inp, const char *book_name_inp, const char *description_inp, const char *publication_date, const char *author_name_inp);
char* search_books_by_author_name(const char *author_name);
int update_book_by_id(int book_id, const char *isbn_inp, const char *book_name_inp, const char *description_inp, const char *publication_date, const char *author_name_inp);
int delete_book_by_name(const char *book_name);

#ifdef __cplusplus
}
#endif

#endif // DATABASE_MANAGE_H
