#define SERIAL_BUFFER_SIZE 2048
#define SERIAL1_BUFFER_SIZE 64

int inputSlave;
char outputSlave;
int inputMaster;
char outputMaster;
int CharCount;
char UTF[256][3];
int MaxChar;

void setup() {
  
  Serial.begin(9600);
  Serial1.begin(1200, SERIAL_7E1);
  MaxChar=80;
  CRLF();
  Store();

  
}

void loop() {

  if (Serial1.available() > 0) {
    //  Serial.print("out");
    inputSlave = Serial1.read();




    outputSlave = inputSlave;

    Serial.print(outputSlave);


  }

  if (Serial.available() > 0) {
    
    inputMaster = Serial.read();
    
    if (inputMaster == 195) {
      
      goto skip;
      
    }else if (inputMaster > 127) {

      Serial.print(inputMaster);
      getUTF(inputMaster);
    } else {
      
      outputMaster = inputMaster;
      Serial1.print(outputMaster);

    }
    delay(20);
    Count();
    
    skip:;
  }
}



int getUTF(int value) {

  char X[3];

  X[0] = UTF[value][0];   //Get the max. 3 bytes from storage
  X[1] = UTF[value][1];
  X[2] = UTF[value][2];

  printUTF(X);
}

int printUTF(char Char[]) {

  int l = Char[2];

  for (int i = 0; i < l; i++) {           // Print for each column of a letter
    Serial1.print(Char[i]);

  }


}



void Count() {
  if (CharCount == 0) {
    CRLF();
  }
  CharCount++;
  if (CharCount > MaxChar) {
    CharCount = 0;
  }
  delay(10);
}

void CRLF() {
  CharCount = 1;
  delay(100);
  char LF = 0x0A;
  char CR = 0x0D;
  Serial1.print(LF);
  Serial1.print(CR);
  delay(100);


}
void Store() {

  UTF[132][0] = 65; //Ä
  UTF[132][1] = 101;
  UTF[132][2] = 2;
  
  UTF[136][0] = 69; //È
  UTF[136][1] = 0;
  UTF[136][2] = 1;

  UTF[137][0] = 69; //È
  UTF[137][1] = 0;
  UTF[137][2] = 1;
  
  UTF[150][0] = 97; //Ö
  UTF[150][1] = 101;
  UTF[150][2] = 2;
  
  UTF[156][0] = 85; //Ü
  UTF[156][1] = 101;
  UTF[156][2] = 2;

  UTF[164][0] = 97; //ä
  UTF[164][1] = 101;
  UTF[164][2] = 2;

  UTF[168][0] = 101; //è
  UTF[168][1] = 0;
  UTF[168][2] = 1;
  
  UTF[169][0] = 101; //é
  UTF[169][1] = 0;
  UTF[169][2] = 1;

  UTF[182][0] = 111; //ö
  UTF[182][1] = 101;
  UTF[182][2] = 2;

  UTF[188][0] = 117; //ü
  UTF[188][1] = 101;
  UTF[188][2] = 2;



}
