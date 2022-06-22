def mystery(z, x, y):
    z -= 1
    x = 2 * y + z
    y = x - 1
    print(y, z)
    return x

"""def main():
    x = 1
    y = 2
    z = 3
    z = mystery(x, z, y)
    print(x, y, z)
    x = mystery(z, z, x)
    print(x, y, z)
    y = mystery(y, y, z)
    print(x, y, z)
"""
def main():
    shows = ['Breaking Bad', 'The Office', 'Community', 'Parks and Recreation']
    print(shows[3][6:-7])
main()

