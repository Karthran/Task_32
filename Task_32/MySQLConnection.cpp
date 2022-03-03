#include <iostream>
#include <mysql.h>

#include "MySQLConnection.h"

MySQLConnection::~MySQLConnection() {}

auto MySQLConnection::open() -> int
{
    // Получаем дескриптор соединения
    _mysql = mysql_init(NULL);
    if (_mysql == nullptr)
    {
        // Если дескриптор не получен — выводим сообщение об ошибке
        std::cout << "Error: can't create MySQL-descriptor" << std::endl;
        return -1;
    }
    // Подключаемся к серверу
    if (!mysql_real_connect(_mysql, "localhost", "root", "rksm", "testdb", 0, NULL, 0))
    {
        // Если нет возможности установить соединение с БД выводим сообщение об ошибке
        std::cout << "Error: can't connect to database " << mysql_error(_mysql) << std::endl;
        return -1;
    }

    // Если соединение успешно установлено выводим фразу — "Success!"
    std::cout << "Success!" << std::endl;
    mysql_set_character_set(_mysql, "utf8");
    std::cout << "connection characterset: " << mysql_character_set_name(_mysql) << std::endl;
    return 0;
}

auto MySQLConnection::close() -> void
{
    // Закрываем соединение с сервером базы данных
    mysql_close(_mysql);
}

auto MySQLConnection::execQuery(const char* sql_query) -> int
{
    return mysql_query(_mysql, sql_query);
}
