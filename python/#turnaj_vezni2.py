#turnaj_vezni2
# True = Defect = Zrada = svedcit
# False = Cooperate = Spoluprace

class MyPlayer:
    """
    Hráč si vypočítá průměr odměny, pokračuje podle soupeře
    """

    COOPERATE = False
    DEFECT = True

    souper_svedcil = 0
    souper_spolupracoval = 0
    ja_svedcil = 0
    ja_spolupracoval = 0

    def __init__(self, payoff_matrix, number_of_iterations=None):
        self.payoff_matrix = payoff_matrix
        self.number_of_iterations = number_of_iterations or 1
        self.my_last_move = None
        self.opponent_last_move = None

        self.zisk_spolupracovat1 = self.payoff_matrix[0][0][0]
        self.zisk_spolupracovat2  = self.payoff_matrix[0][1][0]
        self.zisk_svedcit1 = self.payoff_matrix[1][0][0]
        self.zisk_svedcit2 = self.payoff_matrix[1][1][0]

    def move(self):
        ROZDIL_ODMEN = abs((self.zisk_svedcit1 + self.zisk_svedcit2) / 2 - (self.zisk_spolupracovat1 + self.zisk_spolupracovat2) / 2)
        PRVNI_ITERACE = self.souper_svedcil + self.souper_spolupracoval == 0
        VYHODA_SPOLUPRACE = self.zisk_spolupracovat1 > self.zisk_svedcit2
        VYHODA_SVEDCIT = self.zisk_spolupracovat1 <= self.zisk_svedcit2
        EXTREMNI_VYHODA_ZRADY = self.zisk_svedcit1 > 5 + self.zisk_spolupracovat1 + self.zisk_spolupracovat2

        if EXTREMNI_VYHODA_ZRADY:
            #print("EXTREMNI_VYHODA_ZRADY")
            return MyPlayer.DEFECT
        
        elif VYHODA_SPOLUPRACE :
            #print("VYHODA_SPOLUPRACE")
            if ROZDIL_ODMEN > 5:
                if (self.zisk_svedcit1 + self.zisk_svedcit2) / 2 > (self.zisk_spolupracovat1 + self.zisk_spolupracovat2) / 2:
                    return MyPlayer.DEFECT
                return MyPlayer.COOPERATE

            if PRVNI_ITERACE:
                return MyPlayer.COOPERATE

            if self.souper_svedcil < 3:
                return MyPlayer.COOPERATE
            else:
                return MyPlayer.DEFECT
            
        elif VYHODA_SVEDCIT:
            #print("VYHODA_SVEDCIT")
            return MyPlayer.DEFECT

    def record_last_moves(self, my_last_move, opponent_last_move):
        self.my_last_move = my_last_move
        self.opponent_last_move = opponent_last_move

        if self.opponent_last_move == MyPlayer.DEFECT:
            self.souper_svedcil += 1
        else:
            self.souper_spolupracoval += 1

        if self.my_last_move == MyPlayer.DEFECT:
            self.ja_svedcil += 1
        else:
            self.ja_spolupracoval += 1

if __name__ == "__main__":
    #hrac = MyPlayer(payoff_matrix=(((4, 4), (1, 6)), ((6, 1), (2, 2))))
    #hrac = MyPlayer(payoff_matrix=(((2, 2), (4, 6)), ((6, 4), (10, 10))))
    hrac = MyPlayer(payoff_matrix=(((5, 5), (1, 70)), ((70, 1), (2, 2))))
    print(hrac.move())
    print("  C  D")
    print("C", str(hrac.zisk_spolupracovat1), str(hrac.zisk_spolupracovat2))
    print("D", str(hrac.zisk_svedcit1), str(hrac.zisk_svedcit2))
