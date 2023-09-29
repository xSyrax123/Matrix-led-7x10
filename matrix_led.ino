#define CD4017_CLK PORTB1
#define CD4017_RST PORTB2
#define SERIAL_DATA PORTB3
#define ST_CLK PORTB4
#define SH_CLK PORTB5
#define DELAY 15

/*
 char_data is a two dimensional constant array that holds the 5-bit column values
 of individual rows for ASCII characters that are to be displayed on a 7x10 matrix. 
*/
const byte char_data[95][7] = {
  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, // space
  {0x4, 0x4, 0x4, 0x4, 0x4, 0x0, 0x4}, // !
  {0xA, 0xA, 0xA, 0x0, 0x0, 0x0, 0x0}, // "
  {0xA, 0xA, 0x1F, 0xA, 0x1F, 0xA, 0xA}, // #
  {0x4, 0xF, 0x14, 0xE, 0x5, 0x1E, 0x4}, // $
  {0x18, 0x19, 0x2, 0x4, 0x8, 0x13, 0x3}, // %
  {0x8, 0x14, 0x14, 0x8, 0x15, 0x12, 0xD}, // &
  {0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0}, // '
  {0x4, 0x8, 0x10, 0x10, 0x10, 0x8, 0x4}, // (
  {0x4, 0x2, 0x1, 0x1, 0x1, 0x2, 0x4}, // )
  {0x4, 0x15, 0xE, 0x4, 0xE, 0x15, 0x4}, // *
  {0x0, 0x4, 0x4, 0x1F, 0x4, 0x4, 0x0}, // +
  {0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x8}, // ,
  {0x0, 0x0, 0x0, 0x1F, 0x0, 0x0, 0x0}, // -
  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4}, // .
  {0x0, 0x1, 0x2, 0x4, 0x8, 0x10, 0x0}, // /
  {0xE, 0x11, 0x13, 0x15, 0x19, 0x11, 0xE}, // 0
  {0x6, 0xC, 0x4, 0x4, 0x4, 0x4, 0xE}, // 1
  {0xE, 0x11, 0x1, 0x6, 0x8, 0x10, 0x1F}, // 2
  {0x1F, 0x1, 0x2, 0x6, 0x1, 0x11, 0xF}, // 3
  {0x2, 0x6, 0xA, 0x12, 0x1F, 0x2, 0x2}, // 4
  {0x1F, 0x10, 0x1E, 0x1, 0x1, 0x11, 0xE}, // 5
  {0xE, 0x11, 0x10, 0x1E, 0x11, 0x11, 0xE}, // 6
  {0x1F, 0x1, 0x2, 0x4, 0x8, 0x8, 0x8}, // 7
  {0xE, 0x11, 0x11, 0xE, 0x11, 0x11, 0xE}, // 8
  {0xE, 0x11, 0x11, 0xF, 0x1, 0x11, 0xE}, // 9
  {0x0, 0x0, 0x4, 0x0, 0x4, 0x0, 0x0}, // :
  {0x0, 0x0, 0x4, 0x0, 0x4, 0x4, 0x8}, // ;
  {0x2, 0x4, 0x8, 0x10, 0x8, 0x4, 0x2}, // <
  {0x0, 0x0, 0x1F, 0x0, 0x1F, 0x0, 0x0}, // =
  {0x8, 0x4, 0x2, 0x1, 0x2, 0x4, 0x8}, // >
  {0xE, 0x11, 0x1, 0x2, 0x4, 0x0, 0x4}, // ?
  {0xE, 0x11, 0x17, 0x15, 0x16, 0x10, 0xF}, // @
  {0xE, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11}, // A
  {0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E}, // B
  {0xE, 0x11, 0x10, 0x10, 0x10, 0x11, 0xE}, // C
  {0x1E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E}, // D
  {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F}, // E
  {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10}, // F
  {0xE, 0x11, 0x10, 0x17, 0x15, 0x11, 0xE}, // G
  {0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11}, // H
  {0x1F, 0x4, 0x4, 0x4, 0x4, 0x4, 0x1F}, // I
  {0x1, 0x1, 0x1, 0x1, 0x1, 0x11, 0xE}, // J
  {0x11, 0x11, 0x12, 0x1C, 0x12, 0x11, 0x11}, // K
  {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F}, // L
  {0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11}, // M
  {0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11}, // N
  {0xE, 0x11, 0x11, 0x11, 0x11, 0x11, 0xE}, // O
  {0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10}, // P
  {0xE, 0x11, 0x11, 0x11, 0x15, 0x13, 0xF}, // Q
  {0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x11}, // R
  {0xF, 0x10, 0x10, 0xE, 0x1, 0x1, 0x1E}, // S
  {0x1F, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4}, // T
  {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xE}, // U
  {0x11, 0x11, 0x11, 0x11, 0x11, 0xA, 0x4}, // V
  {0x11, 0x11, 0x11, 0x15, 0x15, 0x1B, 0x11}, // W
  {0x11, 0x11, 0xA, 0x4, 0xA, 0x11, 0x11}, // X
  {0x11, 0x11, 0xA, 0x4, 0x4, 0x4, 0x4}, // Y
  {0x1F, 0x1, 0x2, 0x4, 0x8, 0x10, 0x1F}, // Z
  {0xE, 0x8, 0x8, 0x8, 0x8, 0x8, 0xE}, // [
  {0x0, 0x10, 0x8, 0x4, 0x2, 0x1, 0x0}, // backslash
  {0xE, 0x2, 0x2, 0x2, 0x2, 0x2, 0xE}, // ]
  {0x0, 0x0, 0x4, 0xA, 0x11, 0x0, 0x0}, // ^
  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1F}, // _
  {0x8, 0x4, 0x2, 0x0, 0x0, 0x0, 0x0}, // `
  {0x0, 0x0, 0xE, 0x1, 0xF, 0x11, 0xF}, // a
  {0x10, 0x10, 0x10, 0x1E, 0x11, 0x11, 0x1E}, // b
  {0x0, 0x0, 0xE, 0x11, 0x10, 0x11, 0xE}, // c
  {0x1, 0x1, 0x1, 0xF, 0x11, 0x11, 0xF}, // d
  {0x0, 0x0, 0xE, 0x11, 0x1F, 0x10, 0xF}, // e
  {0xE, 0x9, 0x1C, 0x8, 0x8, 0x8, 0x8}, // f
  {0x0, 0x0, 0xE, 0x11, 0xF, 0x1, 0xE}, // g
  {0x10, 0x10, 0x10, 0x1E, 0x11, 0x11, 0x11}, // h
  {0x4, 0x0, 0x4, 0x4, 0x4, 0x4, 0xE}, // i
  {0x1, 0x0, 0x3, 0x1, 0x1, 0x11, 0xE}, // j
  {0x10, 0x10, 0x11, 0x12, 0x1C, 0x12, 0x11}, // k
  {0xC, 0x4, 0x4, 0x4, 0x4, 0x4, 0xE}, // l
  {0x0, 0x0, 0x1E, 0x15, 0x15, 0x15, 0x15}, // m
  {0x0, 0x0, 0x1E, 0x11, 0x11, 0x11, 0x11}, // n
  {0x0, 0x0, 0xE, 0x11, 0x11, 0x11, 0xE}, // o
  {0x0, 0x0, 0xF, 0x9, 0xE, 0x8, 0x8}, // p
  {0x0, 0x0, 0xF, 0x11, 0xF, 0x1, 0x1}, // q
  {0x0, 0x0, 0x17, 0x18, 0x10, 0x10, 0x10}, // r
  {0x0, 0x0, 0xF, 0x10, 0xE, 0x1, 0x1E}, // s
  {0x8, 0x8, 0x1C, 0x8, 0x8, 0x9, 0x6}, // t
  {0x0, 0x0, 0x11, 0x11, 0x11, 0x13, 0x13}, // u
  {0x0, 0x0, 0x11, 0x11, 0x11, 0xA, 0x4}, // v
  {0x0, 0x0, 0x11, 0x11, 0x15, 0x1F, 0x15}, // w
  {0x0, 0x0, 0x11, 0xA, 0x4, 0xA, 0x11}, // x
  {0x0, 0x0, 0x11, 0x11, 0xF, 0x1, 0x1E}, // y
  {0x0, 0x0, 0x1F, 0x2, 0x4, 0x8, 0x1F}, // z
  {0x2, 0x4, 0x4, 0x8, 0x4, 0x4, 0x2}, // {
  {0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4}, // |
  {0x8, 0x4, 0x4, 0x2, 0x4, 0x4, 0x8}, // }
  {0x0, 0x0, 0x0, 0xA, 0x15, 0x0, 0x0}, // ~
};
uint16_t frame_buffer[7];
char message[] = "MATRIX LED 7X10  ";
byte string_length = strlen(message);

