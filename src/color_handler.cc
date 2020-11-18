#include "color_handler.h"

namespace roadrun {
void ColorHandler::InitializeColorPairs() {
  init_pair(kColorRed, COLOR_RED, COLOR_BLACK);
  init_pair(kColorGreen, COLOR_GREEN, COLOR_BLACK);
  init_pair(kColorYellow, COLOR_YELLOW, COLOR_BLACK);
  init_pair(kColorBlue, COLOR_BLUE, COLOR_BLACK);
  init_pair(kColorMagenta, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(kColorCyan, COLOR_CYAN, COLOR_BLACK);
  init_pair(kColorWhite, COLOR_WHITE, COLOR_BLACK);
}
void ColorHandler::PrintColor(WINDOW* window, int y, int x, const char* str,
                              int color_pair, ...) {
  attron(COLOR_PAIR(color_pair));
  mvwprintw(window, y, x, str);
  attroff(COLOR_PAIR(color_pair));
}
void ColorHandler::PrintRed(WINDOW* window, int y, int x, const char* str,
                            ...) {
  PrintColor(window, y, x, str, kColorRed);
}
void ColorHandler::PrintGreen(WINDOW* window, int y, int x, const char* str,
                              ...) {
  PrintColor(window, y, x, str, kColorGreen);
}
void ColorHandler::PrintYellow(WINDOW* window, int y, int x, const char* str,
                               ...) {
  PrintColor(window, y, x, str, kColorYellow);
}
void ColorHandler::PrintBlue(WINDOW* window, int y, int x, const char* str,
                             ...) {
  PrintColor(window, y, x, str, kColorBlue);
}
void ColorHandler::PrintMagenta(WINDOW* window, int y, int x, const char* str,
                                ...) {
  PrintColor(window, y, x, str, kColorMagenta);
}
void ColorHandler::PrintCyan(WINDOW* window, int y, int x, const char* str,
                             ...) {
  PrintColor(window, y, x, str, kColorCyan);
}
void ColorHandler::PrintWhite(WINDOW* window, int y, int x, const char* str,
                              ...) {
  PrintColor(window, y, x, str, kColorWhite);
}
}  // namespace roadrun
