import serial
import time
import pyautogui

ArduinoSerial=serial.Serial('com3',9600)
time.sleep(2)

while 1:
    incoming=str(ArduinoSerial.readline())
    print incoming

    if "Play/Pause" in incoming:
        pyautogui.typewrite(['space'],0.2)

    if "Rewind" in incoming:
        pyautogui.hotkey('ctrl','left')

    if "Forward" in incoming:
        pyautogui.hotkey('ctrl','right')

    if "Increase" in incoming:
        pyautogui.hotkey('ctrl','up')
  
    if "Decrease" in incoming:
        pyautogui.hotkey('ctrl','down')
  
    
  
    incoming =""
   
