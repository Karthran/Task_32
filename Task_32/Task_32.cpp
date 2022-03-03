//=============================================
#include <gtest/gtest.h>
#include <list>
#include "IDBConnection.h"
#include "MySQLConnection.h"
#include "MockDBConnection.h"
#include "ClassThatUsesDB.h"

class MyTestSuite : public ::testing::Test
{
protected:
    void SetUp()
    {
        //std::cout << "local setup" << std::endl;
        _objAnderTesting = new ClassThatUsesDB(&_mock);
    }

    void TearDown()
    {
        //std::cout << "local teardown" << std::endl;
        delete _objAnderTesting;
    }

protected:
    ClassThatUsesDB* _objAnderTesting;
    MockDBConnection _mock;
};

TEST_F(MyTestSuite, testcase1)
{
    EXPECT_CALL(_mock, open).Times(::testing::AtLeast(1));
    EXPECT_CALL(_mock, execQuery).Times(0);
    EXPECT_CALL(_mock, close).Times(0);
    _objAnderTesting->openConnection();
}

TEST_F(MyTestSuite, testcase2)
{
    EXPECT_CALL(_mock, open).Times(0);
    EXPECT_CALL(_mock, execQuery).Times(::testing::AtLeast(1));
    EXPECT_CALL(_mock, close).Times(0);
    _objAnderTesting->useConnection("Test");
}

TEST_F(MyTestSuite, testcase3)
{
    EXPECT_CALL(_mock, open).Times(0);
    EXPECT_CALL(_mock, execQuery).Times(0);
    EXPECT_CALL(_mock, close).Times(::testing::AtLeast(1));
    _objAnderTesting->closeConnection();
}


int main(int argc, char* argv[])
{
    IDBConnection* db = new MySQLConnection;
    ClassThatUsesDB test_class = ClassThatUsesDB(db);
    test_class.openConnection();
    test_class.closeConnection();
    delete db;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}