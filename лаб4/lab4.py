import time
class Keyboard:
    def __init__(self):
        self.symbols = ['`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-','=', #SHIFT = 0, eng
                        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\',
                        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
                        'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
                        '~', '!', '@', '#', '$', '%', '^','&', '*', '(', ')', '_', '+', #SHIFT = 1, eng
                        'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '|',
                        'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"',
                        'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?',
                        'ё', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', #SHIFT = 0, ru
                        'й', 'ц', 'у', 'к', 'е', 'н', 'г', 'ш', 'щ', 'з', 'х', 'ъ', '\\',
                        'ф', 'ы', 'в', 'а', 'п', 'р', 'о', 'л', 'д', 'ж', 'э',
                        'я', 'ч', 'с', 'м', 'и', 'т', 'ь', 'б', 'ю', '.',
                        'Ё', '!', '"', '№', ';', '%', ':', '?', '*', '(', ')', '_', '+', #SHIFT = 1, ru
                        'Й', 'Ц', 'У', 'К', 'Е', 'Н', 'Г', 'Ш', 'Щ', 'З', 'Х', 'Ъ', '/',
                        'Ф', 'Ы', 'В', 'А', 'П', 'Р', 'О', 'Л', 'Д', 'Ж', 'Э',
                        'Я', 'Ч', 'С', 'М', 'И', 'Т', 'Ь', 'Б', 'Ю', ',']
                        #длина одного "блока" 47
        self.tmpSymbols = self.symbols.copy()#массив клон, его будем изменять
        self.kombos = ['shift', 'ctrl', 'alt'] #массив клавиш для комбинаций
        self.tmpKombos = self.kombos.copy()#его массив клон, чтобы изменять
        self.workflow = []
        self.shift = False #0 - выключен, 1 - включен
        self.caps = False #0 - выключен, 1 - включены
        self.layout = False #0 - eng, 1 - ru
        self.koef = 2 * self.layout + self.shift # 0 - shift=0, eng; 1 - shift=1, eng; 2 - shift = 0, ru; 3 - shift=1, ru

    def Shifted(self): #шифт
        self.shift = not self.shift
        self.refreshKoef()
    def changeLayout(self): #смена раскладки
        self.layout = not self.layout
        self.refreshKoef()
    def Capsed(self): #капс
        self.caps = not self.caps
        self.refreshKoef()
    def refreshKoef(self): #функция обновления коэффициента, нужна для определения символа в массиве self.symbols
        self.koef = 2 * self.layout + (self.shift ^ self.caps)
    def pressKey(self, key): #нажатие клавиши
        if key.lower() == 'caps': #если клавиша caps
            self.Capsed() #сделать символ капсом
        if key in self.symbols:
            time.sleep(1)
            print(self.buildKey(key), end="")
            self.workflow.append(self.buildKey(key))
    def buildKey(self, key): #"строительство" клавиши, происходит за счет подсчета позиции в массиве self.symbols
        if key in self.symbols:
            tmp = self.symbols[self.tmpSymbols.index(key) + 47 * self.koef]
            return tmp
        return ''
        

    def pressKombo(self, key1, key2, key3=""): #нажатие комбинации
        if key1.lower() in self.kombos and key2.lower() in self.kombos and key3 in self.symbols: #проверка на комбинацию из двух клавиш комбинации и обычной клавиши
            time.sleep(1)
            print('[' + self.kombos[self.tmpKombos.index(key1)] + ']' + '[' + self.kombos[self.tmpKombos.index(key2)] + '] ' + self.buildKey(key3), end="")
            self.workflow.append('[' + self.kombos[self.tmpKombos.index(key1)] + ']' + '[' + self.kombos[self.tmpKombos.index(key2)] + '] ' + self.buildKey(key3))
        elif key1.lower() in self.kombos and key2.lower() in self.kombos and key3 in self.kombos: #проверка на комбинацию из трех клавиш комбинации
            sleep(1)
            print('[' + self.kombos[self.tmpKombos.index(key1)] + ']' + '[' + self.kombos[self.tmpKombos.index(key1)] + '] ' + self.kombos[self.tmpKombos.index(key3)], end="")
            self.workflow.append('[' + self.kombos[self.tmpKombos.index(key1)] + ']' + '[' + self.kombos[self.tmpKombos.index(key2)] + '] ' + self.kombos[self.tmpKombos.index(key3)])
        else:
            if key1.lower() == 'alt' and key2.lower() == 'shift': #проверка на shift + alt
                self.changeLayout()
            if key1.lower() == 'shift' and key2 in self.symbols: #проверка на shift
                self.Shifted()
                self.pressKey(key2)
                self.workflow.append(self.buildKey(key2))
                self.Shifted()
            if (key1.lower() == 'ctrl' or key1.lower() == 'alt') and key2 in self.symbols: #остальные клавиши для комбинации
                time.sleep(1)
                print('[' + key1 + '] ' + self.buildKey(key2), end="")
                self.workflow.append('[' + key1 + '] ' + self.buildKey(key2))
        

    def undo(self): #откат
        lastAct = self.workflow.pop()
        for i in range(len(lastAct)):
            print('\b \b', end="")

    def renameKey(self, oldKey, newKey): #переназначение клавиши
        if oldKey in self.symbols and newKey in self.symbols:
            tmp1 = self.tmpSymbols.index(self.buildKey(oldKey))
            tmp2 = self.tmpSymbols.index(self.buildKey(newKey))
            self.tmpSymbols[tmp1], self.tmpSymbols[tmp2] = self.tmpSymbols[tmp2], self.tmpSymbols[tmp1]
            self.reloadWorkflow(oldKey, newKey)

    def renameKombo(self, oldKombo, newKombo): #переназначение клавиш для комбинации
        if oldKombo in self.kombos and newKombo in self.kombos:
            tmpOld = self.tmpKombos.index(oldKombo)
            tmpNew = self.tmpKombos.index(newKombo)
            self.tmpKombos[tmpNew], self.tmpKombos[tmpOld] = self.tmpKombos[tmpOld], self.tmpKombos[tmpNew]
            self.reloadWorkflow(oldKombo, newKombo)
            
    def printWorkflow(self): #вывод workflow
        print(self.workflow)

    def reloadWorkflow(self, oldElem, newElem): #перезагрузка workflow
        if len(newElem) == 1: #если длина символа 1, то это обычная клавиша
            for i in range(0, len(self.workflow)):
                if self.workflow[i] is oldElem:
                    self.workflow[i] = newElem
        else: #если нет, то клавиша для комбинации
            for i in range(0, len(self.workflow)):
                if oldElem in self.workflow[i]:
                    self.workflow[i] = self.workflow[i].replace(oldElem, newElem)
            
kb = Keyboard()
kb.pressKey('f')
kb.pressKombo('shift', 'f')
kb.pressKey('f')
kb.pressKey('caps')
kb.pressKey('f')
kb.pressKombo('shift', 'f')
kb.pressKombo('alt', 'shift')
kb.pressKey('f')
kb.pressKombo('shift', 'f')
kb.pressKey('f')
kb.pressKey('caps')
kb.pressKey('f')
kb.pressKombo('shift', 'f')
kb.pressKombo('alt', 'f')
kb.undo()
kb.pressKombo('alt', 'shift')
kb.pressKey('h')
print("")
print("")
kb.printWorkflow()
kb.renameKey('h', 'n')
kb.pressKey('h')
print("")
print("")
kb.printWorkflow()
print("")
print("")



kb.pressKombo('alt', 'shift', 'a')
print("")
print("")
kb.printWorkflow()
print("")
print("")
kb.renameKombo('alt', 'ctrl')
kb.pressKombo('alt', 'shift', 'a')
print("")
print("")
kb.printWorkflow()
