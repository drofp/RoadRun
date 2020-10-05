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
void ColorHandler::PrintColor(int y, int x, const char* str, int color_pair) {
  attron(COLOR_PAIR(color_pair));
  mvprintw(y, x, str);
  attroff(COLOR_PAIR(color_pair));
}
void ColorHandler::PrintRed(int y, int x, const char* str) {
  PrintColor(y, x, str, kColorRed);
}
void ColorHandler::PrintGreen(int y, int x, const char* str) {
  PrintColor(y, x, str, kColorGreen);
}
void ColorHandler::PrintYellow(int y, int x, const char* str) {
  PrintColor(y, x, str, kColorYellow);
}
void ColorHandler::PrintBlue(int y, int x, const char* str) {
  PrintColor(y, x, str, kColorBlue);
}
void ColorHandler::PrintMagenta(int y, int x, const char* str) {
  PrintColor(y, x, str, kColorMagenta);
}
void ColorHandler::PrintCyan(int y, int x, const char* str) {
  PrintColor(y, x, str, kColorCyan);
}
void ColorHandler::PrintWhite(int y, int x, const char* str) {
  PrintColor(y, x, str, kColorWhite);
}
}  // namespace roadrun
