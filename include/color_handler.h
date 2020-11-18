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
  static void PrintColor(WINDOW* window, int y, int x, const char* str,
                         int color_pair, ...);
  static void PrintRed(WINDOW* window, int y, int x, const char* str, ...);
  static void PrintGreen(WINDOW* window, int y, int x, const char* str, ...);
  static void PrintYellow(WINDOW* window, int y, int x, const char* str, ...);
  static void PrintBlue(WINDOW* window, int y, int x, const char* str, ...);
  static void PrintMagenta(WINDOW* window, int y, int x, const char* str, ...);
  static void PrintCyan(WINDOW* window, int y, int x, const char* str, ...);
  static void PrintWhite(WINDOW* window, int y, int x, const char* str, ...);
};
}  // namespace roadrun

#endif
