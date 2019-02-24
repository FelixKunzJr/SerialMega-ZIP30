# SerialMega-ZIP30


You have to increase the SERIAL_RX_BUFFER_SIZE in the Ardiono core library HardwareSerial.h on line 54 to 2048. This ensures you can transfer big files.

