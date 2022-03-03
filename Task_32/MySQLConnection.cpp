#include <iostream>
#include <mysql.h>

#include "MySQLConnection.h"

MySQLConnection::~MySQLConnection() {}

auto MySQLConnection::open() -> int
{
    // �������� ���������� ����������
    _mysql = mysql_init(NULL);
    if (_mysql == nullptr)
    {
        // ���� ���������� �� ������� � ������� ��������� �� ������
        std::cout << "Error: can't create MySQL-descriptor" << std::endl;
        return -1;
    }
    // ������������ � �������
    if (!mysql_real_connect(_mysql, "localhost", "root", "rksm", "testdb", 0, NULL, 0))
    {
        // ���� ��� ����������� ���������� ���������� � �� ������� ��������� �� ������
        std::cout << "Error: can't connect to database " << mysql_error(_mysql) << std::endl;
        return -1;
    }

    // ���� ���������� ������� ����������� ������� ����� � "Success!"
    std::cout << "Success!" << std::endl;
    mysql_set_character_set(_mysql, "utf8");
    std::cout << "connection characterset: " << mysql_character_set_name(_mysql) << std::endl;
    return 0;
}

auto MySQLConnection::close() -> void
{
    // ��������� ���������� � �������� ���� ������
    mysql_close(_mysql);
}

auto MySQLConnection::execQuery(const char* sql_query) -> int
{
    return mysql_query(_mysql, sql_query);
}
