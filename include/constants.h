#ifndef CONSTANTS_H_
#define CONSTANTS_H_

namespace roadrun
{
// Size and shape
const int kMenuHeight = 30;
const int kMenuWidth = 61; // + 1 for newline character
const int kInfoHeight = 30;
const int kInfoWidth = 30;

// Timing
const int kMaxTickCnt = 20000;
const int kMillisPerFrameEasy = 75;
const int kMillisPerFrameHard = 10;
const int kMillisPerRock = 2*kMillisPerFrameEasy;
const int kScoreTickCnt = 100;

// Movement
const int kDeltaEasy = 1;
const int kDeltaHard = 3;
enum WallSide
{
  kLeft = 0,
  kRight = 1
};
}
#endif
