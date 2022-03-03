#include "ClassThatUsesDB.h"
#include "IDBConnection.h"

ClassThatUsesDB::ClassThatUsesDB(IDBConnection* db_connection):_db_connection(db_connection) {}

auto ClassThatUsesDB::openConnection() -> int
{
    return _db_connection->open();
}

auto ClassThatUsesDB::useConnection(const char* sql_query) -> int
{
    return _db_connection->execQuery(sql_query);
}

auto ClassThatUsesDB::closeConnection() -> void
{
    _db_connection->close();
}
