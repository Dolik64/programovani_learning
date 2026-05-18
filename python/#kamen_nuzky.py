#kamen_nuzky
import random


class MyPlayer:

    """
    Toto je popisny retezec
    """

    def __init__(self, taktika):
        self.taktika = taktika
        

    
        
    def move(self):
        if self.taktika == 0:
            tah = random.randint(0,2)
            if tah == 0:
                return "kamen"
            elif tah == 1:
                return "nuzky"
            return "papir"
        elif self.taktika == 1:
            return "kamen"
        
if __name__ == "__main__":
    konstantni_hrac = MyPlayer(1)
    random_hrac = MyPlayer(0)
    konstantni_hrac_score = 0
    random_hrac_score = 0
    for _ in range(100):
        if konstantni_hrac.move() == random_hrac.move():
            pass
        elif konstantni_hrac.move() == "kamen" and random_hrac.move() == "nuzky":
            konstantni_hrac_score += 1
        elif konstantni_hrac.move() == "kamen" and random_hrac.move() == "papir":
            random_hrac_score += 1
    print("konstantni_hrac_score je " + str(konstantni_hrac_score))
    print("random_hrac_score " + str(random_hrac_score))