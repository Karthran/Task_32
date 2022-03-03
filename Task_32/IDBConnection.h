#pragma once

class IDBConnection
{
public:
    virtual ~IDBConnection() = default;
    virtual auto open() -> int = 0;
    virtual auto close() -> void = 0;
    virtual auto execQuery(const char* sql_query) -> int = 0;
};


