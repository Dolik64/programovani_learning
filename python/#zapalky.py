#zapalky
zapalka = "======="
mezera = "   "
print("hra pro dva hrace: obirej postupne 1 2 nebo 3 zapalky")
print("vyhrava ten, kdo odebere posledni zapalku")
print()
hrac1 = str(input)
for i in range(10):
    print(zapalka + mezera + zapalka)