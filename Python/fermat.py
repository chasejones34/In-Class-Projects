def check_fermat(a, b, c, n ):
    if n > 2 and (a ** n + b ** n == c ** n):
        print("Holy smokes, Fermat was wrong.")
    else: 
        print("No, that doesn't work.")
def fermat():
    a = int(input("Pick a number for a: "))
    b = int(input("Pick a number for b: "))
    c = int(input("Pick a number for c: "))
    n = int(input("Pick a number for n: "))
    return check_fermat(a, b, c, n)

fermat()