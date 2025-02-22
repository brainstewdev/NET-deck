#include<NetHelperLib.h>

#include<U8g2lib.h> 


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 


#define INDIRIZZO_DIS 0x3C  
#define PIN_BTN 2
#define PIN_POT_1 A0
#define PIN_POT_2 A1

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0);

#define imageWidth 128
#define imageHeight 64

const unsigned char bitmap [] U8X8_PROGMEM =
{
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x80, 0x01, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x3c, 0x78, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x83, 0x0f, 0xf0, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0x07, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x03, 0xc0, 0x0f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf8, 0x03, 0x80, 0x1f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0x01, 0x80, 0x3f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0x01, 0x80, 0x7f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0x01, 0x80, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0x01, 0x80, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0x01, 0x80, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0x83, 0x03, 0xc0, 0xc1, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x00, 0x02, 0x40, 0x00, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x43, 0x00, 0x04, 0x20, 0x00, 0xc6, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x18, 0x38, 0x00, 0xc4, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x23, 0x00, 0x38, 0x1c, 0x00, 0xc4, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x23, 0x00, 0x30, 0x1c, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x23, 0x00, 0x30, 0x0c, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x23, 0x00, 0x30, 0x0c, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x23, 0x00, 0x30, 0x1c, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x23, 0x00, 0x38, 0x1c, 0x00, 0x84, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x23, 0x00, 0x38, 0x1c, 0x00, 0xc4, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x63, 0x00, 0x30, 0x1c, 0x00, 0xc6, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0x00, 0x20, 0x0c, 0x00, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0x83, 0x01, 0x04, 0x81, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0x03, 0x80, 0xff, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0x07, 0xc0, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0x0f, 0xe0, 0xff, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0x1f, 0xf0, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0x3f, 0xf8, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0x3f, 0xfc, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0x3f, 0xfc, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfe, 0x3f, 0xfc, 0x7f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf8, 0x3f, 0xfc, 0x1f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0x3f, 0xfc, 0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x3f, 0xfc, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x78, 0x1e, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xc0, 0x07, 0x00, 0xfc, 0x80, 0xff, 0x83, 0xff, 0xc0, 0xc7, 0x07, 0x04, 0xfe, 0xff, 
	0xff, 0x3f, 0x80, 0x07, 0x00, 0x38, 0x00, 0xff, 0x03, 0x3f, 0x80, 0xc7, 0x03, 0x00, 0xfc, 0xff, 
	0xff, 0x1f, 0x00, 0x07, 0x00, 0x18, 0x00, 0xfe, 0x03, 0x1c, 0x00, 0xc7, 0x80, 0x00, 0xf8, 0xff, 
	0xff, 0x0f, 0x00, 0x06, 0x00, 0x08, 0x00, 0xfc, 0x03, 0x0c, 0x08, 0x06, 0x60, 0x00, 0xf0, 0xff, 
	0xff, 0x0f, 0x1f, 0x84, 0x7f, 0x08, 0x1e, 0x08, 0xf8, 0x0f, 0x1f, 0x04, 0x30, 0xf8, 0xe0, 0xff, 
	0xff, 0x87, 0x3f, 0x84, 0x7f, 0x88, 0x3f, 0x38, 0xf0, 0x87, 0x3f, 0x04, 0x38, 0xfc, 0xe1, 0xff, 
	0xff, 0x87, 0x7f, 0x84, 0xff, 0x87, 0x7f, 0x78, 0xc0, 0x87, 0x3f, 0x04, 0x3e, 0xfc, 0xe3, 0xff, 
	0xff, 0x87, 0x7f, 0x04, 0xfe, 0x87, 0x7f, 0xf8, 0x80, 0x87, 0x3f, 0x04, 0x3f, 0xfc, 0xe3, 0xff, 
	0xff, 0x87, 0x7f, 0x04, 0xfc, 0x87, 0x7f, 0x80, 0x03, 0x86, 0x3f, 0x04, 0x3c, 0xfc, 0xe3, 0xff, 
	0xff, 0x07, 0x7f, 0x04, 0xf8, 0x0f, 0x7f, 0x80, 0x07, 0x04, 0x3f, 0x04, 0x38, 0xfc, 0xe3, 0xff, 
	0xff, 0x0f, 0x7e, 0x04, 0xe0, 0x0f, 0x7e, 0x80, 0x1f, 0x08, 0x3e, 0x04, 0x60, 0xf0, 0xe3, 0xff, 
	0xff, 0x0f, 0x60, 0x84, 0x80, 0x1f, 0x60, 0x00, 0x00, 0x08, 0x20, 0x04, 0x40, 0x00, 0xe3, 0xff, 
	0xff, 0x1f, 0x40, 0xfc, 0x01, 0x1f, 0x40, 0x08, 0x00, 0x18, 0x00, 0xfc, 0x01, 0x00, 0xe2, 0xff, 
	0xff, 0x3f, 0x40, 0xfc, 0x07, 0x7e, 0x40, 0x08, 0x00, 0x38, 0x00, 0xfc, 0x03, 0x00, 0xe2, 0xff, 
	0xff, 0xff, 0x41, 0xfc, 0x0f, 0xfc, 0x41, 0x1c, 0x00, 0xf8, 0x41, 0xfc, 0x0f, 0x0c, 0xe2, 0xff

};


