from twython import Twython
import serial

arduinoSerialData = serial.Serial('/dev/ttyACM0',9600)

C_Key = "qkJ9q9ZcbbNWU64207O1VvCAL"
C_Secret = "1Tx5rODHnroNcX5RNY9jti744zHsQNRnvkt9d6NQEzlZFZNyRr"
A_Token = "859344142006067201-FLsbn3mS4kmo3WWmrbV2bEyy3ipMX0v"
A_Secret = "WXhlNHU7beHyrJ4vnEORyKO9kqAenDgR4qZp77Zt9pH2a"

while (1==1): 
    if (arduinoSerialData.inWaiting()>0): 
        myData = arduinoSerialData.readline()
print myData
api= Twython (C_Key, C_Secret, A_Token, A_Secret) api.update_status(status="Hello world")
