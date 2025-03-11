CREATE OR REPLACE PROCEDURE create_db ()
                    LANGUAGE plpgsql AS $$
                    BEGIN
                    CREATE TABLE Books (
                                                id SERIAL PRIMARY KEY,
                                                ISBN VARCHAR(13) UNIQUE NOT NULL,
                                                name VARCHAR(255) NOT NULL,
                                                description TEXT,
                                                publication_date DATE,
                                                author_name VARCHAR(255));
                    END;
                    $$ SECURITY DEFINER;
                    

CREATE OR REPLACE PROCEDURE drop_db()
                    LANGUAGE plpgsql AS $$
                    BEGIN
                    DROP TABLE books;
                    END;
                    $$ SECURITY DEFINER;

CREATE OR REPLACE PROCEDURE clear_table()
                    LANGUAGE plpgsql
                    SECURITY DEFINER
                    AS $$
                    BEGIN
                    TRUNCATE TABLE books;
                    END;
                    $$;

CREATE OR REPLACE PROCEDURE insert_book(
                    new_isbn varchar(13), new_name varchar(255), new_description TEXT, new_publication_date DATE, new_author_name varchar(255))
                    LANGUAGE plpgsql
                    SECURITY DEFINER
                    AS $$
                    BEGIN
                    INSERT INTO "books" (ISBN, name, description, publication_date, author_name)
                    VALUES (new_isbn, new_name, new_description, new_publication_date, new_author_name);
                    END; $$;

CREATE OR REPLACE FUNCTION search_books_by_author_name(search_name TEXT)
                    RETURNS TABLE(id INT, isbn varchar(13), name varchar(255), description TEXT, publication_date DATE, authosr_name varchar(255))
                    LANGUAGE plpgsql
                    SECURITY DEFINER
                    AS $$
                    BEGIN
                        RETURN QUERY
                        SELECT * FROM "books" WHERE author_name LIKE search_name;
                    END;
                    $$;

CREATE OR REPLACE PROCEDURE update_book(book_id INT, new_ISBN VARCHAR(13), new_name VARCHAR(255), new_description TEXT, new_publication_date DATE, new_author_name VARCHAR(255) )
                    LANGUAGE plpgsql
                    SECURITY DEFINER
                    AS $$
                    BEGIN
                    UPDATE "books" SET isbn = new_ISBN, name = new_name, description = new_description, publication_date = new_publication_date, author_name = new_author_name WHERE id = book_id;
                    END; $$;


CREATE OR REPLACE PROCEDURE delete_book_by_name(book_name VARCHAR(255) )
                    LANGUAGE plpgsql
                    SECURITY DEFINER
                    AS $$
                    BEGIN
                    DELETE FROM "books" WHERE name = book_name;
                    END; $$;


CREATE OR REPLACE PROCEDURE grant_user_on_procedure(procedure_name TEXT, user_name TEXT )
                    LANGUAGE plpgsql
                    SECURITY DEFINER
                    AS $$
                    BEGIN
                    EXECUTE format('GRANT EXECUTE ON PROCEDURE %I TO %I', procedure_name, user_name);
                    END; $$;
                    

CREATE OR REPLACE PROCEDURE grant_user_on_function(procedure_name TEXT, user_name TEXT )
                    LANGUAGE plpgsql
                    SECURITY DEFINER
                    AS $$
                    BEGIN
                    EXECUTE format('GRANT EXECUTE ON FUNCTION %I TO %I', procedure_name, user_name);
                    END; $$;

CREATE OR REPLACE PROCEDURE create_user(user_name TEXT, new_password TEXT )
                                        LANGUAGE plpgsql
                                        SECURITY DEFINER
                                        AS $$
                                        BEGIN
                                        EXECUTE format('CREATE USER %I WITH PASSWORD %L', user_name, new_password);
                                        EXECUTE format('GRANT CONNECT ON DATABASE library TO %I', user_name);
                    EXECUTE format('GRANT USAGE ON SCHEMA public TO %I', user_name);
                                        END; $$;

