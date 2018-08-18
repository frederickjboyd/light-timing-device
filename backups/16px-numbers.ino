//// ========== LED Matrix Setup ===========


void print1(int x, int y) {
  matrix.drawLine(x+5, y+0, x+5, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+0, x+6, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+4, y+1, x+4, y+3, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+3, y+2, x+3, y+3, matrix.Color333(txtr, txtg, txtb));
}

void print2(int x, int y){
  matrix.drawLine(x+0, y+0, x+4, y+0, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+1, x+5, y+1, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+4, y+2, x+6, y+2, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+5, y+3, x+5, y+7, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+3, x+6, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+4, y+6, x+6, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+3, y+7, x+5, y+7, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+2, y+8, x+4, y+8, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+2, y+8, x+4, y+8, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+9, x+3, y+9, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+10, x+2, y+10, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+11, x+0, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+11, x+1, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+14, x+6, y+14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+15, x+6, y+15, matrix.Color333(txtr, txtg, txtb));
}

void print3(int x, int y){
  matrix.drawLine(x+0, y+0, x+4, y+0, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+1, x+5, y+1, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+15, x+4, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+14, x+5, y+14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+2, y+7, x+5, y+7, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+2, y+8, x+5, y+8, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+5, y+2, x+5, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+2, x+6, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+5, y+9, x+5, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+9, x+6, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+5, y+9, x+5, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+4, y+6, x+4, y+9, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+4, y+2, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+4, y+13, matrix.Color333(txtr, txtg, txtb));
}

void print4(int x, int y) {
  matrix.drawLine(x+5, y+0, x+5, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+0, x+6, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+11, x+6, y+11, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+10, x+6, y+10, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+9, x+5, y+0, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+9, x+6, y+0, matrix.Color333(txtr, txtg, txtb));
}

void print5(int x, int y) {
  matrix.drawLine(x+0, y+0, x+6, y+0, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+1, x+6, y+1, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+0, x+0, y+7, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+0, x+1, y+7, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+6, x+4, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+7, x+5, y+7, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+4, y+8, x+6, y+8, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+5, y+8, x+5, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+8, x+6, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+14, x+5, y+14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+15, x+4, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+4, y+13, matrix.Color333(txtr, txtg, txtb));
}


void print6(int x, int y) {
  matrix.drawLine(x+2, y+0, x+5, y+0, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+1, x+5, y+1, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+2, y+2, x+0, y+2, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+2, x+0, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+2, x+1, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+3, y+6, x+4, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+7, x+5, y+7, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+5, y+7, x+5, y+14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+8, x+6, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+14, x+5, y+14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+2, y+15, x+4, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+2, y+8, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+4, y+8, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+2, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+4, y+13, matrix.Color333(txtr, txtg, txtb));
}

void print7(int x, int y) {
  matrix.drawLine(x+0, y+0, x+6, y+0, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+1, x+6, y+1, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+5, y+0, x+5, y+5, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+0, x+6, y+5, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+11, x+5, y+3, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+2, y+11, x+6, y+3, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+11, x+1, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+2, y+11, x+2, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+3, y+11, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+4, y+9, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+5, y+7, matrix.Color333(txtr, txtg, txtb));
}

void print8(int x, int y) {
  matrix.drawLine(x+2, y+0, x+4, y+0, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+1, x+5, y+1, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+2, x+6, y+2, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+3, y+2, matrix.Color333(0, 0, 0));
  matrix.drawLine(x+0, y+6, x+6, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+3, y+6, matrix.Color333(0, 0, 0));
  matrix.drawLine(x+0, y+9, x+6, y+9, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+3, y+9, matrix.Color333(0, 0, 0));
  matrix.drawLine(x+0, y+13, x+6, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+3, y+13, matrix.Color333(0, 0, 0));
  matrix.drawLine(x+0, y+2, x+0, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+2, x+1, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+5, y+2, x+5, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+2, x+6, y+6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+9, x+0, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+9, x+1, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+5, y+9, x+5, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+9, x+6, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+2, y+15, x+4, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+14, x+5, y+14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+7, x+5, y+7, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+8, x+5, y+8, matrix.Color333(txtr, txtg, txtb));
}

void print9(int x, int y) {
  x = x + 6;
  y = y + 15;
  matrix.drawLine(x-2, y-0, x-5, y-0, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x-1, y-1, x-5, y-1, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x-2, y-2, x-0, y-2, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x-0, y-2, x-0, y-13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x-1, y-2, x-1, y-13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x-3, y-6, x-4, y-6, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x-0, y-7, x-5, y-7, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x-5, y-7, x-5, y-14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x-6, y-8, x-6, y-13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x-1, y-14, x-5, y-14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x-2, y-15, x-4, y-15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x-2, y-8, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x-4, y-8, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x-2, y-13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x-4, y-13, matrix.Color333(txtr, txtg, txtb));
}

void print0(int x, int y) {
  matrix.drawLine(x+2, y+0, x+4, y+0, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+1, x+5, y+1, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+14, x+5, y+14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+2, y+15, x+4, y+15, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+0, y+2, x+0, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+1, y+2, x+1, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+5, y+2, x+5, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+6, y+2, x+6, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+2, y+2, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+4, y+2, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+2, y+13, matrix.Color333(txtr, txtg, txtb));
  matrix.drawPixel(x+4, y+13, matrix.Color333(txtr, txtg, txtb));
}

