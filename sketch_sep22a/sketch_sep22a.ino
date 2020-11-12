#include "GameField.cpp"




// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)



const byte X = A0; // постоянная для координаты Х

const byte Y = A1; // постоянная для координаты Y

// Hardware SPI (faster, but must use certain hardware pins):
// SCK is LCD serial clock (SCLK) - this is pin 13 on Arduino Uno
// MOSI is LCD DIN - this is pin 11 on an Arduino Uno
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
// Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);
// Note with hardware SPI MISO and SS pins aren't used but will still be read
// and written to during SPI transfer.  Be careful sharing these pins!


GameField *gameField = new GameField();
Hero  *hero = new Hero(42, 48);
void setup()   {
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  Serial.begin(9600);

  
  gameField->createGameField();
  


  
//  display.display();
//  display.clearDisplay();
//  Platform *platform = new Platform(0, 0, 82, 0);
//  display.drawLine(platform->getX0() , 0 , 84, 0, BLACK);
//  display.drawLine(0 , 10 , 84, 10, BLACK);
//  display.display();
//  Stairs *stairs = new Stairs(5, 48, 5, 16);
//  drawStairs(stairs);
//  display.display();
 
 
}


void loop() {
  hero->moves(analogRead(A0));
  gameField->drawGameField(hero);

//  display.setTextSize(1);
//  display.setTextColor(BLACK);
//  display.setCursor(0,0);
//  display.println(analogRead(A0));
//
//  display.display();
//  display.clearDisplay();
//  display.display();
}
