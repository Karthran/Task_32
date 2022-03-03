#pragma once
class IDBConnection;
class ClassThatUsesDB
{
public:
    ClassThatUsesDB(IDBConnection* db_connection);
    auto openConnection() -> int;
    auto useConnection(const char* sql_query) -> int;
    auto closeConnection() -> void;

private:
    IDBConnection* _db_connection{nullptr};
};
