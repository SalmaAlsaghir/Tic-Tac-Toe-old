#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

void setup();
void drawBoard();
bool placeMarker(int row, int col);
int winner();
void swapPlayerAndMarker();
void game();

#endif // TIC_TAC_TOE_H
