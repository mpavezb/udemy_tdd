#include <gtest/gtest.h>
#include <gmock/gmock.h>


class Game {
private:
  std::vector<int> _rolls;
public:
  Game() {}
  
  void roll(int pins) {
    _rolls.push_back(pins);
  }
  
  int score() {
    int total = 0;
    int frame_idx = 0;
    for(int frame=0; frame<10; ++frame) {
      if (isStrike(frame_idx)) {
        total += 10 + strikeBonus(frame_idx);
        frame_idx++;
      } else if (isSpare(frame_idx)) {
        total += 10 + spareBonus(frame_idx);
        frame_idx+=2;
      } else {
        total += frameScore(frame_idx);
        frame_idx+=2;
      }
    }
    return total;
  }

private:
  int frameScore(int frame_idx) {
    return _rolls[frame_idx] + _rolls[frame_idx + 1];
  }
  int strikeBonus(int frame_idx) {
    return _rolls[frame_idx + 1] + _rolls[frame_idx +2];
  }
  int spareBonus(int frame_idx) {
    return _rolls[frame_idx + 2];
  }
  bool isStrike(int frame_idx) {
    return 10 == _rolls[frame_idx];
  }
  bool isSpare(int frame_idx) {
    return !isStrike(frame_idx) && 10 == _rolls[frame_idx] + _rolls[frame_idx+1];
  }
};

class BowlingGameTest: public ::testing::Test {
protected:
  Game game;

  void rollMany(int n, int pins) {
    for (int i=0; i<n; ++i) {
      game.roll(pins);
    }
  }

  void rollSpare() {
    game.roll(5);
    game.roll(5);
  }

  void rollStrike() {
    game.roll(10);
  }
  
};

TEST_F(BowlingGameTest, TestGutterGame) {
  rollMany(20, 0);
  ASSERT_EQ(0, game.score());
}

TEST_F(BowlingGameTest, TestAllOnesGame) {
  rollMany(20, 1);
  ASSERT_EQ(20, game.score());
}

TEST_F(BowlingGameTest, TestOneSpare) {
  rollSpare();
  game.roll(3);
  rollMany(17, 0);
  ASSERT_EQ(16, game.score());
}

TEST_F(BowlingGameTest, TestOneStrike) {
  rollStrike();
  game.roll(3);
  game.roll(4);
  rollMany(16, 0);
  ASSERT_EQ(24, game.score());
}

TEST_F(BowlingGameTest, TestPerfectGame) {
  rollMany(12, 10);
  ASSERT_EQ(300, game.score());
}
