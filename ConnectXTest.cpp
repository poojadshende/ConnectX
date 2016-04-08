/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, incorrectToWinValue)
{
	ConnectX turnx(2,2,-6);	
	ASSERT_EQ(turnx.at(3,3), 0);
}

TEST(ConnectXTest, incorrectWidthValue)
{
	ConnectX turnx(-1,3,4);
	turnx.placePiece(4);
	
	ASSERT_EQ(turnx.at(4,5), 2);
}

TEST(ConnectXTest, incorrectHeightValue)
{
	ConnectX turnx(3,-9,6);
	ASSERT_EQ(turnx.at(4,4), 0);
}

TEST(ConnectXTest, defaultBoardValue)
{
	ConnectX turnx;
	turnx.placePiece(6);
	ASSERT_EQ(turnx.at(6,5), 2);
}

TEST(ConnectXTest, placePieceCorrectly)
{
	ConnectX turnx(8,9,4);
	turnx.placePiece(5);
	turnx.placePiece(5);
	ASSERT_EQ(turnx.at(5,8), 2);
	ASSERT_EQ(turnx.at(5,7), 1);
}


TEST(ConnectXTest, placePieceGreaterWidth)
{
	ConnectX turnx(11,8,4);
	turnx.placePiece(20);
	ASSERT_EQ(turnx.at(20,7), -1);
	ASSERT_EQ(turnx.whoseTurn(), 1);
}

TEST(ConnectXTest, placePieceOutOfBoundColumn)
{
	ConnectX turnx(5,6,4);
	turnx.placePiece(-8);
	ASSERT_EQ(turnx.at(-8,1), -1);
	ASSERT_EQ(turnx.whoseTurn(), 1);
}

TEST(ConnectXTest, placePieceColumnFull)
{
	ConnectX turnx(2,2,2);
	turnx.placePiece(1);
	turnx.placePiece(0);
	turnx.placePiece(1);
	turnx.placePiece(0);
	turnx.placePiece(0);
	ASSERT_EQ(turnx.at(0,0), 1);
	ASSERT_EQ(turnx.whoseTurn(),1);
}

TEST(ConnectXTest, displayMap)
{
	ConnectX turnx(3,8,4);
	turnx.placePiece(1);
	turnx.placePiece(0);
	turnx.showBoard();
	ASSERT_EQ(turnx.at(2,2), 0);
}

TEST(ConnectXTest, invalidLocationGreaterHeight)
{
	ConnectX turnx(5,6,4);
	turnx.placePiece(6);
	
	ASSERT_EQ(turnx.at(4,14), -1);
}
