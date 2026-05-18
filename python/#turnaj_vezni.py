#turnaj_vezni
#pokrocily_hrac
#Hodnoty v payoff matici jsou body / zisky, ne tresty. Mate se je snazit tedy maximalizovat.
# Zaroven prvni radka reprezentuje 0 / False reprezentuje COOPERATE (=spolupracovat) 
#a 1 / True reprezentuje DEFECT (=zradit / svedcit).
#prvni iterace at je COOP tedy False


class MyPlayer:
    """
    hrac si vypocita prumer odmeny, pokrcuje podle soupere
    """

    
    souper_svedcil = 0
    souper_spolupracoval = 0
    ja_svedcil = 0
    ja_spolupracoval = 0

    def __init__(self, payoff_matrix, number_of_iterations=None):
        self.payoff_matrix = payoff_matrix
        self.number_of_iterations = number_of_iterations or 1
        self.my_last_move = None
        self.opponent_last_move = None

        self.zisk_svedcit1 = self.payoff_matrix[0][0][0]
        self.zisk_svedcit2 = self.payoff_matrix[0][1][0]
        self.zisk_spolupracovat1 = self.payoff_matrix[1][0][0]
        self.zisk_spolupracovat2 = self.payoff_matrix[1][1][0]
   
    def move(self):
        COOPERATE = False
        DEFECT = True
        ROZDIL_ODMEN = abs((self.zisk_svedcit1 + self.zisk_svedcit2)/2 - (self.zisk_spolupracovat1 + self.zisk_spolupracovat2)/2)
        PRVNI_ITERACE = self.souper_svedcil + self.souper_spolupracoval == 0
        
        if self.zisk_spolupracovat1 > self.zisk_svedcit1:
            if ROZDIL_ODMEN > 5:
                if(self.zisk_svedcit1 + self.zisk_svedcit2)/2 > (self.zisk_spolupracovat1 + self.zisk_spolupracovat2)/2:
                    return True
                return False
            
            if PRVNI_ITERACE:
                return False

            if self.souper_svedcil < 3:
                return False
            else:
                return True
        else:
            return False
               
    def record_last_moves(self, my_last_move, opponent_last_move):
        self.my_last_move = my_last_move
        self.opponent_last_move = opponent_last_move
        if self.opponent_last_move == True:
            self.souper_svedcil += 1
        else:
            self.souper_spolupracoval += 1
        if self.my_last_move == True:
            self.ja_svedcil += 1
        else:
            self.ja_spolupracoval += 1

if __name__ == "__main__":
    hrac = MyPlayer( payoff_matrix=(((4,4),(1,6)) , ((6,1),(2,2))) )
    print(hrac.move())
    print("  C  D")
    #print("C" + str(hrac.zisk_svedcit1[0][0][0]))