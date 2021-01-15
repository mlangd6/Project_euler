import time

'''Thanks to Python we could resolve it easyly with a very short code.
Python has a module calendar permits to find the day of a date
with the function weekday(). If d a date and d.weekday() == 6,
the date corresponds to a sunday.'''

'''
We create two arrays[12] arrays[i] contains the number of day on the month i.
One array is for leap years, other for the other year.
The function is simple, and we constats the algortihm with shorts calculus
'''
def sundays():
    m = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    b = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    # 01/01/1901 is a tuesday
    date = 2
    res = 0

    for year in range(1901, 2001) :
        for month in range(0, 12) :
            if year%4 != 0 :
                date += m[month]%7
            else :
                date += b[month]%7
            if date%7 == 0 :
                res = res + 1
    return res

def main():
    start = time.time()

    res = sundays()

    end  = time.time()

    print ("Found ", res,"in", end-start, "seconds.")