void set_bit(byte bitnum) {
  PORTB |= _BV(bitnum);
}

void clr_bit(byte bitnum) {
  PORTB &= ~_BV(bitnum);
}

void bit_data(byte bitnum, bool val) {
  if (val) set_bit(bitnum);
  else clr_bit(bitnum);
}

void set_clr_bit(byte bitnum) {
  set_bit(bitnum);
  clr_bit(bitnum);
}

void send_data(uint16_t data) {
  for (uint16_t mask = 1; mask & 0x3ff; mask <<= 1) { // Extracts one bit at a time from the data 10 times starting with the LSB.
    bit_data(SERIAL_DATA, data & mask); // Set data pin high if the current bit is 1, else set data pin low.
    set_clr_bit(SH_CLK); // Set and reset clock pin, telling the shift register to read in the current data pin value.
  }
 
  set_clr_bit(ST_CLK); // Set and reset latch pin to display the data at the output of the shift registers.
}

void send_frame_buffer() {
  for (byte t = 0; t < DELAY; t++) { // The delay we get with loops.
    for (byte row = 0; row < 7; row++) { // For each row.
        send_data(frame_buffer[row]); // Send 10 bits to shift registers.
        _delay_us(800); // This delay defines the time to play each pattern.
        send_data(0); // Clear the row so we can go on to the next row without smearing.
        set_clr_bit(CD4017_CLK); // On to the next row.
    }
     
    set_clr_bit(CD4017_RST);  // Select the first row.
  }
}

void load_char(byte pos) {
  for (byte column = 0; column < 5; column++) {
    for (byte row = 0; row < 7; row++) {  
      byte index = message[pos]; 
      byte temp = char_data[index-32][row];
      frame_buffer[row] = (frame_buffer[row]<<1) | (temp>>4-column);
    }
   
    send_frame_buffer();
  }
}

void display_message() {
  for (byte c = 0;  c < string_length; c++) {
    load_char(c);
     
    for (byte row = 0; row < 7; row++) { // One column of separation between characters.
      frame_buffer[row] <<= 1;
    }
     
    send_frame_buffer();
  }
}

int main() {
  DDRB = 0b111111;
  set_clr_bit(CD4017_RST); // Makes sure the 4017 value is 0.
  send_data(0); // Clear shift registers.
    
  while (1) {
    display_message();
  }
}
