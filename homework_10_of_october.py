#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math #подключение библиотеки для математических рассчетов 
import numpy #подключение второй библиотеки для математических рассчетов 
import matplotlib.pyplot as mpp #подключение третьей библиотеки для математических рассчетов. У нее длинное название, так что программа обращается к ней по присвоенному сокращению

# Эта программа рисует график функции, заданной выражением ниже

if __name__=='__main__': #программа будет работать, только если запущенна как основная (а не как модуль)
    arguments = numpy.arange(0, 200, 0.1) #Функция возвращает одномерный массив с равномерно разнесенными значениями внутри заданного интервала.
    mpp.plot( 
        arguments, #массив arguments передается функции в качестве параметра. Номера элементов откладываются по оси х, соотвествующие значения по оси у
        [math.sin(a) / a * math.sin(a/20.0) for a in arguments] #каждому а-ому элемнту массива присваивается значение математической функии в соответсвующей точке
    )
    mpp.show() #программа показывает график пользователю