#define logoWidth 20
#define logoHeight 20

const unsigned char epd_bitmap_logo_arasaka_only [] PROGMEM = {
	0x00, 0x06, 0x00, 0xe0, 0x3f, 0x00, 0x70, 0xe7, 0x00, 0x98, 0x9f, 0x01, 0x8c, 0x1f, 0x03, 0x86, 
	0x1f, 0x02, 0xb6, 0xff, 0x06, 0xfa, 0xff, 0x05, 0xfe, 0xf6, 0x07, 0xff, 0xf6, 0x07, 0xff, 0xf6, 
	0x07, 0xfa, 0xf6, 0x05, 0x82, 0x1f, 0x04, 0x06, 0x0f, 0x06, 0x06, 0x06, 0x02, 0x0c, 0x06, 0x03, 
	0x18, 0x86, 0x01, 0x70, 0xe6, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x06, 0x00
};


bool menu = true;

uint8_t numLiv;
char diff;

const char* difficolta[] = {
  "Facile",
  "Normale",
  "Discreta",
  "Avanzata",
};

void setup() {
  u8g2.begin();
  // imposto pin
  pinMode(PIN_BTN, INPUT);
  pinMode(PIN_POT_1, INPUT);
  pinMode(PIN_POT_2, INPUT);
  //Set font.
  u8g2.setFont(u8g2_font_5x8_tf);

  u8g2.firstPage();
  do {  
    drawWelcomeScreen();    
  } while( u8g2.nextPage() );
  delay(1000);  // to wait a while so that everyone can see your nice welcome screen
}

void drawWelcomeScreen(){
  u8g2.drawXBMP(0,0, imageWidth, imageHeight, bitmap);
}

char** piani;

void draw(){

  if(menu){
    u8g2.setCursor(10, 10);
    u8g2.print(F("Numero Livelli: "));
    u8g2.print(numLiv);
    u8g2.setCursor(10, 30);

    u8g2.print(F("Difficoltà:"));
    u8g2.print(difficolta[diff]);

  }else{
    u8g2.setCursor(10, 10);
    for(int i = 0; i < 7 && (i +diff < numLiv);i++){
      u8g2.setCursor(10,10*(i));
      u8g2.print(piani[i+diff]);
    }
  }
  // disegna il logo piccolo
  u8g2.drawXBMP(108,44, logoWidth, logoHeight, epd_bitmap_logo_arasaka_only);
}

void update(){
  if(menu){
  if(digitalRead(PIN_BTN) == HIGH){
      // vai in mod visualizzazione
      menu = false;
      // crea il labirinto
      piani = NetHelperLib::generaPiani(numLiv, diff, 0);
    }
    numLiv = map(analogRead(PIN_POT_1),0,1024, 3, 15);
    // calcolo difficoltà
    diff = map(analogRead(PIN_POT_2), 0, 1024, 0, 4);
  }else{
    // uso diff per scorrere:
    diff = map(analogRead(PIN_POT_1),0,1024, 0, numLiv);
  }
}

void loop() {
  u8g2.firstPage();

  do {
    update();
    draw();
  } while (u8g2.nextPage());
  //Delay before repeating the loop.
  delay(50);
}