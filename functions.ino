// ================================================================
// ===                    GENERAL FUNCTIONS                     ===
// ================================================================

int readButtons() {
  int temp = 0;
  if (digitalRead(button1) == HIGH || digitalRead(remoteA) == HIGH || digitalRead(button2) == HIGH || digitalRead(remoteB) == HIGH) {
    if (digitalRead(button2) == HIGH || digitalRead(remoteB) == HIGH) {
      temp = 2;
    }
    else if (digitalRead(button1) == HIGH || digitalRead(remoteA) == HIGH) {
      temp = 1;
    }
    while (digitalRead(button1) == HIGH || digitalRead(remoteA) == HIGH || digitalRead(button2) == HIGH || digitalRead(remoteB) == HIGH) {
    }  
  }
  return temp;
}


//Calibrate accelerometers
void calibrate() {
  //reset value
  cnt = 0;
  ax1avg = 0;
  ay1avg = 0;
  az1avg = 0;
  ax2avg = 0;
  ay2avg = 0;
  az2avg = 0;

   while (cnt < 484) {
    sensor1.getAcceleration(&ax1, &ay1, &az1);
    sensor2.getAcceleration(&ax2, &ay2, &az2);
    ax1avg = ax1avg + ax1;
    ay1avg = ay1avg + ay1;
    az1avg = az1avg + az1;
    ax2avg = ax2avg + ax2;
    ay2avg = ay2avg + ay2;
    az2avg = az2avg + az2;
    cnt++;
  }
  ax1avg = ax1avg / 484;
  ay1avg = ay1avg / 484;
  az1avg = az1avg / 484;
  ax2avg = ax2avg / 484;
  ay2avg = ay2avg / 484;
  az2avg = az2avg / 484;
}

// printMode takes a single letter (the mode) and prints that letter to both displays
void printMode(char mode) {
  matrix.setCursor(43, 9);
  matrix.setTextSize(2);
  matrix.setTextColor(matrix.Color333(txtr, txtg, txtb));
  matrix.print(mode);
  matrix.setCursor(11, 9);
  matrix.print(mode);
}

