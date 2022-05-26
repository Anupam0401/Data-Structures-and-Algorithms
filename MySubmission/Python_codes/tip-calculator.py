print("Welcome to the Tip calculator!")
bill=float(input("What was the total bill? $"))
percentage=int(input("What pecentage tip would you like to give? 10, 12 or 15?  "))
people=int(input("How many people to split the bill into?  "))
each_person_pay = (bill*percentage/100 + bill) / people
each_person_pay ="{:.2f}".format(each_person_pay)
print(f"Each person should pay : ${each_person_pay}")