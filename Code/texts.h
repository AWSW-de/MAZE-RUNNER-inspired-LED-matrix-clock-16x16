//####################################################################################################################################################

// Clear the complete display:
void MAZE_CLEAR() {
  for (uint16_t i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, 0, 0, 0);
  }
  pixels.show();
}

//####################################################################################################################################################

// Show runner :)
void showrunner(int digit, String letter, int wait, uint32_t c, uint32_t r, int delDisplayStart, int delDisplayEnd) {

  if (delDisplayStart == 1) {
    MAZE_CLEAR();
  }

  int myArray[25];
  memset(myArray, 0, sizeof(myArray));

  // DIGIT 1: 11111
  // ##############

  if (digit == 1) {

    if (letter == "0") {
      int myArray2 [] = {45, 44, 43, 42, 41, 54, 73, 86, 105, 106, 107, 108, 109, 82, 77, 50, 45};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "1") {
      int myArray2 [] = {41, 54, 73, 86, 105};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "2") {
      int myArray2 [] = {45, 44, 43, 42, 41, 54, 73, 74, 75, 76, 77, 82, 109, 108, 107, 106, 105};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "A") {
      int myArray2 [] = {109, 82, 77, 76, 75, 76, 77, 50, 45, 44, 43, 42, 41, 54, 73, 74, 73, 86, 105};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "M") {
      int myArray2 [] = {109, 82, 77, 50, 45, 44, 43, 52, 75, 52, 43, 42, 41, 54, 73, 86, 105};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "C") {
      int myArray2 [] = {105, 106, 107, 108, 109, 82, 77, 50, 45, 44, 43, 42, 41};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }
  }

  // DIGIT 2: 22222
  // ##############

  if (digit == 2) {

    if (letter == "0") {
      int myArray2 [] = {38, 37, 36, 35, 34, 61, 66, 93, 98, 99, 100, 101, 102, 89, 70, 57, 38};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }


    if (letter == "1") {
      int myArray2 [] = {34, 61, 66, 93, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "2") {
      int myArray2 [] = {38, 37, 36, 35, 34, 61, 66, 67, 68, 69, 70, 89, 102, 101, 100, 99, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "3") {
      int myArray2 [] = {38, 37, 36, 35, 34, 61, 66, 67, 68, 69, 70, 69, 68, 67, 66, 93, 98, 99, 100, 101, 102};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "4") {
      int myArray2 [] = {38, 57, 70, 69, 68, 67, 66, 61, 34, 61, 66, 93, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "5") {
      int myArray2 [] = {34, 35, 36, 37, 38, 57, 70, 69, 68, 67, 66, 93, 98, 99, 100, 101, 102};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "6") {
      int myArray2 [] = {34, 35, 36, 37, 38, 57, 70, 69, 68, 67, 66, 93, 98, 99, 100, 101, 102, 89, 70, 57, 38, 37, 36, 35, 34};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "7") {
      int myArray2 [] = {38, 37, 36, 35, 34, 61, 66, 93, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "8") {
      int myArray2 [] = {98, 99, 100, 101, 102, 89, 70, 69, 70, 57, 38, 37, 36, 35, 34, 61, 66, 67, 68, 67, 66, 93, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "9") {
      int myArray2 [] = {38, 37, 36, 35, 34, 61, 66, 67, 68, 69, 70, 57, 38, 37, 36, 35, 34, 61, 66, 93, 98, 99, 100, 101, 102};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "A") {
      int myArray2 [] = {102, 89, 70, 57, 38, 37, 36, 35, 34, 61, 66, 67, 68, 69, 68, 67, 66, 93, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "W") {
      int myArray2 [] = {38, 57, 70, 89, 102, 101, 100, 91, 68, 91, 100, 99, 98, 93, 66, 61, 34};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "LO") {
      int myArray2 [] = {38, 57, 70, 89, 102, 101, 100, 99, 98, 36, 35, 34, 61, 66, 67, 68, 59, 36};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }
  }

  // DIGIT 3: 33333
  // ##############

  if (digit == 3) {

    if (letter == "0") {
      int myArray2 [] = {150, 149, 148, 147, 146, 173, 178, 205, 210, 211, 212, 213, 214, 201, 182, 169, 150};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "1") {
      int myArray2 [] = {150, 169, 182, 201, 214};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "2") {
      int myArray2 [] = {146, 147, 148, 149, 150, 169, 182, 181, 180, 179, 178, 205, 210, 211, 212, 213, 214};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "3") {
      int myArray2 [] = {146, 147, 148, 149, 150, 169, 182, 181, 180, 179, 178, 179, 180, 181, 182, 201, 214, 213, 212, 211, 210};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "4") {
      int myArray2 [] = {146, 173, 178, 179, 180, 181, 182, 169, 150, 169, 182, 201, 214};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "5") {
      int myArray2 [] = {150, 149, 148, 147, 146, 173, 178, 179, 180, 181, 182, 201, 214, 213, 212, 211, 210};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "S") {
      int myArray2 [] = {150, 149, 148, 147, 146, 173, 178, 179, 180, 181, 182, 201, 214, 213, 212, 211, 210};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "Z") {
      int myArray2 [] = {214, 213, 212, 211, 210, 204, 180, 170, 150, 149, 148, 147, 146};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "C") {
      int myArray2 [] = {150, 149, 148, 147, 146, 173, 178, 205, 210, 211, 212, 213, 214};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }
  }

  // DIGIT 4: 44444
  // ##############

  if (digit == 4) {

    if (letter == "0") {
      int myArray2 [] = {157, 156, 155, 154, 153, 166, 185, 198, 217, 218, 219, 220, 221, 194, 189, 162, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "1") {
      int myArray2 [] = {221, 194, 189, 162, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "2") {
      int myArray2 [] = {153, 154, 155, 156, 157, 162, 189, 188, 187, 186, 185, 198, 217, 218, 219, 220, 221};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "3") {
      int myArray2 [] = {153, 154, 155, 156, 157, 162, 189, 188, 187, 186, 185, 186, 187, 188, 189, 194, 221, 220, 219, 218, 217};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "4") {
      int myArray2 [] = {153, 166, 185, 186, 187, 188, 189, 194, 221, 194, 189, 162, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "5") {
      int myArray2 [] = {157, 156, 155, 154, 153, 166, 185, 186, 187, 188, 189, 194, 221, 220, 219, 218, 217};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "6") {
      int myArray2 [] = {157, 156, 155, 154, 153, 166, 185, 186, 187, 188, 189, 194, 221, 220, 219, 218, 217, 198, 185, 166, 153, 154, 155, 156, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "7") {
      int myArray2 [] = {153, 154, 155, 156, 157, 162, 189, 194, 221};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "8") {
      int myArray2 [] = {153, 154, 155, 156, 157, 162, 189, 188, 187, 186, 185, 166, 185, 198, 217, 218, 219, 220, 221, 194, 189, 162, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "9") {
      int myArray2 [] = {217, 218, 219, 220, 221, 194, 189, 162, 157, 156, 155, 154, 153, 166, 185, 186, 187, 188, 189};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "E") {
      int myArray2 [] = {157, 156, 155, 154, 153, 166, 185, 186, 187, 186, 185, 198, 217, 218, 219, 220, 221};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "W") {
      int myArray2 [] = {153, 166, 185, 198, 217, 218, 219, 196, 187, 196, 219, 220, 221, 194, 189, 162, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "K") {
      int myArray2 [] = {153, 166, 185, 198, 217, 198, 185, 186, 187, 163, 157, 163, 187, 195, 221};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }
  }

  for (int element : myArray) {
    if (element != 0) {
      pixels.setPixelColor(element, r);
      pixels.show();
      delay(wait);
      pixels.setPixelColor(element, c);
    }
  }
  pixels.show();
  delay(wait);


  if (delDisplayEnd == 1) {
    MAZE_CLEAR();
  }
}

//####################################################################################################################################################

// Show texts and numbers on the 4 digit positions:
void showtext(int digit, String letter, int wait, uint32_t c, int delDisplayStart, int delDisplayEnd) {

  if (delDisplayStart == 1) {
    MAZE_CLEAR();
  }

  // 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

  int myArray[25];
  memset(myArray, 0, sizeof(myArray));

  // DIGIT 1: 11111
  // ########

  if (digit == 1) {
    // Random digit 1 position:
    int myArrayDigit1[25] = {45, 44, 43, 42, 41, 50, 51, 52, 53, 54, 77, 76, 75, 74, 73, 82, 83, 84, 85, 86, 109, 108, 107, 106, 105};
    for (int element : myArrayDigit1) {
      pixels.setPixelColor(element, pixels.Color(random(256), random(256), random(256)));
    }

    if (letter == "0") {
      int myArray2 [] = {45, 44, 43, 42, 41, 54, 73, 86, 105, 106, 107, 108, 109, 82, 77, 50, 45};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "1") {
      int myArray2 [] = {41, 54, 73, 86, 105};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "2") {
      int myArray2 [] = {45, 44, 43, 42, 41, 54, 73, 74, 75, 76, 77, 82, 109, 108, 107, 106, 105};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "A") {
      int myArray2 [] = {109, 82, 77, 76, 75, 76, 77, 50, 45, 44, 43, 42, 41, 54, 73, 74, 73, 86, 105};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "M") {
      int myArray2 [] = {109, 82, 77, 50, 45, 44, 43, 52, 75, 52, 43, 42, 41, 54, 73, 86, 105};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "C") {
      int myArray2 [] = {105, 106, 107, 108, 109, 82, 77, 50, 45, 44, 43, 42, 41};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "W") {
      int myArray2 [] = {45, 50, 77, 82, 109, 108, 107, 84, 75, 106, 105, 86, 73, 54, 41};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "T") {
      int myArray2 [] = {45, 44, 43, 42, 41, 52, 75, 84, 107};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

  }

  // 222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222

  // DIGIT 2: 22222
  // ########
  if (digit == 2) {

    // Random digit 2 position:
    int myArrayDigit2[25] = {38, 37, 36, 35, 34, 57, 58, 59, 60, 61, 70, 69, 68, 67, 66, 89, 90, 91, 92, 93, 102, 101, 100, 99, 98};
    for (int element : myArrayDigit2) {
      pixels.setPixelColor(element, pixels.Color(random(256), random(256), random(256)));
    }

    if (letter == "0") {
      int myArray2 [] = {38, 37, 36, 35, 34, 61, 66, 93, 98, 99, 100, 101, 102, 89, 70, 57, 38};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "1") {
      int myArray2 [] = {34, 61, 66, 93, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "2") {
      int myArray2 [] = {38, 37, 36, 35, 34, 61, 66, 67, 68, 69, 70, 89, 102, 101, 100, 99, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "3") {
      int myArray2 [] = {38, 37, 36, 35, 34, 61, 66, 67, 68, 69, 70, 69, 68, 67, 66, 93, 98, 99, 100, 101, 102};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "4") {
      int myArray2 [] = {38, 57, 70, 69, 68, 67, 66, 61, 34, 61, 66, 93, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "5") {
      int myArray2 [] = {34, 35, 36, 37, 38, 57, 70, 69, 68, 67, 66, 93, 98, 99, 100, 101, 102};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "6") {
      int myArray2 [] = {34, 35, 36, 37, 38, 57, 70, 69, 68, 67, 66, 93, 98, 99, 100, 101, 102, 89, 70, 57, 38, 37, 36, 35, 34};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "7") {
      int myArray2 [] = {38, 37, 36, 35, 34, 61, 66, 93, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "8") {
      int myArray2 [] = {98, 99, 100, 101, 102, 89, 70, 69, 70, 57, 38, 37, 36, 35, 34, 61, 66, 67, 68, 67, 66, 93, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "9") {
      int myArray2 [] = {38, 37, 36, 35, 34, 61, 66, 67, 68, 69, 70, 57, 38, 37, 36, 35, 34, 61, 66, 93, 98, 99, 100, 101, 102};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "A") {
      int myArray2 [] = {102, 89, 70, 57, 38, 37, 36, 35, 34, 61, 66, 67, 68, 69, 68, 67, 66, 93, 98};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "W") {
      int myArray2 [] = {38, 57, 70, 89, 102, 101, 100, 91, 68, 91, 100, 99, 98, 93, 66, 61, 34};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "LO") {
      int myArray2 [] = {38, 57, 70, 89, 102, 101, 100, 99, 98, 36, 35, 34, 61, 66, 67, 68, 59, 36};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "I") {
      int myArray2 [] = {36, 59, 68, 91, 100};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

  }

  // 333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333

  // DIGIT 3: 33333
  // ########
  if (digit == 3) {

    // Random digit 3 position:
    int myArrayDigit3[25] = {146, 147, 148, 149, 150, 173, 172, 171, 170, 169, 178, 179, 180, 181, 182, 205, 204, 203, 202, 201, 210, 211, 212, 213, 214};
    for (int element : myArrayDigit3) {
      pixels.setPixelColor(element, pixels.Color(random(256), random(256), random(256)));
    }

    if (letter == "0") {
      int myArray2 [] = {150, 149, 148, 147, 146, 173, 178, 205, 210, 211, 212, 213, 214, 201, 182, 169, 150};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "1") {
      int myArray2 [] = {150, 169, 182, 201, 214};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "2") {
      int myArray2 [] = {146, 147, 148, 149, 150, 169, 182, 181, 180, 179, 178, 205, 210, 211, 212, 213, 214};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "3") {
      int myArray2 [] = {146, 147, 148, 149, 150, 169, 182, 181, 180, 179, 178, 179, 180, 181, 182, 201, 214, 213, 212, 211, 210};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "4") {
      int myArray2 [] = {146, 173, 178, 179, 180, 181, 182, 169, 150, 169, 182, 201, 214};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "5") {
      int myArray2 [] = {150, 149, 148, 147, 146, 173, 178, 179, 180, 181, 182, 201, 214, 213, 212, 211, 210};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "C") {
      int myArray2 [] = {150, 149, 148, 147, 146, 173, 178, 205, 210, 211, 212, 213, 214};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "F") {
      int myArray2 [] = {146, 147, 148, 149, 150, 173, 178, 205, 210, 179, 180};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "M") {
      int myArray2 [] = {146, 147, 148, 149, 150, 171, 180, 173, 178, 205, 210, 169, 182, 201, 214};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "S") {
      int myArray2 [] = {150, 149, 148, 147, 146, 173, 178, 179, 180, 181, 182, 201, 214, 213, 212, 211, 210};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "Z") {
      int myArray2 [] = {214, 213, 212, 211, 210, 204, 180, 170, 150, 149, 148, 147, 146};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

  }

  // 444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444

  // DIGIT 4: 44444
  // ########
  if (digit == 4) {

    // Random digit 4 position:
    int myArrayDigit4[25] = {153, 154, 155, 156, 157, 166, 165, 164, 163, 162, 185, 186, 187, 188, 189, 198, 197, 196, 195, 194, 217, 218, 219, 220, 221};
    for (int element : myArrayDigit4) {
      pixels.setPixelColor(element, pixels.Color(random(256), random(256), random(256)));
    }

    if (letter == "0") {
      int myArray2 [] = {157, 156, 155, 154, 153, 166, 185, 198, 217, 218, 219, 220, 221, 194, 189, 162, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "1") {
      int myArray2 [] = {221, 194, 189, 162, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "2") {
      int myArray2 [] = {153, 154, 155, 156, 157, 162, 189, 188, 187, 186, 185, 198, 217, 218, 219, 220, 221};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "3") {
      int myArray2 [] = {153, 154, 155, 156, 157, 162, 189, 188, 187, 186, 185, 186, 187, 188, 189, 194, 221, 220, 219, 218, 217};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "4") {
      int myArray2 [] = {153, 166, 185, 186, 187, 188, 189, 194, 221, 194, 189, 162, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "5") {
      int myArray2 [] = {157, 156, 155, 154, 153, 166, 185, 186, 187, 188, 189, 194, 221, 220, 219, 218, 217};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "6") {
      int myArray2 [] = {157, 156, 155, 154, 153, 166, 185, 186, 187, 188, 189, 194, 221, 220, 219, 218, 217, 198, 185, 166, 153, 154, 155, 156, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "7") {
      int myArray2 [] = {153, 154, 155, 156, 157, 162, 189, 194, 221};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "8") {
      int myArray2 [] = {153, 154, 155, 156, 157, 162, 189, 188, 187, 186, 185, 166, 185, 198, 217, 218, 219, 220, 221, 194, 189, 162, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "9") {
      int myArray2 [] = {217, 218, 219, 220, 221, 194, 189, 162, 157, 156, 155, 154, 153, 166, 185, 186, 187, 188, 189};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "E") {
      int myArray2 [] = {157, 156, 155, 154, 153, 166, 185, 186, 187, 186, 185, 198, 217, 218, 219, 220, 221};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "I") {
      int myArray2 [] = {155, 164, 187, 196, 219};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "K") {
      int myArray2 [] = {153, 166, 185, 198, 217, 198, 185, 186, 187, 163, 157, 163, 187, 195, 221};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

    if (letter == "W") {
      int myArray2 [] = {153, 166, 185, 198, 217, 218, 219, 196, 187, 196, 219, 220, 221, 194, 189, 162, 157};
      memcpy(myArray, myArray2, sizeof(myArray2));
    }

  }

  for (int element : myArray) {
    if (element != 0) {
    pixels.setPixelColor(element, c);
    }
  }
  pixels.show();
  delay(wait);

  if (delDisplayEnd == 1) {
    MAZE_CLEAR();
  }
}
