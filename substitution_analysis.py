import argparse
import os

def select():

    print()
    print("1) back")
    print("2) forward")
    print("3) exit")
    
if __name__=="__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument("-f", required=True)

    args = parser.parse_args()
    
    try:
        f = open(args.f, 'r', encoding="utf8")

        origin_text = f.read()
        back_text = origin_text

        f.close()
        
        print(origin_text)

        while True:

            select()

            choice = int(input())

            if choice == 1:
                origin_text = back_text
                print(origin_text)
                
            elif choice == 2:
                back_text = origin_text
                o_text = input("original text: ")
                r_text = input("replace text: ")

                origin_text = origin_text.replace(o_text, r_text)

                print(origin_text)
            elif choice == 3:
                break
                
            else:
                print("{} is not exitst".format(choice))
                continue
    
    except:
        print("file is not exist")
