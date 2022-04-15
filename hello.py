# 以下代码仅适用于python3, 安装python3后在终端输入"python3 hello.py"
def func():
    print (1/0)

if __name__ == '__main__':
    # input()接收字符串, 括号里的字符串会先显示在终端上，起提醒用户的作用
    hello = input("please enter a string:")
    print('this is your input', hello)
    # int(xxx) 把xxx转化成int，同理，float(xxx)，把xxx转化成float
    number = (input("please enter a number:"))
    print('this is your another input', number)
    print('hello')
    print('world')

