import serial
from playsound import playsound

class HotKeysServer:

    yeah = "C:/Users/Guillermo/Downloads/Yeah.mp3"

    def play_sound(self,file):
        playsound(file)


    def __init__(self,port,speed):
        self.port = port
        self.speed = speed


    def start_server(self):
        ser = serial.Serial(self.port, self.speed, timeout=1)

        while(True):
            line = str(ser.readline())
            if(line):
                
                if("yeah" in line):
                    print("YEAH!")
                    self.play_sound(self.yeah)


if __name__ == "__main__":
    server = HotKeysServer('COM9',9600)
    server.start_server()