CREATE USER admin WITH PASSWORD '123';
CREATE USER guest WITH PASSWORD 'guest';
-- Отзыв всех привилегий на таблицу books от пользователя guest
REVOKE ALL PRIVILEGES ON TABLE books FROM guest;

-- Отзыв всех привилегий на схему public от пользователя guest
REVOKE ALL PRIVILEGES ON SCHEMA public FROM guest;

-- Отзыв права CREATE на схеме public от пользователя guest
REVOKE CREATE ON SCHEMA public FROM guest;

-- Отзыв всех привилегий на таблицу books от пользователя admin
REVOKE ALL PRIVILEGES ON TABLE books FROM admin;

-- Отзыв всех привилегий на схему public от пользователя admin
REVOKE ALL PRIVILEGES ON SCHEMA public FROM admin;

-- Отзыв права CREATE на схеме public от пользователя admin
REVOKE CREATE ON SCHEMA public FROM admin;

-- Отзыв всех привилегий на процедуру create_db от всех пользователей (PUBLIC)
REVOKE ALL ON PROCEDURE create_db FROM PUBLIC;

-- Отзыв всех привилегий на процедуру clear_table от всех пользователей (PUBLIC)
REVOKE ALL ON PROCEDURE clear_table FROM PUBLIC;

-- Отзыв всех привилегий на процедуру drop_db от всех пользователей (PUBLIC)
REVOKE ALL ON PROCEDURE drop_db FROM PUBLIC;

-- Отзыв всех привилегий на процедуру insert_book от всех пользователей (PUBLIC)
REVOKE ALL ON PROCEDURE insert_book FROM PUBLIC;

-- Отзыв всех привилегий на процедуру update_book от всех пользователей (PUBLIC)
REVOKE ALL ON PROCEDURE update_book FROM PUBLIC;

-- Отзыв всех привилегий на процедуру delete_book_by_name от всех пользователей (PUBLIC)
REVOKE ALL ON PROCEDURE delete_book_by_name FROM PUBLIC;

-- Отзыв всех привилегий на функцию search_books_by_author_name от всех пользователей (PUBLIC)
REVOKE ALL ON FUNCTION search_books_by_author_name FROM PUBLIC;

-- Предоставление права на подключение к базе данных library пользователю admin
GRANT CONNECT ON DATABASE library TO admin;

-- Предоставление права на подключение к базе данных library пользователю guest
GRANT CONNECT ON DATABASE library TO guest;

-- Предоставление права на выполнение процедуры create_db пользователю admin
GRANT EXECUTE ON PROCEDURE create_db TO admin;

-- Предоставление права на выполнение процедуры clear_table пользователю admin
GRANT EXECUTE ON PROCEDURE clear_table TO admin;

-- Предоставление права на выполнение процедуры drop_db пользователю admin
GRANT EXECUTE ON PROCEDURE drop_db TO admin;

-- Предоставление права на выполнение процедуры insert_book пользователю admin
GRANT EXECUTE ON PROCEDURE insert_book TO admin;

-- Предоставление права на выполнение процедуры update_book пользователю admin
GRANT EXECUTE ON PROCEDURE update_book TO admin;

GRANT EXECUTE ON PROCEDURE create_user TO admin;

GRANT EXECUTE ON PROCEDURE grant_user_on_procedure TO admin;

GRANT EXECUTE ON PROCEDURE grant_user_on_function TO admin;

-- Предоставление права на выполнение процедуры delete_book_by_name пользователю admin
GRANT EXECUTE ON PROCEDURE delete_book_by_name TO admin;

-- Предоставление права на выполнение функции search_books_by_author_name пользователю admin
GRANT EXECUTE ON FUNCTION search_books_by_author_name TO admin;

-- Предоставление права на выполнение функции search_books_by_author_name пользователю guest
GRANT EXECUTE ON FUNCTION search_books_by_author_name TO guest;

