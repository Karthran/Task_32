#pragma once
#include "gmock/gmock.h"
#include "IDBConnection.h"

class MockDBConnection : public IDBConnection
{
public:
    MOCK_METHOD(int, open,(), (override));
    MOCK_METHOD(void, close,(), (override));
    MOCK_METHOD(int, execQuery, (const char* sql_query), (override));
};
