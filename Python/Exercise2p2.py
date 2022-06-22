import math 

def volume_of_sphere():
    r=5
    print((4/3) * math.pi * r)

def total_price_of_books():
    print ((24.95 * .6) * 60.0 + 3.0 + 59.0 * .75)

def time_for_breakfast():
    easy = 495
    tempo = 432
    runningTime = (2 * easy + 3 * tempo) / 60
    timeLeft = 6 * 60 + 52
    timeReturnHours= (timeLeft + runningTime) / 60
    timeReturnMinutes= (timeLeft + runningTime) % 60
    print("You return home at " + str(int(timeReturnHours)) + ":" + str(int(timeReturnMinutes)) + " A.M")

volume_of_sphere()
total_price_of_books()
time_for_breakfast()