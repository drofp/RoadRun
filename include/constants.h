#ifndef CONSTANTS_H_
#define CONSTANTS_H_

namespace roadrun
{
// Size and shape
const int kMenuHeight = 30;
const int kMenuWidth = 61; // + 1 for newline character

// Timing
const int kMaxTickCnt = 20000;
const int kMillisPerFrameEasy = 75;
const int kMillisPerFrameHard = 10;
const int kMillisPerRock = 2*kMillisPerFrameEasy;

// Movement
const int kDeltaEasy = 1;
const int kDeltaHard = 3;
}
#endif
