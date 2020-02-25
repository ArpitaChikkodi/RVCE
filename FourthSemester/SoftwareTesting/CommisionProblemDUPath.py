def testCommission():
    global locks, stocks, barrels, totalSales, commission
    global lsales, ssales, bsales
    lockPrice,stockPrice,barrelPrice = 45,30,25
    count,totalLock,totalStocks,totalBarrels = 0,0,0,0
    locks = int(input("Enter the total number of locks : "))
    while locks != -1:
        stocks = int(input("Enter the total number of stocks : "))
        barrels = int(input("Enter the total number of barrels : "))
        if locks < 1 or locks > 70 and stocks < 1 or stocks > 80 and barrels < 1 or barrels > 90:
            count = 1
            print("Invalid Input!")
            exit()
        else:
            totalLock += locks
            totalStocks += stocks
            totalBarrels += barrels
            locks = int(
                input("Enter the number of locks or to exit the loop enter -1 : "))

    print("total locks : ", totalLock)
    print("total stocks : ", totalStocks)
    print("total barrel : ", totalBarrels)
    lsales = (totalLock * lockPrice)
    ssales = (totalStocks * stockPrice)
    bsales = (totalBarrels * barrelPrice)
    totalSales = lsales + ssales + bsales
    print("Total sales is : ", totalSales)
    if totalSales in range(1001, 1801):
        commission = 0.10 * 1000
        commission = commission + (0.15 * (totalSales - 1000))
    elif totalSales > 1800:
        commission = 0.10 * 1000  # for less than 1000 totalsales
        commission = commission + (0.15 * 800)  # for sales range in 1000 to 1800
        commission = commission + (0.20 * (totalSales - 1800))  # totalsales above 1800
    else:
        commission = 0.10 * totalSales
    print("Commission is ", commission)


testCommission()
'''while True:
    ch = int(input("Enter 1 to retest or 0 to exit : "))
    if ch == 1:
        testCommission()
    if ch == 0:
        print("Testing done!")
        exit()
'''