void printTime(int value, int x, int y) {
  // ==================================================
  // ===    PRINTING IN MILLISECONDS (I.E. X.XX)    ===
  // ==================================================
  x = x + 0;
  switch (value/1000) {
    case 0: print0(x, y); value = value - (value/1000)*1000; break;
    case 1: print1(x-1, y); value = value - (value/1000)*1000; break;
    case 2: print2(x, y); value = value - (value/1000)*1000; break;
    case 3: print3(x, y); value = value - (value/1000)*1000; break;
    case 4: print4(x, y); value = value - (value/1000)*1000; break;
    case 5: print5(x, y); value = value - (value/1000)*1000; break;
    case 6: print6(x, y); value = value - (value/1000)*1000; break;
    case 7: print7(x, y); value = value - (value/1000)*1000; break;
    case 8: print8(x, y); value = value - (value/1000)*1000; break;
    case 9: print9(x, y); value = value - (value/1000)*1000; break;
  }

  x = x + 8;
  switch (value/100) {
    case 0: print0(x, y); value = value - (value/1000)*1000; break;
    case 1: print1(x-1, y); value = value - (value/100)*100; break;
    case 2: print2(x, y); value = value - (value/100)*100; break;
    case 3: print3(x, y); value = value - (value/100)*100; break;
    case 4: print4(x, y); value = value - (value/100)*100; break;
    case 5: print5(x, y); value = value - (value/100)*100; break;
    case 6: print6(x, y); value = value - (value/100)*100; break;
    case 7: print7(x, y); value = value - (value/100)*100; break;
    case 8: print8(x, y); value = value - (value/100)*100; break;
    case 9: print9(x, y); value = value - (value/100)*100; break;
  }

  x = x + 8;
  switch (value/10) {
    case 0: print0(x, y); value = value - (value/10)*10; break;
    case 1: print1(x-1, y); value = value - (value/10)*10; break;
    case 2: print2(x, y); value = value - (value/10)*10; break;
    case 3: print3(x, y); value = value - (value/10)*10; break;
    case 4: print4(x, y); value = value - (value/10)*10; break;
    case 5: print5(x, y); value = value - (value/10)*10; break;
    case 6: print6(x, y); value = value - (value/10)*10; break;
    case 7: print7(x, y); value = value - (value/10)*10; break;
    case 8: print8(x, y); value = value - (value/10)*10; break;
    case 9: print9(x, y); value = value - (value/10)*10; break;
  }

  x = x + 8;
  switch (value) {
    case 0: print0(x, y); break;
    case 1: print1(x-1, y); break;
    case 2: print2(x, y); break;
    case 3: print3(x, y); break;
    case 4: print4(x, y); break;
    case 5: print5(x, y); break;
    case 6: print6(x, y); break;
    case 7: print7(x, y); break;
    case 8: print8(x, y); break;
    case 9: print9(x, y); break;
  }
  
  
  // ===================================================
  // ===       PRINTING IN SECONDS (I.E. X.XX)       ===
  // ===================================================
  /*if (value > 19999) {
    matrix.setCursor(x+1, x+1);
    matrix.setTextSize(1);
    matrix.print("Time");
    matrix.setCursor(x+1, x+9);
    matrix.print("Out");
    return;
  }

  //======= PRINT TENS DIGIT =======
  if (value > 9999) {
    print1(x-3, y);
    value = value - 10000;
  }

  //======= PRINT ONES DIGIT =======
  x = x + 5; // Set x cursor
  switch (value/1000) {
    case 0: print0(x, y); value = value - (value/1000)*1000; break;
    case 1: print1(x-1, y); value = value - (value/1000)*1000; break;
    case 2: print2(x, y); value = value - (value/1000)*1000; break;
    case 3: print3(x, y); value = value - (value/1000)*1000; break;
    case 4: print4(x, y); value = value - (value/1000)*1000; break;
    case 5: print5(x, y); value = value - (value/1000)*1000; break;
    case 6: print6(x, y); value = value - (value/1000)*1000; break;
    case 7: print7(x, y); value = value - (value/1000)*1000; break;
    case 8: print8(x, y); value = value - (value/1000)*1000; break;
    case 9: print9(x, y); value = value - (value/1000)*1000; break;
  }
  x = x - 5; //reset cursor

  
  //======= PRINT DECIMAL PLACE =======
  matrix.drawLine(x+13, y+12, x+13, y+14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+14, y+12, x+14, y+14, matrix.Color333(txtr, txtg, txtb));
  matrix.drawLine(x+15, y+12, x+15, y+14, matrix.Color333(txtr, txtg, txtb));

  //======== PRINT TENTH DIGIT =======
  x = x + 17;
  switch (value/100) {
    case 0: print0(x, y); value = value - (value/1000)*1000; break;
    case 1: print1(x-1, y); value = value - (value/100)*100; break;
    case 2: print2(x, y); value = value - (value/100)*100; break;
    case 3: print3(x, y); value = value - (value/100)*100; break;
    case 4: print4(x, y); value = value - (value/100)*100; break;
    case 5: print5(x, y); value = value - (value/100)*100; break;
    case 6: print6(x, y); value = value - (value/100)*100; break;
    case 7: print7(x, y); value = value - (value/100)*100; break;
    case 8: print8(x, y); value = value - (value/100)*100; break;
    case 9: print9(x, y); value = value - (value/100)*100; break;
  }
  x = x - 17;

  //======= PRINT HUNDREDTH DIGIT =======
  x = x + 25;
  matrix.setCursor(x, y);
  switch (value/10) {
    case 0: print0(x, y); value = value - (value/10)*10; break;
    case 1: print1(x-1, y); value = value - (value/10)*10; break;
    case 2: print2(x, y); value = value - (value/10)*10; break;
    case 3: print3(x, y); value = value - (value/10)*10; break;
    case 4: print4(x, y); value = value - (value/10)*10; break;
    case 5: print5(x, y); value = value - (value/10)*10; break;
    case 6: print6(x, y); value = value - (value/10)*10; break;
    case 7: print7(x, y); value = value - (value/10)*10; break;
    case 8: print8(x, y); value = value - (value/10)*10; break;
    case 9: print9(x, y); value = value - (value/10)*10; break;
  }
  x = x - 25;
  */
}

