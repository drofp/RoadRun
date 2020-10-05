#ifndef COLOR_HANDLER_H_
#define COLOR_HANDLER_H_

#include <string_view>

#include "curses.h"

namespace roadrun {
const int kColorRed = COLOR_RED;
const int kColorGreen = COLOR_GREEN;
const int kColorYellow = COLOR_YELLOW;
const int kColorBlue = COLOR_BLUE;
const int kColorMagenta = COLOR_MAGENTA;
const int kColorCyan = COLOR_CYAN;
const int kColorWhite = COLOR_WHITE;
class ColorHandler {
 public:
  static void InitializeColorPairs();
  static void PrintColor(int y, int x, const char* str, int color_pair);
  static void PrintRed(int y, int x, const char* str);
  static void PrintGreen(int y, int x, const char* str);
  static void PrintYellow(int y, int x, const char* str);
  static void PrintBlue(int y, int x, const char* str);
  static void PrintMagenta(int y, int x, const char* str);
  static void PrintCyan(int y, int x, const char* str);
  static void PrintWhite(int y, int x, const char* str);
};
}  // namespace roadrun

#endif
