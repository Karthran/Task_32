#pragma once
#include "IDBConnection.h"

struct MYSQL;

class MySQLConnection : public IDBConnection
{
public:
    virtual ~MySQLConnection();
    virtual auto open() -> int override;
    virtual auto close() -> void override;
    virtual auto execQuery(const char* sql_query) -> int override;

private:
    MYSQL* _mysql{nullptr};
};
