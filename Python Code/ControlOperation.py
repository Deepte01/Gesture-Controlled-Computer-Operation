import serial
import time
import pyautogui
import cv2
import numpy as np


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

    if "pageup" in incoming:
        pyautogui.scroll(100)

    if "pagedown" in incoming:
        pyautogui.scroll(-100)
  
    if "Decrease" in incoming:
        pyautogui.hotkey('ctrl','down')

    if 'change' in incoming:                  # if incoming data is 'change'
        pyautogui.keyDown('alt')                   # performs "alt+tab" operation which switches the tab
        pyautogui.press('tab')
        pyautogui.keyUp('alt')
        
    if 'RecordVideo' in incoming:
        cap=cv2.VideoCapture(0)
        fourcc=cv2.VideoWriter_fourcc(*'XVID')
        out=cv2.VideoWriter('output.avi',fourcc,20.0,(640,480))
        while True:
            ret, frame=cap.read()
            gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
            out.write(frame)
            cv2.imshow('frame',frame)
            if cv2.waitKey(1) & 0xFF==ord('q'):
                break
        cap.release()
        out.release()
        cv2.destroyAllWindows()
  
    incoming =""
   
