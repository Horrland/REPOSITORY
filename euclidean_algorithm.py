print('введите первую чиселку')
a = int(input())
print('введите вторую')
b = int(input())
while a != b:
    if a > b:
        a -= b
    else:
        b -= a
print('вот их НОД: ', a)